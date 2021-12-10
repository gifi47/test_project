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
    shader.Dispose();
    glfwDestroyWindow(_window);
    glfwTerminate();
    return 0;
}

Game::Game(const char* name): Application(name){

}

void Game::Init() {
    std::cout << "start init\n";
    Shader s = Shader("/home/gifi/CLionProjects/test_project/Game/Shaders/color");
    shader = s;
    std::cout << "shaders created\n";
    chunk = Chunk(16, 16, 16);
    std::cout << "chunk created\n";
    chunk.GenerateData();
    std::cout << "data generated\n";
    mesh = chunk.GenerateMesh();
    std::cout << "mesh generated\n";
    batch = Batch(mesh);
    std::cout << "batch created\n";
}
