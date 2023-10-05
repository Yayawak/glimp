#ifndef SHADER_CLASS_H
# define SHADER_CLASS_H

#include <GLFW/glfw3.h>
// #include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <glm/glm.hpp>
#include "glm/gtc/type_ptr.hpp" // for use value_ptr()

std::string get_file_contents(const char *filename);
// const char* get_file_contents(const char *filename);

class Shader
{
    public:
        GLuint shaderProgramId;
        Shader(const char *vertexFile, const char *fragmentFile);

        void Activate();
        void Delete();
        void Deactivate();
        void setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose = GL_FALSE);
        void setVec3fv(glm::vec3 vec, const GLchar* name);
    private:
        GLint compileStatus;
        char compileShaderLog[512];
        GLuint CreateShader(const char *txt, GLenum shaderType);
};

#endif
