#include "../includes/World.hpp"
#include "../includes/WorldGameObjectVisualizer.hpp"
#include "../includes/WorldCamera.hpp"
#include <cassert>
#include <functional>
#include <thread>
#include <vector>
#include <future>

World::World()
{
    initialize();
    assert(window != 0);
    printf("--------------------------------------- start doing game loop ---------------------------------------\n");
}

void World::initialize()
{
    printf("--------------------------------------- start initialized game ---------------------------------------\n");
    std::cout << "Welcome to Open World !\n";
    window = setupWindow(screenWidth, screenHeight, "World Void");
    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    shader = new Shader(
        "/Users/rio/Desktop/glgl/applications/superKEngine/Shaders/default.vert",
        "/Users/rio/Desktop/glgl/applications/superKEngine/Shaders/default.frag"
    );

    camera = new WorldCamera(screenWidth, screenHeight, 
        glm::vec3(0, 0, 10),
        window,
        shader);
    assert(camera);
}


void World::gameLoop()
{
    assert(window != NULL);
    while (!glfwWindowShouldClose(window) && !isWorldEnd)
    // while (glfwWindowShouldClose(window) != -1)
    // while (true)
    {
        // glClearColor(35/255.f, 115/255.f, 200/255.f, 1.f); // vivid blue
        // glClearColor(128/255.f, 203/255.f, 196/255.f, 1.f); // green lime
        // glClearColor(14/255.f, 148/255.f, 152/255.f, 1.f); // green some
        glClearColor(148/255.f, 152/255.f, 0/255.f, 1.f); // เขียวขี้ม้า
        // glClearColor(148/255.f, 147/255.f, 233/255.f, 1.f); // licac
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        camera->updateUniform();
        // glm::vec3 camNewPos = camera->getPosition() + glm::vec3(0.01, 0, 0);
        // camera->setPosition(camNewPos);
        // visulizeWorldGameObjects(true);
        render();

        collisionManager();
        // printf("A");

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    delete this;
}

World::~World()
{
    glfwTerminate();
    glfwDestroyWindow(window);
}

void World::addMeshObject(Mesh* mesh, bool isInteractable, std::string name)
{
    printf("Added mesh[%s] object to World wrapper\n", name.c_str());
    // mesh->setCameraFromWorld(camera);
    worldObjects.push_back(WObjectData(mesh, isInteractable, name));
}

void World::render()
{
    // printf("rendering a mesh.\n"); // float x = 0.8 * sin(glfwGetTime());
    float x = 1.5 * sin(glfwGetTime());
    // printf("xlight = %f\n", x);
    shader->setVec3fv(
        glm::vec3(-x, 0.3, 0),
        "lightPos");
        
    for (int mi = 0; mi < worldObjects.size(); mi++)
    {
        WObjectData cur = worldObjects[mi];
        // cur.meshObject->update();
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
    // printf("size of world objects is %lu\n", worldObjects.size());
    for (int mi = 0; mi < worldObjects.size(); mi++)
    {
        // for (int mj = mi + 1; mj < worldObjects.size(); mj++) // it's good but can used with cube (becuz i'm not implemented cube collide detection yet)
        for (int mj = 0; mj < worldObjects.size(); mj++) // it's good but can used with cube (becuz i'm not implemented cube collide detection yet)
        {
            if (mi == mj) continue;
            Mesh *first = worldObjects[mi].meshObject;
            Mesh *second = worldObjects[mj].meshObject;
            // if (sphere.isCollideWith(cubeMesh))
            if (first->isCollideWith(*second))
            {
                // printf("[ %s & %s ]\n\n\n", worldObjects[mi].name.c_str(), worldObjects[mj].name.c_str());
                // first->physics->isSimulateVelocious = 0;
                // second->physics->isSimulateVelocious = 0;
                second->physics->setVelocity(glm::vec3(0));
                // first->physics->setVelocity(glm::vec3(0));
                // ? too much global
                // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
                // printf("mesh collision detected\n");

            }
            else
            {
                // printf("not collided\n");
                // glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
                // first->physics->isSimulateVelocious = 1;
                // second->physics->isSimulateVelocious = 1;
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