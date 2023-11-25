#pragma once
#include <GLFW/glfw3.h>

class Drawable {
    friend class Window;
    virtual void draw(GLFWwindow *window) const = 0;

public:
    virtual void move(float x, float y, float z = 0.f) = 0;
};
