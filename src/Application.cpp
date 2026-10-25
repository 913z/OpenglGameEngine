#include <iostream>
#include <string>

#include "Application.h"
#include "graphics/GraphicsAPI.h"
#include "graphics/ShaderProgram.h"

namespace app {
    Application& Application::getInstance() {
        static Application app;
        return app;
    }

    bool Application::init() {
        if (!window.init()) {
            std::cout << "Failed to initialize window" << std::endl;
            return false;
        }

        std::string vertexSource = R"(
        #version 330 core
        layout(location=0) in vec4 position;
        void main() {
            gl_Position = position;
        }
        )";
        std::string fragmentSource = R"(
        #version 330 core
        out vec4 color;
        void main() {
            color = vec4(1.0, 0.0, 0.0, 1.0);
        }
        )";
        ShaderProgram shader((char*)vertexSource.c_str(),
                             (char*)fragmentSource.c_str());
        getGraphicsAPI().setShaderProgram(shader);
        getGraphicsAPI().bindShaderProgram();

        return true;
    }

    void Application::run() {
        while (!window.getWindowShouldClose()) {
            window.clearBuffer();

            window.pollEvent();
            window.swapBuffer();
        }
    }

    void Application::destroy() {
    }

    Window& Application::getWindow() {
        return window;
    }

    GraphicsAPI& Application::getGraphicsAPI() {
        return graphicsAPI;
    }
} // namespace app
