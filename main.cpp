#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "LogEngine v0.2"

// ������� �������� (���������� 4 �������, ��� ��� ������ �������)
GLfloat vertices[] = {
    // ����������       // �����
    -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // ������ �����, �������
     0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // ������ ������, ������
     0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // ������� ������, �����
    -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f  // ������� �����, �����
};

// ������� ��� ��������� �������� �� ���� �������������
GLuint indices[] = {
    0, 1, 2, // ������ �����������
    2, 3, 0  // ������ �����������
};

int main() {
    // ������������� GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // ������������� GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }

    Shader shaderProgram("shader.vert", "shader.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkVBO(VBO1, 0);

    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // ������� ����
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.3f, 0.1f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate(); // ���������� ��������: shaderPorgram -> shaderProgram
        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete(); // ��������� �������� ��������� ���������

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}