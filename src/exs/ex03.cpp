// #include "../structure/headers/shaderClass.hpp"
#include "../structure/headers/stdgl.hpp"

// ? Use for 2d image 
static GLfloat vertices[] = 
{
    // NOTE : position                |        color
    // 0.5f, 0.9f,                        0.0f, 1.0f, 0.0f, 0.0f,
    // 0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,  0.0f, 1.0f, 0.0f,
    // -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, 1.0f, 0.0f, 1.0f,
    // -0.5f, 0.5f * float(sqrt(3)) / 3, 0.0f, 0.0f, 1.0f, 0.0f
    0.5f, 0.9f,                         1.0f, 0.0f, 0.0f,
    0.5f, -0.5f * float(sqrt(3)) / 3,   0.1f, 0.1f, 0.5f,
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, 1.0f, 0.0f,
    -0.5f, 0.5f * float(sqrt(3)) / 3,  0.0f, 1.0f, 1.0f
    // -0.0f, 0.5f * float(sqrt(3)) / 3, 0.0f,
    // 0.5f, 0.5f * float(sqrt(3)) / 3, 0.0f,
};
// static float vertices[] = {
//   // X      Y     Z     R     G     B     U     V
//     -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
//     0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
//     0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
//     -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
// };
// ? Cube
// GLfloat vertices[] = {
//     //NOTE position     | color          | texture
//     -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
//     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
//     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

//     -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
//     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,

//     -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
//     -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
//     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
//     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
//     0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

//     -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
//     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
//     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
//     -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
//     -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

//     -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
//     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
//     -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f
// };

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

// static glm::mat4 trans(1.0f);
// static glm::mat4 view = glm::lookAt(
//     glm::vec3(1.2f, 1.2f, 1.2f),
//     // glm::vec3(2, 2, 2),
//     // glm::vec3(4, 4, 4),
//     glm::vec3(0.0f),
//     glm::vec3(.0f, .0f, 1.f)
// );   


static GLuint indices[] = {
    0, 1, 2,
    2, 3, 0
};

// static void keyInputManagerFn(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
//     {
//         // flip();
//     }
// }

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
    // glfwSetKeyCallback(window, keyInputManagerFn);
    glfwMakeContextCurrent(window);
    // glEnable(GL_DEPTH_TEST);
    // glEnable(GL_STENCIL_TEST);

    // glStencilFunc(GL_GEQUAL, 2, 0xFF);
    // glStencilFunc(GL_LESS, 2, 0xFF);

    Shader shaderProgram(
        "/Users/rio/Desktop/glgl/src/resources/shaders/default.vert",
        "/Users/rio/Desktop/glgl/src/resources/shaders/default.frag");

    VAO vao1;
    vao1.Bind();

    VBO vbo1(vertices, sizeof(vertices));
    EBO ebo1(indices, sizeof(indices));


    //FIXME: Still not implemented stride.
    // vao1.LinkVBO(vbo1, 0); // -> old code for only positions componentes (can not use with colors, etc....)
    vao1.LinkAttrib(vbo1, 0, 2, GL_FLOAT, 5 * sizeof(float), (void *)0);
    vao1.LinkAttrib(vbo1, 1, 3, GL_FLOAT, 5 * sizeof(float), (void *)(3 * sizeof(float)));

    

    //ANCHOR Manually Get Attributes from shader program
    // GLint positionAttrib = glGetAttribLocation(shaderProgram.shaderProgramId, "position");
    // glEnableVertexAttribArray(positionAttrib);
    // glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, GL_FALSE,
    //     sizeof(float), 0);
        // 5 * sizeof(float), 0);
    // glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, GL_FALSE,
    //     8 * sizeof(float), 0);

    


    // GLint colorAttrib = glGetAttribLocation(shaderProgram.shaderProgramId, "color");
    // glEnableVertexAttribArray(colorAttrib);
    // // * 3 is r, g, b components
    // // glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE,
    // //     5 * sizeof(float), (void *)(2 * sizeof(float)));
    // glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE,
    //     8 * sizeof(float), (void *)(3 * sizeof(float)));
    


    // GLint texAtt = glGetAttribLocation(shaderProgram.shaderProgramId, "texCoord");
    // glEnableVertexAttribArray(texAtt);
    // // * 3 is r, g, b components
    // // glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE,
    // //     5 * sizeof(float), (void *)(2 * sizeof(float)));
    // glVertexAttribPointer(texAtt, 3, GL_FLOAT, GL_FALSE,
    //     8 * sizeof(float), (void *)(6 * sizeof(float)));
    

    // vbo1.Unbind();
    // ebo1.Unbind();

    // GLint positionAtt

    auto t_start = std::chrono::high_resolution_clock::now();

    // GLint uniTransform = glGetUniformLocation(shaderProgram.shaderProgramId, "trans");

    // view = glm::mat4(1.f);
    // GLint uniView = glGetUniformLocation(shaderProgram.shaderProgramId, "view");
    

    // glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));
    // glm::mat4 proj = glm::perspective(
    //     glm::radians(45.f), 
    //     800.0f / 600.0f,
    //     1.0f,
    //     10.f
    // );
    // GLint uniProj = glGetUniformLocation(shaderProgram.shaderProgramId, "proj");
    // glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));

    GLint uniScale = glGetUniformLocation(shaderProgram.shaderProgramId, "scale");
    // glUniform1f(uniScale, 1.5f);

    while (!glfwWindowShouldClose(window))
    {
        // glClearColor(.17f, .13f, .15f, 1.0f);
        // ? old 
        glClear(GL_COLOR_BUFFER_BIT);
        // * for depth testing
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shaderProgram.Activate();        

        // vao1.Bind();

        //NOTE - Transform Matrix
        // glm::mat4 trans(1.0f);
        auto now = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::duration<float> >(now - t_start).count();

        // glUniform1f(uniScale, (int(time) % 3));
        glUniform1f(uniScale, time);

        // trans = glm::rotate(trans,
        //     // glm::radians(1.0f) * time,
        //     glm::radians(1.0f),
        //     // glm::vec3(0.0f, 0.0f, 1.0f));
        //     glm::vec3(0.0f, time, time));
        //     // glm::vec3(time, time, time));
        // float s = sin(time * 5.f) * 0.25f + 1.75f;
        // float s = sin(time * 5.f) * .15f + 1.f;
        // std::cout << "sin value : " << s << std::endl;
        // trans = glm::scale(trans, 
        //     glm::vec3(s, s, s) 
        // );

        // glUniformMatrix4fv(uniTransform, 1, GL_FALSE, glm::value_ptr(trans));
        // glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));
        // ------------------- end transform ---------------
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawArrays(GL_TRIANGLES, 0, 36);
        // glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    vao1.Delete();
    vbo1.Delete();
    ebo1.Delete();
    shaderProgram.Delete();


    glfwDestroyWindow(window);
    glfwTerminate();

    return (0);
}