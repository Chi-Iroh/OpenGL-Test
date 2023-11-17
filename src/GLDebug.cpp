#include <format>
#include "../include/GLDebug.hpp"

std::string GLDebug::getMessageSource(GLenum source) {
    switch (source) {
    case GL_DEBUG_SOURCE_API:
        return "Call to the OpenGL API";
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        return "Call to a window-system API";
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        return "Compiler for a shading language";
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        return "An application associated with OpenGL";
    case GL_DEBUG_SOURCE_APPLICATION:
        return "User of this application";
    case GL_DEBUG_SOURCE_OTHER:
        return "Somewhere, maybe you'll find one day...";
    default:
        throw GLException(std::format("Debug source '{}' not recognized.", std::to_string(source)));
    };
}

std::string GLDebug::getMessageType(GLenum type) {
    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        return "Error from API";
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        return "Deprecated bahaviour";
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        return "Undefined bahaviour";
    case GL_DEBUG_TYPE_PORTABILITY:
        return "Not portable behaviour";
    case GL_DEBUG_TYPE_PERFORMANCE:
        return "Performance issues";
    case GL_DEBUG_TYPE_MARKER:
        return "Command stream annotation";
    case GL_DEBUG_TYPE_PUSH_GROUP:
        return "Group pushing";
    case GL_DEBUG_TYPE_POP_GROUP:
        return "group popping";
    case GL_DEBUG_TYPE_OTHER:
        return "Some unknown reason, maybe you'll find one day...";
    default:
        throw GLException(std::format("Debug type '{}' not recognized.", std::to_string(type)));
    }
}

std::string GLDebug::getMessageSeverity(GLenum severity) {
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        return "High";
    case GL_DEBUG_SEVERITY_MEDIUM:
        return "Medium";
    case GL_DEBUG_SEVERITY_LOW:
        return "Low";
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        return "Info";
    default:
        throw GLException(std::format("Debug Severity '{}' not recognized.", std::to_string(severity)));
    }
}