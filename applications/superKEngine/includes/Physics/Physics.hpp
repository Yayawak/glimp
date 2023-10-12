#ifndef Physics_H
#define Physics_H

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Mesh;

class Physics
{
private:
    Mesh *mesh;
    glm::vec3 velocity = glm::vec3(0);
    float prevTime = glfwGetTime();;
    glm::vec3 accelarationVector = glm::vec3(0.0f);
    bool physicOn = false;
    void simulateVelocious();
public:
    Physics(Mesh *mesh);
    void update();
    // void addForce(glm::vec3 newTonVector);
    void addVelocity(glm::vec3 newVel);
    void simulatePhysics(bool isEnable);
    // void resetVelocityAndAcceleration(bool isDisable = true);
    bool isSimulateVelocious = true;
    void showphys();
    void setVelocity(glm::vec3 vel);
    inline glm::vec3 getVelocity() { return velocity; }
};

#include "../Mesh.hpp"

#endif