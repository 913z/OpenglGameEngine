#pragma once

namespace app {
    class ShaderProgram;

    class GraphicsAPI {
    private:
        ShaderProgram* shaderProgram = nullptr;

    public:
        void setShaderProgram(ShaderProgram& program);
        void bindShaderProgram();
    };
} // namespace app
