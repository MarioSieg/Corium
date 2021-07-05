#include <atomic>
#include <algorithm>
#include <execution>
#include <fstream>

#include "../../Nominax/Include/Nominax/Common/Common.hpp"
#include "../../Nominax/Include/Nominax/ByteCode.hpp"

namespace Nominax::Common
{
	U64 ILog2DeBruijn(U64 x)
	{
		static constexpr std::array<U64, 64> DE_BRUIJN_TABLE
		{
			0x00, 0x3A, 0x01, 0x3B,
			0x2F, 0x35, 0x02, 0x3C,
			0x27, 0x30, 0x1B, 0x36,
			0x21, 0x2A, 0x03, 0x3D,
			0x33, 0x25, 0x28, 0x31,
			0x12, 0x1C, 0x14, 0x37,
			0x1E, 0x22, 0x0B, 0x2B,
			0x0E, 0x16, 0x04, 0x3E,
			0x39, 0x2E, 0x34, 0x26,
			0x1A, 0x20, 0x29, 0x32,
			0x24, 0x11, 0x13, 0x1D,
			0x0A, 0x0D, 0x15, 0x38,
			0x2D, 0x19, 0x1F, 0x23,
			0x10, 0x09, 0x0C, 0x2C,
			0x18, 0x0F, 0x08, 0x17,
			0x07, 0x06, 0x05, 0x3F
		};

		x |= x >> UINT64_C(1);
		x |= x >> UINT64_C(2);
		x |= x >> UINT64_C(4);
		x |= x >> UINT64_C(8);
		x |= x >> UINT64_C(16);
		x |= x >> UINT64_C(32);

		return DE_BRUIJN_TABLE[x * UINT64_C(0x03F6EAF2CD271461) >> UINT64_C(58)];
	}

	U32 LinearizeCoords2D(const U16 x, const U16 y)
	{
		static constexpr std::array<U16, 256> MORTON_TABLE
		{
			0x0000, 0x0001, 0x0004, 0x0005, 0x0010, 0x0011, 0x0014, 0x0015,
			0x0040, 0x0041, 0x0044, 0x0045, 0x0050, 0x0051, 0x0054, 0x0055,
			0x0100, 0x0101, 0x0104, 0x0105, 0x0110, 0x0111, 0x0114, 0x0115,
			0x0140, 0x0141, 0x0144, 0x0145, 0x0150, 0x0151, 0x0154, 0x0155,
			0x0400, 0x0401, 0x0404, 0x0405, 0x0410, 0x0411, 0x0414, 0x0415,
			0x0440, 0x0441, 0x0444, 0x0445, 0x0450, 0x0451, 0x0454, 0x0455,
			0x0500, 0x0501, 0x0504, 0x0505, 0x0510, 0x0511, 0x0514, 0x0515,
			0x0540, 0x0541, 0x0544, 0x0545, 0x0550, 0x0551, 0x0554, 0x0555,
			0x1000, 0x1001, 0x1004, 0x1005, 0x1010, 0x1011, 0x1014, 0x1015,
			0x1040, 0x1041, 0x1044, 0x1045, 0x1050, 0x1051, 0x1054, 0x1055,
			0x1100, 0x1101, 0x1104, 0x1105, 0x1110, 0x1111, 0x1114, 0x1115,
			0x1140, 0x1141, 0x1144, 0x1145, 0x1150, 0x1151, 0x1154, 0x1155,
			0x1400, 0x1401, 0x1404, 0x1405, 0x1410, 0x1411, 0x1414, 0x1415,
			0x1440, 0x1441, 0x1444, 0x1445, 0x1450, 0x1451, 0x1454, 0x1455,
			0x1500, 0x1501, 0x1504, 0x1505, 0x1510, 0x1511, 0x1514, 0x1515,
			0x1540, 0x1541, 0x1544, 0x1545, 0x1550, 0x1551, 0x1554, 0x1555,
			0x4000, 0x4001, 0x4004, 0x4005, 0x4010, 0x4011, 0x4014, 0x4015,
			0x4040, 0x4041, 0x4044, 0x4045, 0x4050, 0x4051, 0x4054, 0x4055,
			0x4100, 0x4101, 0x4104, 0x4105, 0x4110, 0x4111, 0x4114, 0x4115,
			0x4140, 0x4141, 0x4144, 0x4145, 0x4150, 0x4151, 0x4154, 0x4155,
			0x4400, 0x4401, 0x4404, 0x4405, 0x4410, 0x4411, 0x4414, 0x4415,
			0x4440, 0x4441, 0x4444, 0x4445, 0x4450, 0x4451, 0x4454, 0x4455,
			0x4500, 0x4501, 0x4504, 0x4505, 0x4510, 0x4511, 0x4514, 0x4515,
			0x4540, 0x4541, 0x4544, 0x4545, 0x4550, 0x4551, 0x4554, 0x4555,
			0x5000, 0x5001, 0x5004, 0x5005, 0x5010, 0x5011, 0x5014, 0x5015,
			0x5040, 0x5041, 0x5044, 0x5045, 0x5050, 0x5051, 0x5054, 0x5055,
			0x5100, 0x5101, 0x5104, 0x5105, 0x5110, 0x5111, 0x5114, 0x5115,
			0x5140, 0x5141, 0x5144, 0x5145, 0x5150, 0x5151, 0x5154, 0x5155,
			0x5400, 0x5401, 0x5404, 0x5405, 0x5410, 0x5411, 0x5414, 0x5415,
			0x5440, 0x5441, 0x5444, 0x5445, 0x5450, 0x5451, 0x5454, 0x5455,
			0x5500, 0x5501, 0x5504, 0x5505, 0x5510, 0x5511, 0x5514, 0x5515,
			0x5540, 0x5541, 0x5544, 0x5545, 0x5550, 0x5551, 0x5554, 0x5555
		};

		return MORTON_TABLE[y >> 8] << 17 | MORTON_TABLE[x >> 8] << 16 | MORTON_TABLE[y & 0xFF] << 1 | MORTON_TABLE[x &
			0xFF];
	}

