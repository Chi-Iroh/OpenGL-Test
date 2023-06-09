#pragma once
#include <cstdint>

namespace Color::RGB {
    constexpr uint32_t BLACK{};
    constexpr uint32_t WHITE{ 0xFF'FF'FF };
    constexpr uint32_t RED{ 0xFF'00'00 };
    constexpr uint32_t GREEN{ 0x00'FF'00 };
    constexpr uint32_t BLUE{ 0x00'00'FF };
    constexpr uint32_t YELLOW{ RED | GREEN };
    constexpr uint32_t PINK{ RED | BLUE };
    constexpr uint32_t CYAN{ GREEN | BLUE };
}

namespace Color {
    struct Color {
        uint8_t red{};
        uint8_t green{};
        uint8_t blue{};
        uint8_t alpha{ 0xFF };

        constexpr Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF) noexcept :
            red{ red },
            green{ green },
            blue{ blue },
            alpha{ alpha }
        {}

        constexpr Color(uint32_t rgb = RGB::BLACK, uint8_t alpha = 0xFF) noexcept :
            Color((rgb & RGB::RED) >> 16, (rgb & RGB::GREEN) >> 8, rgb & RGB::BLUE, alpha)
        {}
    };

    constexpr Color BLACK{};
    constexpr Color WHITE{ RGB::WHITE };
    constexpr Color RED{ RGB::RED };
    constexpr Color GREEN{ RGB::GREEN };
    constexpr Color BLUE{ RGB::BLUE };
    constexpr Color YELLOW{ RGB::YELLOW };
    constexpr Color PINK{ RGB::PINK };
    constexpr Color CYAN{ RGB::CYAN };
}