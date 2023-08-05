#ifndef VAO_Class_H
# define VAO_Class_H

#include <GLFW/glfw3.h>
#include "VBO.hpp"

class VAO
{
    public:
        GLuint Id;
        VAO();

        void LinkVBO(VBO VBO, GLuint layout);
        void Bind();
        void Unbind();
        void Delete();
};

#endif