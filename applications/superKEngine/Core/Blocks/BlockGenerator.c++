#include "../../includes/Blocks/BlockGenerator.hpp"
#include <cstdio>

Cube *BlockFactory::generateBlock(BlockType blockType, glm::vec3 position)
{
    Cube *returnBlock = new Cube(position);

    switch (blockType)
    {
        case dirt:
            returnBlock->setNewTexture("/Users/rio/Desktop/glgl/img/blocks/dirt.png");
            break;
        case brick:
            // returnBlock.setNewTexture("/Users/rio/Desktop/glgl/img/blocks/mario-brick.png");
            returnBlock->setNewTexture("/Users/rio/Desktop/glgl/img/blocks/brick.png", GL_RGBA);
            break;
        case powerGain:
            returnBlock->setNewTexture("/Users/rio/Desktop/glgl/img/blocks/mario-power-block.png", GL_RGBA);
            break;
        case questionair:
            returnBlock->setNewTexture("/Users/rio/Desktop/glgl/img/blocks/mario-question-block.png", GL_SRGB_ALPHA);
            break;
        default:
            fprintf(stderr, "No this block supported yet.\n");
            break;
    }
    return returnBlock;
}