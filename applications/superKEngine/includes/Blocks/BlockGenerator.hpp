#ifndef BlockGener_H
#define BlockGener_H

#include "../Cube.hpp"

enum BlockType
{
    dirt,
    brick,
    powerGain,
    questionair
};

class BlockFactory
{
public:
    static Cube *generateBlock(BlockType blockType, glm::vec3 position = glm::vec3(0));
};

#endif