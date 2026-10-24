#include <iostream>

#include "Application.h"

int main() {
    app::Application& app = app::Application::getInstance();

    if (!app.init()) {
        std::cout << "Failed to init application" << std::endl;
        return -1;
    }

    app.run();
    app.destroy();

    return 0;
}
