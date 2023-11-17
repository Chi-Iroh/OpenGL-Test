#include "../include/GLException.hpp"

GLException::GLException(const std::string& message) {
    this->message = message;
}

const char* GLException::what() const noexcept {
    return message.c_str();
}