#include "../../structure/headers/stdgl.hpp"

void ex06_text()
{
    GLFWwindow* w = setupWindow("TEXT TEXT");
    Shader program(
        "/Users/rio/Desktop/glgl/src/exs/ex06_text/StandardShading.vert",
        "/Users/rio/Desktop/glgl/src/exs/ex06_text/StandardShading.frag");
    
    // GLuint texture

    initText2D("/Users/rio/Desktop/glgl/src/exs/ex06_text/Holstein.DDS");
    // initText2D("Holstein.DDS");
    GLuint TextureID = glGetUniformLocation(program.shaderProgramId, "myTextureSampler");



    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    while (glfwWindowShouldClose(w) == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.Activate();
        char text[256];        
        sprintf(text, "%.2f sec", glfwGetTime());
        // printText2D(text, 10, 10, 60);

        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, texture)
        glUniform1i(TextureID, 0);

        glfwSwapBuffers(w);
        glfwPollEvents();
    }
    cleanupText2D();
    glfwTerminate();
}