//
// Created by gifi on 05.12.2021.
//

#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <GL/glew.h>
#include "../Utils/Utils.h"
#include <iostream>

class Shader {
public:
    Shader();
    explicit Shader(const std::string& name);
    void Use() const;
    void Dispose() const;

private:
    GLuint _shader_program{};

    static void CheckShaderErrors(const GLuint& shader);
    static void CheckProgramErrors(const GLuint& program);
};


#endif //ENGINE_SHADER_H
