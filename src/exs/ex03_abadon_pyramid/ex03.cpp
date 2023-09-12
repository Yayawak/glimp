#include "../../structure/headers/stdgl.hpp"
#include "glm/fwd.hpp"
#include <type_traits>

static const char *texPath = "img/abadon.png";
// static const char *texPath = "img/sexyboy.png";
static GLfloat vertices[] = 
{
    // NOTE : position   |        color       | texCoordiation
    -0.5f,  +0.0f, +0.5f,  0.83f, 0.70f, 0.44f,   0.0f, 0.0f,
    -0.5f,  +0.0f, -0.5f,  0.83f, 0.70f, 0.44f,   5.0f, 0.0f,
    +0.5f,  +0.0f, -0.5f,  0.83f, 0.70f, 0.44f,   0.0f, 0.0f,
    +0.5f,  +0.0f, +0.5f,  0.83f, 0.70f, 0.44f,   5.0f, 0.0f,
    +0.0f,  +0.8f, +0.0f,  0.92f, 0.86f, 0.75f,   2.5f, 5.0f
};

static GLuint indices[] = {
    0, 1, 2,
    0, 2, 3,
    0, 1, 4,
    1, 2, 4,
    2, 3, 4,
    3, 0, 4
};

// static glm::mat4 trans(1.0f);

// static void keyInputManagerFn(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
//     {
//         // flip();
//     }
// }
static int screen_height = 600;
static int screen_width = 800;

int ex03()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // GLFWwindow *window = glfwCreateWindow(700, 500, "EX03", NULL, NULL);
    GLFWwindow *window = glfwCreateWindow(screen_width, screen_height, "EX03", NULL, NULL);
    // glfwSetKeyCallback(window, keyInputManagerFn);
    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);
    // glEnable(GL_STENCIL_TEST);

    // glStencilFunc(GL_GEQUAL, 2, 0xFF);
    // glStencilFunc(GL_LESS, 2, 0xFF);

    Shader shaderProgram(
        "/Users/rio/Desktop/glgl/src/exs/ex03_abadon_pyramid/default.vert",
        "/Users/rio/Desktop/glgl/src/exs/ex03_abadon_pyramid/default.frag"
    );

    VAO vao1;
    vao1.Bind();

    VBO vbo1(vertices, sizeof(vertices));
    EBO ebo1(indices, sizeof(indices));


    vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0);
    vao1.LinkAttrib(vbo1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    vao1.LinkAttrib(vbo1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *)(6 * sizeof(float)));

    
    Texture tex(texPath,
        GL_TEXTURE_2D, GL_TEXTURE0,
        GL_RGB, GL_UNSIGNED_BYTE
    );
    tex.texUnit(shaderProgram, "tex0", 0);
    // vao1.Unbind();
    // vbo1.Unbind();
    // ebo1.Unbind();



    // Camera camera(screen_width, screen_height, glm::vec3(-0.8f, 0.0f, 0.0f));
    Camera camera(screen_width, screen_height, glm::vec3(0.0f, 0.5f, 0.7f));
    // Camera camera(screen_width, screen_height,
    //     glm::vec3(0.0f, 1.f, 0.7f));
    // camera.Orientation = glm::vec3(1.0f, 0.0f, 0.0f);
    // camera.Orientation = glm::vec3(0.0f, 0.0f, -2.0f);
    // camera.Orientation = glm::vec3(0.0f, 0.0f, -2.0f);
    camera.PaneCamera(shaderProgram, "transf");
    // Camera camera(screen_width, screen_height,
        // glm::vec3(2.0f, 2.0f, 2.0f));


    while (!glfwWindowShouldClose(window))
    {
        glClearColor(.17f, .13f, .15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shaderProgram.Activate();        

        // vao1.Bind(); // ? for what

        tex.Bind();


        // NOTE : New way to control input (with mouse)
        camera.computeMatricesFromInputs(window, shaderProgram, "camMatrix");
        //TODO  modulate
        // camera.Inputs(window);
        // camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");
        // camera.Matrix(145.0f, 0.01f, 100.0f, shaderProgram, "camMatrix");

        if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
            camera.PaneCamera(shaderProgram, "transf", glm::vec3(1.0f, 0.0f, 0.0f));
        if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
            camera.PaneCamera(shaderProgram, "transf", glm::vec3(0.0f, 1.0f, 0.0f));
        if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS)
            camera.PaneCamera(shaderProgram, "transf", glm::vec3(0.0f, 0.0f, 1.0f));


        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    vao1.Delete();
    vbo1.Delete();
    ebo1.Delete();
    tex.Delete();
    shaderProgram.Delete();


    glfwDestroyWindow(window);
    glfwTerminate();

    return (0);
}