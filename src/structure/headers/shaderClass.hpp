#ifndef Shader_Class_H
# define Shader_Class_H

#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char *filename);

class Shader
{
    public:
        GLuint shaderProgramId;
        Shader(const char *vertexFile, const char *fragmentFile);

        void Activate();
        void Delete();
    private:
        GLint compileStatus;
        char compileShaderLog[512];
        GLuint CreateShader(const char *txt, GLenum shaderType);
};

#endif