	U32 Xorshift32Atomic()
	{
		static constinit std::atomic_uint32_t seed32{0x12B9B0A1};
		seed32 ^= seed32 << 0xD;
		seed32 ^= seed32 >> 0x11;
		seed32 ^= seed32 << 0x5;
		return seed32;
	}

	U64 Xorshift64Atomic()
	{
		static constinit std::atomic_uint64_t seed64{0x139408DCBBF7A44};
		seed64 ^= seed64 << 0xD;
		seed64 ^= seed64 >> 0x7;
		seed64 ^= seed64 << 0x11;
		return seed64;
	}

	U32 Xorshift128Atomic()
	{
		static constinit std::atomic_uint32_t x{0x75BCD15};
		static constinit std::atomic_uint32_t y{0x159A55E5};
		static constinit std::atomic_uint32_t z{0x1F123BB5};
		static constinit std::atomic_uint32_t w{0x5491333};

		const uint32_t t = x ^ x << 0xB;
		x.exchange(y);
		y.exchange(z);
		z.exchange(w);
		w ^= w >> 0xD ^ t ^ t >> 0x8;
		return w;
	}

	U32 Xorshift32ThreadLocal()
	{
		static constinit thread_local U32 seed32{0x12B9B0A1};
		seed32 ^= seed32 << 0xD;
		seed32 ^= seed32 >> 0x11;
		seed32 ^= seed32 << 0x5;
		return seed32;
	}

	U64 Xorshift64ThreadLocal()
	{
		static constinit thread_local U64 seed64{0x139408DCBBF7A44};
		seed64 ^= seed64 << 0xD;
		seed64 ^= seed64 >> 0x7;
		seed64 ^= seed64 << 0x11;
		return seed64;
	}

	U32 Xorshift128ThreadLocal()
	{
		static constinit thread_local U32 x{0x75BCD15};
		static constinit thread_local U32 y{0x159A55E5};
		static constinit thread_local U32 z{0x1F123BB5};
		static constinit thread_local U32 w{0x5491333};

		const uint32_t t = x ^ x << 0xB;
		x = y;
		y = z;
		z = w;
		w ^= w >> 0xD ^ t ^ t >> 0x8;
		return w;
	}

	void IAllocator::Allocate(void*& out, const std::size_t size) const
	{
		out = static_cast<U8*>(std::malloc(size));
	}

	void IAllocator::Reallocate(void*& out, const std::size_t size) const
	{
		out = static_cast<U8*>(std::realloc(out, size));
	}

