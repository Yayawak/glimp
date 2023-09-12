#ifndef SETUP_WINDOW_H
#define SETUP_WINDOW_H

// #define GL_SILENCE_DEPRECATION
// #include <GL/glew.h>
#include <GLFW/glfw3.h>


GLFWwindow* setupWindow();
GLFWwindow* setupWindow(const char *windowName);
GLFWwindow* setupWindow(int w, int h, const char *windowName);

#endif