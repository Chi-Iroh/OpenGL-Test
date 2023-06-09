#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace GLUtils {
    // shouldn't be called before GLEW initialization, it will return 0
    GLint getMajorVersion();

    // shouldn't be called before GLEW initialization, it will return 0
    GLint getMinorVersion();

    void errorCallback(int error, const char *description);

    void resizeCallback([[maybe_unused]] GLFWwindow* window, int newWidth, int newHeight);

    constexpr void resizeDummyCallback(GLFWwindow*, int, int) noexcept {};

    constexpr size_t LOG_LENGTH{ 1'024 };
}