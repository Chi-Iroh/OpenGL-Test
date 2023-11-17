#include "../include/GLException.hpp"
#include "../include/Square.hpp"

Square::Square() {}

Square::Square(const glm::vec3& center, float size) :
    center{ center },
    size{ size }
{
    if (size < 0) {
        throw GLException("Cannot create a square with size <= 0 !");
    }
}

void Square::draw(GLFWwindow* window) const {
    for (const Triangle& triangle : triangles) {
        triangle.draw(window);
    }
}

void Square::setTrianglesPosition() {
    const std::array<glm::vec3, 4> vertices{
        {  }
    };
}

void Square::setBackgroundColor(const Color::Color& color) {
    for (Triangle& triangle : triangles) {
        triangle.setBackgroundColor(color);
    }
}

void Square::setPosition(const glm::vec3& newCenter) {
    center = newCenter;
    setTrianglesPosition();
}