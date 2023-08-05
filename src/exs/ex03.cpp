// #include "../structure/headers/shaderClass.hpp"
#include "../structure/headers/stdgl.hpp"
#include "math.h"

// static GLfloat vertices[] = 
// {
//     // -.5f, 0.f, .0f,
//     // .5f, 0.f, .0f,
//     // .0f, 0.5f, .0f,
//     -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
//     0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
//     -0.5f, 0.5f * float(sqrt(3)) / 3, 0.0f,
// };
static float vertices[] = {
    0.0f, 0.5f,
    0.5f, -0.5f,
    -0.5f, -0.5f
};

static GLuint indices[] = {
    0, 1, 2
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

    // Shader shaderProgram(
    //     "/Users/rio/Desktop/glgl/src/resources/shaders/default.vert",
    //     "/Users/rio/Desktop/glgl/src/resources/shaders/default.frag");

    // --------------------- New version ----------------------------------------------------------------
    VAO vao1;
    vao1.Bind();

    VBO vbo1(vertices, sizeof(vertices));
    // EBO ebo1(indices, sizeof(indices));


    // vao1.LinkVBO(vbo1, 0);
    // vao1.Unbind();
    // vbo1.Unbind();
    // // ebo1.Unbind();
    // --------------------- Old version ----------------------------------------------------------------
    // GLuint vao;
    // glGenVertexArrays(1, &vao);
    // glBindVertexArray(vao); // --> ok

    // GLuint vbo; // --> ok
    // glGenBuffers(1, &vbo); // --> ok
    // glBindBuffer(GL_ARRAY_BUFFER, vbo); //--> ok
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //--> ok
    // std::cout << "vertex buffer object = " << vbo << std::endl;

    Shader shaderProgram(
        "/Users/rio/Desktop/glgl/src/resources/shaders/default.vert",
        "/Users/rio/Desktop/glgl/src/resources/shaders/default.frag");


    // ? Making the linke between vertex data & atributes
    GLint posAttribute = glGetAttribLocation(shaderProgram.shaderProgramId, "position");
    // GLint posAttribute = glGetAttribLocation(sp, "position");
    glVertexAttribPointer(posAttribute, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttribute);




    while (!glfwWindowShouldClose(window))
    {
        // glClearColor(.17f, .13f, .15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // shaderProgram.Activate();        

        // vao1.Bind();

        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
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