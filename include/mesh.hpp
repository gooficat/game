#pragma once
#include <vector>

#include <GL/glew.h>

#include "shader.hpp"

struct Mesh {
    std::vector<float> vertices;
    std::vector<unsigned> indices;
    unsigned VAO, VBO, EBO;
    Mesh(std::vector<float>& vertices, std::vector<unsigned>& indices);
    void draw(Shader& shader);
    ~Mesh();
};
