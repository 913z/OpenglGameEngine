#include <glad/glad.h>

#include "RenderQueue.h"

namespace app {
    void RenderQueue::submit(const Mesh &mesh) {
        queue.push_back(mesh);
    }
    
    void RenderQueue::render() const {
        for (auto& cmd : queue) {
        }

    }
}
