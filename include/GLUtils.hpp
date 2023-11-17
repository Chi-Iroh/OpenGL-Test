#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "CommandLineArguments.hpp"
#include "Events/Keyboard.hpp"

namespace GLUtils {
    extern CommandLineArguments args;

    // shouldn't be called before GLEW initialization, it will return 0
    GLint getMajorVersion();

    // shouldn't be called before GLEW initialization, it will return 0
    GLint getMinorVersion();

    void errorCallback(int error, const char *description);

    void resizeCallback([[maybe_unused]] GLFWwindow* window, int newWidth, int newHeight);

    void debugCallback(GLenum source, GLenum type, GLenum id, GLenum severity, [[maybe_unused]] GLsizei length, const GLchar* message, [[maybe_unused]] const void* userParam);

    constexpr void resizeDummyCallback(GLFWwindow*, int, int) noexcept {};

    constexpr size_t LOG_LENGTH{ 1'024 };
}