#ifndef Quad_H
#define Quad_H

#include "../../../src/structure/headers/stdgl.hpp"
#include "Primitive.hpp"

class Quad : public Primitive
{
public:
    Quad(
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 scale = glm::vec3(1)
    )
        : Primitive()
    {
        Vertex vertices[] =
        {
            // posotion, color, texcoords, normal
            glm::vec3(-0.5f,  0.5f, 0.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(-0.5f, -0.5f, 0.f),       glm::vec3(0.f, 1.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3( 0.5f, -0.5f, 0.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3( 0.5f,  0.5f, 0.f),       glm::vec3(0.f, 1.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
        };
        unsigned noOfV = sizeof(vertices) / sizeof(Vertex);
        GLuint indices[] = 
        {
            0, 1, 2,
            0, 2, 3,
        };
        unsigned noOfI = sizeof(indices) / sizeof(GLuint);

        set(vertices, noOfV, indices, noOfI);
    }
private:
};

#endif