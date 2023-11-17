#pragma once
#include "Events/Keyboard.hpp"

enum class EventType {
    KeyPressedOrReleased
};

struct Event {
    EventType type;
    union {
        KeyEvent keyEvent;
    } event;
};