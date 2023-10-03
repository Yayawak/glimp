#include "./includes/stdEngine.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "includes/Mesh.hpp"
#include "includes/Cube.hpp"
#include "includes/Quad.hpp"
// #include "includes/Qube.hpp"
#include "includes/Triangle.hpp"
// #include "includes/.hpp"
#include <unistd.h>

static const char *texPath = "img/abadon.png";

void updateInput(GLFWwindow* w, 
    // glm::vec3 &pos, 
    // glm::vec3 &rot, 
    // glm::vec3 &scale
    Mesh &mesh
)
{
    // const float speed = 0.01f;
    const float speed = 0.05f;
    // const float deltaScale = 0.1f;
    const float deltaScale = 0.01f;
    const float rotationSpeed = 1.f;

    // * Move Y
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
    // * Move X
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
    // * Move Z
    if (glfwGetKey(w, GLFW_KEY_R) == GLFW_PRESS)
    {
        // pos.x -= speed;
        mesh.move(glm::vec3(0, 0, -speed));
    }
    if (glfwGetKey(w, GLFW_KEY_F) == GLFW_PRESS)
    {
        // pos.x += speed;
        mesh.move(glm::vec3(0, 0, +speed));
    }
    // * Rotation Around Y Axis
    if (glfwGetKey(w, GLFW_KEY_Q) == GLFW_PRESS)
    {
        // mesh.setRotation(glm::vec3(0, -speed, 0));
        mesh.rotate(glm::vec3(0, -rotationSpeed, 0));
        // mesh.rotate(glm::vec3(0, 0, -speed));
    }
    if (glfwGetKey(w, GLFW_KEY_E) == GLFW_PRESS)
    {
        // mesh.setRotation(glm::vec3(0, +speed, 0));
        mesh.rotate(glm::vec3(0, +rotationSpeed, 0));
        // mesh.rotate(glm::vec3(0, 0, +speed));
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


int main(void)
{
    // fork(); // make 2 game

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
        "/Users/rio/Desktop/glgl/applications/superKEngine/Shaders/default.vert",
        "/Users/rio/Desktop/glgl/applications/superKEngine/Shaders/default.frag"
    );
    // cam.PaneCamera(cubeShader, "")

    // Mesh m(vertices, noOfV, indices, noOfI);
    // Mesh m(vertices, noOfV, indices, noOfI,
    //     glm::vec3(0),
    //     glm::vec3(0),
    //     glm::vec3(1.3)
    // );
    // Quad *give_me_a_name = new Quad();
    // Quad give_me_a_name;
    // Mesh quad(Quad());
    // Mesh quad(give_me_a_name);

    // Mesh trigMesh(new Triangle()
    //     // , "img/abadon.png"
    //     // , texPath
    // );

    Mesh plane(new Quad());
    plane.setPosition(glm::vec3(0, -1.5, 0));
    plane.rotate(glm::vec3(90, 0, 0));
    plane.scaleMesh(glm::vec3(4));

    // Mesh cubeMesh(new Cube());
    Mesh cubeMesh(new Cube(),
        "/Users/rio/Desktop/glgl/img/abadon.png"
    );
    cubeMesh.setScale(glm::vec3(0.5f));
    cubeMesh.move(glm::vec3(0, 0, -3));
    // Mesh *cubeMeshs[9];

    // for (int i = 0; i < 9; i++)
    // {
    //     int r = i / 3;
    //     int c = i % 3;

    //     Mesh *cb = new Mesh(new Cube());
    //     cb->setPosition(glm::vec3(r, c, 0));
    //     // cb->setPosition(glm::vec3(0, 0, 0));
    //     cubeMeshs[i] = cb;
    // }
    // Mesh *ms[3];

    // for (int i = 0; i < 3; i++)
    // {
    //     Mesh *m = new Mesh(vertices, noOfV, indices, noOfI,
    //         glm::vec3(0, 1 - (i / 2), 0),
    //         glm::vec3(0),
    //         glm::vec3(0.3)
    //     );
    //     ms[i] = m;
    // }
    sleep(1);
    printf("--------------------------------------- start doing game loop ---------------------------------------\n");
    while (!glfwWindowShouldClose(w))
    {
        // glClearColor(.07f, .03f, .15f, 1.0f); // dark blue
        glClearColor(35/255.f, 115/255.f, 200/255.f, 1.f); // vivid blue
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        // cam.computeMatricesFromInputs(w, *cubeShader, "camMatrix");
        // m.render(cubeShader);

        // quad.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
        // quad.render(cubeShader);

        // trigMesh.render(cubeShader);
        // for (int i = 0; i < 3; i++)
        // {
        //     ms[i]->render(cubeShader);
        //     updateInput(w, *ms[i]);
        // }

        // for (int i = 0; i < 9; i++)
        // {
        //     cubeMeshs[i]->render(cubeShader);
        //     updateInput(w, *cubeMeshs[i]);
        // }


        // cubeMeshs[0]->render(cubeShader);
        // updateInput(w, *cubeMeshs[0]);
        plane.render(cubeShader);
        updateInput(w, plane);

        // m.rotate(glm::vec3(0.0f, 0.0f, 1.0f));
        // m.scaleMesh(glm::vec3(1.0f, 0.1f * sin(glfwGetTime()), 1.0f));
        // updateInput(w, m);
        // updateInput(w, quad);

        cubeMesh.render(cubeShader);
        updateInput(w, cubeMesh);

        glfwSwapBuffers(w);
        glfwPollEvents();
    }


    glfwTerminate();
    glfwDestroyWindow(w);
    return (0);
}