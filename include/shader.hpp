#pragma once
#include <string>

#include <GL/glew.h>

struct Shader {
    unsigned ID;
    Shader(const char* vertexSource, const char* fragmentSource);
    ~Shader();
};