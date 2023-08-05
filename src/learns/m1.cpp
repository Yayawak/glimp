// #include <stdio.h>
// #include "vendors/GLFW/glfw3.h"
// #include <math.h>
// #include <iostream>
// #include <string>
// #include "vendors/GLFW/linmath.h"
// #include <stdlib.h>


// static int n = 0;

// static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, GLFW_TRUE);
//     if (key == GLFW_KEY_S && action == GLFW_PRESS)
//     {
//         // glfwSwapBuffers(window);
//         GLFWwindow *newW;
//         // newW = glfwCreateWindow(50, 50, strcat("A", itoa(n++)), NULL, NULL);
//         newW = glfwCreateWindow(50, 50, ("A" + std::to_string(n++)).c_str(), NULL, NULL);

//     }
// }

// void error_callback(int error, const char *desc)
// {
//     fprintf(stderr, "Error : %s\n", desc);
// }

// void end_callback(GLFWwindow *w)
// {
//     std::cout << "End of Program." << std::endl;
// }

// int main(void)
// {
//     GLFWwindow* window;
//     GLFWwindow* w2;

//     /* Initialize the library */
//     if (!glfwInit())
//         return -1;

//     glfwSetErrorCallback(error_callback);


//     /* Create a windowed mode window and its OpenGL context */
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
//     window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//     int fw, fh;
//     glfwGetFramebufferSize(window, &fw, &fh);
//     glViewport(0, 0, fw, fh);
//     // w2 = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }

//     /* Make the window's context current */
//     glfwMakeContextCurrent(window);

//     glfwSetWindowCloseCallback(window, end_callback);
//     glfwSetKeyCallback(window, key_callback);
//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window))
//     {
//         /* Render here */
//         glClear(GL_COLOR_BUFFER_BIT);

//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);

//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     // {
//     //     int i = 0;
//     //     while (i < pow(10, 6))
//     //     {
//     //         // std::cout << i;
//     //         std::cout << i << ",";
//     //         i++;
//     //     }
//     //     glfwDestroyWindow(window);
//     // }


//     glfwTerminate();
//     return 0;
// }
