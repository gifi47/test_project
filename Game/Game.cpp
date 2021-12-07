//
// Created by gifi on 06.12.2021.
//

#include "Game.h"

int8_t Game::Loop() {
    while (!glfwWindowShouldClose(_window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader.Use();
        batch.Render();
        glfwSwapBuffers(_window);
    }

    glfwDestroyWindow(_window);
    glfwTerminate();
    return 0;
}

Game::Game(const char* name): Application(name){

}

void Game::Init() {
    std::cout << "start init\n";
    shader = Shader("/home/gifi/CLionProjects/test_project/Game/Shaders/default");
    std::cout << "shaders created\n";
    chunk = Chunk(16, 16, 16);
    std::cout << "chunk created\n";
    chunk.GenerateData();
    std::cout << "data generated\n";
    mesh = chunk.GenerateMesh();
    std::cout << "mesh generated\n";
    float* verts{new float[]{ 0.0f, 0.5f, 0.0f, 0.4f, -0.3f, 0.0f, -0.4f, -0.3f, 0.0f,}};
    u_int32_t* inds{new u_int32_t[]{0, 1, 2}};
    Mesh m = Mesh(verts, 9, inds, 3);
    batch = Batch(m);
    std::cout << "batch created\n";
}
