// #include "headers/Texture.hpp"
#include "headers/stdgl.hpp"
#include <iostream>
// #ifndef STB
// #define STB

// #define STB_IMAGE_IMPLEMENTATION
// #include <stb/stb_image.h>

// #endif

#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3

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

    // glTexParameteri(textype, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    // glTexParameteri(textype, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glTexImage2D(
        textype, 0, GL_RGBA,
        w, h, 0,
        format, pixel,
        bytes
    );
    glGenerateMipmap(textype);


    // glBindTexture(textype, 0);
    Unbind();
    // stbi_image_free(bytes); // -> this like provide memory leak
    // std::cout << "bytes after freed : " << bytes << std::endl;
}

void Texture::texUnit(Shader& shaderProgram, const char *uniform, GLuint unit)
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






#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

GLuint loadDDS(const char *imagepath) {

  unsigned char header[124];

  FILE *fp;

  /* try to open the file */
  fp = fopen(imagepath, "rb");
  if (fp == NULL) {
    printf("%s could not be opened. Are you in the right directory ? Don't "
           "forget to read the FAQ !\n",
           imagepath);
    getchar();
    return 0;
  }

  /* verify the type of file */
  char filecode[4];
  fread(filecode, 1, 4, fp);
  if (strncmp(filecode, "DDS ", 4) != 0) {
    fclose(fp);
    return 0;
  }

  /* get the surface desc */
  fread(&header, 124, 1, fp);

  unsigned int height = *(unsigned int *)&(header[8]);
  unsigned int width = *(unsigned int *)&(header[12]);
  unsigned int linearSize = *(unsigned int *)&(header[16]);
  unsigned int mipMapCount = *(unsigned int *)&(header[24]);
  unsigned int fourCC = *(unsigned int *)&(header[80]);

  unsigned char *buffer;
  unsigned int bufsize;
  /* how big is it going to be including all mipmaps? */
  bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize;
  buffer = (unsigned char *)malloc(bufsize * sizeof(unsigned char));
  fread(buffer, 1, bufsize, fp);
  /* close the file pointer */
  fclose(fp);

  unsigned int components = (fourCC == FOURCC_DXT1) ? 3 : 4;
  unsigned int format;
  switch (fourCC) {
  case FOURCC_DXT1:
    format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
    break;
  case FOURCC_DXT3:
    format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
    break;
  case FOURCC_DXT5:
    format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
    break;
  default:
    free(buffer);
    return 0;
  }

  // Create one OpenGL texture
  GLuint textureID;
  glGenTextures(1, &textureID);

  // "Bind" the newly created texture : all future texture functions will modify
  // this texture
  glBindTexture(GL_TEXTURE_2D, textureID);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  unsigned int blockSize =
      (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;
  unsigned int offset = 0;

  /* load the mipmaps */
  for (unsigned int level = 0; level < mipMapCount && (width || height);
       ++level) {
    unsigned int size = ((width + 3) / 4) * ((height + 3) / 4) * blockSize;
    glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height, 0, size,
                           buffer + offset);

    offset += size;
    width /= 2;
    height /= 2;

    // Deal with Non-Power-Of-Two textures. This code is not included in the
    // webpage to reduce clutter.
    if (width < 1)
      width = 1;
    if (height < 1)
      height = 1;
  }

  free(buffer);

  return textureID;
}
