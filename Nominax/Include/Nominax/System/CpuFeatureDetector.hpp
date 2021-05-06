#pragma once

#include "Platform.hpp"

#if NOMINAX_ARCH_X86_64
#   include "../Arch/X86_64.hpp"
#endif

namespace Nominax
{
#if NOMINAX_ARCH_X86_64
    /// <summary>
    /// Architecture dependent cpu feature flags.
    /// </summary>
    using FeatureBits = X86_64::CpuFeatureBits;
#else
    using FeatureBits = void;
#   error "ARM is not yet implemented!"
#endif

    static_assert(std::is_default_constructible_v<FeatureBits>);

    /// <summary>
    /// Detects architecture dependent cpu features.
    /// </summary>
    class CpuFeatureDetector final
    {
        /// <summary>
        /// Architecture dependent bits.
        /// </summary>
        FeatureBits Features_;

    public:
        /// <summary>
        /// Construct new instance and query cpu feature
        /// using architecture dependent routines.
        /// </summary>
        CpuFeatureDetector() noexcept(false);

        /// <summary>
        /// No copy.
        /// </summary>
        CpuFeatureDetector(const CpuFeatureDetector&) = delete;

        /// <summary>
        /// No move.
        /// </summary>
        CpuFeatureDetector(CpuFeatureDetector&&) = delete;

        /// <summary>
        /// No copy.
        /// </summary>
        auto operator =(const CpuFeatureDetector&) -> CpuFeatureDetector& = delete;

        /// <summary>
        /// No move.
        /// </summary>
        auto operator =(CpuFeatureDetector&&) -> CpuFeatureDetector& = delete;

        /// <summary>
        /// Destructor.
        /// </summary>
        ~CpuFeatureDetector() = default;

        /// <summary>
        /// Access the architecture dependent feature bits directly.
        /// </summary>
        auto operator ->() const noexcept(true) -> const FeatureBits&;

        /// <summary>
        /// Access the architecture dependent feature bits directly.
        /// </summary>
        auto operator *() const noexcept(true) -> const FeatureBits&;

        /// <summary>
        /// Prints all the architecture dependent features in different colors.
        /// </summary>
        auto PrintFeatures() const -> void;
    };

    inline CpuFeatureDetector::CpuFeatureDetector() noexcept(false) : Features_{} {}

    inline auto CpuFeatureDetector::operator ->() const noexcept(true) -> const FeatureBits&
    {
        return this->Features_;
    }

    inline auto CpuFeatureDetector::operator *() const noexcept(true) -> const FeatureBits&
    {
        return this->Features_;
    }

    inline auto CpuFeatureDetector::PrintFeatures() const -> void
    {
        this->Features_.PrintFeatures();
    }
}
