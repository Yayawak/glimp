#include "../../structure/headers/stdgl.hpp"
#include <vector>

// static float cubeVertices[] = {
//     -0.1f, -0.1f, 0.1f,
// };

// static float cubeVertices[] = {
//     //NOTE position     | color          
//     -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 
//     -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,

//     -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
//     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 
//     -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,

//     -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,

//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 

//     -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 
//     -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,

//     -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
//     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 
//     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 
//     -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f
// };

static GLfloat pyramidVertices[] = 
{
    // NOTE : position   |        color      
    // -0.5f,  +0.0f, +0.5f,  0.83f, 0.70f, 0.44,
    // -0.5f,  +0.0f, -0.5f,  0.83f, 0.70f, 0.44,
    // +0.5f,  +0.0f, -0.5f,  0.83f, 0.70f, 0.44,
    // +0.5f,  +0.0f, +0.5f,  0.83f, 0.70f, 0.44,
    // +0.0f,  +0.8f, +0.0f,  0.92f, 0.86f, 0.75

    -0.5f,  +0.0f, +0.5f,  1.00f, 0.00f, 0.00f,
    -0.5f,  +0.0f, -0.5f,  0.00f, 1.00f, 0.00f,
    +0.5f,  +0.0f, -0.5f,  0.00f, 0.00f, 1.00f,
    +0.5f,  +0.0f, +0.5f,  1.00f, 1.00f, 0.00f,
    +0.0f,  +0.8f, +0.0f,  0.00f, 1.00f, 1.00f
};

static GLuint pyramidIndices[] = {
    0, 1, 2,
    0, 2, 3,
    0, 1, 4,
    1, 2, 4,
    2, 3, 4,
    3, 0, 4
};

void ex05()
{
    GLFWwindow* w = setupWindow("EX05 Load Model from Blender");
    Shader sp(
        "/Users/rio/Desktop/glgl/src/exs/ex05_load_model/vs.vert",
        "/Users/rio/Desktop/glgl/src/exs/ex05_load_model/fs.frag");

    GLuint texture = loadDDS("/Users/rio/Desktop/glgl/src/exs/ex05_load_model/uvmap.DDS");
    GLuint textureId = glGetUniformLocation(sp.shaderProgramId, "myTextureSampler");

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;

    // bool res = loadOBJ("cube.obj", vertices, uvs, normals);
    bool res = loadOBJ(
        "/Users/rio/Desktop/glgl/src/exs/ex05_load_model/cube.obj",
        vertices, uvs, normals);
    // Load it into a VBO
    // VBO vbo(&vertices[0], vertices.size() * sizeof(glm::vec3));
    // VAO vao;
    // vao.Bind();

    GLuint vaoId;
    glGenVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);


    GLuint vtbf;
    glGenBuffers(1, &vtbf);
    glBindBuffer(GL_ARRAY_BUFFER, vtbf);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    std::cout << "vertex size is " << vertices.size() << std::endl;

    GLuint uvbf;
    glGenBuffers(1, &uvbf);
    glBindBuffer(GL_ARRAY_BUFFER, uvbf);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * uvs.size(), &uvs[0], GL_STATIC_DRAW);

    // vao.LinkAttrib(vtbf, 0, 3, GL_FLOAT, 0, (void *)0);
    // vao.LinkAttrib(VBO &vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset)

    // Camera cam(screenWidth, screenHeight, glm::vec3(0.0f, 0.0f, 5.f));
    // Camera cam(screenWidth, screenHeight, glm::vec3(2, 2, 2));
    // Camera cam(screenWidth, screenHeight, glm::vec3(0.0f, 7.0f, 0.f));
    // cam.PaneCamera()

    // SECTION ---------- pyramid ----------------
    Shader pyramidSp(
        "/Users/rio/Desktop/glgl/src/exs/ex05_load_model/pyramid.vert",
        "/Users/rio/Desktop/glgl/src/exs/ex05_load_model/pyramid.frag");
    VAO pyramidVao;
    pyramidVao.Bind();

    VBO pyramidVbo(pyramidVertices, sizeof(pyramidVertices));
    EBO pyramidEbo(pyramidIndices, sizeof(pyramidIndices));

    pyramidVao.LinkAttrib(pyramidVbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
    pyramidVao.LinkAttrib(pyramidVbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    // cubeVao.LinkAttrib(cubeVbo, 1, 3, GL_FLOAT, 3 * sizeof(float), (void *)2);


    // Camera cam(screenWidth, screenHeight, glm::vec3(0, 10, 10));
    // Camera cam(screenWidth, screenHeight, glm::vec3(0, 0, 80));
    Camera cam(screenWidth, screenHeight, glm::vec3(0, 0, 2.3));
    cam.PaneCamera(pyramidSp, "MVP");

    while (glfwWindowShouldClose(w) == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

        // SECTION : Model
        // cam.Inputs(w);
        cam.computeMatricesFromInputs(w, sp, "MVP");
        // cam.PaneCamera(sp, "MVP", glm::vec3(0.0f, 0.0f, 1.0f));
        sp.Activate();
        
        // cam.PaneCamera(sp, "MVP", glm::vec3(0.0f, 0.0f, 1.0f));
        // cam.PaneCamera(sp, "MVP", glm::vec3(1.0f, 0.0f, 0.0f));


        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        // set "myTextureSampler" sampler to use Texture Unit 0
        glUniform1i(textureId, 0); // texture unit 0

        glEnableVertexAttribArray(0); // vertices atts
        glBindBuffer(GL_ARRAY_BUFFER, vtbf);
        glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

        glEnableVertexAttribArray(1); // uv atts
        glBindBuffer(GL_ARRAY_BUFFER, uvbf);
        glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, 0, (void *)0);
        // glBindVertexArray(vaoId);

        glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        // SECTION : Pyramid
        // pyramidSp.Activate();
        // cam.computeMatricesFromInputs(w, pyramidSp, "MVP");
        // cam.Inputs(w);
        // cam.Matrix(45.0f, 0.1f, 100.0f, pyramidSp, "MVP");
        // glUniformMatrix4fv()
        // pyramidVao.Bind();
        // cam.PaneCamera(cubeSp, "MVP");
        // glDrawArrays(GL_TRIANGLES, 0, sizeof(cubeVertices) / sizeof(float));
        // glDrawArrays(GL_TRIANGLES, 0, 36);
        // glDrawArrays(GL_TRIANGLES, 0, 36);
        // glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices)
        // glDrawElements(GL_ELEMENT_ARRAY_BUFFER, )
        // glDrawElements(GL_TRIANGLES, sizeof(pyramidIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
        // glDisableVertexAttribArray(0);
        // glDisableVertexAttribArray(1);
        // pyramidSp.

        glfwSwapBuffers(w);
        glfwPollEvents();
    }


    glDeleteTextures(1, &texture);
    glDeleteVertexArrays(1, &vaoId);
    glDeleteBuffers(1, &vtbf);
    glDeleteBuffers(1, &uvbf);
    sp.Delete();

    pyramidSp.Delete();
    pyramidVao.Delete();
    pyramidVbo.Delete();
    pyramidEbo.Delete();

    glfwTerminate();
}
