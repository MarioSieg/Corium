#include "../../../Include/Nominax/Foundation/NativeTypeRegistry.hpp"
#include "../../../Include/Nominax/Foundation/Protocol.hpp"
#include "../../../Include/Nominax/ByteCode/Signal.hpp"

namespace Nominax::Foundation
{
    const constinit NativeTypeRegistry NATIVE_TYPE_REGISTRY
    {
        {
            NativeTypeInfo::Make<std::int64_t>("int"),
            NativeTypeInfo::Make<double>("float"),
            NativeTypeInfo::Make<char32_t>("char"),
            NativeTypeInfo::Make<bool>("bool"),
            NativeTypeInfo::Make<void*>("void*"),
            NativeTypeInfo::Make<Record>("Record"),
            NativeTypeInfo::Make<ByteCode::Signal>("Signal"),
            NativeTypeInfo::Make<ByteCode::Signal::Discriminator>("Signal::Discriminator"),
            NativeTypeInfo::Make<Object>("Object"),
            NativeTypeInfo::Make<ObjectHeader>("ObjectHeader"),
        }
    };

    auto NativeTypeRegistry::Display(std::ostream& stream) const -> void
    {
        for (const NativeTypeInfo& info : this->Data)
        {
            Print(stream, "{0: <32} | {1: <3} | {2: <3}\n", info.Name, info.Size, info.Alignment);
        }
    }
}
