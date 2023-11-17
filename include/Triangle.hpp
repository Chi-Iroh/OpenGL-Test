#pragma once
#include <array>
#include <glm/glm.hpp>
#include "DrawTypes/Colorable.hpp"
#include "DrawTypes/Drawable.hpp"
#include "Vector.hpp"

class Triangle : public Drawable, public Colorable {
private:
    using VerticesType = std::array<VertexType, 3>;
    using GLVerticesType = std::conditional_t<sizeof(std::array<glm::vec3, 3>) == sizeof(glm::vec3[3]), std::array<glm::vec3, 3>, glm::vec3[3]>;

    friend class Square;

    GLVerticesType GLVertices{};
    void draw(GLFWwindow* window) const override;
    void linkShaders();

public:
    explicit Triangle(const VertexType& vertex1, const VertexType& vertex2, const VertexType& vertex3);
    explicit Triangle(const VerticesType& vertices);
    Triangle();

    void setBackgroundColor(const Color::Color& color) override;
    void setVertices(const VerticesType& vertices);
};