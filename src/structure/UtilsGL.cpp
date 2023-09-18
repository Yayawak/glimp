#include "headers/utilsGL.hpp"

void vecshow(glm::vec3 v)
{
    printf("vec3 [%f, %f, %f]\n", v.x, v.y, v.z);    
}

// GLuint* vecToGlui(std::vector<GLuint> vec)
// {
//     // GLfloat v[vec.size()];
//     GLuint v[vec.size()];
//     for (int i = 0; i < vec.size(); ++i)
//     {
//         v[i] = vec[i];
//     }
//     GLuint *p = v;
//     return p;
// }

// std::vector<GLuint> gluiToVec(GLuint *ptrToGlui, size_t noOfGlui)
// {
//     std::vector<GLuint> ret(noOfGlui);
//     // GLfloat v[vec.size()];
//     for (size_t i = 0; i < noOfGlui; ++i)
//     {
//         ret.push_back(ptrToGlui[i]);
//     }
//     return ret;
// }

GLfloat* vecToGlf(std::vector<GLfloat> vec)
{
    // printf("size of vec = %lu\n", vec.size());

    // GLfloat *v[vec.size()];
    GLfloat v[vec.size()];

    for (int i = 0; i < vec.size(); ++i)
    // GLfloat v[108];
    // for (int i = 0; i < 108; ++i)
    {
        v[i] = vec[i];
        // v[i] = vec[108 + i];
        // std::cout << "pushing" << i << "|" << v[i] << ", ";
    }
    // printf("size of v = %lu\n", sizeof(v));
    GLfloat *p = v;
    return p;
    // GLfloat *p = v;
    // return *v;
}

std::vector<GLfloat> glfToVec(GLfloat *ptrToGlf, size_t noOfGlf)
{
    // std::vector<GLfloat> ret(noOfGlf);
    std::vector<GLfloat> ret;
    // GLfloat v[vec.size()];
    for (int i = 0; i < noOfGlf; ++i)
    {
        // std::cout << "pushing" << i << ", ";
        // printf("'i[%d] = %f\n", i, ptrToGlf[i]);
        ret.push_back(ptrToGlf[i]);
    }
    return ret;
}


void showvertices(GLfloat *vertices, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("v[%lu] = %.1f, ", i, vertices[i]);
    }
    printf("\n");
}

void showvertices(GLuint *vertices, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("v[%lu] = %.1d, ", i, vertices[i]);
    }
    printf("\n");
}