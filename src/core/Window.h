#pragma once

namespace app {
    class Window {
    private:
        const float windowWidth = 800, windowHeight = 600;
        const char* windowTitle = "GameEngine";

        void* window = nullptr;

    public:
        bool init();
        void destroy();

        void pollEvent();
        void swapBuffer();
        void clearBuffer();
        bool getWindowShouldClose() const;
    };
} // namespace app
