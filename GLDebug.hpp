#pragma once
#include <string>
#include <unordered_map>
#include <GL/glew.h>
#include "GLException.hpp"

namespace GLDebug {
    std::string getMessageSource(GLenum source);

    std::string getMessageType(GLenum type);

    std::string getMessageSeverity(GLenum severity);
}