#ifndef Cube_H
#define Cube_H

#include "../../../src/structure/headers/stdgl.hpp"
#include "Primitive.hpp"
#include "Mesh.hpp"
#include <cassert>
#include <cstdio>


class Cube : public Mesh
{
private:

public:
    // glm::vec3 sizeEachAspect = glm::vec3(2) / 2.f;
    // glm::vec3 halfSizeAspectVector = glm::vec3(2) / 2.f;
    // glm::vec3 halfSizeAspectVector = glm::vec3(2.f) / 2.f;

    Cube( glm::vec3 position = glm::vec3(0));
    bool isCollideWith(Mesh& other);
    void scaleMesh(const glm::vec3 scale);
    void update();
};

#endif