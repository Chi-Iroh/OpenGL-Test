#pragma once
#include <GLFW/glfw3.h>

class Drawable {
    friend class Window;
    virtual void draw(GLFWwindow *window) const = 0;
};
