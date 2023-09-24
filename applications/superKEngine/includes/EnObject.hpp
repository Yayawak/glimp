#ifndef EnObject_H
#define EnObject_H
// #include "../includes/stdEngine.hpp"
#include "../../../src/structure/headers/stdgl.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"
#include "glm/trigonometric.hpp"
#include <new>

class EnObject
{
protected:
    VAO *vao = new VAO();
    // VAO *vao;
    VBO *vbo;
    EBO *ebo;
    Shader *shaderProgram;
    std::vector<Vertex> vertices;
    // std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
    // GLfloat *vertices;
    // GLuint *indices;
    size_t noOfVertices;
    size_t noOfIndices;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat4 ModelMatrix;

public:
    // EnObject();
    EnObject(
        Vertex *vertexArray,
        const unsigned& noOfVertices,
        GLuint *indexArray,
        const unsigned& noOfIndices
    )
    {
        initVertexData(vertexArray, noOfVertices, indexArray, noOfIndices);
        initModelMatrix();
        // init();
    }

    ~EnObject()
    {
        vao->Delete();
        vbo->Delete();
        ebo->Delete();
    }

    void initVertexData(Vertex *vertexArray,
        const unsigned& noOfVertices,
        GLuint *indexArray,
        const unsigned& noOfIndices
    )
    {
        for (size_t i = 0; i < noOfVertices; i++)
        {
            this->vertices.push_back(vertexArray[i]);
        }
        for (size_t i = 0; i < noOfIndices; i++)
        {
            this->indices.push_back(indexArray[i]);
        }
    }

    void iniVAO()
    {
        vao->Bind();
        
        vbo = new VBO(vertices);
        ebo = new EBO(indices);

        // position
        vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);
        // color
        // vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, 3 * sizeof(float), (void *)(3 * ));
    }

    void initModelMatrix()
    {
        position = glm::vec3(0);
        rotation = glm::vec3(0);
        scale = glm::vec3(1);

        ModelMatrix = glm::mat4(1.f);
        ModelMatrix = glm::translate(ModelMatrix, position);
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
        ModelMatrix = glm::scale(ModelMatrix, scale);
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
    // virtual void init()
    // {

    // }
    // virtual void init() {};
    // virtual void init();
    // virtual void always() = 0;
    virtual void always()
    {
        shaderProgram->Activate();

        // this->updateUniform(shaderProgram);

        vao->Bind();

        if (this->indices.empty())
            glDrawArrays(GL_TRIANGLES, 0, noOfVertices);
        else
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }
    // virtual void always();

    void updateUniform(Shader* shader)
    {
        // shader->setMat4fv()
    }

    virtual void scaleObject(glm::vec3 scaleVector)
    {
        // sha
        // * this is not good behavior (use shader to change scale)
        // GLint scaleVecId = glGetUniformLocation(shaderProgram->shaderProgramId, "scaleVec");
        // glUniform3f(scaleVecId, scaleVector.x, scaleVector.y, scaleVector.z);
        // glUniform3fv(GLint location, GLsizei count, const GLfloat *value)
        for (size_t i = 0; i < noOfVertices; i++)
        {
            // int j = 3 * i;
            // vertices[j + 0] *= scaleVector.x;
            // vertices[j + 1] *= scaleVector.y;
            // vertices[j + 2] *= scaleVector.z;
            vertices[i].position *= scaleVector;
        }
        std::cout << "result after scaled.\n";
        // showvertices(vertices, noOfVertices);
    }

    // virtual void setPosition(glm::vec3 center)
    // {
    //     this->center = center;
    // }

    virtual void shiftByVec(glm::vec3 shiftVector)
    {
        for (size_t i = 0; i < noOfVertices; i++)
        {
            // int j = 3 * i;
            // vertices[j + 0] += shiftVector.x;
            // vertices[j + 1] += shiftVector.y;
            // vertices[j + 2] += shiftVector.z;
            vertices[i].position += shiftVector;
        }
        std::cout << "result after shifted.\n";
        // showvertices(vertices, noOfVertices);
    }

    // void

    Shader *getShaderProgramPtr();
};


#endif
