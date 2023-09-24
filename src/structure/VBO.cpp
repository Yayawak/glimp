#include "headers/VBO.hpp"
#include "headers/utilsGL.hpp"
// #include "headers/Vertex.hpp"

// VBO::VBO(Vertex *vertices, GLsizeiptr size)
// {
//     this->VBO(vertices.)
// }
VBO::VBO(std::vector<Vertex> stdVertices) 
{
    showvertices(stdVertices);
    // std::cout << "initing std vec\n";
    // showvertices(stdVertices);
    // GLfloat positions[3 * stdVertices.size()];

    // GLfloat V[3 * stdVertices.size()];
    printf("stdVertices size: %lu\n", stdVertices.size());
    const int maxRowSize = 11;
    GLfloat V[maxRowSize * stdVertices.size()];
    
    for (int i = 0; i < stdVertices.size(); i++)
    {
        V[(i * maxRowSize) + 0] = stdVertices[i].position.x;
        V[(i * maxRowSize) + 1] = stdVertices[i].position.y;
        V[(i * maxRowSize) + 2] = stdVertices[i].position.z;

        V[(i * maxRowSize) + 3] = stdVertices[i].color.x;
        V[(i * maxRowSize) + 4] = stdVertices[i].color.y;
        V[(i * maxRowSize) + 5] = stdVertices[i].color.z;

        V[(i * maxRowSize) + 6] = stdVertices[i].texcoord.x;
        V[(i * maxRowSize) + 7] = stdVertices[i].texcoord.y;

        V[(i * maxRowSize) + 8] = stdVertices[i].normal.x;
        V[(i * maxRowSize) + 9] = stdVertices[i].normal.y;
        V[(i * maxRowSize) + 10] = stdVertices[i].normal.z;
    }
    // VBO(V, stdVertices.size() * sizeof(GLfloat));
    // VBO(V, stdVertices.size() * sizeof(GLfloat));
    VBO(V, sizeof(V));
}

// // FIXME : still bad implementation
// VBO::VBO(std::vector<GLfloat> verticesVec)
// {
//     // vecToGlf(verticesVec);
//     GLfloat *v = vecToGlf(verticesVec);
//     // vecshow(glm::vec3 v)
//     // showvertices(v, verticesVec.size());
//     // VBO(v, verticesVec.size());
//     // printf("size of verticesVec.size() * sizeof(GLfloat) = %lu\n", verticesVec.size() * sizeof(GLfloat));
//     VBO(v, verticesVec.size() * sizeof(GLfloat));
//     // printf("size of v = %lu\n", sizeof(*v));
//     // VBO(v, sizeof(*v));
// }

VBO::VBO(GLfloat *vertices, GLsizeiptr sizeBytes)
{
    printf("base VBO class initializing verticees of %lu bytes\n", sizeBytes);
    showvertices(vertices, sizeBytes / sizeof(GLfloat));

    glGenBuffers(1, &Id);
    glBindBuffer(GL_ARRAY_BUFFER, Id);
    glBufferData(GL_ARRAY_BUFFER, sizeBytes, vertices, GL_STATIC_DRAW);
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