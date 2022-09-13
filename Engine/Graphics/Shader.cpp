//
// Created by gifi on 05.12.2021.
//

#include "Shader.h"

Shader::Shader(const std::string& name) {
    //std::cout << ReadFile(name + ".vert");
    const GLchar* vertex_shader_code{ReadFile(name + ".vert")};

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_code, nullptr);
    glCompileShader(vertex_shader);

    CheckShaderErrors(vertex_shader);

    const GLchar* fragment_shader_code{ReadFile(name + ".frag")};

    GLuint fragment_shader{glCreateShader(GL_FRAGMENT_SHADER)};
    glShaderSource(fragment_shader, 1, &fragment_shader_code, nullptr);
    glCompileShader(fragment_shader);

    CheckShaderErrors(fragment_shader);

    _shader_program = glCreateProgram();
    glAttachShader(_shader_program, vertex_shader);
    glAttachShader(_shader_program, fragment_shader);
    glLinkProgram(_shader_program);

    CheckProgramErrors(_shader_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    delete[] vertex_shader_code;
    delete[] fragment_shader_code;
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

void Shader::Dispose() const {
    glDeleteProgram(_shader_program);
}

Shader::Shader() = default;
