#pragma once
#include <chrono>
#include "./Time.hpp"

class Clock {
    using TimePoint = decltype(std::chrono::high_resolution_clock::now());
    TimePoint start{};

    inline TimePoint getActualTime() const;

public:
    Clock();

    Time getElapsedTime() const;

    inline void reset();
};

// Number of FPS
constexpr unsigned DEFAULT_DISPLAY_RATE{ 60 };
// Number of event polls per second
constexpr unsigned DEFAULT_EVENT_POLLS_RATE{ 10 };

// converts a rate (per second) to an epison in microseconds
constexpr long double rateToEpsilon(unsigned rate);

#include "../inl/Clock.inl"