#include <iostream>

#include "Application.h"
#include "graphics/GraphicsAPI.h"

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
