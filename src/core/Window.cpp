#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Window.h"

namespace app {
    bool Window::init() {
        if (!glfwInit()) {
            std::cout << "Failed to initialize glfw." << std::endl;
            return false;
        }

        window = glfwCreateWindow(windowWidth, windowHeight, windowTitle,
                                  nullptr, nullptr);
        if (window == nullptr) {
            std::cout << "Failed to create window." << std::endl;
            return false;
        }

        glfwMakeContextCurrent((GLFWwindow*)window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to init glad." << std::endl;
            return false;
        }

        return true;
    }

    void Window::destroy() {
        glfwDestroyWindow((GLFWwindow*)window);
        glfwTerminate();
    }

    void Window::pollEvent() {
        glfwPollEvents();
    }

    void Window::swapBuffer() {
        glfwSwapBuffers((GLFWwindow*)window);
    }

    void Window::clearBuffer() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    bool Window::getWindowShouldClose() const {
        return glfwWindowShouldClose((GLFWwindow*)window) == GL_TRUE;
    }
} // namespace app
