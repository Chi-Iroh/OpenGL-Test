#include <format>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "CommandLineArguments.hpp"
#include "GLDebug.hpp"
#include "GLException.hpp"

namespace GLUtils {
    CommandLineArguments args{};

    // shouldn't be called before GLEW initialization, it will return 0
    GLint getMajorVersion() {
        GLint major{};

        glGetIntegerv(GL_MAJOR_VERSION, &major);
        return major;
    }

    // shouldn't be called before GLEW initialization, it will return 0
    GLint getMinorVersion() {
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

    void debugCallback(GLenum source, GLenum type, GLenum id, GLenum severity, [[maybe_unused]] GLsizei length, const GLchar* message, [[maybe_unused]] const void* userParam) {
        std::cerr << "GL DEBUG : " << std::endl;
        std::cerr <<  "\tSource : " << GLDebug::getMessageSource(source) << std::endl;
        std::cerr << "\tType : " << GLDebug::getMessageType(type) << std::endl;
        std::cerr << "\tSeverity : " << GLDebug::getMessageSeverity(severity) << std::endl;
        std::cerr << "\tMessage '" << message << '\'' << std::endl;
    }
}