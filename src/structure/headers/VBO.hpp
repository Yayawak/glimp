#ifndef VBO_Class_H
# define VBO_Class_H

#include <GLFW/glfw3.h>
#include <vector>
// #include <GL/glew.h>
#include "Vertex.hpp"
#include "utilsGL.hpp"
#include <vector>
// #include "glm/gtc/type_ptr.hpp" // for value_ptr()

class VBO
{
// private:
public:
    GLuint Id;
    // VBO(std::vector<GLfloat> verticesVec);
    VBO(GLfloat *vertices, GLsizeiptr sizeBytes);
    // VBO(std::vector<Vertex> *stdVertices);
    VBO(std::vector<SVertex>::value_type *ptr_to_value, GLsizeiptr sizeBytes);

    void Bind();
    void Unbind();
    void Delete();
};

#endif