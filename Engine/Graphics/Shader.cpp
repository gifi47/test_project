//
// Created by gifi on 05.12.2021.
//

#include <cstring>
#include "Shader.h"

Shader::Shader(const std::string& name) {
    const GLchar * trt = "#version 330 core\n"
                         "\n"
                         "layout (location = 0) in vec3 position;\n"
                         "\n"
                         "void main()\n"
                         "{\n"
                         "    gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                         "}";
    std::cout << "size of default text " << strlen(trt) << "\n";
    std::cout << "size of readed text " << strlen(ReadFile(name + ".vert")) << "\n";
    const GLchar* vertex_shader_code{ReadFile(name + ".vert")};
    std::cout << "size of vertex_shader_code text " << strlen(vertex_shader_code) << "\n";
    std::cout << "-----------------------\n" << vertex_shader_code << "\n----------------------------\n";
    //std::cout << "-------trt----------------\n" << trt << "\n----------trt------------------\n";

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_code, nullptr);
    glCompileShader(vertex_shader);

    CheckShaderErrors(vertex_shader);
    std::cout << "vert\n";

    const GLchar* fragment_shader_code{ReadFile(name + ".frag")};
    std::cout << "-----------------------\n" << fragment_shader_code << "\n----------------------------\n";

    GLuint fragment_shader{glCreateShader(GL_FRAGMENT_SHADER)};
    glShaderSource(fragment_shader, 1, &fragment_shader_code, nullptr);
    glCompileShader(fragment_shader);

    CheckShaderErrors(fragment_shader);
    std::cout << "frag\n";

    _shader_program = glCreateProgram();
    glAttachShader(_shader_program, vertex_shader);
    glAttachShader(_shader_program, fragment_shader);
    glLinkProgram(_shader_program);

    CheckProgramErrors(_shader_program);
    std::cout << "prog\n";

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    std::cout << "end \n";
}

void Shader::Use() const {
    glUseProgram(_shader_program);
}

void Shader::CheckShaderErrors(const GLuint& shader){
    GLint success;
    GLchar infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "Error: shader compilation error\n" << infoLog << std::endl;
    }
}

void Shader::CheckProgramErrors(const GLuint& program){
    GLint success;
    GLchar infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cout << "Error: shader program compilation error\n" << infoLog << std::endl;
    }
}

Shader::~Shader() {
    if (_shader_program != 0) {
        glDeleteProgram(_shader_program);
    }
}

Shader::Shader() = default;
