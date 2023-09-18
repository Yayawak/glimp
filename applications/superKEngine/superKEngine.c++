#include "./includes/stdEngine.hpp"
#include "includes/Plane.hpp"
#include <unistd.h>

int main(void)
{
    printf("--------------------------------------- start initialized game ---------------------------------------\n");
    std::cout << "Welcome to KEngine Open World !\n";
    // GLFWwindow *w = setupWindow(screenWidth, screenHeight, "Engine World Void");
    GLFWwindow *w = setupWindow(screenWidth, screenHeight, "Engine World Void");

    // Plane plane(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(3, 2, 1));
    // Plane plane(glm::vec3(-5, -5, -5), glm::vec3(9, 9, 9));
    Plane plane;
    // std::cout << "nn, ";
    // Camera cam(screenWidth, screenHeight, glm::vec3(0.0, 0.5f, 0.7f));
    // cam.PaneCamera(*plane.getShaderProgramPtr(), "transf");
    // Panel p(glm::vec3(0.0f, 50.f, 180.f), glm::vec4(0.0f, 0.5f, 1.f, 1.f), "sus");

    // Camera camera(1024, 1024, glm::vec3(0.0f, 0.5f, 0.7f), w);
    // Camera camera(1024, 1024, glm::vec3(0.0f, 0.5f, 0.7f));
    Camera camera(screenWidth, screenHeight, glm::vec3(-5, -5, 5));
    camera.PaneCamera(*plane.getShaderProgramPtr(), "transf");
    // printf("a\n");
    sleep(1);
    printf("--------------------------------------- start doing game loop ---------------------------------------\n");
    while (!glfwWindowShouldClose(w))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, .15f, .0f);

        // camera.computeMatricesFromInputs(*plane.getShaderProgramPtr(), "camMatrix");
        camera.computeMatricesFromInputs(w, *plane.getShaderProgramPtr(), "camMatrix");
        // std::cout << "a";
        plane.always();
        // p.draw();

        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    // p.clean();
    glfwTerminate();
    glfwDestroyWindow(w);
    return (0);
}