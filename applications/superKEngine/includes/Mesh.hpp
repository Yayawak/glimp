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
#include <vector>
#include "Primitive.hpp"

struct TripleIndex
{
    GLuint a;
    GLuint b;
    GLuint c;
};



class Mesh
{
protected:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    size_t noOfVertices;
    size_t noOfIndices;

    // VAO *vao = new VAO();
    VAO *vao;
    VBO *vbo;
    EBO *ebo;
    Texture *texture;

    // Shader *shaderProgram;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat4 ModelMatrix;
    glm::mat4 ProjectionMatrix;
    glm::mat4 ViewMatrix;

    void callthisfakeconstructor(
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
        texture = NULL; // must have

        initVertexData(vertexArray, noOfVertices, indexArray, noOfIndices);
        initVAO();
    }

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
        
        // vbo = new VBO(vertices);
        vbo = new VBO(vertices.data(), vertices.size() * sizeof(Vertex));
        // vertices.data();
        // glGe
        // glGenBuffers(1, &this->vbo->Id);
        // glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data())
        ebo = new EBO(indices);


        // position, color, texcoord, normal
        // 3 + 3 + 2 + 3 = 11
        GLsizeiptr stride = 11 * sizeof(float);
        vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, stride, (void *)(0 * sizeof(float)));
        vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, stride, (void *)(3 * sizeof(float)));
        vao->LinkAttrib(*vbo, 2, 2, GL_FLOAT, stride, (void *)(6 * sizeof(float)));
        vao->LinkAttrib(*vbo, 3, 3, GL_FLOAT, stride, (void *)(8 * sizeof(float)));
    
        vao->Unbind();
    }

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

    inline Mesh() {}
    // inline Mesh() { printf("This is base naked constructor of Mesh class.\n"); }
    Mesh(
        Primitive *primitive,
        const char *texturePath
    )
    {
        this->position = glm::vec3(0);
        this->rotation = glm::vec3(0);
        this->scale = glm::vec3(1);
    
        texture = new Texture(
            texturePath,
            GL_TEXTURE_2D, GL_TEXTURE0,
            GL_RGB, GL_UNSIGNED_BYTE
        );

        initVertexData(primitive->getVertices(), primitive->getNoOfVertices(),
            primitive->getIndices(), primitive->getNoOfIndices()
        );
        initVAO();
    }

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
    
        texture = NULL;
        initVertexData(primitive->getVertices(), primitive->getNoOfVertices(),
            primitive->getIndices(), primitive->getNoOfIndices()
        );
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
    }

    ~Mesh()
    {
        vao->Delete();
        vbo->Delete();
        ebo->Delete();
    }


    void render(Shader* shader)
    {
        updateProjectionMatrix();
        updateViewMatrix();
        updateModelMatrix();
        
        updateUniform(shader);


        shader->Activate(); // must active after updateUniform


        // if (texture != NULL)
        // {
        //     // texture->texUnit(*shader, "tex0", 0);
        //     // texture->Bind();
        // }
        // else{
        //     std::cout << "im real null texture\n";
        // }

        vao->Bind();


        // #define JTest
        // #ifndef JTest
        // Texture *texture = new Texture(
        //     // texturePath,
        //     // "img/abadon.png",
        //     "/Users/rio/Desktop/glgl/img/abadon.png",
        //     GL_TEXTURE_2D, GL_TEXTURE0,
        //     GL_RGB, GL_UNSIGNED_BYTE
        // );
        // texture->texUnit(*shader, "tex0", 0);
        if (texture != NULL)
        {
            GLint loc = glGetUniformLocation(shader->shaderProgramId, "isHasTexture");
            glUniform1i(loc, 1);

            texture->Bind();
        }
        // meshes with no textures path file
        else
        {
            GLint loc = glGetUniformLocation(shader->shaderProgramId, "isHasTexture");
            glUniform1i(loc, 0);
        }

        // #endif

        // if (this->indices.empty())
        //     glDrawArrays(GL_TRIANGLES, 0, noOfVertices);
        // else
        // glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_BYTE, 0);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_INT, 0);
        // glDrawArrays(GL_TRIANGLES, 0, noOfVertices);

        // texture->Delete();
        // shader->Deactivate();
    }

    void setPosition(const glm::vec3 pos)
    {
        this->position = pos;
        for (int i = 0; i < this->noOfVertices; i++)
        {
            vertices[i].position += pos;
            vertices[i].normal += pos;
        }
    }

    void setRotation(const glm::vec3 rotation)
    {
        this->rotation = rotation;
    }

    void setScale(const glm::vec3 scale)
    {
        this->scale = scale;
        for (int i = 0; i < this->noOfVertices; i++)
        {
            vertices[i].position *= scale;
            // vertices[i].normal *= scale;
        }
    }

    void move(const glm::vec3 shiftVector)
    {
        this->position += shiftVector;
        for (int i = 0; i < this->noOfVertices; i++)
        {
            vertices[i].position += shiftVector;
            vertices[i].normal += shiftVector;
        }
    }

    void rotate(const glm::vec3 rotation)
    {
        this->rotation += rotation;
        if (this->rotation.x > 360)    
            this->rotation.x = 0;
    }

    void scaleMesh(const glm::vec3 scale)
    {
        this->scale *= scale;
        for (int i = 0; i < this->noOfVertices; i++)
        {
            vertices[i].position *= scale;
            // vertices[i].normal *= scale;
        }
    }

    virtual bool isCollideWith(Mesh& other) = 0;

    inline std::vector<Vertex> getVertices() { return vertices; }
    inline std::vector<GLuint> getIndices() { return indices; }
    // inline GLuint* getIndices() { return indices.data(); }
    // inline GLuint* getIndices() { return indices.data(); }
    inline GLuint getNoOfVertices() {return noOfVertices; }
    inline GLuint getNoOfIndices() {return noOfIndices; }
};


#endif
