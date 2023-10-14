#include "../includes/MarioWorld.hpp"
#include "../includes/Mario.hpp"
#include "../includes/Enemy.hpp"
#include "glm/ext/quaternion_geometric.hpp"
#include <iterator>

MarioWorld::MarioWorld()
{

}

void MarioWorld::collisionManager()
{
    for (int mi = 0; mi < worldObjects.size(); mi++)
    {
        // for (int mj = mi + 1; mj < worldObjects.size(); mj++) // it's good but can used with cube (becuz i'm not implemented cube collide detection yet)
        for (int mj = 0; mj < worldObjects.size(); mj++) // it's good but can used with cube (becuz i'm not implemented cube collide detection yet)
        {
            if (mi == mj) continue;
            Mesh *first = worldObjects[mi].meshObject;
            Mesh *second = worldObjects[mj].meshObject;
            if (first->isCollideWith(*second))
            {
                // printf("[ %s & %s ]\n\n\n", worldObjects[mi].name.c_str(), worldObjects[mj].name.c_str());
                // * used this
                second->physics->setVelocity(glm::vec3(0));

                // second->physics->isSimulateVelocious = false;
                // float bounceAmplitude = 8.f;
                // // float bounceAmplitude = 5.f;
                // // float bounceAmplitude = 3.5f;
                // second->physics->setVelocity(-bounceAmplitude * glm::normalize(second->physics->getVelocity()));
                // second->physics->setVelocity(glm::vec3(0));
                // printf("mesh collision detected\n");

                Mario *mro = dynamic_cast<Mario *>(first);
                Enemy *enm = dynamic_cast<Enemy *>(second);
                if (mro && enm)
                {
                    // gameover();
                    // worldObjects.erase(mj);
                    // std::consti
                    // worldObjects.remove
                    // auto k =worldObjects.at(mj);
                    std::vector<WObjectData>::iterator it = worldObjects.begin();
                    it += mj;
                    // worldObjects.erase(it);
                }
            }
            else
            {
                // second->physics->isSimulateVelocious = true;
                // first->physics->isSimulateVelocious = true;
                // printf("not collided\n");
            }
        }
    }
}


void MarioWorld::gameover()
{
    printf("GAME OVER\n");
    isWorldEnd = true;
}