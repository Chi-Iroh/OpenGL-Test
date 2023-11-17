#pragma once
#include <exception>
#include <string>

class GLException : public std::bad_alloc {
    std::string message{};
public:
    GLException(const std::string& message);
    const char* what() const noexcept override;
};