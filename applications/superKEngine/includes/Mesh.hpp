#ifndef EnObject_H
#define EnObject_H
// #include "../includes/stdEngine.hpp"
#include "../../../src/structure/headers/stdgl.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"
#include "glm/trigonometric.hpp"
#include <cassert>
#include <new>

class Mesh
{
private:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    size_t noOfVertices;
    size_t noOfIndices;

    VAO *vao;
    VBO *vbo;
    EBO *ebo;

    // Shader *shaderProgram;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat4 ModelMatrix;


    // ! must be called before initVAO (must have data in vertices variable before initialization)
    void initVertexData(Vertex *vertexArray,
        const unsigned& noOfVertices,
        GLuint *indexArray,
        const unsigned& noOfIndices
    )
    {
        this->noOfIndices = noOfIndices;
        this->noOfVertices = noOfVertices;

        for (size_t i = 0; i < noOfVertices; i++)
        {
            this->vertices.push_back(vertexArray[i]);
        }
        for (size_t i = 0; i < noOfIndices; i++)
        {
            this->indices.push_back(indexArray[i]);
        }
    }

    void initVAO()
    {
        assert(noOfVertices != 0);
        assert(noOfIndices != 0);

        vao = new VAO();
        vao->Bind();
        
        vbo = new VBO(vertices);
        ebo = new EBO(indices);

        // position, color, texcoord, normal
        // 3 + 3 + 2 + 3 = 11
        vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 11 * sizeof(float), (void *)(0 * sizeof(float)));
        vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, 11 * sizeof(float), (void *)(3 * sizeof(float)));
        vao->LinkAttrib(*vbo, 2, 2, GL_FLOAT, 11 * sizeof(float), (void *)(6 * sizeof(float)));
        vao->LinkAttrib(*vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void *)(8 * sizeof(float)));
    
        vao->Unbind();
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

    void updateUniform(Shader* shader)
    {
        shader->setMat4fv(this->ModelMatrix, "ModelMatrix");
    }


public:
    Mesh(
        Vertex *vertexArray,
        const unsigned& noOfVertices,
        GLuint *indexArray,
        const unsigned& noOfIndices
    )
    {
        initVertexData(vertexArray, noOfVertices, indexArray, noOfIndices);
        initVAO();
        initModelMatrix();
    }

    ~Mesh()
    {
        vao->Delete();
        vbo->Delete();
        ebo->Delete();
    }


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

    void render(Shader* shader)
    {
        shader->Activate();
        // updateUniform(shader);


        vao->Bind();

        // if (this->indices.empty())
        //     glDrawArrays(GL_TRIANGLES, 0, noOfVertices);
        // else
        // glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_BYTE, 0);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_INT, 0);

        // glDrawArrays(GL_TRIANGLES, 0, noOfVertices);

        // shader->Deactivate();
    }


};


#endif
