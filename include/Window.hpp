#pragma once
#include <functional>
#include <string>
#include <GLFW/glfw3.h>
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

    Vector2<int> size();
    GLFWwindow* get() noexcept;
    const GLFWwindow* get() const noexcept;

    bool pollEvent(Event& event) const;

    operator bool() noexcept;
};