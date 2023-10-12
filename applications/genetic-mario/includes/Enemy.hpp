#ifndef MarioEnemy_H
#define MarioEnemy_H

#include "../../superKEngine/includes/stdEngine.hpp"

class Enemy : public Cube
{
private:
    // void marioInputHandler();
    // GLFWwindow *window;
    float speedX = 0.02f;
    // float speedX = 0.0f;
public:
    Enemy();
    // void jump();
    void update();
    // void startInputHandler(GLFWwindow* window);
    virtual void moveBehavior();
};

#endif