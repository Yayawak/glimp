#ifndef TEXTURE_CLASS_H
# define TEXTURE_CLASS_H

#include "shaderClass.hpp"

GLuint loadDDS(const char *imagepath);

class Texture
{
    public:
        GLuint Id;
        GLenum type;
        Texture(const char *image, GLenum textype,
            GLenum slot, GLenum format,
            GLenum pixel
        );

        void texUnit(Shader& shaderProgram, const char *uniform, GLuint unit);
        void Bind();
        void Unbind();
        void Delete();
};

#endif