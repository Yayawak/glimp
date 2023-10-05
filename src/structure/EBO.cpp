#include "headers/EBO.hpp"
#include "headers/utilsGL.hpp"

EBO::EBO(std::vector<GLuint> indices)
{
    // printf("Indicess Vector size = %lu\n", indices.size());
    // showvertices(indices);
    GLuint idxs[indices.size()];
    for (size_t i = 0; i < indices.size(); i++)
        idxs[i] = indices[i];
    EBO(idxs, sizeof(idxs));
}

EBO::EBO(GLuint *indices, GLsizeiptr size)
{
    glGenBuffers(1, &Id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void EBO::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Id);
}

void EBO::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
    glDeleteBuffers(1, &Id);
}