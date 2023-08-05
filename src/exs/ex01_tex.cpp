// #include "../inc/jstd.hpp"
// // #include <SOIL.h>

// // float vertices[] = {
// //     0.f, -.5f, 0.f,
// //     -.5f, 0.f, 0.f,
// //     .5f, 0.f, 0.f
// // };
// typedef struct SABEOReturnData {
//     GLuint vbo, vao, ebo;
//     SABEOReturnData(GLuint vbo, GLuint vao, GLuint ebo) : vbo(vbo), vao(vao), ebo(ebo)
//     {}
// } ABEOReturnData;

// typedef struct SAttributesData {
//     int colAtt, texAtt, posAtt;
// } AttributesData;
// GLfloat vertices[] = {
//     //  Position      Color             Texcoords
//         -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
//          0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
//          0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
//         -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
//     };

// GLuint shaderProgram;
// GLuint H = 400;
// GLuint W = 600;
// const char *vsSrc = "#version 330 core\n"
//     "in vec2 position;\n"
//     "in vec3 color;\n"
//     "out vec3 Color;\n"
//     "in vec2 texcoord;\n"
//     "out vec2 Texcoord;\n"
//     "void main()\n"
//     "{\n"
//     // "   Color = color;\n"
//     "   gl_Position = vec4(position.x, -position.y, 0.0, 1.0);\n"
//     "   Texcoord = texcoord;\n"
//     "}\0";
// const char *fsSrc = "#version 330 core\n\
//     in vec3 color;\n\
//     out vec4 outColor;\n\
//     // out vec4 FragColor;\n\
//     in vec2 Texcoord;\n\
//     uniform sampler2D texKitten;\n\
//     uniform sampler2D texPuppy;\n\
//     void main()\n\
//     {\n\
//         // outColor = vec4(color, 1.0f);\n\
//         // FragColor = vec4(0.4f, 0.f, 1.f, 1.f);\n\
//         // FragColor = vec4(0.4f, 0.f, 1.f, 1.f);\n\
//         // FragColor = vec4(color, 1.f);\n\
//         outColor = mix(texture(texKitten, Texcoord), texture(texPuppy, Texcoord), 0.5);\n\
//     }\n";

// GLFWwindow *setUpWindow(std::string appTitle="App", GLuint widht=800, GLuint height=400)
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

// void processInput(GLFWwindow *w)
// {
//     if (glfwGetKey(w, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(w, true);
// }

// GLuint getVertexShader(const char *s)
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

// GLuint getFragmentShader(const char *s)
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

// GLuint initShaderProgram(GLuint vs, GLuint fs)
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


// // void convertVerticesToMatrix(const float* vertices, mat4x1 result[3]) {
// //     for (int i = 0; i < 3; i++) {
// //         result[i][0] = vertices[i * 3];
// //         result[i][1] = vertices[i * 3 + 1];
// //         result[i][2] = 0.0f;
// //         result[i][3] = 1.0f;
// //     }
// // }

// // void createTriangle()
// // GLuint setDraw()
// ABEOReturnData setDraw()
// {
//     GLuint vao;
//     GLuint vbo;
//     glGenVertexArrays(1, &vao);
//     glGenBuffers(1, &vbo);

//     glBindVertexArray(vao);
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);

//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
//     glEnableVertexAttribArray(0);

//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);

//     GLuint ebo;
//     GLuint elements[] = {
//         0, 1, 2,
//         2, 3, 0
//     };
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
//     // return (vao);
//     return (ABEOReturnData(vao, vbo, ebo));
// }

// AttributesData setAttributes()
// {
//     GLint posAtt = glGetAttribLocation(shaderProgram, "position");
//     glEnableVertexAttribArray(posAtt);
//     glVertexAttribPointer(posAtt, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);

//     int colAtt = glGetAttribLocation(shaderProgram, "color");
//     glEnableVertexAttribArray(colAtt);
//     glVertexAttribPointer(colAtt, 3, GL_FLOAT, 0, 7 * sizeof(float), (void *)(2 * sizeof(float)));

//     int texAtt = glGetAttribLocation(shaderProgram, "texcoord");
//     glEnableVertexAttribArray(texAtt);
//     glVertexAttribPointer(texAtt, 2, GL_FLOAT, 0, 7 * sizeof(float), (void *)(5 * sizeof(float)));

//     AttributesData d = AttributesData();
//     d.colAtt = colAtt;
//     d.posAtt = posAtt;
//     d.texAtt = texAtt;
//     return (d);
// }
// // class TrigUpsideDown
// // {

// // };
// static void loadTex()
// {
//     uint textures[2];
//     glGenTextures(2, textures);

//     int w, h;
//     unsigned char *img;
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D, textures[0]);
//     // img = SOIL_load_image("../../img/abadon.jpg", &w, &h, 0, SOIL_LOAD_RGB);
//     img = SOIL_load_image("abadon.jpg", &w, &h, 0, SOIL_LOAD_RGB);
//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
//     SOIL_free_image_data(img);

//     glUniform1i(glGetUniformLocation(shaderProgram, "texKitten"), 0);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


//     // ? ------------------ second image --------------------
//     glActiveTexture(GL_TEXTURE1);
//     glBindTexture(GL_TEXTURE_2D, textures[1]);
//         img = SOIL_load_image("../../img/slark.png", &w, &h, 0, SOIL_LOAD_RGB);
//         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
//         SOIL_free_image_data(img);
//     glUniform1i(glGetUniformLocation(shaderProgram, "texPuppy"), 1);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// }

// // static GLuint textex()
// // {
// //     GLuint tex;
// //     glGenTextures(1, &tex);
// //     glBindTexture(GL_TEXTURE_2D, tex);
// //     // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
// //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
// //     glGenerateMipmap(GL_TEXTURE_2D);
// //     return (tex);
// // }

// int loopWindow(GLFWwindow *w)
// {
//     // GLuint vao = setDraw();
//     ABEOReturnData abe = setDraw();
//     // textex();

//     while (!glfwWindowShouldClose(w))
//     {
//         processInput(w);
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // bg-color green
//         glClear(GL_COLOR_BUFFER_BIT);

//         // vertices[0] += .05f;
//         // glBindVertexArray(abe.vao);

//         // glDrawArrays(GL_TRIANGLES, 0, 3);
//         glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

//         glfwSwapBuffers(w);
//         glfwPollEvents();
//     }
//     glfwTerminate();
//     return (0);
// }

// int ex_textex()
// {
//     GLFWwindow *w = setUpWindow("Show Image & Texture", W, H);
//     GLuint vertexShader = getVertexShader(vsSrc);
//     GLuint fragmentShader = getFragmentShader(fsSrc);
//     // static GLuint shaderProgram = initShaderProgram(vertexShader, fragmentShader);
//     shaderProgram = initShaderProgram(vertexShader, fragmentShader);
//     glUseProgram(shaderProgram);
//     setAttributes();
//     loadTex();
//     loopWindow(w);
//     return (0);
// }
