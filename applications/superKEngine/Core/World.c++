#include "../includes/World.hpp"
#include "../includes/WorldGameObjectVisualizer.hpp"
#include <cassert>
#include <vector>

// World* World::instance = NULL;
// World* instance = NULL;
// instance = NULL;
// World* instance = NULL;

World* World::instance = new World();

World::World()
{
    initialize();
    assert(window != 0);

    // auto map = TerrainGenerator::generateTerrain(20, 10);
    // TerrainGenerator::showMatrix(map);

    sleep(1);
    printf("--------------------------------------- start doing game loop ---------------------------------------\n");

    Cube cubeMesh;
    cubeMesh.setScale(glm::vec3(0.02f));
    // cubeMesh.move(glm::vec3(0, 0, -3));

    // Terrain terr(5, 3);
    // Terrain terr(40, 20);
    // Terrain terr(5, 8);
    Terrain terr(14, 8);
    terr.rotate(glm::vec3(-90, 0, 0));
    terr.setPosition(glm::vec3(-1.4, -1.4, 0));

    Sphere sphere(glm::vec3(0), 0.3);
    sphere.move(glm::vec3(0, 0, -4));
    Sphere s2(glm::vec3(0.1, 0, 0), 0.1);
// 
    // World::getInstance()->addMeshObject(&cubeMesh);
    addMeshObject(&cubeMesh, false, "c0");
    addMeshObject(&sphere, true, "s0");
    addMeshObject(&s2, false, "s1");

    addMeshObject(&terr, false, "terrain0");

    Cube dirt;
    // dirt.setNewTexture("/Users/rio/Desktop/glgl/img/abadon.png");
    dirt.setNewTexture("img/blocks/dirt.png");
    addMeshObject(&dirt, true, "dirt");
    // // terr.move(glm::vec3(-1.f, -1.f, 0.f));
    // visulizeWorldGameObjects(true);

    // WorldViz::visualizeObjectsInWorld();
    // dirt.colorWhitener();

    gameLoop();
}

World* World::getInstance()
{
    // if (instance == NULL)
    // {
    //     printf("Created Only One World\n");
    //     instance = new World();
    // }
    return instance;
}

void World::gameLoop()
{
    // GLFWwindow* window = World::getInstance()->getWindowOfWorld();
    while (!glfwWindowShouldClose(window))
    {
        // glClearColor(.07f, .03f, .15f, 1.0f); // dark blue
        glClearColor(35/255.f, 115/255.f, 200/255.f, 1.f); // vivid blue
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        // visulizeWorldGameObjects(true);
        render();

        // collisionManager();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

World::~World()
{
    glfwTerminate();
    glfwDestroyWindow(window);
}

void World::addMeshObject(Mesh* mesh, bool isInteractable, std::string name)
{
    printf("Added mesh[%s] object to World wrapper\n", name.c_str());
    worldObjects.push_back(WObjectData(mesh, isInteractable, name));
}

void World::initialize()
{
    printf("--------------------------------------- start initialized game ---------------------------------------\n");
    std::cout << "Welcome to KEngine Open World !\n";
    window = setupWindow(screenWidth, screenHeight, "World Void");
    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    shader = new Shader(
        "/Users/rio/Desktop/glgl/applications/superKEngine/Shaders/default.vert",
        "/Users/rio/Desktop/glgl/applications/superKEngine/Shaders/default.frag"
    );
}

void World::render()
{
    // printf("rendering a mesh.\n");
    // float x = 0.8 * sin(glfwGetTime());
    float x = 1.5 * sin(glfwGetTime());
    // printf("xlight = %f\n", x);
    shader->setVec3fv(
        glm::vec3(-x, 0.3, 0),
        "lightPos");
        
    for (int mi = 0; mi < worldObjects.size(); mi++)
    {
        WObjectData cur = worldObjects[mi];
        cur.meshObject->render(shader);

        // meshObects[mi]->render(shader);
        if (cur.name.compare("c0") == 0)
        {
            cur.meshObject->move(glm::vec3(0.05 / 4 * sin(glfwGetTime()), 0, 0));
        }
        if (cur.isInteractable)
        {
            updateInput(window, *cur.meshObject);
        }
        // if (cur.name.compare("terrain0") == 0)
        // {
        //     printf("redrawing terrain\n");
        //     Terrain *t = (Terrain *)(cur.meshObject);
        //     t->redraw();
        // }
    }
}

void World::collisionManager()
{
    for (int mi = 0; mi < worldObjects.size(); mi++)
    {
        for (int mj = mi + 1; mj < worldObjects.size(); mj++) // it's good but can used with cube (becuz i'm not implemented cube collide detection yet)
        {
            Mesh *first = worldObjects[mi].meshObject;
            Mesh *second = worldObjects[mj].meshObject;
            // if (sphere.isCollideWith(cubeMesh))
            if (first->isCollideWith(*second))
            {
                glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
                // printf("mesh collision detected\n");
            }
            else
            {
                // printf("not collided\n");
                glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
            }
        }
    }
}

void World::visulizeWorldGameObjects(bool enable = true)
{

    std::vector<VizNodeData> vizNodeDatas;
    // create graph 
    for (size_t i = 0; i < worldObjects.size(); i++)
    {
        VizNodeData vizNode;

        WObjectData pivot = worldObjects[i];
        vizNode.wobj = &pivot;
        for (size_t j = 0; j < worldObjects.size(); j++)
        {
            if (i == j) continue;
            WObjectData sub = worldObjects[j];
            float dist = glm::distance(pivot.meshObject->getPosition(), sub.meshObject->getPosition());


            NodeAndDistance nodeAndDist;
            nodeAndDist.neighborNode = &sub;
            nodeAndDist.distFromPivotToNeighbor = dist;

            vizNode.nodedistances.push_back(nodeAndDist);

            // vizNode.nodedistances.push_back(const_reference __x)
            // vizNode.nodedistances = dist;
            // node.dist = dist;
            // nodes.push_back(node);
        }
        vizNodeDatas.push_back(vizNode);
    }

    for (size_t i = 0; i < vizNodeDatas.size(); i++)
    {
        VizNodeData viz = vizNodeDatas[i];
        // obj.
        printf("[%lu:%s]\n", i, viz.wobj->name.c_str());
        // for (size_t j = i + 1; j < viz.nodedistances.size(); j++)
        for (size_t j = 0; j < viz.nodedistances.size(); j++)
        {
            NodeAndDistance neighborData = viz.nodedistances[j];
            float dist = neighborData.distFromPivotToNeighbor;
            WObjectData *nb = neighborData.neighborNode;
            // nb->name.c_str();

            printf("\tnb[%lu, %s], dist[%f]\n", j, nb->name.c_str(), dist);
        }
        printf("\n");
    }
    printf("\n");
    
}

// std::vector<WObjectData> *World::getWObjectData() 
// {
//     return worldObjects;
// }

    // inline GLFWwindow* getWindowOfWorld() { return window; }
    // inline void setGameLoopThreadPtr(std::thread *threadPtr) { gameLoopThread = threadPtr; }
    // inline std::thread* getGameLoopThreadPtr() { return gameLoopThread; }
    // void collision
    // inline *std::vector<WObjectData> getWObjectData() { return }

