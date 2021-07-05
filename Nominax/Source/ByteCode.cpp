#include "../../Nominax/Include/Nominax/ByteCode/ByteCode.hpp"
#include "../../Nominax/Include/Nominax/Common/PanicRoutine.hpp"
#include "../../Nominax/Include/Nominax/Common/Algorithm.hpp"
#include "../../Nominax/Include/Nominax/Common/ComparatorProxyF64.hpp"
#include "../../Nominax/Include/Nominax/Common/AtomicState.hpp"

#include <execution>

namespace Nominax::ByteCode
{
	void TransformStreamToImageByCopy(const Stream& input, Image& output, JumpMap& jumpMap)
	{
		// allocate image and copy code:
		{
			const auto binaryImage{new(std::nothrow) Signal[input.Size()]};
			std::memcpy(binaryImage, std::data(input.GetCodeBuffer()),
			            std::size(input.GetCodeBuffer()) * sizeof(Signal));
			output = Image{static_cast<void*>(binaryImage), std::size(input.GetCodeBuffer()) * sizeof(Signal)};
		}

		// create jump map and execution address mapping:
		jumpMap.resize(input.Size());

		const auto& discriminators{input.GetDiscriminatorBuffer()};
		for (std::size_t i{0}; i < input.Size(); ++i)
		{
#if NOX_OPT_EXECUTION_ADDRESS_MAPPING

			if (discriminators[i] == Signal::Discriminator::JumpAddress)
			{
				output[i].Ptr = const_cast<void*>(Core::ComputeRelativeJumpAddress(output.GetBlobData(), output[i].JmpAddress));
			}

#endif
			jumpMap[i] = static_cast<U8>(discriminators[i] == Signal::Discriminator::Instruction);
		}
	}

	Image::Image(const std::span<const Signal> blob)
	{
		NOX_PANIC_ASSERT_NOT_ZERO(blob.size(), "Byte code image with zero size is invalid!");
		this->Size_ = std::size(blob);
		this->Blob_ = new(std::nothrow) Signal[this->Size_];
		std::memcpy(this->Blob_, std::data(blob), this->Size_ * sizeof(Signal));
	}

	Image::Image(const void* const data, const std::size_t byteSize)
	{
		NOX_PANIC_ASSERT_NOT_ZERO(byteSize, "Byte code image with zero size is invalid!");
		NOX_PANIC_ASSERT_NOT_NULL(data, "Byte code image with null data is invalid!");
		NOX_PANIC_ASSERT_TRUE(byteSize % sizeof(Signal) == 0, "Byte code image size must be a multiple of eight!");
		this->Size_ = byteSize / sizeof(Signal);
		this->Blob_ = new(std::nothrow) Signal[this->Size_];
		std::memcpy(this->Blob_, data, byteSize);
	}

	Image::Image(Signal* const data, const std::size_t size)
	{
		NOX_PANIC_ASSERT_NOT_ZERO(size, "Byte code image with zero size is invalid!");
		NOX_PANIC_ASSERT_NOT_NULL(data, "Byte code image with null data is invalid!");
		this->Blob_ = data;
		this->Size_ = size;
	}

	Image::Image(U8* const data, const std::size_t size)
	{
		NOX_PANIC_ASSERT_TRUE(size % sizeof(Signal) == 0, "Byte code image size must be a multiple of eight!");
		NOX_PANIC_ASSERT_NOT_ZERO(size, "Byte code image with zero size is invalid!");
		NOX_PANIC_ASSERT_NOT_NULL(data, "Byte code image with null data is invalid!");

		this->Size_ = size / sizeof(Signal);
		this->Blob_ = reinterpret_cast<Signal*>(data);
	}

	Image::Image(Image&& other) : Blob_{other.Blob_}, Size_{other.Size_}
	{
		other.Blob_ = nullptr;
		other.Size_ = 0;
	}

	Image& Image::operator =(Image&& other)
	{
		if (this->Blob_ && this->Size_)
		{
			delete[] this->Blob_;
		}

		this->Blob_ = other.Blob_;
		this->Size_ = other.Size_;

		other.Blob_ = nullptr;
		other.Size_ = 0;

		return *this;
	}

	Image::~Image()
	{
		delete[] this->Blob_;
		this->Blob_ = nullptr;
		this->Size_ = 0;
	}

	using Dis = Signal::Discriminator;;

	static constexpr std::array ANY_TYPE
	{
		Dis::U64,
		Dis::I64,
		Dis::F64,
		Dis::CharClusterUtf8,
		Dis::CharClusterUtf16,
		Dis::CharClusterUtf32
	};

