#include <glad/glad.h>

#include "ShaderProgram.h"

namespace app {
    ShaderProgram::ShaderProgram(const char* vertexSource,
                                 const char* fragmentSource) {
        programId = glCreateProgram();

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(vertexShader, 1, &vertexSource, nullptr);
        glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
        glCompileShader(vertexShader);
        glCompileShader(fragmentShader);

        glAttachShader(programId, vertexShader);
        glAttachShader(programId, fragmentShader);

        glLinkProgram(programId);
        glValidateProgram(programId);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    ShaderProgram::~ShaderProgram() {
        glDeleteProgram(programId);
    }

    void ShaderProgram::bind() {
        glUseProgram(programId);
    }
} // namespace app
