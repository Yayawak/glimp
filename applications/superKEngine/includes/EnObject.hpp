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
    // std::vector<GLfloat> vertices;
    // std::vector<GLuint> indices;
    GLfloat *vertices;
    GLuint *indices;
    size_t noOfVertices;
    size_t noOfIndices;

    glm::vec3 center;
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

    virtual void scale(glm::vec3 scaleVector)
    {
        // sha
        // * this is not good behavior (use shader to change scale)
        // GLint scaleVecId = glGetUniformLocation(shaderProgram->shaderProgramId, "scaleVec");
        // glUniform3f(scaleVecId, scaleVector.x, scaleVector.y, scaleVector.z);
        // glUniform3fv(GLint location, GLsizei count, const GLfloat *value)
        for (size_t i = 0; i < noOfVertices; i++)
        {
            int j = 3 * i;
            vertices[j + 0] *= scaleVector.x;
            vertices[j + 1] *= scaleVector.y;
            vertices[j + 2] *= scaleVector.z;
        }
        std::cout << "result after scaled.\n";
        showvertices(vertices, noOfVertices);
    }

    // virtual void setPosition(glm::vec3 center)
    // {
    //     this->center = center;
    // }

    virtual void shiftByVec(glm::vec3 shiftVector)
    {
        for (size_t i = 0; i < noOfVertices; i++)
        {
            int j = 3 * i;
            vertices[j + 0] += shiftVector.x;
            vertices[j + 1] += shiftVector.y;
            vertices[j + 2] += shiftVector.z;
        }
        std::cout << "result after shifted.\n";
        showvertices(vertices, noOfVertices);
    }

    // void

    Shader *getShaderProgramPtr();
};


#endif
