#include <chrono>
#include <format>
#include <iostream>
#include <limits>
#include <optional>
#include <random>
#include <type_traits>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "CommandLineArguments.hpp"
#include "Coords.hpp"
#include "GLException.hpp"
#include "GLUtils.hpp"
#include "Random.hpp"
#include "Triangle.hpp"
#include "Window.hpp"

constexpr int ERROR_CODE{ 1 };

void initGLFW(int argc, char* argv[]) {
    glfwSetErrorCallback(GLUtils::errorCallback);
    if (glfwInit() == GLFW_FALSE) {
        std::exit(ERROR_CODE);
    }
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_NO_ERROR, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    GLUtils::args = CommandLineArguments(argc, argv);
}

void createSmallerTriangle(Triangle& triangle) {
    static std::array<VertexType, 3> vertices{
        Coords::windowToGLCoordinates({ 500, 1'000 }, { 1'000, 1'000 }),
        Coords::windowToGLCoordinates({ 0, 0 }, { 1'000, 1'000 }),
        Coords::windowToGLCoordinates({ 1'000, 0 }, { 1'000, 1'000 }),
    };

    triangle.setVertices(vertices);
    triangle.setBackgroundColor(Color::Color{ Random::randomValue<uint32_t>(0, 0xFF'FF'FF) });
    for (VertexType& vertex : vertices) {
        vertex = Coords::GLToWindowCoordinates({ vertex.x, vertex.y }, { 1'000, 1'000 });
        vertex = Math::moveToCoord(vertex, { 500, 500, 0 }, 0.05);
        vertex = Coords::windowToGLCoordinates(Vector2<float>{ vertex.x, vertex.y }, { 1'000, 1'000 });
    }
}

int main(int argc, char* argv[]) {
    int returnCode{ 0 };

    try {
        initGLFW(argc, argv);
        Window window{ 1'000, 1'000, "Hello, World !" };
        std::array<Triangle, 100> triangles{};
        for (Triangle& triangle : triangles) {
            createSmallerTriangle(triangle);
        }

        while (window.isOpen()) {
            window.clear(Color::CYAN);
            for (const Triangle& triangle : triangles) {
                window.draw(triangle);
            }
            window.display();
            glfwPollEvents();
        }
    } catch (GLException& glException) {
        std::cerr << "GL-related exception occured :" << std::endl << '\t' << glException.what() << std::endl;
        returnCode = ERROR_CODE;
    } catch (std::exception& otherException) {
        std::cerr << "Non GL-related exception occured :" << std::endl << '\t' << otherException.what() << std::endl;
        returnCode = ERROR_CODE;
    }
    glfwTerminate();
    return returnCode;
}
