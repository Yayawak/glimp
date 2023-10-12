#ifndef Mesh_H
#define Mesh_H
// #include "../includes/stdEngine.hpp"
#include "../../../src/structure/headers/stdgl.hpp"
// #include "Physics/Physics.hpp"
#include "glm/fwd.hpp"
#include <cassert>
#include <vector>
#include "Primitive.hpp"

struct TripleIndex
{
    GLuint a;
    GLuint b;
    GLuint c;
};


class Physics;


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

    glm::vec3 position = glm::vec3(0);
    glm::vec3 rotation = glm::vec3(0);
    glm::vec3 scale = glm::vec3(1);

    glm::mat4 ModelMatrix;

    // bool physicOn = false;
    // glm::mat4 ProjectionMatrix;
    // glm::mat4 ViewMatrix;
    // WorldCamera *camera;

    void callthisfakeconstructor(
        Vertex *vertexArray,
        const unsigned& noOfVertices,
        GLuint *indexArray,
        const unsigned& noOfIndices,
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 scale = glm::vec3(1)
    );

    // ! must be called before initVAO (must have data in vertices variable before initialization)
    void initVertexData(Vertex *vertexArray,
        const unsigned& noOfVertices,
        GLuint *indexArray,
        const unsigned& noOfIndices
    );

    void initVAO();


    void updateModelMatrix();


    void updateUniform(Shader* shader);

public:
    Physics *physics;
    // bool canMove = true;
    void setNewTexture(std::string texturePath, GLenum format = GL_RGB);
    inline Mesh() {}
    // inline Mesh() { printf("This is base naked constructor of Mesh class.\n"); }
    Mesh(
        Primitive *primitive,
        const char *texturePath
    );

    Mesh(
        Primitive *primitive,
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 scale = glm::vec3(1)
    );

    Mesh(
        Vertex *vertexArray,
        const unsigned& noOfVertices,
        GLuint *indexArray,
        const unsigned& noOfIndices,
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 scale = glm::vec3(1)
    );

    ~Mesh();


    void render(Shader* shader);
    // virtual void update() = 0;
    virtual void update();

    void setPosition(const glm::vec3 pos);

    void setRotation(const glm::vec3 rotation);

    void setScale(const glm::vec3 scale);

    void move(const glm::vec3 shiftVector);

    void rotate(const glm::vec3 rotation);

    void scaleMesh(const glm::vec3 scale);

    // void setColor()
    // {
    //     for (size_t i = 0; i < this->noOfVertices; i++)
    //     {
    //         printf("vertice %lu\n", i);
    //         vertices[i].color = glm::vec3(1);
    //     }
    // }

    virtual bool isCollideWith(Mesh& other) = 0;

    inline std::vector<Vertex> getVertices() { return vertices; }
    inline std::vector<GLuint> getIndices() { return indices; }
    // inline GLuint* getIndices() { return indices.data(); }
    // inline GLuint* getIndices() { return indices.data(); }
    inline GLuint getNoOfVertices() {return noOfVertices; }
    inline GLuint getNoOfIndices() {return noOfIndices; }

    inline glm::vec3 getPosition() { return position; }
    inline glm::vec3 getRotation() { return rotation; }
    inline glm::vec3 getScale() { return scale; }
    // inline void setCameraFromWorld(WorldCamera *worldCamera ) { this->camera = worldCamera;}

    void meshShow();

    // void enabePhysic(bool enable);
};

#include "Physics/Physics.hpp"

#endif
