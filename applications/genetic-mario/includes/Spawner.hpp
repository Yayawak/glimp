#ifndef Spawner_H
#define Spawner_H

#include <glm/glm.hpp>
#include <vector>
#include "Enemy.hpp"
#include "MarioWorld.hpp"

struct EnemyData
{
    Enemy *enemy;
    std::string name;
};

class Spawner
{
    std::vector<EnemyData *> pool;
    glm::vec3 position;
    float tickInterval = 3.f;
    MarioWorld *marioWorld;
public:
    Spawner(glm::vec3 position, MarioWorld *marioWorld);

    void addEnemyToPool(Enemy *enemy, std::string name);

    void update();
    void spawnEnemyEveryUnitSeconds();
};

#endif