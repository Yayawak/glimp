// #include "../structure/headers/shaderClass.hpp"
#include "../structure/headers/stdgl.hpp"
#include "glm/trigonometric.hpp"
#include "math.h"
#include <chrono>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static GLfloat vertices[] = 
{
    // NOTE : position                  ----   color
    // 0.5f, 0.9f,                        0.0f, 1.0f, 0.0f, 0.0f,
    // 0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,  0.0f, 1.0f, 0.0f,
    // -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, 1.0f, 0.0f, 1.0f,
    // -0.5f, 0.5f * float(sqrt(3)) / 3, 0.0f, 0.0f, 1.0f, 0.0f
    0.5f, 0.9f,                         1.0f, 0.0f, 0.0f,
    0.5f, -0.5f * float(sqrt(3)) / 3,   0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f * float(sqrt(3)) / 3, 1.0f, 0.0f, 1.0f,
    -0.5f, 0.5f * float(sqrt(3)) / 3,  0.0f, 1.0f, 1.0f
    // -0.0f, 0.5f * float(sqrt(3)) / 3, 0.0f,
    // 0.5f, 0.5f * float(sqrt(3)) / 3, 0.0f,
};
// static GLfloat vertices[] = 
// {
//     0.5f, 0.9f, 0.0f,
//     0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
//     -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
//     -0.5f, 0.5f * float(sqrt(3)) / 3, 0.0f,
//     // -0.0f, 0.5f * float(sqrt(3)) / 3, 0.0f,
//     // 0.5f, 0.5f * float(sqrt(3)) / 3, 0.0f,
// };
// static float vertices[] = {
//     0.0f, 0.5f,
//     0.5f, -0.5f,
//     -0.5f, -0.5f
// };

static GLuint indices[] = {
    0, 1, 2,
    2, 3, 0
};

int ex03()
{
    // Shader sd("../resources/shaders/defualt.vert",
    //     "../resources/shaders/defualt.frag");
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(700, 500, "EX03", NULL, NULL);
    glfwMakeContextCurrent(window);

    Shader shaderProgram(
        "/Users/rio/Desktop/glgl/src/resources/shaders/default.vert",
        "/Users/rio/Desktop/glgl/src/resources/shaders/default.frag");

    VAO vao1;
    vao1.Bind();

    VBO vbo1(vertices, sizeof(vertices));
    EBO ebo1(indices, sizeof(indices));


    //FIXME: Still not implemented stride.
    // vao1.LinkVBO(vbo1, 0);

    //ANCHOR Manually Get Attributes from shader program
    GLint positionAttrib = glGetAttribLocation(shaderProgram.shaderProgramId, "position");
    glEnableVertexAttribArray(positionAttrib);
    glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, GL_FALSE,
        5 * sizeof(float), 0);

    GLint colorAttrib = glGetAttribLocation(shaderProgram.shaderProgramId, "color");
    glEnableVertexAttribArray(colorAttrib);
    // * 3 is r, g, b components
    glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE,
        5 * sizeof(float), (void *)(2 * sizeof(float))
    );
    


    // vbo1.Unbind();
    // ebo1.Unbind();

    // GLint positionAtt


    GLint uniTransform = glGetUniformLocation(shaderProgram.shaderProgramId, "trans");
    glm::mat4 trans(1.0f);
    auto t_start = std::chrono::high_resolution_clock::now();

    while (!glfwWindowShouldClose(window))
    {
        // glClearColor(.17f, .13f, .15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // shaderProgram.Activate();        

        // vao1.Bind();

        //NOTE - Transform Matrix
        // glm::mat4 trans(1.0f);
        auto now = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::duration<float> >(now - t_start).count();
        trans = glm::rotate(trans,
            // glm::radians(1.0f) * time,
            glm::radians(1.0f),
            glm::vec3(0.0f, 0.0f, 1.0f));

        // glm::value_ptr(trans);
        glUniformMatrix4fv(uniTransform, 1, GL_FALSE, 
            glm::value_ptr(trans)
        );
        // ------------------- end transform ---------------
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawArrays(GL_TRIANGLES, 0, 4);
        // glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // vao1.Delete();
    // vbo1.Delete();
    // ebo1.Delete();
    // shaderProgram.Delete();


    glfwDestroyWindow(window);
    glfwTerminate();

    return (0);
}