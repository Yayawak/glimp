#ifndef VBO_Class_H
# define VBO_Class_H

#include <GLFW/glfw3.h>
// #include <GL/glew.h>

class VBO
{
    public:
        GLuint Id;
        VBO(GLfloat *vertices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};

#endif