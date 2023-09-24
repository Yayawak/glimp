#ifndef Plane_H
#define Plane_H
#include "EnObject.hpp"
#include "glm/glm.hpp"
#include <cmath>


// static const GLfloat triangle_buffer_data[] = { 2.0f, 0.5f, 0.0f,
//                                                 1.5, 0.5, 0.0f,
//                                                 2.0f, 1.0f, 0.0f};
// static GLfloat g_vertex_buffer_data[] = { 
// static GLfloat g_vertex_buffer_data[] = { 
//     -1.0f,-1.0f,-1.0f,
//     -1.0f,-1.0f, 1.0f,
//     -1.0f, 1.0f, 1.0f,
//         1.0f, 1.0f,-1.0f,
//     -1.0f,-1.0f,-1.0f,
//     -1.0f, 1.0f,-1.0f,
//         1.0f,-1.0f, 1.0f,
//     -1.0f,-1.0f,-1.0f,
//         1.0f,-1.0f,-1.0f,
//         1.0f, 1.0f,-1.0f,
//         1.0f,-1.0f,-1.0f,
//     -1.0f,-1.0f,-1.0f,
//     -1.0f,-1.0f,-1.0f,
//     -1.0f, 1.0f, 1.0f,
//     -1.0f, 1.0f,-1.0f,
//         1.0f,-1.0f, 1.0f,
//     -1.0f,-1.0f, 1.0f,
//     -1.0f,-1.0f,-1.0f,
//     -1.0f, 1.0f, 1.0f,
//     -1.0f,-1.0f, 1.0f,
//         1.0f,-1.0f, 1.0f,
//         1.0f, 1.0f, 1.0f,
//         1.0f,-1.0f,-1.0f,
//         1.0f, 1.0f,-1.0f,
//         1.0f,-1.0f,-1.0f,
//         1.0f, 1.0f, 1.0f,
//         1.0f,-1.0f, 1.0f,
//         1.0f, 1.0f, 1.0f,
//         1.0f, 1.0f,-1.0f,
//     -1.0f, 1.0f,-1.0f,
//         1.0f, 1.0f, 1.0f,
//     -1.0f, 1.0f,-1.0f,
//     -1.0f, 1.0f, 1.0f,
//         1.0f, 1.0f, 1.0f,
//     -1.0f, 1.0f, 1.0f,
//         1.0f,-1.0f, 1.0f
// };
// float ver[8 * 3] = 
// ! must be static
// static GLfloat ver[] = 
static GLfloat ver[] = 
{
    -1.0,-1.0,1.0,
    -1.0,1.0,1.0,
    1.0,1.0,1.0,
    1.0,-1.0,1.0,
    -1.0,-1.0,-1.0,
    -1.0,1.0,-1.0,
    1.0,1.0,-1.0,
    1.0,-1.0,-1.0,
};
// GLfloat *ptrVtx= ver;
// static GLfloat ver[] = 
// {
//     -1.0,-1.0,1.0,
//     -1.0,1.0,1.0,
//     1.0,1.0,1.0,
// };

// { -1, -1, -1,
// 1, -1, -1,
// 1, 1, -1,
// -1, 1, -1,
// -1, -1, 1,
// 1, -1, 1,
// 1, 1, 1,
// -1, 1, 1
// };

// GLuint inds[4 * 6] = 
// ! must be static
static GLuint inds[] = 
// GLuint inds[] = 
// GLuint inds[] = 
{
    0,3,2,1,
    2,3,7,6,
    0,4,7,3,
    1,2,6,5,
    4,5,6,7,
    0,1,5,4,
};
// int *ptrInds = inds;

// {0, 3, 2, 1,
//  2, 3, 7, 6,
//  0, 4, 7, 3,
//  1, 2, 6, 5,
//  4, 5, 6, 7,
//  0, 1, 5, 4 };

// {0, 1, 2};



class Cube : public EnObject
{
private:
    float width;
    float height;
    float detph;

public:

    // GLfloat startTime;
    GLfloat startTime = glfwGetTime();
    Cube() : EnObject(0, 0, 0, 0)
    {
        shaderProgram = new Shader(
            "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.vert",
            "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.frag"
        );

        // std::cout << "set up all configuration.\n";
        // vertices = glfToVec(g_vertex_buffer_data, sizeof(g_vertex_buffer_data) / sizeof(GLfloat));
        // vertices = g_vertex_buffer_data;
        // noOfVertices = sizeof(g_vertex_buffer_data) / sizeof(GLfloat);
        
        for (int i = 0; i < 8; i++)
        {
            Vertex v;
            // for (int j = 0; j < 3; j++)
            // {
            //     v.position 
            // }
            // v.position = glm::vec3((i * 3) + 0, )
            v.position.x = ver[(i * 3) + 0];
            v.position.y = ver[(i * 3) + 1];
            v.position.z = ver[(i * 3) + 2];
            vertices.push_back(v);
        }

        // vertices = ver;
        // vertices = ptrVtx;
        // noOfVertices = sizeof(ver) / sizeof(GLfloat);
        noOfVertices = 8;

        // indices = inds;

        // indices = ptrInds;
        // noOfIndices = sizeof(inds) / sizeof(GLuint);
        noOfIndices = 4 * 8;

        // showvertices(GLfloat *vertices, size_t size)
        // scale(glm::vec3(1.5, 0.2, 1.5));
        // showvertices(indices, noOfIndices);
    }

    // void Plane::init()
    void init()
    {
    }


    // void Plane::always()
    void always()
    {
        // * ---------- making set up -------------
        shaderProgram->Activate();
        vao->Bind();
        // * --------- experiament ------
        // * ---------- making linking -------------

        // vbo = new VBO(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
        // vbo = new VBO(vertices, noOfVertices * sizeof(GLfloat));
        // vbo = new VBO(vertices.data());
        // vbo = new VBO(vertices.data(), noOfVertices * sizeof(GLfloat));
        vbo = new VBO(vertices);
        // ebo = new EBO(indices, noOfIndices * sizeof(GLuint));

        // scale(glm::vec3(2, 1, 1));

        // postion only
        vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);

        // glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_INT, 0);
        // glDrawArrays(GL_TRIANGLES, 0, 36);
        glDrawArrays(GL_TRIANGLES, 0, 8);
        // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, 4 * 6, GL_UNSIGNED_BYTE, indices);
        // glDrawElements(GL_QUADS, 4 * 6, GL_UNSIGNED_BYTE, indices);

        vbo->Delete();
        // ebo->Delete();
    }

    // void Plane::clear()
    void clear()
    {
        // vao->Delete();
        // shaderProgram->Delete();
    }

};
#endif