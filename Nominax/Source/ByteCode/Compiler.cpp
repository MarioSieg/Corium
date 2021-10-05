#include <charconv>
#include <fstream>

#include "../../Include/Nominax/ByteCode/Compiler.hpp"
#include "../../Include/Nominax/ByteCode/Stream.hpp"
#include "../../Include/Nominax/Foundation/Print.hpp"

namespace Nominax::ByteCode
{
    auto Compiler::Compile(const std::string& path, [[maybe_unused]] Stream& stream, [[maybe_unused]] ErrorList& errors) -> bool
    {
        static constexpr const std::string_view CODE_FORMAT { "Format: <instruction> %(<type>)#<immediate>" };

        std::ifstream file { path };
        if (!file) [[unlikely]]
        {
            return false;
        }
        std::string token;
        while (file >> token)
        {
            if (std::empty(token))
            {
                continue;
            }
            switch (token[0])
            {
                case TYPE_MARKER:
                {
                    auto i { std::cbegin(token) };
                    ++i; // skip %
                    if (*i++ != LPAREN) [[unlikely]]
                    {
                        errors.emplace_back(Foundation::Format("Missing type parenthesis: {}! {}", token, CODE_FORMAT));
                        continue;
                    }
                    std::array<const char, 3> typeID { *i++, *i++, *i++ };
                    const std::string_view typeView { std::cbegin(typeID), std::cend(typeID) };
                    Signal::Discriminator discriminator;
                    {
                        bool found { false };
                        for (std::underlying_type_t<Signal::Discriminator> j { }; j < std::size(TYPE_NAME_LIST); ++j)
                        {
                            if (typeView == TYPE_NAME_LIST[j])
                            {
                                discriminator = static_cast<Signal::Discriminator>(j);
                                found = true;
                                break;
                            }
                        }
                        if (!found) [[unlikely]]
                        {
                            auto msg { Foundation::Format("Invalid type name: {}! Available: ", typeView) };
                            for (const std::string_view& type: TYPE_NAME_LIST)
                            {
                                msg += type;
                                msg.push_back(' ');
                            }
                            errors.emplace_back(std::move(msg));
                            continue;
                        }
                    }
                    if (*i++ != RPAREN) [[unlikely]]
                    {
                        errors.emplace_back(Foundation::Format("Missing type parenthesis: {}! {}", token, CODE_FORMAT));
                        continue;
                    }
                    if (*i++ != IMMEDIATE_MARKER) [[unlikely]]
                    {
                        errors.emplace_back(Foundation::Format("Missing immediate marker: {}! {}", token, CODE_FORMAT));
                        continue;
                    }
                    const std::string_view imm { i, std::cend(token) };
                    switch (discriminator)
                    {
                        case Signal::Discriminator::MemoryOffset:
                        case Signal::Discriminator::Intrinsic:
                        case Signal::Discriminator::JumpAddress:
                        case Signal::Discriminator::TypeID:
                        case Signal::Discriminator::FieldOffset:
                        {
                            std::uint64_t x;
                            const auto [_, err] { std::from_chars(&*std::cbegin(imm), &*std::cend(imm), x) };
                            if (err != std::errc()) [[unlikely]]
                            {
                                errors.emplace_back(Foundation::Format("Invalid immediate: {}! {}", imm, CODE_FORMAT));
                                continue;
                            }
                            switch (discriminator)
                            {
                                case Signal::Discriminator::MemoryOffset:
                                    stream.Emit(MemOffset { x });
                                break;

                                case Signal::Discriminator::Intrinsic:
                                    stream.Emit(UserIntrinsicInvocationID { x } );
                                break;

                                case Signal::Discriminator::JumpAddress:
                                    stream.Emit(JumpAddress { x } );
                                break;

                                case Signal::Discriminator::TypeID:
                                    stream.Emit(TypeID { x } );
                                break;

                                case Signal::Discriminator::FieldOffset:
                                    stream.Emit(FieldOffset { x });
                                break;

                                default: ;
                            }
                        }
                        break;

                        case Signal::Discriminator::SysCall:
                        {
                            bool found = false;
                            SysCall call;
                            for (std::underlying_type_t<SysCall> k { }; k < std::size(SYSCALL_MNEMONIC_TABLE); ++k)
                            {
                                if (imm == SYSCALL_MNEMONIC_TABLE[k])
                                {
                                    call = static_cast<SysCall>(k);
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) [[unlikely]]
                            {
                                errors.emplace_back(Foundation::Format("Invalid syscall: \"{}\"!", SYSCALL_MNEMONIC_TABLE[Foundation::ToUnderlying(call)]));
                                continue;
                            }
                            stream.Emit(call);
                        }
                        break;

                        case Signal::Discriminator::Int:
                        {
                            std::int64_t x;
                            const auto [_, err] { std::from_chars(&*std::cbegin(imm), &*std::cend(imm), x) };
                            if (err != std::errc()) [[unlikely]]
                            {
                                errors.emplace_back(Foundation::Format("Invalid immediate: {}! {}", imm, CODE_FORMAT));
                                continue;
                            }
                            stream.Emit(x);
                        }
                        break;

                        case Signal::Discriminator::Float:
                        {
                            double x;
                            const auto [_, err] { std::from_chars(&*std::cbegin(imm), &*std::cend(imm), x) };
                            if (err != std::errc()) [[unlikely]]
                            {
                                errors.emplace_back(Foundation::Format("Invalid immediate: {}! {}", imm, CODE_FORMAT));
                                continue;
                            }
                            stream.Emit(x);
                        }
                        break;

                        default: ;
                    }
                }
                break;

                default:
                {
                    bool found = false;
                    for (std::underlying_type_t<Instruction> i { }; i < std::size(MNEMONIC_LIST); ++i)
                    {
                        if (MNEMONIC_LIST[i] == token)
                        {
                            stream.Emit(static_cast<Instruction>(i));
                            found = true;
                        }
                    }
                    if (!found) [[unlikely]]
                    {
                        errors.emplace_back(Foundation::Format("Unknown instruction: `{}`! {}", token, CODE_FORMAT));
                    }
                }
                break;
            }
        }
        return std::empty(errors);
    }
}
