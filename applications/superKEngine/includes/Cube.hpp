#ifndef Cube_H
#define Cube_H

#include "../../../src/structure/headers/stdgl.hpp"
#include "Primitive.hpp"
#include "Mesh.hpp"
#include <cassert>
#include <cstdio>

// static unsigned alphabetToIndex(char c)
// static unsigned a2i(char c)
static unsigned ai(char c)
{
    assert(c >= 'a' && c <= 'h');

    switch (c) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'g':
            return 5;
        case 'h':
            return 6;
        case 'f':
            return 7;
        default:
            fprintf(stderr, "Error unknowk alphabet between a to h\n");
            return -1;
    }
}

class Cube : public Mesh
{
private:
    glm::vec3 sizeEachAspect;
public:
    Cube(
        glm::vec3 position = glm::vec3(0)
        // glm::vec3 rotation = glm::vec3(0),
        // glm::vec3 scale = glm::vec3(1)
    )
        : Mesh()
    {
        this->position = position;
        // this->rotation = glm::vec3(0);
        // this->scale = glm::vec3(1);
        Vertex vertices[] =
        {
            // posotion, color, texcoords, normal
            // A
            glm::vec3(-1.0f, -1.0f,  1.f),       glm::vec3(1.f, 0.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
            // B
            glm::vec3(-1.0f,  1.0f,  1.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(5.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
            // C
            glm::vec3( 1.0f,  1.0f,  1.f),       glm::vec3(1.f, 0.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
            // D
            glm::vec3( 1.0f, -1.0f,  1.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(0.0f, 5.0f),        glm::vec3(0.0f, 0.0f, 0.0f),

            // E
            glm::vec3(-1.0f, -1.0f, -1.f),       glm::vec3(1.f, 0.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
            // G
            glm::vec3(-1.0f,  1.0f, -1.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(5.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
            // H
            glm::vec3( 1.0f,  1.0f, -1.f),       glm::vec3(1.f, 0.f, 0.f),     glm::vec2(5.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
            // F
            glm::vec3( 1.0f, -1.0f, -1.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(10.0f, 5.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
        };
        unsigned noOfV = sizeof(vertices) / sizeof(Vertex);
        GLuint indices[] = 
        {
            ai('b'), ai('a'), ai('d'),
            ai('b'), ai('c'), ai('d'),

            ai('a'), ai('b'), ai('g'),
            ai('a'), ai('e'), ai('g'),

            ai('d'), ai('c'), ai('h'),
            ai('d'), ai('f'), ai('h'),

            ai('c'), ai('b'), ai('g'),
            ai('c'), ai('h'), ai('g'),

            ai('d'), ai('a'), ai('e'),
            ai('d'), ai('f'), ai('e'),

            ai('f'), ai('e'), ai('g'),
            ai('f'), ai('h'), ai('g'),

            // 0,3,2,1,
            // 2,3,7,6,
            // 0,4,7,3,
            // 1,2,6,5,
            // 4,5,6,7,
            // 0,1,5,4,
            

        };
        unsigned noOfI = sizeof(indices) / sizeof(GLuint);

        // set(vertices, noOfV, indices, noOfI);
        callthisfakeconstructor(vertices, noOfV, indices, noOfI);
    }

    bool isCollideWith(Mesh& other)
    {
        return false;
    }
};

#endif