#include "./includes/stdEngine.hpp"
#include "includes/Mesh.hpp"
// #include "includes/.hpp"
#include <unistd.h>

Vertex vertices[] =
{
    // posotion, color, texcoords, normal
    glm::vec3(-0.5f,  0.5f, 0.f),       glm::vec3(1.f, 0.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(-0.5f, -0.5f, 0.f),       glm::vec3(0.f, 1.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3( 0.5f, -0.5f, 0.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3( 0.5f,  0.5f, 0.f),       glm::vec3(0.f, 1.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),

    // glm::vec3(-0.5f,  0.5f, 1.f),       glm::vec3(1.f, 0.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
    // glm::vec3(-0.5f, -0.5f, 1.f),       glm::vec3(0.f, 1.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
    // glm::vec3( 0.5f, -0.5f, 1.f),       glm::vec3(0.f, 0.f, 1.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f),
    // glm::vec3( 0.5f,  0.5f, 1.f),       glm::vec3(0.f, 1.f, 0.f),     glm::vec2(0.0f, 0.0f),        glm::vec3(0.0f, 0.0f, 0.0f)
};

unsigned noOfV = sizeof(vertices) / sizeof(Vertex);
// unsigned noOfV = 4;

GLuint indices[] = 
{
    0, 1, 2,
    0, 2, 3,
};
unsigned noOfI = sizeof(indices) / sizeof(GLuint);

int main(void)
{
    printf("--------------------------------------- start initialized game ---------------------------------------\n");
    std::cout << "Welcome to KEngine Open World !\n";
    GLFWwindow *w = setupWindow(screenWidth, screenHeight, "Engine World Void");

    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    // Shader *cubeShader = new Shader(
    //     "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.vert",
    //     "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.frag"
    // );
    Shader *cubeShader = new Shader(
        "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.vert",
        "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.frag"
    );

    Mesh m(vertices, noOfV, indices, noOfI);
    sleep(1);
    printf("--------------------------------------- start doing game loop ---------------------------------------\n");
    while (!glfwWindowShouldClose(w))
    {
        glClearColor(.07f, .03f, .15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);


        m.render(cubeShader);

        glfwSwapBuffers(w);
        glfwPollEvents();
    }


    glfwTerminate();
    glfwDestroyWindow(w);
    return (0);
}