	void IAllocator::Deallocate(void*& out) const
	{
		std::free(out);
		out = nullptr;
	}

	void IAllocator::AllocateAligned(void*& out, const std::size_t size, const std::size_t alignment) const
	{
#if NOX_OS_WINDOWS && NOX_COM_CLANG
		out = static_cast<U8*>(_aligned_malloc(size, alignment));
#else
		out = static_cast<U8*>(aligned_alloc(alignment, size));
#endif
	}

	void IAllocator::ReallocateAligned(void*& out, const std::size_t size, const std::size_t alignment) const
	{
#if NOX_OS_WINDOWS && NOX_COM_CLANG
		out = static_cast<U8*>(_aligned_realloc(out, size, alignment));
#else
		auto mem{static_cast<U8*>(aligned_alloc(alignment, size))};
		std::memcpy(mem, out, size);
		std::free(out);
		out = mem;
#endif
	}

	void IAllocator::DeallocateAligned(void*& out) const
	{
#if NOX_OS_WINDOWS && NOX_COM_CLANG
		_aligned_free(out);
#else
		std::free(out);
#endif
		out = nullptr;
	}

	void IAllocator::Valloc(void*& out, const std::size_t size) const
	{
		this->Allocate(out, size);
	}

	void IAllocator::Vdealloc(void*& out) const
	{
		this->Deallocate(out);
	}

	CliArgParser::CliArgParser(const signed argc, const char* const* const argv)
	{
		Args_.reserve(argc);
		Args_.insert(argv, argc + argv);
	}

	bool CliArgParser::AddOption(const std::string_view name, const std::string_view description)
	{
		Options_.emplace_back(std::make_pair(name, description));
		return this->HasFlag(name);
	}

	void CliArgParser::PrintAllOptions()
	{
		for (const auto& [k, v] : this->Options_)
		{
			Print("{} = {}\n", k, v);
		}
	}

	bool CliArgParser::IsEmpty() const
	{
		return this->Args_.size() <= 1;
	}

	const std::unordered_set<std::string_view>& CliArgParser::GetArgs() const
	{
		return this->Args_;
	}

	const std::vector<std::pair<std::string_view, std::string_view>>& CliArgParser::GetOptions() const
	{
		return this->Options_;
	}

	bool CliArgParser::HasFlag(const std::string_view key)
	{
		return std::ranges::find(this->Args_, key) != this->Args_.end();
	}

	static constexpr std::pair<std::size_t, std::string_view> GetMemoryUnitInfo(const std::size_t bytes)
	{
		if (bytes == 0 || bytes < KB)
		{
			return {bytes, "B"};
		}
		if (bytes < MB)
		{
			return {bytes / KB, "KB"};
		}
		if (bytes < GB)
		{
			return {bytes / MB, "MB"};
		}
		if (bytes < TB)
		{
			return {bytes / GB, "GB"};
		}
		return {bytes, "B"};
	}

	void DebugAllocator::Allocate(void*& out, const std::size_t size) const
	{
		IAllocator::Allocate(out, size);
		const auto [count, suffix]{GetMemoryUnitInfo(size)};
		Print(TextColor::BrightGreen, "Allocate({:#X}, {} {})\n", reinterpret_cast<std::uintptr_t>(out), count, suffix);
		++this->Allocations_;
		this->BytesAllocated_ += size;
	}

	void DebugAllocator::Reallocate(void*& out, const std::size_t size) const
	{
		IAllocator::Reallocate(out, size);
		const auto [count, suffix]{GetMemoryUnitInfo(size)};
		Print(TextColor::BrightYellow, "Reallocate({:#X}, {} {})\n", reinterpret_cast<std::uintptr_t>(out), count,
		      suffix);
		++this->Reallocations_;
	}

	void DebugAllocator::Deallocate(void*& out) const
	{
		Print(TextColor::BrightRed, "Deallocate({:#X})\n", reinterpret_cast<std::uintptr_t>(out));
		IAllocator::Deallocate(out);
		++this->Deallocations_;
	}

