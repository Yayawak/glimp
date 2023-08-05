// #include "vendors/GLFW/glfw3.h"
// #include <stdio.h>
// #include <iostream>
// void drawTrig()
// {
// }

// int main()
// {
//     if (!glfwInit())
//     {
//         fprintf(stderr, "Erro count not start GLFW3\n");
//         return (1);
//     }

//     GLFWwindow *w = glfwCreateWindow(640, 480, "Triangle Program", NULL, NULL);
//     glfwMakeContextCurrent(w);

//     const GLubyte *renderer = glGetString(GL_RENDER);
//     const GLubyte *version = glGetString(GL_VERSION);
//     // std::cout << "Renderer : " << *renderer;
//     printf("Renderer : %s\n", renderer);
//     std::cout << "OpenGL version supported : " << version << std::endl;

//     // glEnable(GL_DEPTH_TEST);
//     // glDepthFunc(GL_LESS);
//     glVertex
//     while (!glfwWindowShouldClose(w))
//     {
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//         drawTrig();
//         float points[] = {
//             0.0f, 0.5f, 0.0f,
//             0.5f, -0.5f, 0.0f,
//             -0.5f, -0.5f, 0.0f};
//         GLuint vbo = 0;
//         glGenBuffers(1, &vbo);
//         glBindBuffer(GL_ARRAY_BUFFER, vbo);
//         glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

//         GLuint vao = 0;
//         // glGenVertexArrays(1, &vao);
//         // glArray
//         glEnableVertexAttribArray(vao);
//         glVertexAttribPointer(vao, 2, GL_FLOAT, GL_FALSE,
//                               sizeof(points), (void *)0);
//         glDrawArrays(GL_TRIANGLES, 0, 3);

//         glfwPollEvents();
//         glfwSwapBuffers(w);
//     }

//     glfwTerminate();
//     return (0);
// }
