// #include "../inc/jstd.hpp"
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include <iostream>
// #include <ostream>

// static float vertices[] = {
//     0.f, -.5f, 0.f,
//     -.5f, .4f, 0.f,
//     .5f, .4f, 0.f
// };
// static GLuint shaderProgram;
// static GLuint H = 400;
// static GLuint W = 600;
// static const char *vsSrc = "#version 330 core\n"
//     "in vec2 position;\n"
//     "in vec3 color;\n"
//     // "in vec2 texcoord;\n"
//     // // "in vec3 color;\n"
//     // "out vec2 Texcoord;\n"
//     "out vec3 Color;\n"

//     "uniform mat4 trans;\n"
//     "void main()\n"
//     "{\n"
//     // "   Color = color;\n"
//     // "   Texcoord = texcoord;\n"
//     // "   gl_Position = vec4(position.x, -position.y, 0.0, 1.0);\n"
//     // "   gl_Position = trans * vec4(position, 0.0, 1.0);\n"
//     // todo : ?????????? How to make trans works ?
//     "   gl_Position = vec4(position, 0.0, 1.0);\n"
//     "}\0";
// static const char *fsSrc = "#version 330 core\n\
//     // in vec3 color;\n\
//     // out vec4 outColor;\n\
//     out vec4 FragColor;\n\
//     void main()\n\
//     {\n\
//         // outColor = vec4(color, 1.0f);\n\
//         // FragColor = vec4(0.4f, 0.f, 1.f, 1.f);\n\
//         FragColor = vec4(1.0f, 0.f, 0.f, 1.f);\n\
//         // FragColor = vec4(color, 1.f);\n\
//     }\n";

// static GLFWwindow *setUpWindow(std::string appTitle="App", GLuint widht=800, GLuint height=400)
// {
//     std::cout << "Creating App : " + appTitle << std::endl;
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif
//     GLFWwindow *w = glfwCreateWindow(widht, height, appTitle.c_str(), NULL, NULL);
//     if (!w)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return (NULL);
//     }
//     glfwMakeContextCurrent(w);
//     return (w);
// }

// static void processInput(GLFWwindow *w)
// {
//     if (glfwGetKey(w, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(w, true);
// }

// static GLuint getVertexShader(const char *s)
// {
//     GLuint vs = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(vs, 1, &s, NULL);
//     glCompileShader(vs);
//     int compileStatus;
//     char log[512];
//     glGetShaderiv(vs, GL_COMPILE_STATUS, &compileStatus);
//     if (!compileStatus)
//     {
//         glGetShaderInfoLog(vs, 512, NULL, log);
//         std::cout << "Error : Vertex shader compilation : \n " << log << "\n";
//     }
//     return (vs);
// }

// static GLuint getFragmentShader(const char *s)
// {
//     GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(fs, 1, &s, NULL);
//     glCompileShader(fs);
//     int compileStatus;
//     char log[512];
//     glGetShaderiv(fs, GL_COMPILE_STATUS, &compileStatus);
//     if (!compileStatus)
//     {
//         glGetShaderInfoLog(fs, 512, NULL, log);
//         std::cout << "Error : Vertex FRAGMENT compilation : \n " << log << "\n";
//     }
//     return (fs);
// }

// static GLuint initShaderProgram(GLuint vs, GLuint fs)
// {
//     GLuint sp = glCreateProgram();
//     glAttachShader(sp, vs);
//     glAttachShader(sp, fs);
//     // GLint colorAtt = glGetAttribLocation(sp, "color");
//     // glEnableVertexAttribArray(colorAtt);
//     // glVertexAttribPointer(colorAtt, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(2 * sizeof(float)));
//     glLinkProgram(sp);

//     int success;
//     char infoLog[512];
//     glGetProgramiv(sp, GL_LINK_STATUS, &success);
//     if (!success) {
//         glGetProgramInfoLog(sp, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//     }
//     glDeleteShader(vs);
//     glDeleteShader(fs);
//     return (sp);
// }

// static GLuint createTriangle()
// {
//     GLuint vao, vbo;
//     glGenVertexArrays(1, &vao);
//     glGenBuffers(1, &vbo);

//     glBindVertexArray(vao);
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);

//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
//     glEnableVertexAttribArray(0);

//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);

//     return (vao);
// }

// static void linkAttributes()
// {
//     GLint posAtt = glGetAttribLocation(shaderProgram, "position");
//     glEnableVertexAttribArray(posAtt);
//     glVertexAttribPointer(posAtt, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);
// }

// static int loopWindow(GLFWwindow *w)
// {
//     GLuint vao = createTriangle();
//     // auto t_start = std::chrono::high_resolution::now();
//     // glUseProgram(shaderProgram);
//     auto t_start = std::chrono::high_resolution_clock::now();

//     while (!glfwWindowShouldClose(w))
//     {
//         processInput(w);
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // bg-color green
//         glClear(GL_COLOR_BUFFER_BIT);

//         glBindVertexArray(vao);

//         auto t_now = std::chrono::high_resolution_clock::now();
//         float time = std::chrono::duration_cast<std::chrono::duration<float> >(t_now - t_start).count();
//         glm::mat4 trans;
//         trans = glm::rotate(trans,
//             time * glm::radians(180.0f),
//             glm::vec3(.0f, .0f, 1.f)
//         );
//         std::cout << time << std::endl;
//         GLuint uniTrans = glGetUniformLocation(shaderProgram, "trans");
//         glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
//         // glUniformMatrix4fv(uniT)
//         glDrawArrays(GL_TRIANGLES, 0, 3);

//         glfwSwapBuffers(w);
//         glfwPollEvents();
//     }
//     glfwTerminate();
//     return (0);
// }


// int ex_matrix00()
// {
//     glm::mat4 trans = glm::mat4(1.0f);
//     trans = glm::rotate(trans, glm::radians(180.0f),
//         glm::vec3(.0f, .0f, 1.f)
//     );

//     glm::vec4 result = trans * glm::vec4(1.f, .0f, .0f, 1.f);
//     printf("%f, %f, %f\n", result.x, result.y, result.z);



//     GLFWwindow *w = setUpWindow("Upside-Down Triangle App", W, H);
//     GLuint vertexShader = getVertexShader(vsSrc);
//     GLuint fragmentShader = getFragmentShader(fsSrc);
//     // static GLuint shaderProgram = initShaderProgram(vertexShader, fragmentShader);
//     shaderProgram = initShaderProgram(vertexShader, fragmentShader);
//     linkAttributes();
//     glUseProgram(shaderProgram);
//     loopWindow(w);

//     return (0);
// }