	void DebugAllocator::AllocateAligned(void*& out, const std::size_t size, const std::size_t alignment) const
	{
		IAllocator::AllocateAligned(out, size, alignment);
		const auto [count, suffix]{GetMemoryUnitInfo(size)};
		Print(TextColor::BrightGreen, "AllocateAligned({:#X}, {} {}, {} A)\n", reinterpret_cast<std::uintptr_t>(out),
		      count, suffix, alignment);
		++this->Allocations_;
		this->BytesAllocated_ += size;
	}

	void DebugAllocator::ReallocateAligned(void*& out, const std::size_t size, const std::size_t alignment) const
	{
		IAllocator::ReallocateAligned(out, size, alignment);
		const auto [count, suffix]{GetMemoryUnitInfo(size)};
		Print(TextColor::BrightGreen, "ReallocateAligned({:#X}, {} {}, {} A)\n", reinterpret_cast<std::uintptr_t>(out),
		      count, suffix, alignment);
		++this->Reallocations_;
	}

	void DebugAllocator::DeallocateAligned(void*& out) const
	{
		Print(TextColor::BrightRed, "DeallocateAligned({:#X})\n", reinterpret_cast<std::uintptr_t>(out));
		IAllocator::DeallocateAligned(out);
		++this->Deallocations_;
	}

	void DebugAllocator::DumpAllocationInfo() const
	{
		const auto [count, suffix]{GetMemoryUnitInfo(this->BytesAllocated_)};
		Print(TextColor::BrightGreen, "Allocations: {}\n", this->Allocations_);
		Print(TextColor::BrightGreen, "Reallocations: {}\n", this->Reallocations_);
		Print(TextColor::BrightGreen, "Deallocations: {}\n", this->Deallocations_);
		Print(TextColor::BrightGreen, "Total: {} {}\n", count, suffix);
		if (this->Allocations_ != this->Deallocations_)
		{
			Print(TextColor::BrightYellow, "Missing allocations: {}\n", this->Allocations_ - this->Deallocations_);
		}
		Print(TextColor::BrightYellow, "Warning! Some global shutdown deallocations might not be tracked!\n");
	}

	signed NominaxMain(const signed argc, const char* const* const argv)
	{
		{
			CliArgParser argParser{argc, argv};
			const auto help{argParser.AddOption("-h", "print help") || argParser.IsEmpty()};
			const auto isa{argParser.AddOption("-i", "print virtual instruction set")};
			const auto ver{argParser.AddOption("-v", "print version")};

			if (help)
			{
				Print("Usage: \n");
				argParser.PrintAllOptions();
			}
			else if (isa)
			{
				Print("{: < 10} |  {: < 8}| {: < 3} | {: < 3} | {: < 3} |\n\n", "Mnemonic", "OpCode", "Imm", "Psh",
				      "Pop");
				for (U64 i{0}; i < static_cast<U64>(ByteCode::Instruction::$Count); ++i)
				{
					const auto& mnemonic{ByteCode::INSTRUCTION_MNEMONICS[i]};
					const auto immCount{ByteCode::INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES[i].size()};
					const auto pushCount{ByteCode::INSTRUCTION_PUSH_COUNTS[i]};
					const auto popCount{ByteCode::INSTRUCTION_POP_COUNTS[i]};
					Print("{: < 10} |   {:#04x}   | {: < 3} | {: < 3} | {: < 3} |\n", mnemonic, i, immCount, pushCount,
					      popCount);
				}
			}
			else if (ver)
			{
				Core::PrintSystemInfo();
			}
		}

		return 0;
	}

	std::tm SafeLocalTime(const std::time_t& time)
	{
		std::tm buffer{};
#if NOX_COM_GCC
		localtime_r(&time, &buffer);
#elif NOX_OS_WINDOWS
		localtime_s(&buffer, &time);
#else
		static std::mutex mtx;
		std::lock_guard<std::mutex> lock(mtx);
		buffer = *std::localtime(&_time);
#endif
		return buffer;
	}

	static constinit volatile std::sig_atomic_t SignalStatus{0};

	std::sig_atomic_t QuerySignalStatus()
	{
		return SignalStatus;
	}

	void InstallSignalHandlers(auto (&handler)(std::sig_atomic_t) -> void)
	{
		std::signal(SIGINT, &handler);
		std::signal(SIGILL, &handler);
		std::signal(SIGFPE, &handler);
		std::signal(SIGSEGV, &handler);
		std::signal(SIGTERM, &handler);
		std::signal(SIGABRT, &handler);
	}

