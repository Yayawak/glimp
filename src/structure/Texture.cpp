// #include "headers/Texture.hpp"
#include "headers/stdgl.hpp"
#include <iostream>
// #ifndef STB
// #define STB

// #define STB_IMAGE_IMPLEMENTATION
// #include <stb/stb_image.h>

// #endif
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

Texture::Texture(const char *image, GLenum textype,
    GLenum slot, GLenum format,
    GLenum pixel
)
{
    type = textype;
    int w, h, colorChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *bytes = stbi_load( image,
        &w, &h, &colorChannels, 0);
    if (stbi_failure_reason())
    {
        stbi_image_free(bytes);
        std::cout << "Failed reason : " << stbi_failure_reason();
        // exit(0);
    }

    glGenTextures(1, &Id);
    glActiveTexture(slot);
    glBindTexture(textype, Id);

    glTexParameteri(textype, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(textype, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(textype, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(textype, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // glTexParameteri(textype, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    // glTexParameteri(textype, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    // float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glTexImage2D(
        textype, 0, GL_RGBA,
        w, h, 0,
        GL_RGBA, GL_UNSIGNED_BYTE,
        bytes
    );
    glGenerateMipmap(textype);


    // glBindTexture(textype, 0);
    Unbind();
    // stbi_image_free(bytes); // -> this like provide memory leak
    // std::cout << "bytes after freed : " << bytes << std::endl;
}

void Texture::texUnit(Shader shaderProgram, const char *uniform, GLuint unit)
{
    // GLuint uniTex0 = glGetUniformLocation(shaderProgram.shaderProgramId, "tex0");
    GLuint uniTex = glGetUniformLocation(shaderProgram.shaderProgramId, uniform);
    shaderProgram.Activate();
    glUniform1i(uniTex, unit);
}

void Texture::Bind()
{
    glBindTexture(type, Id);
}

void Texture::Unbind()
{
    glBindTexture(type, 0);
}

void Texture::Delete()
{
    glDeleteTextures(1, &Id);
}