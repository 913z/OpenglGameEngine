#pragma once

#include "core/Window.h"
#include "graphics/GraphicsAPI.h"

namespace app {
    class Application {
    private:
        Window window;

        GraphicsAPI graphicsAPI;

    public:
        static Application& getInstance();

        bool init();
        void run();
        void destroy();

        Window& getWindow();
        GraphicsAPI& getGraphicsAPI();
    };
} // namespace app
