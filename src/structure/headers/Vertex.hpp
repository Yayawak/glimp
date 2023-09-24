#ifndef VTX_H
#define VTX_H
#include <glm/glm.hpp>

#include <vector>

typedef struct SVertex
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 texcoord;
    glm::vec3 normal;

} Vertex;

#endif