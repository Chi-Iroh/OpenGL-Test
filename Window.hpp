#pragma once
#include <functional>
#include <string>
#include <GLFW/glfw3.h>
#include "Color.hpp"
#include "DrawTypes/Drawable.hpp"
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

public:
    explicit Window(int width = 0, int height = 0, const std::string& title = "", bool handleResize = true, bool isMainGLwindow = true);
    Window(const Window& window);
    ~Window();

    void clear(const Color::Color& color = Color::BLACK);
    void draw(const Drawable& drawable);
    void display();

    bool isOpen();

    Vector2<int> size();
    GLFWwindow* get() noexcept;

    operator bool() noexcept;
};