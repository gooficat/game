#include "camera.hpp"

Camera::Camera(float fov, float aspect, float near, float far) : position(0.0f), rotation(0.0f) {
    projection = glm::perspective(fov,aspect, near, far);
}

void Camera::use(Shader& shader) {
    view = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::rotate(view, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    view = glm::translate(view, -position);

    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, &projection[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "view"), 1, GL_FALSE, &view[0][0]);
}