	const std::array<PerInstructionArgTypes, static_cast<std::size_t>(Instruction::$Count)>
	INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES
	{
		PerInstructionArgTypes{{Dis::I64}}, // int
		{{Dis::SystemIntrinsicCallID}}, // intrin
		{{Dis::UserIntrinsicCallID}}, // cintrin
		{{Dis::U64}}, // call
		{}, // ret
		{{Dis::U64}, {Dis::U64}}, // mov
		{{Dis::U64}, {std::begin(ANY_TYPE), std::end(ANY_TYPE)}}, // sto
		{{std::begin(ANY_TYPE), std::end(ANY_TYPE)}}, // push
		{}, // pop
		{}, // pop2
		{}, // dupl
		{}, // dupl2
		{}, // swap
		{}, // nop
		{{Dis::JumpAddress}}, // jmp
		{{Dis::JumpAddress}}, // jmprel
		{{Dis::JumpAddress}}, // jz
		{{Dis::JumpAddress}}, // jnz
		{{Dis::JumpAddress}}, // jo_cmpi
		{{Dis::JumpAddress}}, // jo_cmpf
		{{Dis::JumpAddress}}, // jno_cmpi
		{{Dis::JumpAddress}}, // jno_cmpf
		{{Dis::JumpAddress}}, // je_cmpi
		{{Dis::JumpAddress}}, // je_cmpf
		{{Dis::JumpAddress}}, // jne_cmpi
		{{Dis::JumpAddress}}, // jne_cmpf
		{{Dis::JumpAddress}}, // ja_cmpi
		{{Dis::JumpAddress}}, // ja_cmpf
		{{Dis::JumpAddress}}, // jl_cmpi
		{{Dis::JumpAddress}}, // jl_cmpf
		{{Dis::JumpAddress}}, // jae_cmpi
		{{Dis::JumpAddress}}, // jae_cmpf
		{{Dis::JumpAddress}}, // jle_cmpi
		{{Dis::JumpAddress}}, // jle_cmpf
		{}, // pushz
		{}, // ipusho
		{}, // fpusho
		{}, // iinc
		{}, // idec
		{}, // iadd
		{}, // isub
		{}, // imul
		{}, // idiv
		{}, // imod
		{}, // iand
		{}, // ior
		{}, // ixor
		{}, // icom
		{}, // isal
		{}, // isar
		{}, // irol
		{}, // iror
		{}, // ineg
		{}, // fadd
		{}, // fsub
		{}, // fmul
		{}, // fdiv
		{}, // fmod
		{}, // fneg
		{}, // finc
		{}, // fdec
		{
			// vpush
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)}
		},
		{}, // vpop
		{}, // vadd
		{}, // vsub
		{}, // vmul
		{}, // vdiv
		{
			// matpush
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
		},
		{}, // matpop
		{}, // matadd
		{}, // matsub
		{}, // matmul
		{} // matdiv
	};

	using Common::ILog2;
	using Common::Proxy_F64IsZero;
	using Common::Proxy_F64IsOne;
	using Common::IsPowerOfTwo;

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	ScopedVariable<F64>& ScopedVariable<F64>::Push(const F64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// If zero, optimize with special push zero instruction.
			if (Proxy_F64IsZero(value))
			{
				this->Attached_.Do<Instruction::PushZ>();
				return *this;
			}

			// If one, optimize with special push F32 one instruction.
			if (Proxy_F64IsOne(value))
			{
				this->Attached_.Do<Instruction::FPushO>();
				return *this;
			}

			// If the value is the previous written element in the stream,
			// we can just duplicate it:
			if (!this->Attached_.IsEmpty() && this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Dupl>();
				return *this;
			}
		}

		// Else just do a push:
		this->Attached_.Do<Instruction::Push>(value);
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::Push(const I64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// If zero, optimize with special push zero instruction.
			if (value == 0)
			{
				this->Attached_.Do<Instruction::PushZ>();
				return *this;
			}

			// If one, optimize with special push integer one instruction.
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IPushO>();
				return *this;
			}

			// If the value is the previous written element in the stream,
			// we can just duplicate it:
			if (!this->Attached_.IsEmpty() && this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Dupl>();
				return *this;
			}
		}

		// Else just do a push:
		this->Attached_.Do<Instruction::Push>(value);
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::Push(const U64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// If zero, optimize with special push zero instruction.
			if (value == 0)
			{
				this->Attached_.Do<Instruction::PushZ>();
				return *this;
			}

			// If one, optimize with special push integer one instruction.
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IPushO>();
				return *this;
			}

			// If the value is the previous written element in the stream,
			// we can just duplicate it:
			if (!this->Attached_.IsEmpty() && this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Dupl>();
				return *this;
			}
		}
		// Else just do a push:
		this->Attached_.Do<Instruction::Push>(value);
		return *this;
	}

	template <>
	ScopedVariable<F64>& ScopedVariable<F64>::Add(const F64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (Proxy_F64IsZero(value))
			{
				return this->DoNothing();
			}

			// Optimize to increment:
			if (Proxy_F64IsOne(value))
			{
				this->Attached_.Do<Instruction::FInc>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::FAdd>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::Add(const I64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (value == 0)
			{
				return this->DoNothing();
			}

			// Optimize to increment:
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IInc>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IAdd>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::Add(const U64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (value == 0)
			{
				return this->DoNothing();
			}

			// Optimize to increment:
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IInc>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IAdd>();
		return *this;
	}


	template <>
	ScopedVariable<F64>& ScopedVariable<F64>::Sub(const F64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (Proxy_F64IsZero(value))
			{
				return this->DoNothing();
			}

			// Optimize to decrement:
			if (Proxy_F64IsOne(value))
			{
				this->Attached_.Do<Instruction::FDec>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::FSub>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::Sub(const I64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (value == 0)
			{
				return this->DoNothing();
			}

			// Optimize to decrement:
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IDec>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISub>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::Sub(const U64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (value == 0)
			{
				return this->DoNothing();
			}

			// Optimize to decrement:
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IDec>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISub>();
		return *this;
	}

	template <>
	ScopedVariable<F64>& ScopedVariable<F64>::Mul(const F64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// By 0 or 1 is a no-op:
			if (Proxy_F64IsZero(value) || Proxy_F64IsOne(value))
			{
				return this->DoNothing();
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::FMul>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::Mul(I64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// By 0 or 1 is a no-op:
			if (value == 0 || value == 1)
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = ILog2(value);
				this->Push(value);
				this->Attached_.Do<Instruction::ISal>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IMul>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::Mul(U64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// By 0 or 1 is a no-op:
			if (value == 0 || value == 1)
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = ILog2(value);
				this->Push(value);
				this->Attached_.Do<Instruction::ISal>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IMul>();
		return *this;
	}

	template <>
	ScopedVariable<F64>& ScopedVariable<F64>::Div(const F64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// x / x is always 1
			if (this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Pop>();
				this->Push(1.0);
				return *this;
			}

			// By 1 it's just the same value.
			if (Proxy_F64IsOne(value))
			{
				return this->DoNothing();
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::FDiv>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::Div(I64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// x / x is always 1
			if (this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Pop>();
				this->Push(static_cast<decltype(value)>(1));
				return *this;
			}

			// By 1 it's just the same value.
			if (value == 1)
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = ILog2(value);
				this->Push(value);
				this->Attached_.Do<Instruction::ISar>();
				return *this;
			}
		}

		this->Push(value);
		this->Attached_.Do<Instruction::IDiv>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::Div(U64 value)
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// x / x is always 1
			if (this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Pop>();
				this->Push(static_cast<decltype(value)>(1));
				return *this;
			}

			// By 1 it's just the same value.
			if (value == 1)
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = ILog2(value);
				this->Push(value);
				this->Attached_.Do<Instruction::ISar>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IDiv>();
		return *this;
	}

	template <>
	ScopedVariable<F64>& ScopedVariable<F64>::Mod(const F64 value)
	{
		this->Push(value);
		this->Attached_.Do<Instruction::FMod>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::Mod(const I64 value)
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IMod>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::Mod(const U64 value)
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IMod>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::And(const I64 value)
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IAnd>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::And(const U64 value)
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IAnd>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::Or(const I64 value)
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IOr>();
		return *this;
	}


	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::Or(const U64 value)
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IOr>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::Xor(const I64 value)
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IXor>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::Xor(const U64 value)
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IXor>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::ShiftLeft(const I64 value)
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISal>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::ShiftLeft(const U64 value)
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISal>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::ShiftRight(const I64 value)
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISar>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::ShiftRight(const U64 value)
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISar>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::RotateLeft(const I64 value)
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IRol>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::RotateLeft(const U64 value)
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IRol>();
		return *this;
	}

	template <>
	ScopedVariable<I64>& ScopedVariable<I64>::RotateRight(const I64 value)
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IRor>();
		return *this;
	}

	template <>
	ScopedVariable<U64>& ScopedVariable<U64>::RotateRight(const U64 value)
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IRor>();
		return *this;
	}

	using namespace Common;

	void Stream::PrintByteCode() const
	{
		Print(TextColor::Green, "Len: {}, Size: {} B", this->Size(), this->SizeInBytes());
		for (std::size_t i{0}; i < this->Size(); ++i)
		{
			if (this->CodeDisc_[i] == Signal::Discriminator::Instruction)
			{
				Print(TextColor::Green, "\n&{:08X}: ", i);
				Print(TextColor::Cyan, "{}", this->Code_[i].Instr);
			}
			else
			{
				Print(TextColor::Magenta, " {}", (*this)[i]);
			}
		}
		Print("\n\n");
	}

	void Stream::PrintMemoryCompositionInfo() const
	{
		Print("Stream size: {}\n", this->Size());
		Print("Code buffer: {:.03F} MB\n",
		      Bytes2Megabytes<F32>(
			      static_cast<F32>(this->Code_.size()) * static_cast<F32>(sizeof(CodeStorageType::value_type))));
		Print("Discriminator buffer: {:.03F} MB\n", Bytes2Megabytes<F32>(
			      static_cast<F32>(this->CodeDisc_.size()) * static_cast<F32>(sizeof(
				      DiscriminatorStorageType::value_type))));
		Print("Total: {:.03F} MB\n", Bytes2Megabytes<F32>(static_cast<F32>(this->SizeInBytes())));
	}

	Stream& Stream::Prologue()
	{
		for (const auto& [discriminator, signal] : PrologueCode())
		{
			this->CodeDisc_.emplace_back(discriminator);
			this->Code_.emplace_back(signal);
		}
		return *this;
	}

	Stream& Stream::Epilogue()
	{
		for (const auto& [discriminator, signal] : EpilogueCode())
		{
			this->CodeDisc_.emplace_back(discriminator);
			this->Code_.emplace_back(signal);
		}
		return *this;
	}

	ValidationResultCode Stream::Build(Image& out, JumpMap& outJumpMap) const
	{
		if (const auto validationResult{ValidateFullPass(*this)}; validationResult != ValidationResultCode::Ok)
		{
			[[unlikely]]
				return validationResult;
		}
		TransformStreamToImageByCopy(*this, out, outJumpMap);
		return ValidationResultCode::Ok;
	}

	bool Stream::ContainsPrologue() const
	{
		return ByteCode::ContainsPrologue(*this);
	}

	bool Stream::ContainsEpilogue() const
	{
		return ByteCode::ContainsEpilogue(*this);
	}

	bool ContainsPrologue(const Stream& input)
	{
		constexpr const auto& code{Stream::PrologueCode()};
		if (input.Size() < code.size())
		{
			[[unlikely]]
				return false;
		}
		for (std::size_t i{0}; i < code.size(); ++i)
		{
			if (code[i] != input[i])
			{
				[[unlikely]]
					return false;
			}
		}
		return true;
	}

	bool ContainsEpilogue(const Stream& input)
	{
		constexpr const auto& code{Stream::EpilogueCode()};
		if (input.Size() < code.size())
		{
			[[unlikely]]
				return false;
		}
		for (std::size_t i{0}, j{input.Size() - code.size()}; i < code.size(); ++i)
		{
			if (code[i] != input[j + i])
			{
				[[unlikely]]
					return false;
			}
		}
		return true;
	}

	ValidationResultCode ValidateFullPass(const Stream& input, UserIntrinsicRoutineRegistry intrinsicRegistry,
	                                      U32* const outIndex)
	{
		// Check if empty:
		if (input.IsEmpty())
		{
			[[unlikely]]
				return ValidationResultCode::Empty;
		}

		// Check if we've reached the pointer compression limit:
		if (input.Size() >= std::numeric_limits<U32>::max())
		{
			[[unlikely]]
				return ValidationResultCode::SignalLimitReached;
		}

		// Check if prologue code is contained:
		if (!ContainsPrologue(input))
		{
			[[unlikely]]
				return ValidationResultCode::MissingPrologueCode;
		}

		// Check if epilogue code is contained:
		if (!ContainsEpilogue(input))
		{
			[[unlikely]]
				return ValidationResultCode::MissingEpilogueCode;
		}

		// Validate that user intrinsic calls are non null:
		for (IntrinsicRoutine* const routine : intrinsicRegistry)
		{
			if (!routine)
			{
				[[unlikely]]
					return ValidationResultCode::InvalidUserIntrinsicCall;
			}
		}

		// Error code:
		AtomicState<ValidationResultCode> error{};
		std::atomic<U32> errorIndex{0};

		const auto& codeBuf{input.GetCodeBuffer()};
		const auto& discBuf{input.GetDiscriminatorBuffer()};
		const auto bufBegin{&*std::begin(discBuf)};
		const auto bufEnd{&*std::end(discBuf)};

		auto validationRoutine
		{
			[&error, &codeBuf, &input, &intrinsicRegistry, &errorIndex, bufBegin, bufEnd](
			const Signal::Discriminator& iterator)
			{
				const std::ptrdiff_t index{DistanceRef(iterator, bufBegin)};
				const Signal signal{codeBuf[index]};
				auto result{ValidationResultCode::Ok};

				switch (iterator)
				{
					// validate instruction:
				case Signal::Discriminator::Instruction:
					{
						const auto* const next{SearchForNextInstruction(&iterator, bufEnd)};
						const auto args{
							ExtractInstructionArguments(&iterator, ComputeInstructionArgumentOffset(&iterator, next))
						};
						result = ValidateInstructionArguments(signal.Instr, args); // validate args
					}
					break;

				case Signal::Discriminator::JumpAddress:
					{
						result = ValidateJumpAddress(input, signal.JmpAddress)
							         ? ValidationResultCode::Ok
							         : ValidationResultCode::InvalidJumpAddress;
					}
					break;

				case Signal::Discriminator::UserIntrinsicCallID:
					{
						result = ValidateUserIntrinsicCall(intrinsicRegistry, signal.UserIntrinID)
							         ? ValidationResultCode::Ok
							         : ValidationResultCode::InvalidUserIntrinsicCall;
					}
					break;

				default: ;
				}

				if (result != ValidationResultCode::Ok)
				[[unlikely]]
				{
					errorIndex.store(index);
					error(result);
				}
			}
		};

		std::for_each(std::execution::par_unseq, std::begin(discBuf), std::end(discBuf), validationRoutine);

		// Return error if the error value is not okay
		if (!error)
		[[unlikely]]
		{
			if (outIndex)
			{
				[[unlikely]]
					*outIndex = errorIndex.load();
			}
			return error();
		}

		if (outIndex)
		{
			[[unlikely]]
				*outIndex = 0;
		}

		return ValidationResultCode::Ok;
	}

	bool ValidateJumpAddress(const Stream& bucket, const JumpAddress address)
	{
		const auto idx{static_cast<std::size_t>(address)};

		// validate that jump address is inside the range of the bucket:
		if (bucket.Size() <= idx)
		{
			[[unlikely]]
				return false;
		}

		return NOX_EXPECT_VALUE(bucket[idx].Contains<Instruction>(), true);
	}

	bool ValidateSystemIntrinsicCall(const SystemIntrinsicCallID id)
	{
		constexpr auto max{static_cast<std::underlying_type_t<decltype(id)>>(SystemIntrinsicCallID::$Count) - 1};
		const auto value{static_cast<std::underlying_type_t<decltype(id)>>(id)};
		static_assert(std::is_unsigned_v<decltype(value)>);
		return NOX_EXPECT_VALUE(value <= max, true);
	}

	bool ValidateUserIntrinsicCall(const UserIntrinsicRoutineRegistry& routines, UserIntrinsicCallID id)
	{
		static_assert(std::is_unsigned_v<std::underlying_type_t<decltype(id)>>);
		return NOX_EXPECT_VALUE(static_cast<std::underlying_type_t<decltype(id)>>(id) < routines.size(), true);
	}

	ValidationResultCode ValidateInstructionArguments(const Instruction instruction,
	                                                  const std::span<const Signal::Discriminator>& args)
	{
		// First check if the argument count is incorrect:
		if (LookupInstructionArgumentCount(instruction) > args.size())
		{
			[[unlikely]]
				return ValidationResultCode::NotEnoughArgumentsForInstruction;
		}

		// First check if the argument count is incorrect:
		if (LookupInstructionArgumentCount(instruction) < args.size())
		{
			[[unlikely]]
				return ValidationResultCode::TooManyArgumentsForInstruction;
		}

		for (std::size_t i{0}; i < args.size(); ++i)
		{
			const Signal::Discriminator discriminator{args[i]};

			// Check if our given type index is within the required indices:

			const TypeIndexTable& required{LookupInstructionArgumentTypes(instruction)[i]};
			const bool isWithinAllowedIndices{
				std::find(std::begin(required), std::end(required), discriminator) != std::end(required)
			};

			if (!isWithinAllowedIndices)
			{
				// if not, validation failed:
				[[unlikely]]
					return ValidationResultCode::ArgumentTypeMismatch;
			}
		}

		return ValidationResultCode::Ok;
	}
}
