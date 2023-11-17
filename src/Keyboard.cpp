#include <unordered_map>
#include "../include/Events/Keyboard.hpp"

constexpr std::size_t __keyCount{ static_cast<std::size_t>(Key::__Count) };

class KeyHash {
public:
    constexpr std::size_t operator()(Key key) const {
        return std::hash<std::size_t>{}(static_cast<std::size_t>(key));
    }
};

enum class KeyState {
    Released,
    Pressed,
    HeldDown
};

static std::unordered_map<Key, KeyState, KeyHash> __keysState{
    { Key::Unknown, KeyState::Released },
    { Key::Space, KeyState::Released },
    { Key::Apostrophe, KeyState::Released },
    // Equivalent to Key::Apostrophe, left in comment for clarity
    // Key::SingleQuote,
    { Key::Comma, KeyState::Released },
    { Key::Minus, KeyState::Released },
    // Equivalent to Key::Minus, left in comment for clarity
    //  Key::Dash,
    //  Key::Hyphen,
    { Key::Period, KeyState::Released },
    { Key::Slash, KeyState::Released },
    { Key::Digit0, KeyState::Released },
    { Key::Digit1, KeyState::Released },
    { Key::Digit2, KeyState::Released },
    { Key::Digit3, KeyState::Released },
    { Key::Digit4, KeyState::Released },
    { Key::Digit5, KeyState::Released },
    { Key::Digit6, KeyState::Released },
    { Key::Digit7, KeyState::Released },
    { Key::Digit8, KeyState::Released },
    { Key::Digit9, KeyState::Released },
    { Key::Semicolon, KeyState::Released },
    { Key::Equal, KeyState::Released },
    { Key::A, KeyState::Released },
    { Key::B, KeyState::Released },
    { Key::C, KeyState::Released },
    { Key::D, KeyState::Released },
    { Key::E, KeyState::Released },
    { Key::F, KeyState::Released },
    { Key::G, KeyState::Released },
    { Key::H, KeyState::Released },
    { Key::I, KeyState::Released },
    { Key::J, KeyState::Released },
    { Key::K, KeyState::Released },
    { Key::L, KeyState::Released },
    { Key::M, KeyState::Released },
    { Key::N, KeyState::Released },
    { Key::O, KeyState::Released },
    { Key::P, KeyState::Released },
    { Key::Q, KeyState::Released },
    { Key::R, KeyState::Released },
    { Key::S, KeyState::Released },
    { Key::T, KeyState::Released },
    { Key::U, KeyState::Released },
    { Key::V, KeyState::Released },
    { Key::W, KeyState::Released },
    { Key::X, KeyState::Released },
    { Key::Y, KeyState::Released },
    { Key::Z, KeyState::Released },
    { Key::LeftSquareBracket, KeyState::Released },
    { Key::Backslash, KeyState::Released },
    { Key::RightSquareBracket, KeyState::Released },
    { Key::GraveAccent, KeyState::Released },
    { Key::Backtick, KeyState::Released },
    { Key::ExtraKey1ForNonUSKeyboard, KeyState::Released },
    { Key::ExtraKey2ForNonUSKeyboard, KeyState::Released },
    { Key::Escape, KeyState::Released },
    { Key::Enter, KeyState::Released },
    { Key::Tab, KeyState::Released },
    { Key::Backspace, KeyState::Released },
    { Key::Insert, KeyState::Released },
    { Key::Delete, KeyState::Released },
    { Key::ArrowRight, KeyState::Released },
    { Key::ArrowLeft, KeyState::Released },
    { Key::ArrowDown, KeyState::Released },
    { Key::ArrowUp, KeyState::Released },
    // Equivalent to Key::ArrowX, left in comment for clarity
    // Key::Right,
    // Key::Left,
    // Key::Down,
    // Key::Up,
    { Key::PageUp, KeyState::Released },
    { Key::PageDown, KeyState::Released },
    { Key::Home, KeyState::Released },
    { Key::End, KeyState::Released },
    { Key::CapsLock, KeyState::Released },
    { Key::ScrollLock, KeyState::Released },
    { Key::NumLock, KeyState::Released },
    { Key::PrintScreen, KeyState::Released },
    { Key::Pause, KeyState::Released },
    { Key::F1, KeyState::Released },
    { Key::F2, KeyState::Released },
    { Key::F3, KeyState::Released },
    { Key::F4, KeyState::Released },
    { Key::F5, KeyState::Released },
    { Key::F6, KeyState::Released },
    { Key::F7, KeyState::Released },
    { Key::F8, KeyState::Released },
    { Key::F9, KeyState::Released },
    { Key::F10, KeyState::Released },
    { Key::F11, KeyState::Released },
    { Key::F12, KeyState::Released },
    { Key::F13, KeyState::Released },
    { Key::F14, KeyState::Released },
    { Key::F15, KeyState::Released },
    { Key::F16, KeyState::Released },
    { Key::F17, KeyState::Released },
    { Key::F18, KeyState::Released },
    { Key::F19, KeyState::Released },
    { Key::F20, KeyState::Released },
    { Key::F21, KeyState::Released },
    { Key::F22, KeyState::Released },
    { Key::F23, KeyState::Released },
    { Key::F24, KeyState::Released },
    { Key::F25, KeyState::Released },
    { Key::NumPad0, KeyState::Released },
    { Key::NumPad1, KeyState::Released },
    { Key::NumPad2, KeyState::Released },
    { Key::NumPad3, KeyState::Released },
    { Key::NumPad4, KeyState::Released },
    { Key::NumPad5, KeyState::Released },
    { Key::NumPad6, KeyState::Released },
    { Key::NumPad7, KeyState::Released },
    { Key::NumPad8, KeyState::Released },
    { Key::NumPad9, KeyState::Released },
    // Equivalent to Key::NumPadX, left in comment for clarity
    // Key::KeyPad0,
    // Key::KeyPad1,
    // Key::KeyPad2,
    // Key::KeyPad3,
    // Key::KeyPad4,
    // Key::KeyPad5,
    // Key::KeyPad6,
    // Key::KeyPad7,
    // Key::KeyPad8,
    // Key::KeyPad9,
    { Key::Decimal, KeyState::Released },
    { Key::Divide, KeyState::Released },
    { Key::Multiply, KeyState::Released },
    { Key::Substract, KeyState::Released },
    { Key::Add, KeyState::Released },
    { Key::NumPadEnter, KeyState::Released },
    { Key::NumPadEqual, KeyState::Released },
    { Key::KeyPadEnter, KeyState::Released },
    { Key::KeyPadEqual, KeyState::Released },
    { Key::LeftShift, KeyState::Released },
    { Key::LeftControl, KeyState::Released },
    { Key::LeftAlt, KeyState::Released },
    { Key::LeftSuper, KeyState::Released },
    { Key::RightShift, KeyState::Released },
    { Key::RightControl, KeyState::Released },
    { Key::RightAlt, KeyState::Released },
    { Key::RightSuper, KeyState::Released },
    { Key::Menu, KeyState::Released }
};

std::optional<KeyEvent> getPressedKeys(Window& window) {
    KeyEvent event{};
    const auto glfwWindow{ window.get() };

    for (auto& keyState : __keysState) {
        const bool isKeyPressed{ glfwGetKey(glfwWindow, static_cast<int>(keyState.first)) == GLFW_PRESS };
        if (isKeyPressed && keyState.second == KeyState::Released) {
            event.pressedKeys.push_back(keyState.first);
        } else if (isKeyPressed && keyState.second != KeyState::Released) {
            event.heldDownKeys.push_back(keyState.first);
        } else if (!isKeyPressed && keyState.second == KeyState::Pressed) {
            event.releasedKeys.push_back(keyState.first);
        }
    }
    if (event.pressedKeys.empty() && event.heldDownKeys.empty() && event.releasedKeys.empty()) {
        return std::nullopt;
    }
    return event;
}