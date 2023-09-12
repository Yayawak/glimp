#include "../../src/structure/headers/stdgl.hpp"
// #include "../../src/inc/jstd.hpp"
#include "./includes/snake.hpp"
#include "Core/TikTok.cpp"
#include <cmath>
#include <cstdlib>
#include <functional>
#include <sys/shm.h>


// * global variables
float tiksec = 1.f / 10;

int main(void)
{
    // ket_t key;
    // shmget()
    GLFWwindow *w = setupWindow(screenWidth, screenHeight, "SNAKE GAME");

    // glm::vec4 redColor = GlobalColors[red];    
    // printf("redColor: (%f,%f,%f)\n", redColor.x, redColor.y, redColor.z);

    // TikTok tiktok;

    // tiktok.registerFn()
    // Grid grid(6, 6);
    // Grid grid(6, 6, glm::vec3(0.8f, 0.1f, 0.1f));
    Snake snake_1(glm::vec2(0.0, 0.0), green, 0.05, 0.008);
    // FIXME : bug at coloring
    for (int i = 0; i < 8; i++)
        snake_1.addTail();
    // tiktok.registerFn([]() {

    // };
    // );
    // Panel *panel = new Panel()
    float startTime = glfwGetTime();
    while (!glfwWindowShouldClose(w))
    {
        float now = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // glClearColor(35.0/256, 120.0/256, 200./256, .0f);
        glClearColor(0.0f, 0.0f, .15f, .0f);

        // grid.drawGrid(-0.9, 0.9, 0.1, 0.1);
        snake_1.draw();
        if (now - startTime > tiksec)
        {
            snake_1.moveOneStep();
            
            // if (random() > 0.5f)
            //     snake_1.addTail();

            startTime = now;
        }

        snake_1.inputHandler(w);

        // if (glfwGetKey(w, GLFW_KEY_lef))

        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    glfwTerminate();
    glfwDestroyWindow(w);
    return (0);
}