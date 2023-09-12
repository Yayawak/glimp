#include "../../structure/headers/stdgl.hpp"
#include "glm/fwd.hpp"
#include <string>

// float mapToNormal(float value, float min, float max)
// {

// }


void ex07_multiplePanelColor()
{
    // glm::vec4 color
    // todo : make panel of 4 choice colors (r, g, b, orange) -> with specific Rectangle xywh
    GLFWwindow* w = setupWindow(screenWidth, screenHeight, "Multiple Panle Color");
    
    // Shader sp(
    //     "/Users/rio/Desktop/glgl/src/exs/ex07_multiple_panel_color/default.vert",
    //     "/Users/rio/Desktop/glgl/src/exs/ex07_multiple_panel_color/default.frag"
    // );
    // sp.Activate();

    float startedTime = glfwGetTime();
    // glm::vec3 color;
    // glm::vec4 rect;

    Panel topPanel(glm::vec3(0.f, 50.f, 180.f),
        glm::vec4(-1.0f, 1.0, 2.0, 0.08),
        "top"
    );
        // color = glm::vec3(0.1f, 0.4f, .1f);
        // rect = glm::vec4(-1.f, 1.f, 0.5f, 2.f);
        // VAO leftPanelVao = makePanel(color, rect, "left");
    // Panel leftPanel(glm::vec3(35, 60, 90),
    Panel leftPanel(glm::vec3(60, 130, 220),
        glm::vec4(-1, 1, 0.3, 2.f),
        "leftPanel"
    );

    // drawGrid(-0.1, 0.9f, 4, 4, 0.1, 0.05);

    while (!glfwWindowShouldClose(w))
    {
        float now = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, .15f, .0f);


        // x, y, z, w
        // glm::vec4 rect((now - startedTime), 1.f, 0.5f, 2.f);
        // glm::vec4 rect(2.0f * sin(now - startedTime), 1.f, 0.5f, 2.f);

        // float v = 0.01f * sin(now - startedTime);
        // std::cout << v << std::endl;
        // topPanel.shiftByVec(v, 0); 

        // drawGrid(-0.3f, 0.8f, 4, 4, 0.1, 0.05);
        topPanel.draw();
        leftPanel.draw();


        // drawGrid(0.5f, 0.95f, 1, 3, 0.08f, 0.05f);





        // ? can't use
        // makePanel(0, 0, 30, 400, 20, 20, 20, "left");
        // drawGrid(0.05, 0.05, 4, 4, 0.1, 0.05);

        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    // sp.Delete();
    glfwTerminate();
    glfwDestroyWindow(w);
}