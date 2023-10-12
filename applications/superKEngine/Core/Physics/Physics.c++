// #include "../includes/Physics/Physics.hpp"
#include "./../../includes/Physics/Physics.hpp"
// #include "../../../genetic-mario/includes/Mario.hpp"

// const float g = -9.8f;
// const float g = -7.8f;
const float g = -14.8f;

Physics::Physics(Mesh *mesh)
{
    // prevTime = glfwGetTime();
    // accelarationVector.y = -0.001;
    // accelarationVector.y = -0.1;
    accelarationVector.y = g;
    // accelarationVector.y = -0.0001;
    this->mesh = mesh;
}

void Physics::simulateVelocious()
{
    float dt = glfwGetTime() - prevTime;
    prevTime = glfwGetTime();

    velocity += accelarationVector * dt;
    mesh->move(velocity * dt);
}

void Physics::update()
{
    if (!physicOn) return;

    if (isSimulateVelocious)
    {
        accelarationVector = glm::vec3(0, g, 0);
    }
    else
    {
        accelarationVector = glm::vec3(0, 0, 0);
        velocity = glm::vec3(0);
    }
    simulateVelocious();
    
    // showphys();
    // printf("cam here\n");
}

void Physics::addVelocity(glm::vec3 newVel)
{
    // isSimulateVelocious = true;
    // mesh->move(glm::vec3(0, sizeY * 0.02f, 0));
    // accelarationVector += newTonVector;
    velocity += newVel;
}

void Physics::setVelocity(glm::vec3 vel)
{
    // if (!physicOn) return;
    // if (physicOn && isSimulateVelocious)
    if (physicOn)
    {
        // if (Mario *mro = dynamic_cast<Mario *>(mesh))
        // {
        float offset = 0.01f;
        float sizeY = mesh->getScale().y;
        // mro->move(glm::vec3(0, sizeY * offset, 0));
        mesh->move(glm::vec3(0, sizeY * offset, 0));
        // }

        // mesh->move(mesh->getScale() * offset);

        this->velocity = vel;
    }
    // else
    // {
    //     this->velocity = glm::vec3(0);
    // }
}

void Physics::simulatePhysics(bool isEnable)
{
    physicOn = isEnable;
}


void Physics::showphys()
{
    printf("current velocity : ");
    vecshow(velocity, true);
    printf("\n");
}