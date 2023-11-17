#pragma once
#include <chrono>
#include <random>
#include <type_traits>

namespace Random {
    template<typename T>
    requires std::is_arithmetic_v<T>
    using RandomDistribution = std::conditional_t<std::is_floating_point_v<T>, std::uniform_real_distribution<T>, std::uniform_int_distribution<T>>;

    template<typename TimeUnit>
    auto getTime() {
        return std::chrono::duration_cast<TimeUnit>(std::chrono::system_clock::now().time_since_epoch()).count();
    }

    template<typename T>
    requires std::is_arithmetic_v<T>
    T timeSeed(std::random_device& device) {
        if constexpr (std::is_integral_v<T>) {
            return device() ^ getTime<std::chrono::microseconds>();
        } else {
            return static_cast<long double>(getTime<std::chrono::nanoseconds>()) / device();
        }
    }

    template<typename T>
    requires std::is_arithmetic_v<T>
    T randomValue(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
        static std::random_device device{};
        const T seed{ timeSeed<T>(device) };
        std::mt19937 generator{ seed };
        RandomDistribution<T> distribution{ min, max };

        return distribution(generator);
    }
}