#include "headers/VAO.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &Id);    
}

// void VAO::LinkVBO(VBO vbo, GLuint layout)
// {
//     // ? still functional even below line absented.
//     vbo.Bind();
//     //NOTE Making the linke between vertex data & attributes
//     glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
//     // ? 3 = number of components (x, y, z), layout = 0 mean pointer to addr 0 (default)
//     // glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
//     glEnableVertexAttribArray(layout);
//     // ? for cleaning
//     vbo.Unbind();
// }
void VAO::LinkAttrib(VBO vbo, GLuint layout, GLuint numComponents,
    GLenum vartype, GLsizeiptr stride, void *offset)
{
    vbo.Bind();
    glVertexAttribPointer(layout, numComponents, vartype, 
        GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    vbo.Unbind();
}

// ? Why not called this method on constructor ?
//!SECTION SEX X
//ANCHOR - 
//FIXME - 
//STUB - 
//NOTE - 
// todo 
// ?
// *
// !
//SECTION - A
//LINK - "www.w3.org/TR.com"
//LINK - "./src/structure/headers/VAO.cpp"
void VAO::Bind()
{
    glBindVertexArray(Id);
}

void VAO::Unbind()
{
    glBindVertexArray(0);
}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &Id);
}