#ifndef EnObject_H
#define EnObject_H
// #include "../includes/stdEngine.hpp"
#include "../../../src/structure/headers/stdgl.hpp"

class EnObject
{
protected:
    VAO *vao = new VAO();
    // VAO *vao;
    VBO *vbo;
    EBO *ebo;
    Shader *shaderProgram;

public:
    EnObject();
    virtual void init() = 0;
    // virtual void init() {};
    // virtual void init();
    virtual void always() = 0;
    // virtual void always();
    virtual void clear() = 0; // clear bad data

    Shader *getShaderProgramPtr();
};


#endif
