// #ifndef Plane_H
// #define Plane_H
// // // #include "../includes/stdEngine.hpp"
// #include "EnObject.hpp"
// #include "glm/glm.hpp"
// #include <cmath>

// // // static GLfloat vertices[] = {
// // //     5
// // // };

// // class Plane : public EnObject
// // {

// // public:
// //     void init();
// //     void always();
// //     void clear();

// // private: 
// // };

// class Plane : public EnObject
// {
// public:

//     // GLfloat startTime;
//     GLfloat startTime = glfwGetTime();
//     Plane()
//     {
//         // Vertex vertices[] = 
//         // GLfloat vertices[] = 
//         // // std::vector<GLfloat> v(
//         // {
//         //     // pos                         // color                     // texcoord
//         //     // glm::vec3(-0.5f,  0.5f,  0.f)
//         //     // glm::vec3(-0.5f, -0.5f,  0.f),
//         //     // glm::vec3( 0.5f, -0.5f,  0.f),
//         //     // glm::vec3( 0.5f,  0.5f,  0.f),

//         //     -0.5f,  0.5f,  0.f
//         //     -0.5f, -0.5f,  0.f,
//         //     0.5f, -0.5f,  0.f,
//         //     0.5f,  0.5f,  0.f,
//         // };
//         // this->vertices = glfToVec(vertices, sizeof(vertices) / sizeof(GLfloat));

//         // GLuint indices[] = 
//         // {
//         //     0, 1, 2,
//         // };
//         // this->indices = gluiToVec(indices, size_t(sizeof(indices)) / sizeof(GLuint));

//         shaderProgram = new Shader(
//             "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.vert",
//             "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.frag"
//         );
//         std::cout << "set up all configuration.\n";
//     }

//     // void Plane::init()
//     void init()
//     {
//     }

//     // void Plane::always()
//     void always()
//     {
//         // * ---------- making set up -------------
//         // std::cout << "always" << std::endl;
//         shaderProgram->Activate();
//         // vao = new VAO();

//         // GLfloat v[] = 
//         // {
//         //     // pos                         // color                     // texcoord
//         //     -0.5f,  0.5f,  0.f,
//         //     -0.5f, -0.5f,  0.f,
//         //     0.5f, -0.5f,  0.f,
//         //     0.5f,  0.5f,  0.f,
//         // };
//         // // this->vertices = glfToVec(v, sizeof(vertices) / sizeof(GLfloat));
//         vao->Bind();

//         // GLuint indices[] = 
//         // {
//         //     0, 1, 2,
//         // };

//         // * --------- experiament ------

//         // Camera camera(1024, 1024, glm::vec3(0.0f, 0.5f, 0.7f));
//         // camera.PaneCamera(*shaderProgram, "transf");
//         // camera.PaneCamera(shaderProgram,)

//         GLfloat now = glfwGetTime();
//         float sval = sin(now - startTime);

//         // glm::vec3 startPos(0, 0, 0);
//         // glm::vec3 startPos(sval, 0, 0);
//         glm::vec3 startPos(sval, sval, sval);
//         // glm::vec3 endPos(5, 5, 5);
//         glm::vec3 endPos(-0.3, -0.3, 0.3);
//         glm::vec3 deltaVec = abs(startPos - endPos);
//         // deltaVec = startPos - endPos;
//         glm::vec3 octCoords[8];

//         for (int i = 0; i < 7; i++)
//         {
//             octCoords[i] = glm::vec3(startPos); // copy of start position
//         }
//         octCoords[1] += glm::vec3(deltaVec.x, 0, 0);
//         octCoords[2] += glm::vec3(0, 0, deltaVec.z);
//         octCoords[3] += glm::vec3(deltaVec.x, 0, deltaVec.z);
//         octCoords[4] += glm::vec3(0, deltaVec.y, 0);
//         octCoords[5] += glm::vec3(deltaVec.x, deltaVec.y, 0);
//         octCoords[6] += glm::vec3(0, deltaVec.y, deltaVec.z);
//         octCoords[7] = endPos;

//         for (int i = 0; i < 8; i++)
//         {
//             // std::cout << octCoords[i]
//             // vecshow(octCoords[i]);
//             // printf("")
//         }

//         // vertices[0] = octCoords[0].x;
//         // vertices[1] = octCoords[0].y;
//         // vertices[2] = octCoords[0].z;

//         // vertices[3] = octCoords[1].x;

//         GLfloat v[8 * 3];

//         for (int i = 0; i < 8; i++)
//         {
//             int j = 3 * i;
//             v[j + 0] = octCoords[i].x;
//             v[j + 1] = octCoords[i].y;
//             v[j + 2] = octCoords[i].z;
//         }
//         // * pass test
//         // for (int i = 0; i < sizeof(vertices) / sizeof(float); i++)
//         // {
//         //     // std::cout << vertices[i] << ", ";
//         // }
//         GLuint tempIndices[] = {
//             0, 3, 1,
//             0, 3, 2,

//             2, 4, 0,
//             2, 4, 6,

//             3, 5, 1,
//             3, 5, 7,

//             0, 5, 4,
//             0, 5, 1,

//             4, 7, 5,
//             4, 7, 6,

//             2, 7, 3,
//             2, 7, 6
//         };
//         // for (int i = 0; i < sizeof(tempIndices) / sizeof(GLuint); i++)
//         // // for (int i = 0; i < 6; i++)
//         // {
//         //     std::cout << i << ", ";
//         //     tempIndices[i]--;
//         // }
        






//         // * ---------- making linking -------------

//         // vbo = new VBO(vertices, sizeof(vertices));
//         vbo = new VBO(v, sizeof(v));
//         // ebo = new EBO(indices, sizeof(indices));
//         ebo = new EBO(tempIndices, sizeof(tempIndices));
//         // vbo = new VBO(vertices);
//         // ebo = new EBO(indices);

//         // postion only
//         vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);

//         // camera.computeMatricesFromInputs(*shaderProgram, "camMatrix");
//         // vecshow()
//         // glDrawArrays(GL_TRIANGLES, 0, 3);
//         // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
//         glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
//         // shaderProgram->Activate();
//         // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(int), GL_UNSIGNED_INT, 0);
//         // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(int), GL_UNSIGNED_INT, 0);
//         // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
//         // glDrawElements(GL_TRIANGLES, indices.size() * sizeof(GLuint), GL_UNSIGNED_INT, 0);
//         // glDrawElements(GL_TRIANGLES, indices.size() * sizeof(indices[0]), GL_UNSIGNED_INT, 0);
//         // glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//         // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
//         // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(), GL_UNSIGNED_INT, 0);

//         // vao->Delete();
//         vbo->Delete();
//         ebo->Delete();
//     }

//     // void Plane::clear()
//     void clear()
//     {
//         // vao->Delete();
//         // shaderProgram->Delete();
//     }

// };
// #endif