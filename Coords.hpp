#pragma once
#include <utility>
#include "Math.hpp"

namespace Coords {
    constexpr std::pair<float, float> GLCoordinatesRange{ -1.f, 1.f };

    constexpr VertexType windowToGLCoordinates(const Vector2<float>& coordinates, const Vector2<float> windowSize) {
        return {
            Math::fitToRange<float, float>({ 0, windowSize.x }, coordinates.x, GLCoordinatesRange),
            Math::fitToRange<float, float>({ 0, windowSize.y }, coordinates.y, GLCoordinatesRange),
            0.f
        };
    }

    constexpr VertexType GLToWindowCoordinates(const Vector2<float>& coordinates, const Vector2<float> windowSize) {
        return {
            Math::fitToRange<float, float>(GLCoordinatesRange, coordinates.x, { 0, windowSize.x }),
            Math::fitToRange<float, float>(GLCoordinatesRange, coordinates.y, { 0, windowSize.y }),
            0.f
        };
    }
}