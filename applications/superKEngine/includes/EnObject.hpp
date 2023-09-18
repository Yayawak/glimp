#ifndef EnObject_H
#define EnObject_H
// #include "../includes/stdEngine.hpp"
#include "../../../src/structure/headers/stdgl.hpp"
#include "glm/fwd.hpp"

class EnObject
{
protected:
    VAO *vao = new VAO();
    // VAO *vao;
    VBO *vbo;
    EBO *ebo;
    Shader *shaderProgram;
    // std::vector<Vertex> vertices;
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
public:
    // EnObject();
    EnObject()
    {
        init();
    }
    // virtual void init() = 0;
    // void set(
    //     const Vertex* vertices,
    //     const unsigned noOfVertices,
    //     const GLuint* indices,
    //     const unsigned noOfIndices)
    // {
    //     for (size_t i = 0; i < noOfVertices; i++)
    //         this->vertices.push_back(vertices[i]);
    //     for (size_t i = 0; i < noOfIndices; i++)
    //         this->indices.push_back(indices[i]);
    // }
    virtual void init()
    {

    }
    // virtual void init() {};
    // virtual void init();
    virtual void always() = 0;
    // virtual void always();
    virtual void clear() = 0; // clear bad data

    Shader *getShaderProgramPtr();
};


#endif
