// #include "./includes/stdEngine.hpp"
// #include "glm/ext/matrix_transform.hpp"
// #include "includes/Mesh.hpp"
// #include "includes/Cube.hpp"
// #include "includes/Quad.hpp"
// // #include "includes/Qube.hpp"
// #include "includes/Sphere.hpp"
// #include "includes/Triangle.hpp"
// #include "includes/Sphere.hpp"
// #include "includes/World.hpp"
// // #include "includes/.hpp"
// #include <thread>
// #include <unistd.h>


// // void updateInput(GLFWwindow* w, 
// //     // glm::vec3 &pos, 
// //     // glm::vec3 &rot, 
// //     // glm::vec3 &scale
// //     Mesh &mesh
// // )
// // {
// //     // const float speed = 0.01f;
// //     const float speed = 0.05f;
// //     // const float deltaScale = 0.1f;
// //     const float deltaScale = 0.01f;
// //     const float rotationSpeed = 1.f;

// //     // * Move Y
// //     if (glfwGetKey(w, GLFW_KEY_W) == GLFW_PRESS)
// //     {
// //         // pos.z -= speed;
// //         // mesh.move(glm::vec3(0, 0, -speed));
// //         mesh.move(glm::vec3(0, speed, 0));
// //     }
// //     if (glfwGetKey(w, GLFW_KEY_S) == GLFW_PRESS)
// //     {
// //         // pos.z += speed;
// //         // mesh.move(glm::vec3(0, 0, speed));
// //         mesh.move(glm::vec3(0, -speed, 0));
// //     }
// //     // * Move X
// //     if (glfwGetKey(w, GLFW_KEY_A) == GLFW_PRESS)
// //     {
// //         // pos.x -= speed;
// //         mesh.move(glm::vec3(-speed, 0, 0));
// //     }
// //     if (glfwGetKey(w, GLFW_KEY_D) == GLFW_PRESS)
// //     {
// //         // pos.x += speed;
// //         mesh.move(glm::vec3(+speed, 0, 0));
// //     }
// //     // * Move Z
// //     if (glfwGetKey(w, GLFW_KEY_R) == GLFW_PRESS)
// //     {
// //         // pos.x -= speed;
// //         mesh.move(glm::vec3(0, 0, -speed));
// //     }
// //     if (glfwGetKey(w, GLFW_KEY_F) == GLFW_PRESS)
// //     {
// //         // pos.x += speed;
// //         mesh.move(glm::vec3(0, 0, +speed));
// //     }
// //     // * Rotation Around Y Axis
// //     if (glfwGetKey(w, GLFW_KEY_Q) == GLFW_PRESS)
// //     {
// //         // mesh.setRotation(glm::vec3(0, -speed, 0));
// //         mesh.rotate(glm::vec3(0, -rotationSpeed, 0));
// //         // mesh.rotate(glm::vec3(0, 0, -speed));
// //     }
// //     if (glfwGetKey(w, GLFW_KEY_E) == GLFW_PRESS)
// //     {
// //         // mesh.setRotation(glm::vec3(0, +speed, 0));
// //         mesh.rotate(glm::vec3(0, +rotationSpeed, 0));
// //         // mesh.rotate(glm::vec3(0, 0, +speed));
// //     }
// //     if (glfwGetKey(w, GLFW_KEY_Z) == GLFW_PRESS)
// //     {
// //         mesh.scaleMesh(glm::vec3(1) * deltaScale);
// //     }
// //     if (glfwGetKey(w, GLFW_KEY_X) == GLFW_PRESS)
// //     {
// //         mesh.scaleMesh(glm::vec3(1) * -deltaScale);
// //     }
// // }


// // int main(void)
// // {
// //     // fork(); // make 2 game

// //     printf("--------------------------------------- start initialized game ---------------------------------------\n");
// //     std::cout << "Welcome to KEngine Open World !\n";
// //     GLFWwindow *w = setupWindow(screenWidth, screenHeight, "World Void");

// //     // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

// //     Shader *cubeShader = new Shader(
// //         "/Users/rio/Desktop/glgl/applications/superKEngine/Shaders/default.vert",
// //         "/Users/rio/Desktop/glgl/applications/superKEngine/Shaders/default.frag"
// //     );
// //     // cam.PaneCamera(cubeShader, "")

