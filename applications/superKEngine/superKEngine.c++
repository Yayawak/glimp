#include "./includes/stdEngine.hpp"
#include "glm/ext/matrix_transform.hpp"
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

void updateInput(GLFWwindow* w, 
    // glm::vec3 &pos, 
    // glm::vec3 &rot, 
    // glm::vec3 &scale
    Mesh &mesh
)
{
    float speed = 0.01f;
    float deltaScale = 0.1f;
    if (glfwGetKey(w, GLFW_KEY_W) == GLFW_PRESS)
    {
        // pos.z -= speed;
        // mesh.move(glm::vec3(0, 0, -speed));
        mesh.move(glm::vec3(0, speed, 0));
    }
    if (glfwGetKey(w, GLFW_KEY_S) == GLFW_PRESS)
    {
        // pos.z += speed;
        // mesh.move(glm::vec3(0, 0, speed));
        mesh.move(glm::vec3(0, -speed, 0));
    }
    if (glfwGetKey(w, GLFW_KEY_A) == GLFW_PRESS)
    {
        // pos.x -= speed;
        mesh.move(glm::vec3(-speed, 0, 0));
    }
    if (glfwGetKey(w, GLFW_KEY_D) == GLFW_PRESS)
    {
        // pos.x += speed;
        mesh.move(glm::vec3(+speed, 0, 0));
    }
    if (glfwGetKey(w, GLFW_KEY_Q) == GLFW_PRESS)
    {
        // mesh.setRotation(glm::vec3(0, -speed, 0));
        // mesh.rotate(glm::vec3(0, -speed, 0));
        mesh.rotate(glm::vec3(0, 0, -speed));
    }
    if (glfwGetKey(w, GLFW_KEY_E) == GLFW_PRESS)
    {
        // mesh.setRotation(glm::vec3(0, +speed, 0));
        // mesh.rotate(glm::vec3(0, +speed, 0));
        mesh.rotate(glm::vec3(0, 0, +speed));
    }
    if (glfwGetKey(w, GLFW_KEY_Z) == GLFW_PRESS)
    {
        mesh.scaleMesh(glm::vec3(1) * deltaScale);
    }
    if (glfwGetKey(w, GLFW_KEY_X) == GLFW_PRESS)
    {
        mesh.scaleMesh(glm::vec3(1) * -deltaScale);
    }
}

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
    // Camera cam(screenWidth, screenHeight, glm::vec3(0.0f, 0.0f, -1.0f));
    // Panel p()

    Shader *cubeShader = new Shader(
        "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.vert",
        "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.frag"
    );
    // cam.PaneCamera(cubeShader, "")

    // Mesh m(vertices, noOfV, indices, noOfI);
    // Mesh m(vertices, noOfV, indices, noOfI,
    //     glm::vec3(0),
    //     glm::vec3(0),
    //     glm::vec3(1.3)
    // );
    Mesh *ms[3];

    for (int i = 0; i < 3; i++)
    {
        Mesh *m = new Mesh(vertices, noOfV, indices, noOfI,
            glm::vec3(0, 1 - (i / 2), 0),
            glm::vec3(0),
            glm::vec3(0.3)
        );
        ms[i] = m;
    }
    sleep(1);
    printf("--------------------------------------- start doing game loop ---------------------------------------\n");
    while (!glfwWindowShouldClose(w))
    {
        glClearColor(.07f, .03f, .15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        // cam.computeMatricesFromInputs(w, *cubeShader, "camMatrix");

        // m.render(cubeShader);
        for (int i = 0; i < 3; i++)
        {
            ms[i]->render(cubeShader);
            updateInput(w, *ms[i]);
        }

        // m.rotate(glm::vec3(0.0f, 0.0f, 1.0f));
        // m.scaleMesh(glm::vec3(1.0f, 0.1f * sin(glfwGetTime()), 1.0f));
        // updateInput(w, m);

        glfwSwapBuffers(w);
        glfwPollEvents();
    }


    glfwTerminate();
    glfwDestroyWindow(w);
    return (0);
}