#include "../include/DrawTypes/Colorable.hpp"

Colorable::Colorable() : shaderProgram{ glCreateProgram() } {
    if (shaderProgram == 0) {
        throw GLException("Failed to create shader program.");
    }
}

Colorable::~Colorable() {
    vertexShader.detach(shaderProgram);
    fragmentShader.detach(shaderProgram);
    glDeleteProgram(shaderProgram);
}