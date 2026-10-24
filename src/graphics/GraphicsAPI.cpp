#include "GraphicsAPI.h"
#include "ShaderProgram.h"

namespace app {
    void GraphicsAPI::setShaderProgram(ShaderProgram& program) {
        shaderProgram = &program;
    }

    void GraphicsAPI::bindShaderProgram() {
        if (shaderProgram != nullptr) {
            shaderProgram->bind();
        }
    }
}