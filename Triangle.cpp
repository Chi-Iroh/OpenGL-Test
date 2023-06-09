#include <string>
#include <string_view>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "GLException.hpp"
#include "GLUtils.hpp"
#include "Shader.hpp"
#include "Triangle.hpp"

Triangle::Triangle() {}

Triangle::Triangle(const VertexType& vertex1, const VertexType& vertex2, const VertexType& vertex3) :
    GLVertices{
        glm::vec3{ vertex1.x, vertex1.y, vertex1.z },
        glm::vec3{ vertex2.x, vertex2.y, vertex2.z },
        glm::vec3{ vertex3.x, vertex3.y, vertex3.z },
    }
{
    linkShaders();
}

Triangle::Triangle(const VerticesType& vertices) :
    Triangle(vertices[0], vertices[1], vertices[2])
{}

void Triangle::draw(GLFWwindow* window) const {
    GLuint VBO{};

    glUseProgram(shaderProgram);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLVertices), &GLVertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Triangle::linkShaders() {
    vertexShader.attach(shaderProgram);
    fragmentShader.attach(shaderProgram);
    glLinkProgram(shaderProgram);

    int isLinked{};
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &isLinked);
    if (!isLinked) {
        std::string infoLog(GLUtils::LOG_LENGTH + 1, '\0');
        glGetShaderInfoLog(shaderProgram, GLUtils::LOG_LENGTH, nullptr, &infoLog[0]);
        glDeleteProgram(shaderProgram);
        throw GLException(infoLog);
    }
}

void Triangle::setBackgroundColor(const Color::Color& color) {
    fragmentShader.detach(shaderProgram);
    fragmentShader = Shader::Shader<Shader::ShaderType::Fragment>{ Shader::generateFragmentColor(color) };
    linkShaders();
    backgroundColor = color;
}

void Triangle::setVertices(const VerticesType& vertices) {
    for (unsigned i = 0; const VertexType& vertex : vertices) {
        GLVertices[i++] = glm::vec3{ vertex.x, vertex.y, vertex.z };
    }
}