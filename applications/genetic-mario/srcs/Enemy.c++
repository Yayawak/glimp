#include "../includes/Enemy.hpp"
#include <cassert>
#include <cstdint>
#include <cstdlib>


Enemy::Enemy()
{
    
    // setPosition();
    setNewTexture("/Users/rio/Desktop/glgl/img/characters/goomba.png", GL_RGB);
    // physics->simulatePhysics(true);
}

void Enemy::update()
{
    Cube::update();

    // float now = glfwGetTime();
    // float dt = now - marioStartLifeTime;
    // // printf("dt %f\n", dt);
    // if (dt > 2)
    // {
    //     // jump();
    //     marioStartLifeTime = now;
    // }
    moveBehavior();
}

void Enemy::moveBehavior()
{
    // Mesh::move(const glm::vec3 shiftVector)
    move(glm::vec3(-speedX, 0, 0));
}