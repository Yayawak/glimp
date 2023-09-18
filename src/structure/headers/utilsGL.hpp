#ifndef UtilGL_H
#define UtilGL_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stdio.h>
#include <vector>

void vecshow(glm::vec3 v);
std::vector<GLfloat> glfToVec(GLfloat *ptrToGlf, size_t noOfGlf);
GLfloat* vecToGlf(std::vector<GLfloat> vec);

std::vector<GLuint> gluiToVec(GLuint *ptrToGlui, size_t noOfGlui);
GLuint* vecToGlui(std::vector<GLuint> vec);

#endif