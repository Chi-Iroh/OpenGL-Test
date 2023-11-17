#pragma once
#include <array>
#include <glm/glm.hpp>
#include "DrawTypes/Colorable.hpp"
#include "DrawTypes/Drawable.hpp"
#include "Triangle.hpp"

class Square : public Drawable, public Colorable {
private:
    glm::vec3 center{};
    float size{};
    std::array<Triangle, 2> triangles{};

    void draw(GLFWwindow* window) const override;
    void setTrianglesPosition();

public:
    explicit Square(const glm::vec3& center, float size);
    Square();

    void setBackgroundColor(const Color::Color& color) override;
    void setPosition(const glm::vec3& position);
};