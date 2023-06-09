#include <format>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GLException.hpp"

namespace GLUtils {
    // shouldn't be called before GLEW initialization, it will return 0
    GLint glGetMajorVersion() {
        GLint major{};

        glGetIntegerv(GL_MAJOR_VERSION, &major);
        return major;
    }

    // shouldn't be called before GLEW initialization, it will return 0
    GLint glGetMinorVersion() {
        GLint minor{};

        glGetIntegerv(GL_MINOR_VERSION, &minor);
        return minor;
    }

    void errorCallback(int error, const char *description) {
        throw GLException(std::format("GLFW Error (code {}) : '{}'", error, description));
    }

    void resizeCallback([[maybe_unused]] GLFWwindow* window, int newWidth, int newHeight) {
        glViewport(0, 0, newWidth, newHeight);
    }
}