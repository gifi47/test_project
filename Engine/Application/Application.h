//
// Created by gifi on 05.12.2021.
//

#ifndef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Application {
public:
    explicit Application(const char* name);

    virtual int8_t Start();
    virtual int8_t Loop();

    void SetScreenWidth(int16_t pixels);
    void SetScreenHeight(int16_t pixels);
    void SetScreenSize(int16_t width, int16_t height);

protected:
    const char* _name{};
    GLFWwindow* _window{};
    int16_t _width{};
    int16_t _height{};
};


#endif //ENGINE_APPLICATION_H
