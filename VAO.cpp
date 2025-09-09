#include "VAO.h"
#include <glad/glad.h>

VAO::VAO() {
    glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO& VBO, GLuint layout) {
    VBO.Bind(); // ����������� VBO, ����� VAO ��� ��� "���������"
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(layout);
    VBO.Unbind(); // ���������� VBO
}

void VAO::Bind() {
    glBindVertexArray(ID);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

void VAO::Delete() {
    glDeleteVertexArrays(1, &ID);
}