// //     // Cube plane;

// //     // plane.
// //     // plane.setPosition(glm::vec3(0, -1.5, 0));
// //     // plane.rotate(glm::vec3(90, 0, 0));
// //     // plane.scaleMesh(glm::vec3(4));

// //     // Mesh cubeMesh(new Cube());
// //     // Mesh cubeMesh(new Cube(),
// //     //     "/Users/rio/Desktop/glgl/img/abadon.png"
// //     // );
// //     Cube cubeMesh;
// //     cubeMesh.setScale(glm::vec3(0.05f));
// //     // cubeMesh.move(glm::vec3(0, 0, -3));
// //     // Mesh *cubeMeshs[9];


// //     Sphere sphere(glm::vec3(0), 0.3);
// //     Sphere s2(glm::vec3(0.1, 0, 0), 0.1);

// //     sleep(1);
// //     printf("--------------------------------------- start doing game loop ---------------------------------------\n");
// //     while (!glfwWindowShouldClose(w))
// //     {
// //         glClearColor(.07f, .03f, .15f, 1.0f); // dark blue
// //         // glClearColor(35/255.f, 115/255.f, 200/255.f, 1.f); // vivid blue
// //         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);


// //         // plane.render(cubeShader);
// //         // updateInput(w, plane);

// //         // m.rotate(glm::vec3(0.0f, 0.0f, 1.0f));
// //         // m.scaleMesh(glm::vec3(1.0f, 0.1f * sin(glfwGetTime()), 1.0f));
// //         // updateInput(w, m);
// //         // updateInput(w, quad);

// //         cubeMesh.render(cubeShader);
// //         cubeMesh.move(glm::vec3(0.05 / 4 * sin(glfwGetTime()), 0, 0));
// //         // updateInput(w, cubeMesh);

// //         sphere.render(cubeShader);
// //         updateInput(w, sphere);

// //         // s2.render(cubeShader);
// //         // s2.move(glm::vec3(0, 0.05 * sin(glfwGetTime()), 0));

// //         // if (sphere.isCollideWith(s2))
// //         if (sphere.isCollideWith(cubeMesh))
// //         {
// //             glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
// //             // printf("Sphere & s2 mesh collision detected\n");
// //         }
// //         else
// //         {
// //             // printf("not collided\n");
// //             glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
// //         }

// //         glfwSwapBuffers(w);
// //         glfwPollEvents();
// //     }


// //     glfwTerminate();
// //     glfwDestroyWindow(w);
// //     return (0);
// // }

// // void loop()
// // {
// //     // gameLoop();
// //     World::getInstance()->gameLoop();
// // }

// int main(void)
// {
//     World::getInstance();

//     // std::thread t(loop);
//     // World::getInstance()->setGameLoopThreadPtr(&std::thread(gameLoop));
//     // World::getInstance()->setGameLoopThreadPtr(&t);
//     // std::thread t(World::getInstance()->gameLoop);

//     // Cube cubeMesh;
//     // cubeMesh.setScale(glm::vec3(0.05f));
//     // // cubeMesh.move(glm::vec3(0, 0, -3));


//     // Sphere sphere(glm::vec3(0), 0.3);
//     // Sphere s2(glm::vec3(0.1, 0, 0), 0.1);

//     // World::getInstance()->addMeshObject(&cubeMesh);
//     // World::getInstance()->addMeshObject(&sphere);

//         // cubeMesh.render(cubeShader);
//         // cubeMesh.move(glm::vec3(0.05 / 4 * sin(glfwGetTime()), 0, 0));
//         // // updateInput(w, cubeMesh);

//         // sphere.render(cubeShader);
//         // updateInput(w, sphere);

//         // if (sphere.isCollideWith(cubeMesh))
//         // {
//         //     glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
//         //     // printf("Sphere & s2 mesh collision detected\n");
//         // }
//         // else
//         // {
//         //     // printf("not collided\n");
//         //     glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
//         // }

//     // t.join();
//     // World::getInstance()->getGameLoopThreadPtr()->join();

//     return (0);
// }