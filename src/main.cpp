#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "mesh.hpp"
#include "shader.hpp"

const char* defaultShaderVert = R"(#version 330 core
layout(location = 0) in vec3 aPos;
int main() {
    gl_Position = vec4(aPos, 1.0);
})";
const char* defaultShaderFrag = R"(#verion 330 core
out vec4 color;
int main() {
    color = vec4(0.0f, 1.0f, 0.0f, 1.0f);
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

    Mesh triangle(triangleVerts, triangleInds);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        triangle.draw(defaultShader);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}