	void UninstallSignalHandlers()
	{
		std::signal(SIGINT, SIG_DFL);
		std::signal(SIGILL, SIG_DFL);
		std::signal(SIGFPE, SIG_DFL);
		std::signal(SIGSEGV, SIG_DFL);
		std::signal(SIGTERM, SIG_DFL);
		std::signal(SIGABRT, SIG_DFL);
	}

	[[nodiscard]]
	static inline TextFile::ViewType SubstringView
	(
		const TextFile::StringType& source,
		const size_t offset = 0,
		const TextFile::ViewType::size_type count = std::numeric_limits<TextFile::ViewType::size_type>::max()
	)
	{
		if (offset < source.size())
		[[likely]]
		{
			return
			{
				source.data() + offset,
				std::min(source.size() - offset, count)
			};
		}
		return {};
	}

	static inline std::string_view SubstringView
	(
		std::string&& source,
		size_t offset = 0,
		std::string_view::size_type count = std::numeric_limits<std::string_view::size_type>::max()
	) = delete;

	bool TextFile::WriteToFile(std::filesystem::path&& path)
	{
		this->FilePath_ = std::move(path);
		std::ofstream stream{this->FilePath_};
		if (!stream)
		{
			[[likely]]
				return false;
		}
		stream << this->Content_;
		return true;
	}

	bool TextFile::ReadFromFile(std::filesystem::path&& path)
	{
		this->FilePath_ = std::move(path);
		std::ifstream stream{this->FilePath_};
		if (!stream)
		{
			[[unlikely]]
				return false;
		}
		stream.seekg(0, std::ios::end);
		this->Content_.resize(stream.tellg());
		stream.seekg(0, std::ios::beg);
		stream.read(std::data(this->Content_), std::size(this->Content_));
		return true;
	}

	void TextFile::ReadFromFileOrPanic(std::filesystem::path&& path)
	{
		if (!this->ReadFromFile(std::move(path)))
		{
			[[unlikely]]
				Panic(NOX_PAINF, "Failed to read text file from path: {}", path.string());
		}
	}

	void TextFile::ParallelEraseSpaces()
	{
		this->Content_.erase
		(
			std::remove_if(std::execution::par_unseq, std::begin(this->Content_), std::end(this->Content_),
			               [](const char c) -> bool
			               {
				               return c == ' ';
			               }),
			std::end(this->Content_)
		);
	}

	void TextFile::ParallelEraseSpacesAndControlChars()
	{
		this->Content_.erase
		(
			std::remove_if(std::execution::par_unseq, std::begin(this->Content_), std::end(this->Content_),
			               [](const char c) -> bool
			               {
				               return std::isspace<char>(c, std::locale::classic());
			               }),
			std::end(this->Content_)
		);
	}

	void TextFile::ParallelErase(const CharType x)
	{
		this->Content_.erase
		(
			std::remove_if(std::execution::par_unseq, std::begin(this->Content_), std::end(this->Content_),
			               [x](const char c) -> bool
			               {
				               return c == x;
			               }),
			std::end(this->Content_)
		);
	}

	void TextFile::EraseRange(const CharType begin, const CharType end)
	{
		const std::size_t beginIndex{this->Content_.find(begin)};
		const std::size_t endIndex{this->Content_.find(end, beginIndex + 1)};
		this->Content_.erase(beginIndex, endIndex - beginIndex + 1);
	}

	TextFile::ViewType TextFile::SubString(const std::size_t beginIdx, const std::size_t endIdx) const
	{
		return SubstringView(this->Content_, beginIdx, endIdx - beginIdx + 1);
	}

	TextFile::ViewType TextFile::SubStringChar(const CharType beginChar, const CharType endChar) const
	{
		const std::size_t beginIndex{this->Content_.find_first_of(beginChar)};
		const std::size_t endIndex{this->Content_.find_first_of(endChar, beginIndex + 1)};
		return SubstringView(this->Content_, beginIndex, endIndex - beginIndex + 1);
	}
}

using namespace fmt;
using namespace Nominax;
using namespace ByteCode;
using namespace Core;

FormatOutput formatter<Instruction, char, void>::format(const Instruction& value,
                                                        format_context& ctx) const
{
	return format_to
	(
		ctx.out(),
		"{}",
		INSTRUCTION_MNEMONICS[static_cast<std::underlying_type_t<std::remove_reference_t<decltype(value)>>>(value)]
	);
}

