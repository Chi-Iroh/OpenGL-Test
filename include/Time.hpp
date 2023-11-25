#pragma once
#include <chrono>

class Time {
    std::chrono::microseconds microseconds{};

public:
    template <typename Representation, typename Period>
    constexpr Time(std::chrono::duration<Representation, Period> time = std::chrono::seconds(0));

    constexpr long double asSeconds();
    constexpr long double asMilliSeconds();
    constexpr long double asMicroSeconds();
};

#include "../inl/Time.inl"