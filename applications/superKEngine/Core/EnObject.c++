#include "../includes/EnObject.hpp"

// EnObject::EnObject()
// {
//     // vao = new VAO();
//     shaderProgram = NULL;
//     // attach to first starting program section ? (globally)
//     // init();
// }

Shader  *EnObject::getShaderProgramPtr()
{
    Shader *ptr = shaderProgram;
    return (ptr);
}

// // void EnObject::always()
// // {
// //     clear();
// // }