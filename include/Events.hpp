#pragma once
#include "Events/Keyboard.hpp"

enum class EventType {
    NoEvent,
    KeyEvent
};

// note: cannot put all events into an enum, because keyEvent has std::vectors which have non-trivial destructors
struct Event {
    EventType type{ EventType::NoEvent };
    KeyEvent key;
};