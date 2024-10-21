#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"

struct Camera {
    glm::vec3 position, rotation;
    Camera(float fov, float aspect, float near, float far);
    glm::mat4 view, projection;
    void use(Shader& shader);
};
#endif