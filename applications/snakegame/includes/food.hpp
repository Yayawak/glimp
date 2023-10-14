#pragma once

#include "../../../src/structure/headers/stdgl.hpp"
#include <glm/glm.hpp>
#include "../includes/item.hpp"
// const 

class Food : public Item
{
    // glm::vec4 rect
    // Food(glm::vec2 pos, glm::vec2)
public:
    Food(glm::vec4 rect, std::string imageName, std::string _pathToImage)
        : Item(glm::vec4(rect.x, rect.y, rect.z, rect.w),
            imageName,
            _pathToImage
        )
    {
    }
};