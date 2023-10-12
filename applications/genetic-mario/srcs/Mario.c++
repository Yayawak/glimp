#include "../includes/Mario.hpp"
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <vector>

static float marioStartLifeTime = glfwGetTime();
// static float val = 4;

Mario::Mario()
{
    // setPosition();
    setNewTexture("/Users/rio/Desktop/glgl/img/characters/mario.png", GL_RGBA);
    physics->simulatePhysics(true);
}

void Mario::jump()
{
    // printf("jumping\n");
    // val = (float)std::rand() / INTMAX_MAX;
    // printf("jumping with force %f\n", val);
    // physics->isSimulateVelocious = true;
    // physics->addVelocity(glm::vec3(
    //     0,
    //     // 0.0001,
    //     5,
    //     // 100,
    //     // val,
    //     0
    // ));
    physics->setVelocity(glm::vec3(0, 7, 0));
    // world->getWindowOfWorld()
}

void Mario::update()
{
    Cube::update();

    float now = glfwGetTime();
    float dt = now - marioStartLifeTime;
    // printf("dt %f\n", dt);
    if (dt > 2)
    {
        // jump();
        marioStartLifeTime = now;
    }

    marioInputHandler();

    EnemyMarioData *nearestEnemyData = findNearestEnemy();
    if (nearestEnemyData)
    {
        printf("nearest enemy distance : %f\n", nearestEnemyData->distanceFromMario);
    }
}

void Mario::marioInputHandler()
{
    assert(window != NULL);
    if (glfwGetKey(window, GLFW_KEY_SPACE))
    {
        jump();
    }
}

void Mario::initialize(GLFWwindow* window, MarioWorld *world)
// void Mario::startInputHandler(GLFWwindow* window)
{
    this->window = window;
    this->world = world;
}

std::vector<EnemyMarioData *> Mario::findEnemiesInRadialSight()
{
    std::vector<EnemyMarioData *> enemiesInSight;
    for (int i = 0; i < this->world->worldObjects.size(); i++)
    {
        WObjectData *currentWObj = &world->worldObjects[i];
        if (Enemy *e = dynamic_cast<Enemy *>(currentWObj->meshObject))
        {
            float dist = glm::distance(e->getPosition(), this->getPosition());
            if (dist <= sightRadius)
            {
                // printf("Enter here\n");
                EnemyMarioData *emd = new EnemyMarioData();
                emd->distanceFromMario = dist;
                emd->enemy = e;
                enemiesInSight.push_back(emd);
            }
        }
    }
    return enemiesInSight;
}

EnemyMarioData *Mario::findNearestEnemy()
{
    std::vector<EnemyMarioData *> enemyInSight = this->findEnemiesInRadialSight();
    if (enemyInSight.empty()) return 0;
    // printf("enemy in sight size is %lu\n", enemyInSight.size());
    // if (en)
    float minDist = 999.f;
    // Enemy *nearestEnemy = 0;
    EnemyMarioData *nearest = 0;
    for (int i = 0; i < enemyInSight.size(); i++)
    {
        // float dist = glm::distance(enemyInSight[i]->getPosition(), this->getPosition());
        // if (dist < minDist)
        // {
        //     minDist = dist;
        //     nearestEnemy = enemyInSight[i];
        // }
        if (enemyInSight[i]->distanceFromMario < minDist)
        {
            minDist = enemyInSight[i]->distanceFromMario;
            // nearestEnemy = enemyInSight[i]->enemy;
            nearest = enemyInSight[i];
        }
    }
    // EnemyMarioData *emd = new EnemyMarioData();
    // emd->distanceFromMario = minDist;
    // emd->enemy = nearestEnemy;
    return (nearest);
}

void Mario::moveX(bool isLeft)
{
    glm::vec3 rightVec = speedX * glm::vec3(1, 0, 0);
    if (isLeft)
    {
        move(-rightVec);
    }
    else
    {
        move(rightVec);
    }
}