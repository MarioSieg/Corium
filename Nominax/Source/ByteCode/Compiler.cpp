#include <charconv>
#include <fstream>

#include "../../Include/Nominax/ByteCode/Compiler.hpp"
#include "../../Include/Nominax/ByteCode/Stream.hpp"
#include "../../Include/Nominax/Foundation/Print.hpp"
#include "../../Include/Nominax/Foundation/IOStream.hpp"

namespace Nominax::ByteCode
{
    using Foundation::Algorithm::EnumeratingSearch;
    using Foundation::Panic::Panic;
    using Foundation::Panic::PanicF;
    using Foundation::Format;
	using Foundation::IOStream;

    static constexpr std::string_view CODE_FORMAT { "Format: <instruction> %(<type>)#<immediate>" };

    auto Compiler::Compile(const std::string& path, [[maybe_unused]] Stream& stream) -> void
    {
		const std::optional<IOStream> fStream { IOStream::TryOpen(path, Foundation::FileAccessMode::Read, Foundation::FileContentMode::Binary) };
		if (!fStream) [[unlikely]]
		{
			PanicF({}, NOX_FMT("Failed to open file: {}"), path);
		}
		const IOStream& file { *fStream };
		std::vector<std::uint8_t> contents{ };
		if(!file.ReadAll(contents)) [[unlikely]]
		{
			PanicF({}, NOX_FMT("Failed to read file: {}"), path);
		}
		std::array<char, 64> tokenBuf { };
		for (std::uint64_t needle { }; const std::uint8_t u8 : contents)
		{
			const auto chr { static_cast<char>(u8) };
			if (std::isspace(chr))
			{
				const std::string_view tokenView
				{
					std::data(tokenBuf),
					std::data(tokenBuf) + needle
				};
				if (!std::empty(tokenView))
				{
					CompileToken(tokenView, stream);
				}
				needle = 0;
			}
			else
			{
				tokenBuf[needle++] = chr;
				if (needle >= std::size(tokenBuf)) [[unlikely]]
				{
					Panic("Token too long!");
				}
			}
		}
    }

