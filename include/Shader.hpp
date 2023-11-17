#pragma once
#include <filesystem>
#include <format>
#include <fstream>
#include <stdexcept>
#include <string>
#include <GL/glew.h>
#include "Color.hpp"
#include "GLException.hpp"
#include "GLUtils.hpp"
#include "Math.hpp"

namespace Shader {
    std::string generateFragmentColor(const Color::Color& color);
    std::string simpleVertexShader();

    enum class ShaderType {
        Vertex,
        Fragment
    };

    template<ShaderType Type>
    requires (Type == ShaderType::Vertex || Type == ShaderType::Fragment)
    class Shader {
        GLuint shader{};
        std::string code{};
        const char* codePtr{};

        GLuint createShader() {
            const GLuint newShader{ glCreateShader(Type == ShaderType::Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER) };
            if (newShader == 0) {
                throw GLException("Failed to create shader.");
            }
            return newShader;
        }

        void compile() {
            glShaderSource(shader, 1, &codePtr, nullptr);
            glCompileShader(shader);

            int success{};
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                // brackets can't be used here as the compiler thinks it's constructed with initializer-list
                std::string errorMsg(GLUtils::LOG_LENGTH + 1, '\0');
                glGetShaderInfoLog(shader, GLUtils::LOG_LENGTH, nullptr, &errorMsg[0]);
                throw GLException(errorMsg);
            }
        }

    public:
        constexpr Shader() noexcept {}

        explicit Shader(const std::string& code) :
            shader{ createShader() },
            code{ code },
            codePtr{ this->code.c_str() }
        {
            compile();
        }

        explicit Shader(const std::filesystem::path& filepath) {
            std::ifstream shaderFile{ filepath };
            std::string lineBuffer{};

            if (!shaderFile) {
                throw GLException(std::format("Error while opening shader file '{}'.", filepath));
            }
            while (std::getline(shaderFile, lineBuffer)) {
                code += std::move(lineBuffer);
            }
        }

        Shader(const Shader& copy) : Shader(copy.code) {}

        Shader<Type>& operator=(const Shader<Type>& other) {
            shader = createShader();
            code = other.code;
            codePtr = code.c_str();
            compile();
            return *this;
        }

        void attach(GLuint program) const {
            glAttachShader(program, shader);
        }

        void detach(GLuint program) const {
            glDetachShader(program, shader);
        }

        std::string getCode() const noexcept {
            return code;
        }

        const char* const* getPtr() const noexcept {
            return &codePtr;
        }

        ~Shader() {
            glDeleteShader(shader);
        }
    };
}