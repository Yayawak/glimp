#ifndef UtilGL_H
#define UtilGL_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stdio.h>
#include <vector>
#include <iostream>
#include "Vertex.hpp"

void showvertices(std::vector<Vertex> vexs);
void showvertices(GLfloat *vertices, size_t size);
void showvertices(GLuint *vertices, size_t size);
// void vecshow(glm::vec3 v);
void vecshow(glm::vec3 v, bool appendNewLine=true);
std::vector<GLfloat> glfToVec(GLfloat *ptrToGlf, size_t noOfGlf);
GLfloat* vecToGlf(std::vector<GLfloat> vec);

std::vector<GLuint> gluiToVec(GLuint *ptrToGlui, size_t noOfGlui);
GLuint* vecToGlui(std::vector<GLuint> vec);

// float lerp(float x0, float x1, float y0, float y1, float xToPredict)
float lerp(float x0, float x1, float y0, float y1, float xToPredict);

#endif