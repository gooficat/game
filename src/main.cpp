#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader.hpp"
#include "mesh.hpp"
#include "camera.hpp"

const char* defaultShaderVert = R"(#version 330 core
layout(location = 0) in vec3 aPos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
int main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
})";
const char* defaultShaderFrag = R"(#version 330 core
out vec4 color;
int main() {
    color = vec4(1.0f, 0.0f, 1.0f, 1.0f);
})";

std::vector<float> triangleVerts = {
     0.0f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
};
std::vector<unsigned> triangleInds = { 0, 1, 2 };

int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(960, 480, "", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();

    Shader defaultShader(defaultShaderVert, defaultShaderFrag);
    Camera cam(1.5f, 9.6f/4.8f, 0.1f, 100.0f);
    Mesh triangle(triangleVerts, triangleInds);

    cam.position.z = 5.0f;

    glClearColor(1.0f, 0.2f, 0.2f, 1.0f);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        defaultShader.use();
        cam.use(defaultShader);
        triangle.draw(defaultShader);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}