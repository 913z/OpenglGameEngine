#pragma once

#include <vector>

namespace app {
    class VertexLayout;

    class Mesh {
    private:
        unsigned int VBO = 0;
        unsigned int EBO = 0;
        unsigned int VAO = 0;

    public:
        Mesh(const VertexLayout& layout, const std::vector<float>& vertices,
             const std::vector<unsigned int>& indices);
        Mesh(const VertexLayout& layout, const std::vector<float>& vertices);

        void bind();
        void unbind();
    };
} // namespace app
