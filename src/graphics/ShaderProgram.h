#pragma once

namespace app {
    class ShaderProgram {
    private:
        unsigned int programId = 0;

    public:
        ShaderProgram(const char* vertexSource, const char* fragmentSource);
        ~ShaderProgram();

        void bind();
    };
} // namespace app
