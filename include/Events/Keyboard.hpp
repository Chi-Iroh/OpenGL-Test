#pragma once
#include <optional>
#include <vector>
#include <GLFW/glfw3.h>
#include "../Window.hpp"

enum class Key {
    Unknown = GLFW_KEY_UNKNOWN,
    Space = GLFW_KEY_SPACE,
    // Same as SingleQuote
    Apostrophe = GLFW_KEY_APOSTROPHE,
    // Same as Apostrophe
    SingleQuote = Apostrophe,
    Comma = GLFW_KEY_COMMA,
    // Same as Dash and Hyphen
    Minus = GLFW_KEY_MINUS,
    // Same as Minus and Hyphen
    Dash = Minus,
    // Same as Dash and Minus
    Hyphen = Dash,
    Period = GLFW_KEY_PERIOD,
    Slash = GLFW_KEY_SLASH,
    Digit0 = GLFW_KEY_0,
    Digit1 = GLFW_KEY_1,
    Digit2 = GLFW_KEY_2,
    Digit3 = GLFW_KEY_3,
    Digit4 = GLFW_KEY_4,
    Digit5 = GLFW_KEY_5,
    Digit6 = GLFW_KEY_6,
    Digit7 = GLFW_KEY_7,
    Digit8 = GLFW_KEY_8,
    Digit9 = GLFW_KEY_9,
    Semicolon = GLFW_KEY_SEMICOLON,
    Equal = GLFW_KEY_EQUAL,
    A = GLFW_KEY_A,
    B = GLFW_KEY_B,
    C = GLFW_KEY_C,
    D = GLFW_KEY_D,
    E = GLFW_KEY_E,
    F = GLFW_KEY_F,
    G = GLFW_KEY_G,
    H = GLFW_KEY_H,
    I = GLFW_KEY_I,
    J = GLFW_KEY_J,
    K = GLFW_KEY_K,
    L = GLFW_KEY_L,
    M = GLFW_KEY_M,
    N = GLFW_KEY_N,
    O = GLFW_KEY_O,
    P = GLFW_KEY_P,
    Q = GLFW_KEY_Q,
    R = GLFW_KEY_R,
    S = GLFW_KEY_S,
    T = GLFW_KEY_T,
    U = GLFW_KEY_U,
    V = GLFW_KEY_V,
    W = GLFW_KEY_W,
    X = GLFW_KEY_X,
    Y = GLFW_KEY_Y,
    Z = GLFW_KEY_Z,
    LeftSquareBracket = GLFW_KEY_LEFT_BRACKET,
    Backslash = GLFW_KEY_BACKSLASH,
    RightSquareBracket = GLFW_KEY_RIGHT_BRACKET,
    // Same as Backtick
    GraveAccent = GLFW_KEY_GRAVE_ACCENT,
    // Same as GraveAccent
    Backtick = GraveAccent,
    // An extra key, as some keyboard layouts have more keys than US layout, if not existing, GLFW would consider an unknown key was pressed
    ExtraKey1ForNonUSKeyboard = GLFW_KEY_WORLD_1,
    // An extra key, as some keyboard layouts have more keys than US layout, if not existing, GLFW would consider an unknown key was pressed
    ExtraKey2ForNonUSKeyboard = GLFW_KEY_WORLD_2,
    Escape = GLFW_KEY_ESCAPE,
    Enter = GLFW_KEY_ENTER,
    Tab = GLFW_KEY_TAB,
    Backspace = GLFW_KEY_BACKSPACE,
    Insert = GLFW_KEY_INSERT,
    Delete = GLFW_KEY_DELETE,

    // Same as ArrowRigth
    Right = GLFW_KEY_RIGHT,
    // Same as ArrowLeft
    Left = GLFW_KEY_LEFT,
    // Same as ArrowDown
    Down = GLFW_KEY_DOWN,
    // Same as ArrowUp
    Up = GLFW_KEY_UP,

    // Same as Right
    ArrowRight = Right,
    // Same as Left
    ArrowLeft = Left,
    // Same as Down
    ArrowDown = Down,
    // Same as Up
    ArrowUp = Up,

    PageUp = GLFW_KEY_PAGE_UP,
    PageDown = GLFW_KEY_PAGE_DOWN,
    Home = GLFW_KEY_HOME,
    End = GLFW_KEY_END,
    CapsLock = GLFW_KEY_CAPS_LOCK,
    ScrollLock = GLFW_KEY_SCROLL_LOCK,
    NumLock = GLFW_KEY_NUM_LOCK,
    PrintScreen = GLFW_KEY_PRINT_SCREEN,
    Pause = GLFW_KEY_PAUSE,

