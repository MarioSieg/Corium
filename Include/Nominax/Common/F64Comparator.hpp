#pragma once

#include <cstdint>
#include <cmath>
#include <limits>

namespace Nominax 
{
	__attribute__((flatten)) inline auto AlmostEqualsF64(const double a, const double b) noexcept -> bool
	{
		union Castor 
		{
			std::int64_t I;
			double F;
		};

		static_assert(sizeof(std::int64_t) == sizeof(double));
		static_assert(sizeof(Castor) == 8);

		std::int64_t aWord { Castor
		{
			.F = a
		}.I };

		if (aWord < 0)
		{
			aWord = std::numeric_limits<decltype(aWord)>::min() - aWord;
		}

		std::int64_t bWord{ Castor
		{
			.F = b
		}.I };

		if (bWord < 0)
		{
			bWord = std::numeric_limits<decltype(bWord)>::min() - bWord;
		}

		return (std::abs(aWord - bWord) <= 10000);
	}
}