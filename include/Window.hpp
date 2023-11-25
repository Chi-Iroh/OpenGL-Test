#pragma once
#include <functional>
#include <string>
#include <GLFW/glfw3.h>
#include "Clock.hpp"
#include "Color.hpp"
#include "DrawTypes/Drawable.hpp"
#include "Events.hpp"
#include "Vector.hpp"

class Window {
    int width{};
    int height{};
    std::string title{};
    bool doesHandleResize{};
    bool isMainGLwindow{};

    Clock displayClock{};
    unsigned displaysPerSecond{ DEFAULT_DISPLAY_RATE };
    // display epsilon, in microseconds
    long double displayEpsilon{ rateToEpsilon(DEFAULT_DISPLAY_RATE) };

    Clock eventClock{};
    unsigned eventPollsPerSecond{ DEFAULT_EVENT_POLLS_RATE };
    // event poll epsilon, in microseconds
    long double eventPollEpsilon{ rateToEpsilon(DEFAULT_EVENT_POLLS_RATE) };

    GLFWwindow* window{};

    void updateSize();
    void initGLEW();

    std::optional<Event> pollKeyEvent() const;

public:
    explicit Window(int width = 0, int height = 0, const std::string& title = "", bool handleResize = true, bool isMainGLwindow = true);
    Window(const Window& window);
    ~Window();

    Window& operator=(const Window& window) = delete;

    void clear(const Color::Color& color = Color::BLACK);
    void draw(const Drawable& drawable);
    void display();

    bool isOpen();
    void close();

    void setDisplayRate(unsigned displaysPerSecond);
    void setEventPollRate(unsigned eventPollsPerSecond);

    Vector2<int> size();
    GLFWwindow* get() noexcept;

    bool pollEvent(Event& event);

    operator bool() noexcept;
};