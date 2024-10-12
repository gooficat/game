#include "shader.hpp"

Shader::Shader(const char* vertexSource, const char* fragmentSource) {
    unsigned vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert, 1, &vertexSource, NULL);
    glCompileShader(vert);
    unsigned frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag, 1, &fragmentSource, NULL);
    glCompileShader(frag);
    ID = glCreateProgram();
    glAttachShader(ID, vert);
    glAttachShader(ID, frag);
    glLinkProgram(ID);
    glDeleteShader(vert);
    glDeleteShader(frag);
}

Shader::~Shader() {
    glDeleteProgram(ID);
}