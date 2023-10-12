#include "../includes/Spawner.hpp"

static float startTime = glfwGetTime();

Spawner::Spawner(glm::vec3 position, MarioWorld *marioWorld)
{
    this->position = position;
    this->marioWorld = marioWorld;
}

void Spawner::addEnemyToPool(Enemy *enemy, std::string name)
{
    EnemyData *ed;
    ed->enemy = enemy;
    ed->name = name;
    pool.push_back(ed);
    printf("Added enemy to pool.\n");
}

void Spawner::update()
{
    float dt = glfwGetTime() - startTime;
    
    if (dt >= tickInterval)
    {
        spawnEnemyEveryUnitSeconds();
        startTime = glfwGetTime();
    }

}

void Spawner::spawnEnemyEveryUnitSeconds()
{
    if (pool.empty()) return;
    // vector v{10,21,24,13};
    // int random = rand() % v.size();
    // int sel_elem = v[random];
    int random = rand() % pool.size();
    marioWorld->addMeshObject(
        pool[random]->enemy,
        false,
        pool[random]->name
    );
}
// void Spawner::setPosition(glm::vec3 position)