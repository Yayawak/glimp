// ? LINK
// // https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/2.2.hello_triangle_indexed/hello_triangle_indexed.cpp
// // Link statically with GLEW
// #define GLEW_STATIC
// #define GLFW_INCLUDE_GLCOREARB
// // #include <glad/glad.h>
// #include "vendors/GLFW/glfw3.h"
// #include "vendors/GLFW/linmath.h"

// #include <iostream>

// void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// void processInput(GLFWwindow *window);

// // settings
// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;

// const char *vertexShaderSource = "#version 330 core\n"
//     // "layout (location = 0) in vec3 aPos;\n"
//     "in vec2 position;\n"
//     "in vec3 color;\n"
//     "out vec3 Color;\n"
//     "void main()\n"
//     "{\n"
//     // "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//     "   Color = color;\n"
//     "   gl_Position = vec4(position, 0.0, 1.0);\n"
//     "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//     // "uniform vec3 color;\n"
//     "in vec3 color;\n"
//     // "out vec4 FragColor;\n"
//     "out vec4 outColor;\n"
//     "void main()\n"
//     "{\n"
//     // "   FragColor = vec4(color, 1.0f);\n"
//     "   outColor = vec4(color, 1.0f);\n"
//     // "   FragColor = vec4(1.0f, 0.5f, 0.0f, 1.0f);\n"
//     "}\n\0";

// float r()
// {
//     return (rand() % 100) / 100.f;
// }

// static float t = 0.f;

// auto t_start = std::chrono::high_resolution_clock::now();
// int main()
// {
//     // glfw: initialize and configure
//     // ------------------------------
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif

//     // glfw window creation
//     // --------------------
//     GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // glad: load all OpenGL function pointers
//     // ---------------------------------------
//     // if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     // {
//     //     std::cout << "Failed to initialize GLAD" << std::endl;
//     //     return -1;
//     // }


//     // build and compile our shader program
//     // ------------------------------------
//     // vertex shader
//     unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//     glCompileShader(vertexShader);
//     // check for shader compile errors
//     int success;
//     char infoLog[512];
//     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//     if (!success)
//     {
//         glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }
//     // fragment shader
//     unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//     glCompileShader(fragmentShader);
//     // check for shader compile errors
//     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//     if (!success)
//     {
//         glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }
//     // link shaders
//     unsigned int shaderProgram = glCreateProgram();

//     GLint posAtt = glGetAttribLocation(shaderProgram, "position");
//     glEnableVertexAttribArray(posAtt);
//     glVertexAttribPointer(posAtt, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);

//     GLint colorAtt = glGetAttribLocation(shaderProgram, "color");
//     glEnableVertexAttribArray(colorAtt);
//     glVertexAttribPointer(colorAtt, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(2 * sizeof(float)));

//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     glLinkProgram(shaderProgram);
//     // check for linking errors
//     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//     if (!success) {
//         glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//     }
//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);

//     // set up vertex data (and buffer(s)) and configure vertex attributes
//     // ------------------------------------------------------------------
//     // float vertices[] = {
//     //      0.5f,  0.5f, 0.0f,  // top right
//     //      0.5f, -0.5f, 0.0f,  // bottom right
//     //     -0.5f, -0.5f, 0.0f,  // bottom left
//     //     -0.5f,  0.5f, 0.0f   // top left
//     // };
//     float vertices[] = {
//      0.0f,  0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1: Red
//      0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // Vertex 2: Green
//     -0.5f, -0.5f, 0.0f, 0.0f, 1.0f  // Vertex 3: Blue
//     };
//     unsigned int indices[] = {  // note that we start from 0!
//         // 0, 1, 3,  // first Triangle
//         0, 2, 3,  // first Triangle
//         1, 2, 3   // second Triangle
//     };
//     unsigned int VBO, VAO, EBO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);
//     glGenBuffers(1, &EBO);
//     // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);

//     // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
//     //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

//     // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//     // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//     glBindVertexArray(0);


//     // uncomment this call to draw in wireframe polygons.
//     // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

//     // render loop
//     // -----------
//     while (!glfwWindowShouldClose(window))
//     {
//         // input
//         // -----
//         processInput(window);

//         // render
//         // ------
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         // draw our first triangle
//         glUseProgram(shaderProgram);
//         glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//         //glDrawArrays(GL_TRIANGLES, 0, 6);
//         // mat4x4_add(vertices, vertices, vertices);
//         GLuint color = glGetUniformLocation(shaderProgram, "color");
//         // glUniform3f(color, 0.0f, 0.0f, r);
//         // glUniform3f(color, r(), r(), r());
//         // glUniform3f(color, r(), 0.f, 0.f);
//         // glUniform3f(color, t, 0.f, 0.f);
//         // auto t_now = std::chrono::high_resolution_clock::now();
//         // float time = std::chrono::duration_cast<std::chrono::duration<float> >(t_now - t_start).count();

//         // glUniform3f(color, (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);
//         // glUniform3f(color, t += .01f, 0.f, 0.f);
//         // if (t > 1.f)
//         //     t = 0;
//         glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//         // glBindVertexArray(0); // no need to unbind it every time
//         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         // -------------------------------------------------------------------------------
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     // optional: de-allocate all resources once they've outlived their purpose:
//     // ------------------------------------------------------------------------
//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);
//     glDeleteBuffers(1, &EBO);
//     glDeleteProgram(shaderProgram);

//     // glfw: terminate, clearing all previously allocated GLFW resources.
//     // ------------------------------------------------------------------
//     glfwTerminate();
//     return 0;
// }

// // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// // ---------------------------------------------------------------------------------------------------------
// void processInput(GLFWwindow *window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

// // glfw: whenever the window size changed (by OS or user resize) this callback function executes
// // ---------------------------------------------------------------------------------------------
// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
//     // make sure the viewport matches the new window dimensions; note that width and
//     // height will be significantly larger than specified on retina displays.
//     glViewport(0, 0, width, height);
// }
