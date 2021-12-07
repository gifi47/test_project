//
// Created by gifi on 05.12.2021.
//

#include "Application.h"

Application::Application(const char* name) : _name(name) {}

int8_t Application::Start() {
    if (!glfwInit()) {
        std::cout << "Error: glfw doesnt initialize\n";
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    _window = glfwCreateWindow(_width, _height, Application::_name, nullptr, nullptr);
    if (!_window) {
        std::cout << "Error: window creation error\n";
        exit(-1);
    }

    glfwMakeContextCurrent(_window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Error: glew doesnt initialize\n";
        exit(-1);
    }
    glViewport(0, 0, _width, _height);
    glClearColor(0.1, 0.6, 0.1, 1);

    return 0;
}

int8_t Application::Loop() {
    while (!glfwWindowShouldClose(_window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    glfwDestroyWindow(_window);
    glfwTerminate();
    return 0;
}

void Application::SetScreenSize(int16_t width, int16_t height) {
    _width = width;
    _height = height;
}

void Application::SetScreenWidth(int16_t pixels) {
    _width = pixels;
}

void Application::SetScreenHeight(int16_t pixels) {
    _height = pixels;
}


