#include <format>
#include <functional>
#include "../include/GLException.hpp"
#include "../include/GLUtils.hpp"
#include "../include/Window.hpp"

void Window::initGLEW() {
    static bool has_init_GLEW{};

    if (!has_init_GLEW) {
        if (glewInit() != GLEW_OK) {
            throw GLException("GLEW initialization failed !");
        }
    }
    if (GLUtils::args.has_option("--debug")) {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(GLUtils::debugCallback, nullptr);
    }
}

Window::Window(int width, int height, const std::string& title, bool doesHandleResize, bool isMainGLwindow) :
    width{ width },
    height{ height },
    title{ title },
    doesHandleResize{ doesHandleResize },
    isMainGLwindow{ isMainGLwindow },
    window{ glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr) }
{
    if (!window) {
        throw GLException("Failed to allocate window.");
    }
    if (isMainGLwindow) {
        glViewport(0, 0, width, height);
        glfwMakeContextCurrent(window);
    }
    glfwSetFramebufferSizeCallback(window, doesHandleResize ? GLUtils::resizeCallback : GLUtils::resizeDummyCallback);
    initGLEW();
}

Window::Window(const Window& window) : Window(
    window.width,
    window.height,
    window.title,
    window.doesHandleResize,
    window.isMainGLwindow
) {}

Window::~Window() {
    if (window) {
        glfwDestroyWindow(window);
    }
}

void Window::clear(const Color::Color& color) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(color.red / 255.f, color.green / 255.f, color.blue / 255.f, color.alpha / 255.f);
}

void Window::draw(const Drawable& drawable) {
    updateSize();
    drawable.draw(get());
}

void Window::display() {
    glfwSwapBuffers(get());
}

bool Window::isOpen() {
    return !glfwWindowShouldClose(window);
}

void Window::close() {
    glfwSetWindowShouldClose(window, true);
}

void Window::updateSize() {
    glfwGetWindowSize(window, &width, &height);
}

Vector2<int> Window::size() {
    updateSize();
    return { .x = width, .y = height };
}

GLFWwindow* Window::get() noexcept {
    return window;
}

const GLFWwindow* Window::get() const noexcept {
    return window;
}

bool Window::pollEvent(Event& event) const {
    static const std::array eventPolls{
        [this](){ return this->pollKeyEvent(); }
    };
    std::optional<Event> optEvent{};

    glfwPollEvents();
    for (const auto& eventPoll : eventPolls) {
        optEvent = eventPoll();
        if (optEvent.has_value()) {
            event = optEvent.value();
            return true;
        }
    }
    return false;
}

Window::operator bool() noexcept {
    return window != nullptr;
}