#ifndef __World_H
#define __World_H

#include "TerrainGenerator.hpp"
#include "Terrrain.hpp"
#include "stdEngine.hpp"
#include <vector>
#include "inputManager.hpp"
#include <unistd.h>




struct WObjectData
{
    Mesh *meshObject;
    bool isInteractable;
    std::string name;

    WObjectData(Mesh *meshObject, bool isInteractable, std::string name)
    {
        this->meshObject = meshObject;
        this->isInteractable = isInteractable;
        this->name = name;
    }
};

class World
{
private:

    GLFWwindow *window;
    Shader *shader;
    static World* instance;
    // std::vector<WObjectData> worldObjects;

    // World(World &other) = delete;
    // void operator=(const World &) = delete;

    World();

    void gameLoop();

    ~World();

public:
    std::vector<WObjectData> worldObjects;

    static World* getInstance();

    void addMeshObject(Mesh* mesh, bool isInteractable, std::string name);

    void initialize();

    void render();

    void collisionManager();
    // inline GLFWwindow* getWindowOfWorld() { return window; }
    // inline void setGameLoopThreadPtr(std::thread *threadPtr) { gameLoopThread = threadPtr; }
    // inline std::thread* getGameLoopThreadPtr() { return gameLoopThread; }
    // void collision
    // inline *std::vector<WObjectData> getWObjectData() { return }
    // inline std::vector<WObjectData> getWObjectData() { return worldObjects; }
    // std::vector<WObjectData> *getWObjectData();
    void visulizeWorldGameObjects(bool enable);
};

// World* World::instance = NULL;

struct NodeAndDistance
{
    WObjectData *neighborNode;
    float distFromPivotToNeighbor;
};
struct VizNodeData
{
    WObjectData *wobj;
    std::vector<NodeAndDistance> nodedistances;
};

#endif