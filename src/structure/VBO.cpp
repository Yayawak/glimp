#include "headers/VBO.hpp"
#include "headers/utilsGL.hpp"
// #include "headers/Vertex.hpp"

// VBO::VBO(Vertex *vertices, GLsizeiptr size)
// {
//     this->VBO(vertices.)
// }
VBO::VBO(std::vector<Vertex> stdVertices) 
{
    // std::cout << "initing std vec\n";
    // showvertices(stdVertices);
    GLfloat positions[3 * stdVertices.size()];
    
    for (int i = 0; i < stdVertices.size(); i++)
    {
        positions[(i * 3) + 0] = stdVertices[i].position.x;
        positions[(i * 3) + 1] = stdVertices[i].position.y;
        positions[(i * 3) + 2] = stdVertices[i].position.z;
    }
    // VBO(positions, stdVertices.size() * sizeof(GLfloat));
    // VBO(positions, stdVertices.size() * sizeof(GLfloat));
    VBO(positions, sizeof(positions));
}

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
    printf("base initializing verticees of size %lu\n", size);
    showvertices(vertices, size / sizeof(GLfloat));

    glGenBuffers(1, &Id);
    glBindBuffer(GL_ARRAY_BUFFER, Id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    // glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
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