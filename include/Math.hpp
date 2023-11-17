#pragma once
#include <type_traits>
#include <utility>
#include "Vector.hpp"

namespace Math {
    template<typename From, typename To>
    requires (std::is_arithmetic_v<From> && std::is_arithmetic_v<To> && std::is_convertible_v<From, To>)
    constexpr To fitToRange(std::pair<From, From> range, From value, std::pair<To, To> newRange) noexcept {
        return newRange.first + static_cast<long double>(value - range.first) / (range.second - range.first) * (newRange.second - newRange.first);
    }

    constexpr VertexType moveToCoord(const VertexType& current, const VertexType& coord, float percentage) noexcept {
        return {
            current.x + percentage * (coord.x - current.x),
            current.y + percentage * (coord.y - current.y),
            current.z + percentage * (coord.z - current.z)
        };
    }
}