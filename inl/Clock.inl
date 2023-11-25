#pragma once
#include "../include/Clock.hpp"

inline Clock::TimePoint Clock::getActualTime() const {
    return std::chrono::high_resolution_clock::now();
}

inline void Clock::reset() {
    start = getActualTime();
}

constexpr long double rateToEpsilon(unsigned rate) {
    return rate == 0 ? 0 : 1'000'000.L / rate;
}