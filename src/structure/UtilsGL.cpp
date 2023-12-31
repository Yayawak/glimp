#include "headers/utilsGL.hpp"

void vecshow(glm::vec3 v, bool appendNewLine)
{
    // printf("vec[%f, %f, %f]\n", v.x, v.y, v.z);    
    // printf("[%.2f, %.2f, %.2f]", v.x, v.y, v.z);    
    // printf("[%2.2f, %2.2f, %2.2f]", v.x, v.y, v.z);    
    if (appendNewLine)
        printf("[% 0.2f, % 0.2f, % 0.2f]\n", v.x, v.y, v.z);    
    else
        printf("[% 0.2f, % 0.2f, % 0.2f]", v.x, v.y, v.z);    
}

void vecshow(glm::vec2 v)
{
    printf("[% .2f, % .2f]", v.x, v.y);    
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
    printf("printing vertices data of size[%lu]\n", size);
    for (size_t i = 0; i < size; i++)
    {
        // printf("v[%lu] = %.1f, ", i, vertices[i]);
        printf("%.1f ", vertices[i]);
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

void showvertices(std::vector<Vertex> vexs)
{
    printf("No of vertices = %lu\n", vexs.size());
    printf("position 3 | color 3 | texcoord 2 | normal 3\n");
    for (int i = 0; i < vexs.size(); i++)
    {
        Vertex cur = vexs[i];
        // printf("pos[%f, %f, %f]\n", cur.position)
        // printf("pos[%d]:", i);
        printf("pos");
        vecshow(cur.position);
        printf(" | ");

        printf("col");
        vecshow(cur.color);
        printf(" | ");

        printf("tex");
        vecshow(cur.texcoord);
        printf(" | ");

        printf("nom");
        vecshow(cur.normal);
        printf(" | ");

        printf("\n");       
    }
}

float lerp(float x0, float x1, float y0, float y1, float xToPredict)
{
    assert(x1 - x0 != 0);
    float m = (y1 - y0) / (x1 - x0);
    float ret = (m * xToPredict) + y0;
    // assert(y0 < ret && ret < y1);
    assert(y0 <= ret <= y1);
    return ret;
}