#include "./includes/stdEngine.hpp"
#include "includes/Plane.hpp"


int main(void)
{
    std::cout << "Welcome to KEngine Open World !\n";
    // GLFWwindow *w = setupWindow(screenWidth, screenHeight, "Engine World Void");
    GLFWwindow *w = setupWindow(screenWidth, screenHeight, "Engine World Void");

    // Plane plane(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(3, 2, 1));
    Plane plane(glm::vec3(-5, -5, -5), glm::vec3(9, 9, 9));
    // std::cout << "nn, ";
    Camera cam(screenWidth, screenHeight, glm::vec3(0.0, 0.5f, 0.7f));
    cam.PaneCamera(*plane.getShaderProgramPtr(), "transf");

    // printf("a\n");
    while (!glfwWindowShouldClose(w))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, .15f, .0f);

        cam.computeMatricesFromInputs(w, *plane.getShaderProgramPtr(), "camMatrix");
        // std::cout << "a";
        plane.always();

        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    glfwTerminate();
    glfwDestroyWindow(w);
    return (0);
}