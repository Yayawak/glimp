#include "../inc/jstd.hpp"

static float vertices[] = {
    0.f, -.5f, 0.f,
    -.5f, 0.f, 0.f,
    .5f, 0.f, 0.f
};
static GLuint shaderProgram;
static GLuint H = 400;
static GLuint W = 600;
static const char *vsSrc = "#version 330 core\n"
    "in vec2 position;\n"
    // "in vec3 color;\n"
    // "out vec3 Color;\n"
    "void main()\n"
    "{\n"
    // "   Color = color;\n"
    "   gl_Position = vec4(position.x, -position.y, 0.0, 1.0);\n"
    "}\0";
static const char *fsSrc = "#version 330 core\n\
    // in vec3 color;\n\
    // out vec4 outColor;\n\
    out vec4 FragColor;\n\
    void main()\n\
    {\n\
        // outColor = vec4(color, 1.0f);\n\
        // FragColor = vec4(0.4f, 0.f, 1.f, 1.f);\n\
        FragColor = vec4(0.4f, 0.f, 1.f, 1.f);\n\
        // FragColor = vec4(color, 1.f);\n\
    }\n";

static GLFWwindow *setUpWindow(std::string appTitle="App", GLuint widht=800, GLuint height=400)
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
        return (NULL);
    }
    glfwMakeContextCurrent(w);
    return (w);
}

static void processInput(GLFWwindow *w)
{
    if (glfwGetKey(w, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(w, true);
}

static GLuint getVertexShader(const char *s)
{
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &s, NULL);
    glCompileShader(vs);
    int compileStatus;
    char log[512];
    glGetShaderiv(vs, GL_COMPILE_STATUS, &compileStatus);
    if (!compileStatus)
    {
        glGetShaderInfoLog(vs, 512, NULL, log);
        std::cout << "Error : Vertex shader compilation : \n " << log << "\n";
    }
    return (vs);
}

static GLuint getFragmentShader(const char *s)
{
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &s, NULL);
    glCompileShader(fs);
    int compileStatus;
    char log[512];
    glGetShaderiv(fs, GL_COMPILE_STATUS, &compileStatus);
    if (!compileStatus)
    {
        glGetShaderInfoLog(fs, 512, NULL, log);
        std::cout << "Error : Vertex FRAGMENT compilation : \n " << log << "\n";
    }
    return (fs);
}

static GLuint initShaderProgram(GLuint vs, GLuint fs)
{
    GLuint sp = glCreateProgram();
    glAttachShader(sp, vs);
    glAttachShader(sp, fs);
    // GLint colorAtt = glGetAttribLocation(sp, "color");
    // glEnableVertexAttribArray(colorAtt);
    // glVertexAttribPointer(colorAtt, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(2 * sizeof(float)));
    glLinkProgram(sp);

    int success;
    char infoLog[512];
    glGetProgramiv(sp, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(sp, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vs);
    glDeleteShader(fs);
    return (sp);
}


// void convertVerticesToMatrix(const float* vertices, mat4x1 result[3]) {
//     for (int i = 0; i < 3; i++) {
//         result[i][0] = vertices[i * 3];
//         result[i][1] = vertices[i * 3 + 1];
//         result[i][2] = 0.0f;
//         result[i][3] = 1.0f;
//     }
// }

// void createTriangle()
static GLuint createTriangle()
{
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return (vao);
}

// class TrigUpsideDown
// {

// };

static int loopWindow(GLFWwindow *w)
{
    GLuint vao = createTriangle();
    while (!glfwWindowShouldClose(w))
    {
        processInput(w);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // bg-color green
        glClear(GL_COLOR_BUFFER_BIT);

        // vertices[0] += .05f;
        glUseProgram(shaderProgram);
        glBindVertexArray(vao);

        // GLint colorAtt = glGetAttribLocation(shaderProgram, "color");
        // glEnableVertexAttribArray(colorAtt);
        // glVertexAttribPointer(colorAtt, 2, GL_FLOAT, GL_FALSE,
        //                     5*sizeof(float), 0);
        // GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
        // glEnableVertexAttribArray(posAttrib);
        // glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE,
        //                     5*sizeof(float), 0);

        // vertices[0] = (int)vertices[0] % 2;
        // glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(w);
        glfwPollEvents();
    }
    glfwTerminate();
    return (0);
}

static int ex_upsideDownTriangle()
{
    GLFWwindow *w = setUpWindow("Upside-Down Triangle App", W, H);
    GLuint vertexShader = getVertexShader(vsSrc);
    GLuint fragmentShader = getFragmentShader(fsSrc);
    // static GLuint shaderProgram = initShaderProgram(vertexShader, fragmentShader);
    shaderProgram = initShaderProgram(vertexShader, fragmentShader);
    loopWindow(w);
    return (0);
}
