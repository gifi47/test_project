cmake_minimum_required(VERSION 3.21)
project(test_project)

set(CMAKE_CXX_STANDARD 17)

set(OpenGlLinkers -lSOIL -lGLEW -lglfw3 -lGL -lGLU -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -ldl)

add_executable(test_project main.cpp Engine/Application/Application.cpp Engine/Application/Application.h Engine/Graphics/Shader.cpp Engine/Graphics/Shader.h Engine/Utils/Utils.cpp Engine/Utils/Utils.h Engine/Graphics/Batch.cpp Engine/Graphics/Batch.h Engine/Graphics/Mesh.cpp Engine/Graphics/Mesh.h Game/World/Chunk.cpp Game/World/Chunk.h Game/World/World.cpp Game/World/World.h Game/Game.cpp Game/Game.h Engine/Graphics/Camera.cpp Engine/Graphics/Camera.h)
target_link_libraries(test_project ${OpenGlLinkers})
