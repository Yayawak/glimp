#ifndef EnObject_H
#define EnObject_H
// #include "../includes/stdEngine.hpp"
#include "../../../src/structure/headers/stdgl.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"
#include "glm/trigonometric.hpp"
#include <cassert>
#include <new>
#include "Primitive.hpp"

class Mesh
{
private:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    size_t noOfVertices;
    size_t noOfIndices;

    // VAO *vao = new VAO();
    VAO *vao;
    VBO *vbo;
    EBO *ebo;

    // Shader *shaderProgram;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat4 ModelMatrix;
    glm::mat4 ProjectionMatrix;
    glm::mat4 ViewMatrix;


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

    // void initVAO(Primitive* primitive)
    // {
    //     // initVertexData(Vertex *vertexArray, const unsigned int &noOfVertices, GLuint *indexArray, const unsigned int &noOfIndices)
    // }

    void initVAO()
    {
        assert(noOfVertices != 0);
        assert(noOfIndices != 0);

        vao = new VAO();
        vao->Bind();
        
        // vbo = new VBO(vertices);
        vbo = new VBO(vertices.data(), vertices.size() * sizeof(Vertex));
        // vertices.data();
        // glGe
        // glGenBuffers(1, &this->vbo->Id);
        // glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data())
        ebo = new EBO(indices);

        // position, color, texcoord, normal
        // 3 + 3 + 2 + 3 = 11
        // ! problem maybe here
        GLsizeiptr stride = 11 * sizeof(float);
        vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, stride, (void *)(0 * sizeof(float)));
        vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, stride, (void *)(3 * sizeof(float)));
        vao->LinkAttrib(*vbo, 2, 2, GL_FLOAT, stride, (void *)(6 * sizeof(float)));
        vao->LinkAttrib(*vbo, 3, 3, GL_FLOAT, stride, (void *)(8 * sizeof(float)));
    
        vao->Unbind();
    }

    // void initModelMatrix()
    // {
    //     updateModelMatrix();
    // }

    void updateUniform(Shader* shader)
    {
        shader->setMat4fv(this->ModelMatrix, "ModelMatrix");
        shader->setMat4fv(this->ViewMatrix, "ViewMatrix");
        shader->setMat4fv(this->ProjectionMatrix, "ProjectionMatrix");
    }

    void updateModelMatrix()
    {
        ModelMatrix = glm::mat4(1.f);
        ModelMatrix = glm::translate(ModelMatrix, position);
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
        ModelMatrix = glm::scale(ModelMatrix, scale);
    }

    void updateViewMatrix()
    {
        glm::vec3 cameraPosition(0.f, 0.f, 1.f);
        glm::vec3 worldUp(0.f, 1.f, 0.f);
        glm::vec3 cameraFrontDirection(0.f, 0.f, -1.f);
        // glm::vec3 cameraFrontDirection(0.f, 0.f, 1.f);
        ViewMatrix = glm::mat4(1.f);
        ViewMatrix = glm::lookAt(cameraPosition, cameraPosition + cameraFrontDirection, worldUp);
    }

    void updateProjectionMatrix()
    {
        float fov = 90.f;
        float nearPlane = 0.1f;
        float farPlane = 100.f;
        ProjectionMatrix = glm::perspective(
            glm::radians(fov),
            static_cast<float>(screenWidth) / screenHeight,
            nearPlane,
            farPlane
        );
    }


public:
    Mesh(
        Primitive *primitive,
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 scale = glm::vec3(1)
    )
    {
        this->position = position;
        this->rotation = rotation;
        this->scale = scale;

        initVertexData(primitive->getVertices(), primitive->getNoOfVertices(),
            primitive->getIndices(), primitive->getNoOfIndices()
        );
        // initVertexData(primitive.getVertices(), primitive.getNoOfVertices(),
        //     primitive.getIndices(), primitive.getNoOfIndices()
        // );
        initVAO();
        // initModelMatrix();
    }

    Mesh(
        Vertex *vertexArray,
        const unsigned& noOfVertices,
        GLuint *indexArray,
        const unsigned& noOfIndices,
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 scale = glm::vec3(1)
    )
    {
        this->position = position;
        this->rotation = rotation;
        this->scale = scale;

        initVertexData(vertexArray, noOfVertices, indexArray, noOfIndices);
        initVAO();
        // initModelMatrix();
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
        updateProjectionMatrix();
        updateViewMatrix();
        updateModelMatrix();

        updateUniform(shader);
        shader->Activate(); // mus active after updateUniform


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

    void setPosition(const glm::vec3 pos)
    {
        this->position = pos;
    }

    void setRotation(const glm::vec3 rotation)
    {
        this->rotation = rotation;
    }

    void setScale(const glm::vec3 rotation)
    {
        this->rotation = rotation;
    }

    void move(const glm::vec3 shiftVector)
    {
        this->position += shiftVector;
    }

    void rotate(const glm::vec3 rotation)
    {
        this->rotation += rotation;
        if (this->rotation.x > 360)    
            this->rotation.x = 0;
    }

    void scaleMesh(const glm::vec3 scale)
    {
        this->scale += scale;
    }

};


#endif
