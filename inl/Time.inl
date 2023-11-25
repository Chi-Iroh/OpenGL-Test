#pragma once
#include <chrono>
#include "../include/Time.hpp"

template <typename Representation, typename Period>
constexpr Time::Time(std::chrono::duration<Representation, Period> time) :
    microseconds{ std::chrono::duration_cast<std::chrono::microseconds>(time) }
{}

constexpr long double Time::asSeconds() {
    return microseconds.count() / 1'000'000.L;
}

constexpr long double Time::asMilliSeconds() {
    return microseconds.count() / 1'000.L;
}

constexpr long double Time::asMicroSeconds() {
    return microseconds.count();
}