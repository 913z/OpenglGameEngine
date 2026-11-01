#pragma once

#include <vector>

namespace app {
    class Mesh;
    class RenderQueue {
    private:
        std::vector<Mesh> queue;
    public:
        void submit(const Mesh& mesh);

        void render() const;
    };
}
