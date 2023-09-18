#include "headers/utilsGL.hpp"
#include "headers/VBO.hpp"
#include <vector>
// #include "headers/Vertex.hpp"

// VBO::VBO(Vertex *vertices, GLsizeiptr size)
// {
//     this->VBO(vertices.)
// }

// FIXME : still bad implementation
VBO::VBO(std::vector<GLfloat> verticesVec)
{
    // vecToGlf(verticesVec);
    GLfloat *v = vecToGlf(verticesVec);
    // vecshow(glm::vec3 v)
    // showvertices(v, verticesVec.size());
    // VBO(v, verticesVec.size());
    // printf("size of verticesVec.size() * sizeof(GLfloat) = %lu\n", verticesVec.size() * sizeof(GLfloat));
    VBO(v, verticesVec.size() * sizeof(GLfloat));
    // printf("size of v = %lu\n", sizeof(*v));
    // VBO(v, sizeof(*v));
}

VBO::VBO(GLfloat *vertices, GLsizeiptr size)
{
    glGenBuffers(1, &Id);
    glBindBuffer(GL_ARRAY_BUFFER, Id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, Id);
}

void VBO::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
    glDeleteBuffers(1, &Id);
}