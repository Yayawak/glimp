// #ifndef Plane_H
// #define Plane_H
// // #include "../includes/stdEngine.hpp"
// #include "EnObject.hpp"
// #include "glm/glm.hpp"

// // static GLfloat vertices[] = {
// //     5
// // };

// class Plane : public EnObject
// {

// public:
//     glm::vec3 startPos;
//     glm::vec3 endPos;
//     // COLORENUM color;

//     // Plane(glm::vec3 startPos, glm::vec3 endPos, COLORENUM color);
//     Plane(glm::vec3 startPos, glm::vec3 endPos);
//     void init();
//     void always();
//     void clear();

// private: 
//     // 8 is oct , 3 is xyz, 3 is rgb
//     // GLfloat vertices[8 * (3 + 3)];
//     GLfloat vertices[8 * (3)];
//     // 6 sides x 6 needed sub-vertices
//     GLuint *indices[6 * 6];
//     // float dz;
//     // float dx;
//     // float dy;
//     glm::vec3 deltaVec;
//     glm::vec3 octCoords[8];
// };

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
// */
// #endif