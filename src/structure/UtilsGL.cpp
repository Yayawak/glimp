#include "headers/utilsGL.hpp"

void vecshow(glm::vec3 v)
{
    printf("vec3 [%f, %f, %f]\n", v.x, v.y, v.z);    
}

GLuint* vecToGlui(std::vector<GLuint> vec)
{
    // GLfloat v[vec.size()];
    GLuint v[vec.size()];
    for (int i = 0; i < vec.size(); ++i)
    {
        v[i] = vec[i];
    }
    GLuint *p = v;
    return p;
}

std::vector<GLuint> gluiToVec(GLuint *ptrToGlui, size_t noOfGlui)
{
    std::vector<GLuint> ret;
    // GLfloat v[vec.size()];
    for (size_t i = 0; i < noOfGlui; ++i)
    {
        ret.push_back(ptrToGlui[i]);
    }
    return ret;
}

GLfloat* vecToGlf(std::vector<GLfloat> vec)
{
    // GLfloat v[vec.size()];
    GLfloat v[vec.size()];
    for (int i = 0; i < vec.size(); ++i)
    {
        v[i] = vec[i];
    }
    GLfloat *p = v;
    return p;
}

std::vector<GLfloat> glfToVec(GLfloat *ptrToGlf, size_t noOfGlf)
{
    std::vector<GLfloat> ret;
    // GLfloat v[vec.size()];
    for (size_t i = 0; i < noOfGlf; ++i)
    {
        ret.push_back(ptrToGlf[i]);
    }
    return ret;
}