#ifndef MarioWorld_H
#define MarioWorld_H
#include "../../superKEngine/includes/World.hpp"

class MarioWorld : public World
{
public:
    MarioWorld();
    void collisionManager(); // override
    void gameover();
};

#endif