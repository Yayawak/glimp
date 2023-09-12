#include "headers/setupWindow.hpp"
// #include "headers/stdgl.hpp"
#include <cstdio>
#include <iostream>
#include <iterator>
#include "headers/constants.hpp"

GLFWwindow* setupWindow()
{
    return setupWindow("DEFAULT Window");
}

GLFWwindow* setupWindow(const char *windowName)
{
    return setupWindow(screenWidth, screenHeight, windowName);
}

GLFWwindow* setupWindow(int w, int h, const char *windowName)
{
    if (!glfwInit())
    {
        fprintf(stderr, "Can't initialize GLFW ");
        getchar();
        glfwTerminate();
        // exit(-99);
        // return (NULL);
    }
    std::cout << "Initialized " << windowName << "\n";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // GLFWwindow *window = glfwCreateWindow(700, 500, "EX03", NULL, NULL);
    GLFWwindow *window = glfwCreateWindow(w, h, windowName, NULL, NULL);
    // glfwSetKeyCallback(window, keyInputManagerFn);
    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);
    // glEnable(GL_STENCIL_TEST);

    // glStencilFunc(GL_GEQUAL, 2, 0xFF);
    // glStencilFunc(GL_LESS, 2, 0xFF);

    	// Accept fragment if it closer to the camera than the former one
	// glDepthFunc(GL_LESS); 
	// Cull triangles which normal is not towards the camera
	// glEnable(GL_CULL_FACE);



    // Initialize GLEW
	// glewExperimental = true; // Needed for core profile
	// if (glewInit() != GLEW_OK) {
	// 	fprintf(stderr, "Failed to initialize GLEW\n");
	// 	getchar();
	// 	glfwTerminate();
	// 	return NULL;
	// }
    return window;
}