    auto Compiler::CompileToken(const std::string_view token, Stream& stream) -> void
    {
        if (std::empty(token) || token[0] == COMMENT_MARKER)
        {
            return;
        }
        switch (token[0])
        {
	        case TYPE_MARKER:
	        {
	            auto i { std::cbegin(token) + 1 };
	            if (*i++ != LPAREN) [[unlikely]]
	            {
	                PanicF({}, NOX_FMT("Missing type parenthesis: {}! {}"), token, CODE_FORMAT);
	            }
	            const std::array<const char, 3> typeID { *i++, *i++, *i++ };
	            const std::string_view typeView { std::cbegin(typeID), std::cend(typeID) };
	            Signal::Discriminator discriminator{ };
	            {
	                const bool found
	                {
	                    EnumeratingSearch
	                    (
	                        std::cbegin(TYPE_NAME_LIST),
	                        std::cend(TYPE_NAME_LIST),
	                        [typeView, &discriminator](const std::string_view current, const std::uint64_t iteration) -> bool
	                        {
	                            if (typeView == current)
	                            {
	                                discriminator = static_cast<Signal::Discriminator>(iteration);
	                                return true;
	                            }
	                            return false;
	                        }
	                    )
	                };
	                if (!found) [[unlikely]]
	                {
	                    std::string msg { Format(NOX_FMT("Invalid type name: {}! Available: "), typeView) };
	                    for (const std::string_view type : TYPE_NAME_LIST)
	                    {
	                        msg += type;
	                        msg.push_back(' ');
	                    }
	                    Panic(msg);
	                }
	            }
	            if (*i++ != RPAREN) [[unlikely]]
	            {
	                PanicF({}, NOX_FMT("Missing type parenthesis: {}! {}"), token, CODE_FORMAT);
	            }
	            if (*i++ != IMMEDIATE_MARKER) [[unlikely]]
	            {
	               PanicF({}, NOX_FMT("Missing immediate marker: {}! {}"), token, CODE_FORMAT);
	            }
	            const std::string_view immediate { i, std::cend(token) };
	            switch (discriminator)
	            {
		            case Signal::Discriminator::MemoryOffset:
		            case Signal::Discriminator::Intrinsic:
		            case Signal::Discriminator::JumpAddress:
		            case Signal::Discriminator::TypeID:
		            case Signal::Discriminator::FieldOffset:
		            {
		                std::uint64_t x;
		                if (const auto [_, err] { std::from_chars(&*std::cbegin(immediate), &*std::cend(immediate), x) }; err != std::errc()) [[unlikely]]
		                {
		                   PanicF({}, NOX_FMT( "Invalid immediate: {}! {}"), immediate, CODE_FORMAT);
		                }
	                    switch (discriminator)
	                    {
		                    case Signal::Discriminator::MemoryOffset:
		                        stream.Emit(MemOffset{ x });
		                    break;

		                    case Signal::Discriminator::Intrinsic:
		                        stream.Emit(UserIntrinsicInvocationID{ x });
		                    break;

		                    case Signal::Discriminator::JumpAddress:
		                        stream.Emit(JumpAddress{ x });
		                    break;

		                    case Signal::Discriminator::TypeID:
		                        stream.Emit(TypeID{ x });
		                    break;

		                    case Signal::Discriminator::FieldOffset:
		                        stream.Emit(FieldOffset{ x });
		                    break;

		                    default: ;
	                    }
		            }
		            break;

		            case Signal::Discriminator::SysCall:
		            {
		                SysCall call { };
		                const bool found
		                {
							EnumeratingSearch
		                    (
		                        std::cbegin(SYSCALL_MNEMONIC_TABLE),
		                        std::cend(SYSCALL_MNEMONIC_TABLE),
		                        [immediate, &call](const std::string_view current, const std::uint64_t iteration) -> bool
		                        {
		                            if (immediate == current)
		                            {
		                                call = static_cast<SysCall>(iteration);
		                                return true;
		                            }
		                            return false;
		                        }
		                    )
		                };
		                if (!found) [[unlikely]]
		                {
		                    PanicF({}, NOX_FMT("Invalid syscall: \"{}\"!"), SYSCALL_MNEMONIC_TABLE[Foundation::Algorithm::ToUnderlying(call)]);
		                }
		                stream.Emit(call);
		            }
					break;

		            case Signal::Discriminator::Int:
		            {
		                std::int64_t x;
		                if (const auto [_, err] { std::from_chars(&*std::cbegin(immediate), &*std::cend(immediate), x) }; err != std::errc()) [[unlikely]]
		                {
		                    PanicF({}, NOX_FMT("Invalid immediate: {}! {}"), immediate, CODE_FORMAT);
		                }
		                stream.Emit(x);
		            }
		            break;

		            case Signal::Discriminator::Float:
		            {
		                double x;
		                if (const auto [_, err] { std::from_chars(&*std::cbegin(immediate), &*std::cend(immediate), x) }; err != std::errc()) [[unlikely]]
		                {
		                    PanicF({}, NOX_FMT("Invalid immediate: {}! {}"), immediate, CODE_FORMAT);
		                }
		                stream.Emit(x);
		            }
		            break;

					default:;
		        }
		    }
		    break;

	        default:
	        {
	            const bool found
	            {
	                EnumeratingSearch
	                (
	                    std::cbegin(MNEMONIC_LIST),
	                    std::cend(MNEMONIC_LIST),
	                    [token, &stream](const std::string_view current, const std::uint64_t iteration)
	                    {
	                        if (current == token)
	                        {
	                            stream.Emit(static_cast<Instruction>(iteration));
	                            return true;
	                        }
	                        return false;
	                    }
	                )
	            };
	            if (!found) [[unlikely]]
	            {
	                PanicF({}, NOX_FMT("Unknown instruction: `{}`! {}"), token, CODE_FORMAT);
	            }
	        }
	        break;
        }
    }
}
