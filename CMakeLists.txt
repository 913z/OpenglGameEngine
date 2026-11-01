cmake_minimum_required(VERSION 4.4)
project(game_engine)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(dependent/glad/include)

add_subdirectory(dependent/glfw-3.5.1)
link_libraries(glfw)

add_executable(
    game_engine

    src/glad.c
    src/main.cpp
    src/Application.h
    src/Application.cpp
    src/core/Window.h
    src/core/Window.cpp
    src/graphics/GraphicsAPI.h
    src/graphics/GraphicsAPI.cpp
    src/graphics/ShaderProgram.h
    src/graphics/ShaderProgram.cpp
    src/render/VertexLayout.cpp
    src/render/Mesh.h
    src/render/Mesh.cpp
    src/render/RenderQueue.h
    src/render/RenderQueue.cpp
)
