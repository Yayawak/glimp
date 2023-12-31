#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include "shaderClass.hpp"

// Load a .DDS file using GLFW's own loader
GLuint loadDDS(const char *imagepath);

// Load a .BMP file using our custom loader
GLuint loadBMP_custom(const char * imagepath);

// Since GLFW 3, glfwLoadTexture2D() has been removed. You have to use another texture loading library, 
// or do it yourself (just like loadBMP_custom and loadDDS)
// Load a .TGA file using GLFW's own loader
// GLuint loadTGA_glfw(const char * imagepath);


class Texture
{
    public:
        GLuint Id;
        GLenum type;
        Texture(const char *image, GLenum textype,
            GLenum slot, GLenum format,
            GLenum pixel,
            bool showFailReason=true
        );

        void texUnit(Shader& shaderProgram, const char *uniform, GLuint unit);
        void Bind();
        void Unbind();
        void Delete();

};

#endif