    F1 = GLFW_KEY_F1,
    F2 = GLFW_KEY_F2,
    F3 = GLFW_KEY_F3,
    F4 = GLFW_KEY_F4,
    F5 = GLFW_KEY_F5,
    F6 = GLFW_KEY_F6,
    F7 = GLFW_KEY_F7,
    F8 = GLFW_KEY_F8,
    F9 = GLFW_KEY_F9,
    F10 = GLFW_KEY_F10,
    F11 = GLFW_KEY_F11,
    F12 = GLFW_KEY_F12,
    F13 = GLFW_KEY_F13,
    F14 = GLFW_KEY_F14,
    F15 = GLFW_KEY_F15,
    F16 = GLFW_KEY_F16,
    F17 = GLFW_KEY_F17,
    F18 = GLFW_KEY_F18,
    F19 = GLFW_KEY_F19,
    F20 = GLFW_KEY_F20,
    F21 = GLFW_KEY_F21,
    F22 = GLFW_KEY_F22,
    F23 = GLFW_KEY_F23,
    F24 = GLFW_KEY_F24,
    F25 = GLFW_KEY_F25,

    // Same as KeyPad0
    NumPad0 = GLFW_KEY_KP_0,
    // Same as KeyPad1
    NumPad1 = GLFW_KEY_KP_1,
    // Same as KeyPad2
    NumPad2 = GLFW_KEY_KP_2,
    // Same as KeyPad3
    NumPad3 = GLFW_KEY_KP_3,
    // Same as KeyPad4
    NumPad4 = GLFW_KEY_KP_4,
    // Same as KeyPad5
    NumPad5 = GLFW_KEY_KP_5,
    // Same as KeyPad6
    NumPad6 = GLFW_KEY_KP_6,
    // Same as KeyPad7
    NumPad7 = GLFW_KEY_KP_7,
    // Same as KeyPad8
    NumPad8 = GLFW_KEY_KP_8,
    // Same as KeyPad9
    NumPad9 = GLFW_KEY_KP_9,

    // Same as NumPad0
    KeyPad0 = NumPad0,
    // Same as NumPad1
    KeyPad1 = NumPad1,
    // Same as NumPad2
    KeyPad2 = NumPad2,
    // Same as NumPad3
    KeyPad3 = NumPad3,
    // Same as NumPad4
    KeyPad4 = NumPad4,
    // Same as NumPad5
    KeyPad5 = NumPad5,
    // Same as NumPad6
    KeyPad6 = NumPad6,
    // Same as NumPad7
    KeyPad7 = NumPad7,
    // Same as NumPad8
    KeyPad8 = NumPad8,
    // Same as NumPad9
    KeyPad9 = NumPad9,

    Decimal = GLFW_KEY_KP_DECIMAL,
    Divide = GLFW_KEY_KP_DIVIDE,
    Multiply = GLFW_KEY_KP_MULTIPLY,
    Substract = GLFW_KEY_KP_SUBTRACT,
    Add = GLFW_KEY_KP_ADD,

    // Same as KeyPadEnter
    NumPadEnter = GLFW_KEY_KP_ENTER,
    // Same as KeyPadEqual
    NumPadEqual = GLFW_KEY_KP_EQUAL,

    // Same as NumPadEnter
    KeyPadEnter = NumPadEnter,
    // Same as NumPadEqual
    KeyPadEqual = NumPadEqual,

    LeftShift = GLFW_KEY_LEFT_SHIFT,
    LeftControl = GLFW_KEY_LEFT_CONTROL,
    LeftAlt = GLFW_KEY_LEFT_ALT,
    LeftSuper = GLFW_KEY_LEFT_SUPER,
    RightShift = GLFW_KEY_RIGHT_SHIFT,
    RightControl = GLFW_KEY_RIGHT_CONTROL,
    RightAlt = GLFW_KEY_RIGHT_ALT,
    RightSuper = GLFW_KEY_RIGHT_SUPER,
    Menu = GLFW_KEY_MENU,

    // Internal use only
    __Count
};

struct KeyEvent {
    std::vector<Key> pressedKeys{};
    std::vector<Key> heldDownKeys{};
    std::vector<Key> releasedKeys{};
};

std::optional<KeyEvent> getPressedKeys(Window& window);