FormatOutput formatter<SystemIntrinsicCallID, char, void>::format(const SystemIntrinsicCallID& value,
                                                                  format_context& ctx) const
{
	return format_to(ctx.out(), "{:#X}", static_cast<std::underlying_type_t<SystemIntrinsicCallID>>(value));
}

FormatOutput formatter<UserIntrinsicCallID, char, void>::format(const UserIntrinsicCallID& value,
                                                                format_context& ctx) const
{
	return format_to(ctx.out(), "{:#X}", static_cast<std::underlying_type_t<UserIntrinsicCallID>>(value));
}

FormatOutput formatter<JumpAddress, char, void>::format(const JumpAddress& value, format_context& ctx) const
{
	return format_to(ctx.out(), "{:#X}", static_cast<std::underlying_type_t<JumpAddress>>(value));
}

FormatOutput formatter<CharClusterUtf8, char, void>::format(const CharClusterUtf8& value,
                                                            format_context& ctx) const
{
	static_assert(sizeof(char8_t) == sizeof(U8));
	return format_to(ctx.out(),
	                 R"(\{:X}\{:X}\{:X}\{:X}\{:X}\{:X}\{:X}\{:X})",
	                 static_cast<U16>(value.Chars[0]),
	                 static_cast<U16>(value.Chars[1]),
	                 static_cast<U16>(value.Chars[2]),
	                 static_cast<U16>(value.Chars[3]),
	                 static_cast<U16>(value.Chars[4]),
	                 static_cast<U16>(value.Chars[5]),
	                 static_cast<U16>(value.Chars[6]),
	                 static_cast<U16>(value.Chars[7])
	);
}

FormatOutput formatter<CharClusterUtf16, char, void>::format(const CharClusterUtf16& value, format_context& ctx) const
{
	static_assert(sizeof(char16_t) == sizeof(U16));
	return format_to(ctx.out(),
	                 R"(\{:X}\{:X}\{:X}\{:X})",
	                 static_cast<U16>(value.Chars[0]), static_cast<U16>(value.Chars[1]),
	                 static_cast<U16>(value.Chars[2]), static_cast<U16>(value.Chars[3])
	);
}

FormatOutput formatter<CharClusterUtf32, char, void>::format(const CharClusterUtf32& value, format_context& ctx) const
{
	static_assert(sizeof(char32_t) == sizeof(U32));
	return format_to(ctx.out(),
	                 "\\{:X}\\{:X}",
	                 static_cast<U32>(value.Chars[0]), static_cast<U32>(value.Chars[1])
	);
}

FormatOutput formatter<ValidationResultCode, char, void>::format(const ValidationResultCode& value,
                                                                 format_context& ctx) const
{
	const auto idx{static_cast<std::underlying_type_t<std::remove_reference_t<decltype(value)>>>(value)};
	return format_to(ctx.out(), "{}", BYTE_CODE_VALIDATION_RESULT_CODE_MESSAGES[idx]);
}

FormatOutput formatter<ReactorValidationResult, char, void>::format(const ReactorValidationResult& value,
                                                                    format_context& ctx) const
{
	const auto idx{static_cast<std::underlying_type_t<std::remove_reference_t<decltype(value)>>>(value)};
	return format_to(ctx.out(), "{}", REACTOR_VALIDATION_RESULT_ERROR_MESSAGES[idx]);
}

