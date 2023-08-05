#include "../inc/jstd.hpp"
#include "GLFW/glfw3.h"
#include "glm/gtc/type_ptr.hpp"
#include <ostream>

class GlLifeCycle;
static GLuint createRect(GlLifeCycle *glc);


static const char *vertexShaderSrc = "#version 330 core\n"
    // "in vec2 position;\n"
    "layout (location = 0) in vec3 aPos;\n"
    // "in vec3 color;\n"
    // "out vec3 Color;\n"
    // "uniform mat4 trans;\n"
    "void main()\n"
    "{\n"
    // "   Color = color;\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    // "   gl_Position = trans * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    // "   gl_Position = vec4(position, .0f, 1.f);\n"
    "}\0";

static const char *fragmentShaderSrc = "#version 330 core\n"
    "out vec4 FragColor;\n"
    // "in vec3 color;\n"
    // "out vec4 Color;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
    // "   Color = vec4(color, 1.f);\n"
    "}\n\0";


class GlLifeCycle
{
public:
    GLFWwindow *window;
    GLuint shaderProgram;
    GlLifeCycle()
    {
        std::cout << "init Gl Life Cycle" << std::endl;
        setUpWindow("Rect basic crate imgproc app", 800, 500);
        vertexShader = createShader(vertexShaderSrc, GL_VERTEX_SHADER);
        fragmentShader = createShader(fragmentShaderSrc, GL_FRAGMENT_SHADER);
        shaderProgram = createShaderProgram();
        // glUseProgram(shaderProgram);

        loopWindow();
    }

    GLuint createShader(const char *src, GLenum type)
    {
        GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &src, NULL);
        glCompileShader(shader);
        int compileStatus;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
        if (!compileStatus)
        {
            glGetShaderInfoLog(shader, 512, NULL, shaderLog);
            std::cout << "Error : " << type << "shader compilation ...\n"
                    << shaderLog << std::endl;
        }
        return (shader);
    }

    GLuint createShaderProgram()
    {
        GLuint sp = glCreateProgram();

        this->bindAttributes();

        glAttachShader(sp, vertexShader);
        glAttachShader(sp, fragmentShader);
        // GLint colorAtt = glGetAttribLocation(sp, "color");
        // glEnableVertexAttribArray(colorAtt);
        // glVertexAttribPointer(colorAtt, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(2 * sizeof(float)));
        glLinkProgram(sp);

        int success;
        // char infoLog[512];
        glGetProgramiv(sp, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(sp, 512, NULL, shaderLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                    << shaderLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return (sp);
    }


private:
    char shaderLog[512];
    GLuint vertexShader;
    GLuint fragmentShader;
    void setUpWindow(std::string appTitle = "App", GLuint widht = 800, GLuint height = 400)
    {
        std::cout << "Creating App : " + appTitle << std::endl;
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        GLFWwindow *w = glfwCreateWindow(widht, height, appTitle.c_str(), NULL, NULL);
        if (!w)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(w);
        window = w;
    }

    // void createRectangle()

    void bindAttributes()
    {
        // GLint posAtt = glGetAttribLocation(shaderProgram, "position");
        // glEnableVertexAttribArray(posAtt);
        // glVertexAttribPointer(posAtt, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);

        // GLint colorAtt = glGetAttribLocation(shaderProgram, "color");
        // glEnableVertexAttribArray(colorAtt);
        // glVertexAttribPointer(colorAtt, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(2 * sizeof(float)));
    }

    int loopWindow()
    {
        // GLuint vao = createTriangle();
        GLuint vao = createRect(this);
        // glUseProgram(shaderProgram);

        while (!glfwWindowShouldClose(window))
        {
            // processInput(window);
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // bg-color green
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shaderProgram);

            glBindVertexArray(vao);

            // glDrawArrays(GL_TRIANGLES, 0, 3);
            // glDrawArrays(GL_TRIANGLES, 0, 4);
            // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            // glm::mat4 trans;
            // trans = glm::rotate(
            //     trans,
            //     glm::radians(180.0f),
            //     glm::vec3(0.0f, 0.0f, 1.0f)
            // );
            // glUniformMatrix4fv(
            //     glGetUniformLocation(shaderProgram, "trans"),
            //     1,
            //     GL_FALSE,
            //     glm::value_ptr(trans)
            // );

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            // glBindVertexArray(0);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwTerminate();
        return (0);
    }
};

static GLuint createRect(GlLifeCycle *glc)
{
    GLuint vao, vbo, ebo;
    // glGenVertexArrays(1, &vao);
    // float vertices[] = {
    //     0.0f,  0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1: Red
    //     0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // Vertex 2: Green
    //     -0.5f, -0.5f, 0.0f, 0.0f, 1.0f  // Vertex 3: Blue
    // };
    // GLuint indices[] = {
    //     0, 2, 3,
    //     1, 2, 3
    // };
    // float vertices[] = {
    //     -0.5f, 0.5f, 0.0f, // ul
    //     0.5f, 0.5f, 0.0f, // ur
    //     0.5f, -0.5f, 0.0f, // br
    //     -0.5f, -0.5f, 0.0f, // bl
    // };
    float vertices[] = {
        0.0f, 0.5f, 1.0f, .0f, .0f, // red
        0.5f, -0.5f, 0.0f, 1.f, .0f, // g
        -0.5f, -0.5f, 0.0f, .0f, 1.f // b
    };
    GLuint indices[] = {
        1, 2, 3,
        // 1, 2, 3
        0, 2, 3
    };

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // glGenBuffers(1, &ebo);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // GLint positionAtt = glGetAttribLocation(glc->shaderProgram, "position");
    // glVertexAttribPointer(positionAtt, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    // glEnableVertexAttribArray(positionAtt);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    // glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // ? unbinding -> performance
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return (vao);
}

// todo : just create rectangle
int imgproc_app()
{
    // GLFWwindow *w = setUpWindow();
    GlLifeCycle *cycleGl = new GlLifeCycle();
    return (0);
}
