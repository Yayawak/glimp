// #include "../superKEngine/includes/World.hpp"
#include "../superKEngine/includes/Blocks/BlockGenerator.hpp"
#include <cstdint>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include "includes/Enemy.hpp"
#include "includes/Mario.hpp"
#include "includes/MarioWorld.hpp"

static MarioWorld *world = new MarioWorld();

int main(void)
{
    Cube *dirt = BlockFactory::generateBlock(BlockType::dirt);
    Cube *brick = BlockFactory::generateBlock(BlockType::brick);
    Cube *powerBlock = BlockFactory::generateBlock(BlockType::powerGain);
    Cube *questionBlock = BlockFactory::generateBlock(BlockType::questionair);

    Mario *mario = new Mario();
    mario->initialize(world->getWindowOfWorld(), world);

    // Enemy *goomba = new Enemy(glm::vec3(2, 2, 0));
    Enemy *goomba = new Enemy();
    goomba->setPosition(glm::vec3(4, 3, 0));
    // goomba->setPosition(glm::vec3(4, 1, 0));

    std::vector<Cube *> bricks;
    for (int i = 0; i < 8; i++)
    {
        Cube *b = BlockFactory::generateBlock(BlockType::brick);
        bricks.push_back(b);
        b->setPosition(glm::vec3(-8, -3, 0));
        b->move(glm::vec3(2 * i, 0, 0));
        std::string name = std::string("brick ").append(std::to_string(i));
        world->addMeshObject(b, false, name);
    }

    dirt->setPosition(glm::vec3(-2.0f, 0.0f, 0.0f));
    brick->setPosition(glm::vec3(1.0f, 0.0f, 0.0f));
    mario->move(glm::vec3(0, 4, 0));

    // powerBlock.setPosition(glm::vec3(2.0f, 0.0f, 0.0f));
    // questionBlock.setPosition(glm::vec3(4.0f, 0.0f, 0.0f));

    // world->addMeshObject(dirt, false, "dirt 00");
    world->addMeshObject(brick, false, "brick 00");
    world->addMeshObject(mario, true, "mario mainer");
    world->addMeshObject(goomba, false, "goomba");

    // world->addMeshObject(&powerBlock, true, "powerBlock 00");
    // world->addMeshObject(&questionBlock, true, "quesionBlock 00");


    world->gameLoop();
    // EventLoop
    return (0);
}