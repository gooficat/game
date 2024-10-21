#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

#include "glad/glad.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"

struct Mesh {
    std::vector<float> vertices;
    std::vector<unsigned> indices;
    unsigned VAO, VBO, EBO;
    glm::vec3 position, rotation, scale;
    glm::mat4 transform;
    Mesh(std::vector<float>& vertices, std::vector<unsigned>& indices);
    void draw(Shader& shader);
    ~Mesh();
};  
#endif