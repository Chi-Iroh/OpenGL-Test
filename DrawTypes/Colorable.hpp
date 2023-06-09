#pragma once
#include <string>
#include <GL/glew.h>
#include "../Color.hpp"
#include "Drawable.hpp"
#include "../Shader.hpp"

class Colorable {
protected:
    GLuint shaderProgram{};
    Color::Color backgroundColor{ Color::WHITE };
    Shader::Shader<Shader::ShaderType::Vertex> vertexShader{};
    Shader::Shader<Shader::ShaderType::Fragment> fragmentShader{};

    Colorable();
    virtual ~Colorable() = 0;

    virtual void setBackgroundColor(const Color::Color& color) = 0;
};