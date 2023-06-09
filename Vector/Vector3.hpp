#pragma once
#include "../IncrementOperator.hpp"

template<typename T>
requires std::is_arithmetic_v<T>
class Vector3 {
public:
    T x{};
    T y{};
    T z{};

    // --------------------------------------------------------------------

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector3<T>& operator+=(const Vector3<U>& other) noexcept {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    constexpr Vector3<T>& operator+=(T value) noexcept {
        return *this += Vector3<T>{ value, value, value };
    }

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector3<T> operator+(const Vector3<U>& other) const noexcept {
        Vector3<T> copy{ *this };
        copy += other;
        return copy;
    }

    constexpr Vector3<T> operator+(T value) const noexcept {
        return *this + Vector3<T>{ value, value, value };
    }

    constexpr Vector3<T> operator+() const noexcept {
        return *this;
    }

    constexpr Vector3<T>& operator++(PREFIX_INCREMENTATION) noexcept {
        // prefix incrementation
        x++;
        y++;
        z++;
        return *this;
    }

    constexpr Vector3<T>& operator++(POSTFIX_INCREMENTATION) noexcept {
        const Vector3<T> copy{ *this };
        x++;
        y++;
        z++;
        return copy;
    }

    // --------------------------------------------------------------------

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector3<T>& operator-=(const Vector3<U>& other) noexcept {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    constexpr Vector3<T>& operator-=(T value) noexcept {
        return *this -= Vector3<T>{ value, value, value };
    }

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector3<T> operator-(const Vector3<U>& other) const noexcept {
        Vector3<T> copy{ *this };
        copy -= other;
        return copy;
    }

    constexpr Vector3<T> operator-(T value) const noexcept {
        return *this - Vector3<T>{ value, value, value };
    }

    constexpr Vector3<T> operator-() const noexcept {
        return Vector3<T>(-x, -y, -z);
    }

    constexpr Vector3<T>& operator--(PREFIX_DECREMENTATION) noexcept {
        // prefix incrementation
        x--;
        y--;
        z--;
        return *this;
    }

    constexpr Vector3<T>& operator--(POSTFIX_DECREMENTATION) noexcept {
        const Vector3<T> copy{ *this };
        x--;
        y--;
        z--;
        return copy;
    }

    // --------------------------------------------------------------------

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector3<T>& operator*=(const Vector3<U>& other) noexcept {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    constexpr Vector3<T>& operator*=(T value) noexcept {
        return *this *= Vector3<T>{ value, value, value };
    }

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector3<T> operator*(const Vector3<U>& other) const noexcept {
        Vector3<T> copy{ *this };
        copy *= other;
        return copy;
    }

    constexpr Vector3<T> operator*(T value) const noexcept {
        return *this * Vector3<T>{ value, value, value };
    }

    // --------------------------------------------------------------------

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector3<T>& operator/=(const Vector3<U>& other) noexcept {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    constexpr Vector3<T>& operator/=(T value) noexcept {
        return *this /= Vector3<T>{ value, value, value };
    }

    template<typename U>
    requires std::is_convertible_v<U, T>
    constexpr Vector3<T> operator/(const Vector3<U>& other) const noexcept {
        Vector3<T> copy{ *this };
        copy /= other;
        return copy;
    }

    constexpr Vector3<T> operator/(T value) const noexcept {
        return *this / Vector3<T>{ value, value, value };
    }

    // --------------------------------------------------------------------
};
