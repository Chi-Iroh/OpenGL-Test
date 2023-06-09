#include <format>
#include "Shader.hpp"

namespace Shader {
    std::string generateFragmentColor(const Color::Color& color) {
        return std::format(
            "#version {}{}0\n"
            "out vec4 color;\n"

            "void main() {{\n"
            "    color = vec4({:.4f}f, {:.4f}f, {:.4f}f, {:.4f}f);\n"
            "}}",
        GLUtils::getMajorVersion(), GLUtils::getMinorVersion(),
        Math::fitToRange<uint8_t, float>({ 0x00, 0xFF }, color.red, { 0.f, 1.f }),
        Math::fitToRange<uint8_t, float>({ 0x00, 0xFF }, color.green, { 0.f, 1.f }),
        Math::fitToRange<uint8_t, float>({ 0x00, 0xFF }, color.blue, { 0.f, 1.f }),
        Math::fitToRange<uint8_t, float>({ 0x00, 0xFF }, color.alpha, { 0.f, 1.f }));
    }

    std::string simpleVertexShader() {
        return std::format(
            "#version {}{}0\n"
            "layout (location = 0) in vec3 pos;\n"

            "void main() {{\n"
            "    gl_Position = vec4(pos, 1.0f);\n"
            "}}",
            GLUtils::getMajorVersion(), GLUtils::getMinorVersion()
        );
    }
}