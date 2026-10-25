#include <glad/glad.h>

#include "Mesh.h"
#include "VertexLayout.h"

namespace app {
    Mesh::Mesh(const VertexLayout& layout, const std::vector<float>& vertices,
               const std::vector<unsigned int>& indices) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                     vertices.data(), GL_STATIC_DRAW);
        for (auto& element : layout.elements) {
            glEnableVertexAttribArray(element.index);
            glVertexAttribPointer(element.index, element.size, element.type,
                                  GL_FALSE, layout.stride,
                                  (void*)element.offset);
        }
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     indices.size() * sizeof(unsigned int), indices.data(),
                     GL_STATIC_DRAW);

        glBindVertexArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    Mesh::Mesh(const VertexLayout& layout, const std::vector<float>& vertices) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                     vertices.data(), GL_STATIC_DRAW);
        for (auto& element : layout.elements) {
            glEnableVertexAttribArray(element.index);
            glVertexAttribPointer(element.index, element.size, element.type,
                                  GL_FALSE, layout.stride,
                                  (void*)element.offset);
        }

        glBindVertexArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Mesh::bind() {
        if (VAO != 0) {
            glBindVertexArray(VAO);
        }
    }

    void Mesh::unbind() {
        glBindVertexArray(0);
    }
} // namespace app
