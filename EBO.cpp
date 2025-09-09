#include "EBO.h"

// Конструктор: теперь принимает указатель на константный GLuint.
EBO::EBO(const GLuint* indices, GLsizeiptr size) {
    // Используем оператор & для получения адреса ID
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

// Связывание EBO
void EBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

// Отвязывание EBO
void EBO::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Удаление EBO
void EBO::Delete() {
    // Используем оператор & для удаления буфера
    glDeleteBuffers(1, &ID);
}