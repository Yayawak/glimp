#ifndef Plane_H
#define Plane_H
// // #include "../includes/stdEngine.hpp"
#include "EnObject.hpp"
#include "glm/glm.hpp"
#include <cmath>

// // static GLfloat vertices[] = {
// //     5
// // };

// class Plane : public EnObject
// {

// public:
//     void init();
//     void always();
//     void clear();

// private: 
// };
// static const GLfloat g_vertex_buffer_data[] = { 

static const GLfloat triangle_buffer_data[] = { 2.0f, 0.5f, 0.0f,
                                                1.5, 0.5, 0.0f,
                                                2.0f, 1.0f, 0.0f};



class Plane : public EnObject
{
public:

    // GLfloat startTime;
    GLfloat startTime = glfwGetTime();
    Plane()
    {
        // Vertex vertices[] = 
        // GLfloat vertices[] = 
        // // std::vector<GLfloat> v(
        // {
        //     // pos                         // color                     // texcoord
        //     // glm::vec3(-0.5f,  0.5f,  0.f)
        //     // glm::vec3(-0.5f, -0.5f,  0.f),
        //     // glm::vec3( 0.5f, -0.5f,  0.f),
        //     // glm::vec3( 0.5f,  0.5f,  0.f),

        //     -0.5f,  0.5f,  0.f
        //     -0.5f, -0.5f,  0.f,
        //     0.5f, -0.5f,  0.f,
        //     0.5f,  0.5f,  0.f,
        // };
        // this->vertices = glfToVec(vertices, sizeof(vertices) / sizeof(GLfloat));

        // GLuint indices[] = 
        // {
        //     0, 1, 2,
        // };
        // this->indices = gluiToVec(indices, size_t(sizeof(indices)) / sizeof(GLuint));

        shaderProgram = new Shader(
            "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.vert",
            "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.frag"
        );
        std::cout << "set up all configuration.\n";
    }

    // void Plane::init()
    void init()
    {
    }

    // void Plane::always()
    void always()
    {
        // * ---------- making set up -------------
        // std::cout << "always" << std::endl;
        shaderProgram->Activate();
        // vao = new VAO();

        // GLfloat v[] = 
        // {
        //     // pos                         // color                     // texcoord
        //     -0.5f,  0.5f,  0.f,
        //     -0.5f, -0.5f,  0.f,
        //     0.5f, -0.5f,  0.f,
        //     0.5f,  0.5f,  0.f,
        // };
        // // this->vertices = glfToVec(v, sizeof(vertices) / sizeof(GLfloat));
        vao->Bind();

        // GLuint indices[] = 
        // {
        //     0, 1, 2,
        // };

        // * --------- experiament ------
        // * ---------- making linking -------------

GLfloat g_vertex_buffer_data[] = { 
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
};
        // vbo = new VBO(vertices, sizeof(vertices));
        // vbo = new VBO(v, sizeof(v));
        vbo = new VBO(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
        // ebo = new EBO(indices, sizeof(indices));
        // ebo = new EBO(tempIndices, sizeof(tempIndices));
        // ebo = new EBO(, sizeof(tempIndices));
        // vbo = new VBO(vertices);
        // ebo = new EBO(indices);

        // postion only
        vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        // camera.computeMatricesFromInputs(*shaderProgram, "camMatrix");
        // vecshow()
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        // shaderProgram->Activate();
        // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, indices.size() * sizeof(GLuint), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, indices.size() * sizeof(indices[0]), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(), GL_UNSIGNED_INT, 0);

        // vao->Delete();
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