// #include "../../includes/Plane.hpp"
// // #include "../../includes/stdEngine.hpp"
// #include "../../../../src/structure/headers/stdgl.hpp"

// // let say 
// /*
//        * ---- *
//       /      /|
//      /     /  |
//     * ---- *  |
//     |      |  | 
//     |  *   |  *
//     |      | /
//     * ---- *
       
//        Z
//        ^
//        | 
//        |
//       / ---> X
//      /
//    Y

//        1 ---- 2
//       /      /|
//      /     /  |
//     5 ---- 6  |
//     |      |  | 
//     |  3   |  4
//     |      | /
//     7 ---- 8

//     1 -> start, 8 -> end

//     2 = 1 + x
//     3 = 1 + z
//     4 = 1 + x + z
//     5 = 1 + y
//     6 = 1 + x + y
//     7 = 1 + y + z
//     8 = 1 + x + y + z

//     ebo -> ...
//     // back
//     1, 2, 4,
//     1, 3, 4,
//     // left
//     1, 5, 7,
//     1, 3, 7,
//     // top
//     1, 2, 6,
//     1, 5, 6,
//     //right
//     2, 4, 8,
//     2, 6, 8,
//     // front
//     5, 6, 8,
//     5, 7, 6,
//     // bottom
//     3, 4, 8,
//     3, 7, 8

// */

// // Plane::Plane(glm::vec3 startPos, glm::vec3 endPos, COLORENUM color)
// Plane::Plane(glm::vec3 startPos, glm::vec3 endPos)
//     : startPos(startPos), endPos(endPos)
// {
//     shaderProgram = new Shader(
//         "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.vert",
//         "/Users/rio/Desktop/glgl/applications/superKEngine/Core/Plane/default.frag"
//     );
//     deltaVec = abs(startPos - endPos);
//     // deltaVec = startPos - endPos;

//     for (int i = 0; i < 7; i++)
//     {
//         octCoords[i] = glm::vec3(startPos); // copy of start position
//     }
//     octCoords[1] += glm::vec3(deltaVec.x, 0, 0);
//     octCoords[2] += glm::vec3(0, 0, deltaVec.z);
//     octCoords[3] += glm::vec3(deltaVec.x, 0, deltaVec.z);
//     octCoords[4] += glm::vec3(0, deltaVec.y, 0);
//     octCoords[5] += glm::vec3(deltaVec.x, deltaVec.y, 0);
//     octCoords[6] += glm::vec3(0, deltaVec.y, deltaVec.z);
//     octCoords[7] = endPos;

//     for (int i = 0; i < 8; i++)
//     {
//         // std::cout << octCoords[i]
//         vecshow(octCoords[i]);
//         // printf("")
//     }

//     // vertices[0] = octCoords[0].x;
//     // vertices[1] = octCoords[0].y;
//     // vertices[2] = octCoords[0].z;

//     // vertices[3] = octCoords[1].x;

//     for (int i = 0; i < 8; i++)
//     {
//         int j = 3 * i;
//         vertices[j + 0] = octCoords[i].x;
//         vertices[j + 1] = octCoords[i].y;
//         vertices[j + 2] = octCoords[i].z;
//     }
//     // * pass test
//     for (int i = 0; i < sizeof(vertices) / sizeof(float); i++)
//     {
//         std::cout << vertices[i] << ", ";
//     }
//     // GLuint tempIndices[36] = {
//     //     //back
//     //     1, 2, 4,
//     //     1, 3, 4,
//     //     // left
//     //     1, 5, 7,
//     //     1, 3, 7,
//     //     // top
//     //     1, 2, 6,
//     //     1, 5, 6,
//     //     //right
//     //     2, 4, 8,
//     //     2, 6, 8,
//     //     // front
//     //     5, 6, 8,
//     //     5, 7, 6,
//     //     // bottom
//     //     3, 4, 8,
//     //     3, 7, 8
//     // };
//     GLuint tempIndices[] = {
//         0, 3, 1,
//         0, 3, 2,

//         2, 4, 0,
//         2, 4, 6,

//         3, 5, 1,
//         3, 5, 7,

//         0, 5, 4,
//         0, 5, 1,

//         4, 7, 5,
//         4, 7, 6,

//         2, 7, 3,
//         2, 7, 6
//     };
//     // for (int i = 0; i < sizeof(tempIndices) / sizeof(GLuint); i++)
//     // // for (int i = 0; i < 6; i++)
//     // {
//     //     std::cout << i << ", ";
//     //     tempIndices[i]--;
//     // }
//     *indices = tempIndices;

//     // std::cout << "Enter constructure of plane.\n";
// }

// void Plane::init()
// {
// }

// void Plane::always()
// {
//     shaderProgram->Activate();
//     vao = new VAO();
//     vao->Bind();
//     vao->Bind();

//     vbo = new VBO(vertices, sizeof(vertices));
//     ebo = new EBO(*indices, sizeof(*indices));

//     // postion only
//     vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);
//     // shaderProgram->Activate();
//     // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(int), GL_UNSIGNED_INT, 0);
//     // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(int), GL_UNSIGNED_INT, 0);
//     glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//     // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
//     // glDrawElements(GL_TRIANGLES, sizeof(*indices) / sizeof(), GL_UNSIGNED_INT, 0);

//     // vao->Delete();
//     vbo->Delete();
//     ebo->Delete();
//     vao->Delete();
// }

// void Plane::clear()
// {
//     // vao->Delete();
//     // shaderProgram->Delete();
// }
