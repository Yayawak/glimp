#ifndef EBO_Class_H
# define EBO_Class_H

#include <GLFW/glfw3.h>
#include <vector>
// #include <GL/glew.h>

class EBO
{
    public:
        GLuint Id;
        EBO(std::vector<GLuint> indices);
        EBO(GLuint *indices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};

#endif