#pragma once
#include <glm/glm.hpp>
#include "../IncrementOperator.hpp"

template<typename T>
requires std::is_arithmetic_v<T>
class Vector2 {
public:
    T x{};
    T y{};

    // --------------------------------------------------------------------

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector2<T>& operator+=(const Vector2<U>& other) noexcept {
        x += other.x;
        y += other.y;
        return *this;
    }

    constexpr Vector2<T>& operator+=(T value) noexcept {
        return *this += Vector2<T>{ value, value };
    }

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector2<T> operator+(const Vector2<U>& other) const noexcept {
        Vector2<T> copy{ *this };
        copy += other;
        return copy;
    }

    constexpr Vector2<T> operator+(T value) const noexcept {
        return *this + Vector2<T>{ value, value };
    }

    constexpr Vector2<T> operator+() const noexcept {
        return *this;
    }

    constexpr Vector2<T>& operator++(PREFIX_INCREMENTATION) noexcept {
        x++;
        y++;
        return *this;
    }

    constexpr Vector2<T>& operator++(POSTFIX_INCREMENTATION) noexcept {
        const Vector2<T> copy{ *this };
        x++;
        y++;
        return copy;
    }

    // --------------------------------------------------------------------

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector2<T>& operator-=(const Vector2<U>& other) noexcept {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    constexpr Vector2<T>& operator-=(T value) noexcept {
        return *this -= Vector2<T>{ value, value };
    }

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector2<T> operator-(const Vector2<U>& other) const noexcept {
        Vector2<T> copy{ *this };
        copy -= other;
        return copy;
    }

    constexpr Vector2<T> operator-(T value) const noexcept {
        return *this - Vector2<T>{ value, value };
    }

    constexpr Vector2<T> operator-() const noexcept {
        return Vector2<T>(-x, -y);
    }

    constexpr Vector2<T>& operator--(PREFIX_DECREMENTATION) noexcept {
        x--;
        y--;
        return *this;
    }

    constexpr Vector2<T>& operator--(POSTFIX_DECREMENTATION) noexcept {
        const Vector2<T> copy{ *this };
        x--;
        y--;
        return copy;
    }

    // --------------------------------------------------------------------

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector2<T>& operator*=(const Vector2<U>& other) noexcept {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    constexpr Vector2<T>& operator*=(T value) noexcept {
        return *this *= Vector2<T>{ value, value };
    }

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector2<T> operator*(const Vector2<U>& other) const noexcept {
        Vector2<T> copy{ *this };
        copy *= other;
        return copy;
    }

    constexpr Vector2<T> operator*(T value) const noexcept {
        return *this * Vector2<T>{ value, value };
    }

    // --------------------------------------------------------------------

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector2<T>& operator/=(const Vector2<U>& other) noexcept {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    constexpr Vector2<T>& operator/=(T value) noexcept {
        return *this /= Vector2<T>{ value, value };
    }

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector2<T> operator/(const Vector2<U>& other) const noexcept {
        Vector2<T> copy{ *this };
        copy /= other;
        return copy;
    }

    constexpr Vector2<T> operator/(T value) const noexcept {
        return *this / Vector2<T>{ value, value };
    }

    // --------------------------------------------------------------------
};
