#include "../../src/structure/headers/stdgl.hpp"
// #include "../../src/inc/jstd.hpp"
#include "./includes/snake.hpp"
// #include "Core/TikTok.cpp"
#include "./includes/item.hpp"

#include <cmath>
#include <cstdlib>
#include <functional>
#include <sys/shm.h>
#include <unistd.h>
// #include "../../../NNGA/number_generator.hpp"
#include "/Users/rio/Desktop/glgl/NNGA/number_generator.hpp"
#include "includes/farm.hpp"
#include "includes/food.hpp"

// * global variables
// float tiksec = 1.f / 10; // default tik time
// float tiksec = 1.f / 2;  // very slow
float tiksec = 1.f / 20;
// float tiksec = 1.f / 40; // fast

// static const float dt = 0.0006;
static constexpr float dt = 0.0006;

int main()
{
    NumberGenerator<float>::initialize();
    GLFWwindow *w = setupWindow(screenWidth, screenHeight, "SNAKE GAME");
    float startTime = glfwGetTime();

    // glm::vec4 redColor = GlobalColors[red];    
    // printf("redColor: (%f,%f,%f)\n", redColor.x, redColor.y, redColor.z);

    // Item img(glm::vec4(0, 0, 0.1, 0.1), "abadon",
    // // Item img(glm::vec4(0, 0, 0.8, 0.8), "abadon",
    //     // "../../img/abadon.png");
    //     // "/Users/rio/Desktop/glgl/img/abadon.png");
    //     // "img/abadon.png");
    //     "img/ray.jpg");
        // "img/sexyboy.jpg");
        // "img/ham.jpg");
    // Food food(glm::vec4(-0.5f, -0.5f, 0.1, 0.1),

    // Item food(glm::vec4(-0.5f, -0.5f, 0.1, 0.1),
    Item food(glm::vec4(0, 0, 0.1, 0.1),
    // Item food(glm::vec4(0.0f, 0.0f, 0.1, 0.1),
        "ham",
        "/Users/rio/Desktop/glgl/img/blocks/mario-power-block.png",
        GL_RGBA
    );

    // Grid grid(6, 6);
    // Grid grid(6, 6, glm::vec3(0.8f, 0.1f, 0.1f));
    // Snake snake_1(glm::vec2(0.0, 0.0), green, 0.05, 0.008);

    // Snake snake_1(glm::vec2(0.0, 0.0), green, 0.05 / 2, 0.008);
    // FIXME : bug at coloring
    // for (int i = 0; i < 8; i++)
    // for (int i = 0; i < 14; i++)
    //     snake_1.addTail();


    // Snake snake_2(glm::vec2(1.0, 0.0), green, 0.05, 0.008);
    // for (int i = 0; i < 3; i++)
    //     snake_2.addTail();
    // food.draw();

    // Farm farm(8
    // Farm farm(32
    Farm farm(64
        // glm::vec2(10, 10)
    );

    while (!glfwWindowShouldClose(w))
    {
        float now = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // glClearColor(35.0/256, 120.0/256, 200./256, .0f);
        glClearColor(0.0f, 0.0f, .15f, .0f);

        
        farm.updateFarm(dt);

        // snake_1.update(dt);
        food.draw();
        // // snake_2.draw();
        // if (now - startTime > tiksec)
        // {
        //     snake_1.moveOneStep();
        //     // snake_2.moveOneStep();
        //     startTime = now;
        // }

        // for (int i(0); i < 3; i++)
        // {
        //     // farm.currentGeneration->population[i].inputHandler(w);
        // }
        // snake_1.inputHandler(w);
        // // snake_2.inputHandler(w);

        // img.draw();



        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    glfwTerminate();
    glfwDestroyWindow(w);
    return (0);
}