FormatOutput formatter<DiscriminatedSignal, char, void>::format(const DiscriminatedSignal& value,
                                                                format_context& ctx) const
{
	using Dis = Signal::Discriminator;

	switch (value.Discriminator)
	{
	case Dis::U64:
		return format_to(ctx.out(), NOX_LEX_TYPE_U64 " " NOX_LEX_IMM "{}", value.Value.R64.AsU64);

	case Dis::I64:
		return format_to(ctx.out(), NOX_LEX_TYPE_I64 " " NOX_LEX_IMM "{}", value.Value.R64.AsI64);

	case Dis::F64:
		return format_to(ctx.out(), NOX_LEX_TYPE_F64 " " NOX_LEX_IMM "{}", value.Value.R64.AsF64);

	case Dis::CharClusterUtf8:
		return format_to(ctx.out(), NOX_LEX_TYPE_CC1 " " NOX_LEX_IMM "{}", reinterpret_cast<const char*>(&value.Value.R64));

	case Dis::CharClusterUtf16:
		return format_to(ctx.out(), NOX_LEX_TYPE_CC2 " " NOX_LEX_IMM "{}", reinterpret_cast<const char*>(&value.Value.R64)); // TODO CVT

	case Dis::CharClusterUtf32:
		return format_to(ctx.out(), NOX_LEX_TYPE_CC4 " " NOX_LEX_IMM "{}", reinterpret_cast<const char*>(&value.Value.R64)); // TODO CVT

	case Dis::OpCode:
	case Dis::Instruction:
		return format_to(ctx.out(), "{}", value.Value.Instr);

	case Dis::SystemIntrinsicCallID:
		return format_to(ctx.out(), NOX_LEX_TYPE_SIC " " NOX_LEX_IMM "{}",
		                 static_cast<std::underlying_type_t<SystemIntrinsicCallID>>(value.Value.SystemIntrinID));

	case Dis::UserIntrinsicCallID:
		return format_to(ctx.out(), NOX_LEX_TYPE_UIC " " NOX_LEX_IMM "{}",
		                 static_cast<std::underlying_type_t<UserIntrinsicCallID>>(value.Value.UserIntrinID));

	case Dis::JumpAddress:
		return format_to(ctx.out(), NOX_LEX_TYPE_UIC " " NOX_LEX_IMM "{}",
		                 static_cast<std::underlying_type_t<JumpAddress>>(value.Value.JmpAddress));

	default:
	case Dis::Ptr:
		return format_to(ctx.out(), NOX_LEX_TYPE_CC4 " " NOX_LEX_IMM "{:X}", value.Value.R64.AsU64);
	}
}

void* operator new(const std::size_t size)
{
	void* mem;
	Common::GlobalAllocatorProxy->Allocate(mem, size);
	return mem;
}

void* operator new[](const std::size_t size)
{
	void* mem;
	Common::GlobalAllocatorProxy->Allocate(mem, size);
	return mem;
}

#if false

auto operator new(const std::size_t size, const std::align_val_t alignment)  -> void*
{
	void* mem;
	Nominax::Common::GlobalAllocatorProxy->AllocateAligned(mem, size, static_cast<std::size_t>(alignment));
	return mem;
}

auto operator new[](const std::size_t size, const std::align_val_t alignment)  -> void*
{
	void* mem;
	Nominax::Common::GlobalAllocatorProxy->AllocateAligned(mem, size, static_cast<std::size_t>(alignment));
	return mem;
}

#endif

void* operator new(const std::size_t size, [[maybe_unused]] const std::nothrow_t& tag) noexcept(true)
{
	void* mem;
	Common::GlobalAllocatorProxy->Allocate(mem, size);
	return mem;
}

void* operator new[](const std::size_t size, [[maybe_unused]] const std::nothrow_t& tag) noexcept(true)
{
	void* mem;
	Common::GlobalAllocatorProxy->Allocate(mem, size);
	return mem;
}

#if false

auto operator new(const std::size_t size, const std::align_val_t alignment, [[maybe_unused]] const std::nothrow_t& tag)  -> void*
{
	void* mem;
	Nominax::Common::GlobalAllocatorProxy->AllocateAligned(mem, size, static_cast<std::size_t>(alignment));
	return mem;
}

auto operator new[](const std::size_t size, const std::align_val_t alignment, [[maybe_unused]] const std::nothrow_t& tag)  -> void*
{
	void* mem;
	Nominax::Common::GlobalAllocatorProxy->AllocateAligned(mem, size, static_cast<std::size_t>(alignment));
	return mem;
}

#endif

void operator delete(void* mem) noexcept(true)
{
	Common::GlobalAllocatorProxy->Deallocate(mem);
}

void operator delete(void* mem, std::size_t) noexcept(true)
{
	Common::GlobalAllocatorProxy->Deallocate(mem);
}

void operator delete[](void* mem) noexcept(true)
{
	Common::GlobalAllocatorProxy->Deallocate(mem);
}

void operator delete[](void* mem, std::size_t) noexcept(true)
{
	Common::GlobalAllocatorProxy->Deallocate(mem);
}
