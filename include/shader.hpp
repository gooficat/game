#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <iostream>
#include "glad/glad.h"

struct Shader {
    unsigned ID;
    Shader(const char* vertexSource, const char* fragmentSource);
    void use();
    ~Shader();
};

#endif