#include <algorithm>
#include <cctype>
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
#include "../include/CommandLineArguments.hpp"
#include "../include/Coords.hpp"
#include "../include/GLException.hpp"
#include "../include/GLUtils.hpp"
#include "../include/Random.hpp"
#include "../include/Triangle.hpp"
#include "../include/Utils.hpp"
#include "../include/Window.hpp"

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

void handleEvent(Window& window, Event& event) {
    if (event.type == EventType::KeyEvent) {
        constexpr std::array keyTypes{
            "pressed",
            "held",
            "released"
        };
        const std::array<std::reference_wrapper<std::vector<Key>>, 3> keyArrays{
            event.key.pressedKeys,
            event.key.heldDownKeys,
            event.key.releasedKeys
        };

        if (containerHas(event.key.pressedKeys, Key::Escape)) {
            window.close();
        }
        for (std::size_t i = 0; const auto& keyArray : keyArrays) {
            for (const Key& key : keyArray.get()) {
                const int keycode{ static_cast<int>(key) };
                if (std::isprint(keycode)) {
                    std::cout << static_cast<unsigned char>(keycode) << ' ';
                } else {
                    std::cout << "A non-printable char ";
                }
                std::cout << std::format("is {}.", keyTypes[i]) << std::endl;
            }
        }
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

        Event event{};
        while (window.isOpen()) {
            window.clear(Color::CYAN);
            for (const Triangle& triangle : triangles) {
                window.draw(triangle);
            }
            window.display();
            while (window.pollEvent(event)) {
                handleEvent(window, event);
            }
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
