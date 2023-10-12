// #include "../../includes/Cube.hpp"
// #include "../../includes/stdEngine.hpp"
// #include "../../../../src/structure/headers/stdgl.hpp"
// #include <vector>
#include "../includes/Cube.hpp"
#include "glm/common.hpp"

/*
       Z
       ^
       | 
       |
      / ---> X
     /
   Y

       1 ---- 2
      /      /|
     /     /  |
    5 ---- 6  |
    |      |  | 
    |  3   |  4
    |      | /
    7 ---- 8
*/

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

Cube::Cube( glm::vec3 position)
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
        glm::vec3(-1.0f,  1.0f,  1.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(0.0f, 1.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
        // C
        glm::vec3( 1.0f,  1.0f,  1.f),       glm::vec3(1.f, 0.f, 0.f),     glm::vec2(1.0f, 1.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
        // D
        glm::vec3( 1.0f, -1.0f,  1.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(1.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),

        // E
        glm::vec3(-1.0f, -1.0f, -1.f),       glm::vec3(1.f, 0.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
        // G
        glm::vec3(-1.0f,  1.0f, -1.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(0.0f, 1.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
        // H
        glm::vec3( 1.0f,  1.0f, -1.f),       glm::vec3(1.f, 0.f, 0.f),     glm::vec2(1.0f, 1.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
        // F
        glm::vec3( 1.0f, -1.0f, -1.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(1.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
    };

    for (int i = 0; i < 8; i++)
    {
        vertices[i].color = glm::vec3(1, 1, 1);
    }

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
    // colorWhitener()
    // for (int i = 0; i < this->vertices.size(); i++)
    // {
    //     this->vertices[i].color = glm::vec3(1);
    // }
}

// static bool inRange(float min, float max, float val)
static bool inRange(glm::vec2 range, float val)
{
    return (range.x <= val && val <= range.y);
    // return (min <= val && val <= max);
}

// bool isIn

bool Cube::isCollideWith(Mesh& other)
{
    // if(NewType* v = dynamic_cast<NewType*>(old)) {
    if (Cube* that = dynamic_cast<Cube *>(&other))
    // if (auto other = dynamic_cast<Cube &>(other))
    {
        // printf("scale vector of A | B : \t");
        // vecshow(this->scale, false);
        // vecshow(that->scale);

        glm::vec2 leftRight = glm::vec2(position.x - scale.x, position.x + scale.x);
        glm::vec2 botTop = glm::vec2(position.y - scale.y, position.y + scale.y);
        glm::vec2 backFront = glm::vec2(position.z - scale.z, position.z + scale.z);

        // glm::vec3 thislowerVec = position - scale;
        // glm::vec3 thisupperVec = position + scale;
        // glm::vec3 thatlowerVec = that->position - that->scale;
        // glm::vec3 thatupperVec = that->position + that->scale;
        
        // this->meshShow();
        // that->meshShow();
        // printf("lr [%f, %f]: ", leftRight.x, leftRight.y);
        // printf("\n\n");
        
        // glm::clamp()
        if (   
            // leftRight.x <= that->position.x 
            // && that->position.x <= leftRight.y
            // && botTop.y <= that->position.y <= leftRight.y
            // && backFront.x <= that->position.z <= backFront.y
            (
                inRange(leftRight, that->position.x - that->scale.x)
                || inRange(leftRight, that->position.x + that->scale.x)
            )
            &&
            (
                inRange(botTop, that->position.y - that->scale.y)
                || inRange(botTop, that->position.y + that->scale.y)
            )
            &&
            (
                inRange(backFront, that->position.z - that->scale.z)
                || inRange(backFront, that->position.z + that->scale.z)
            )
        )
        {
            // * B is in A
            return true;
        }
        return false;
        // for (this->scale.x)
        // printf("Cube is detected with a cube\n");
        // printf()
    }
    // printf("\n");

    return false;
}

// void Cube::scaleMesh(const glm::vec3 scale)
// {
//     Mesh::scaleMesh(scale);
//     this->halfSizeAspectVector = scale / 2.f;
// }

void Cube::update()
{
    Mesh::update();
}