#ifndef Mario_H 
#define Mario_H
#include "../../superKEngine/includes/stdEngine.hpp"
#include "Enemy.hpp"
#include "MarioWorld.hpp"
#include "Spawner.hpp"
#include <vector>

struct EnemyMarioData
{
    Enemy *enemy;
    float distanceFromMario;
};

class Mario : public Cube
{
private:
    GLFWwindow *window;
    float sightRadius = 8.f;
    MarioWorld *world;
    float speedX = 1.2f;

    void marioInputHandler();
public:
    Mario();
    void jump();
    void update();
    // void startInputHandler(GLFWwindow* window);
    void initialize(GLFWwindow* window, MarioWorld *world);
    // std::vector<Enemy *> findAllEnemies();
    // std::vector<Enemy *> findEnemiesInRadialSight();
    std::vector<EnemyMarioData *> findEnemiesInRadialSight();
    // Enemy *findNearestEnemy();
    EnemyMarioData *findNearestEnemy();
    void moveX(bool isLeft);
};

#endif