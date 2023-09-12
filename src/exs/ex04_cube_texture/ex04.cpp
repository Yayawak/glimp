#include "../../structure/headers/stdgl.hpp"
// #include "../../structure/headers/constants.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"
#include "glm/trigonometric.hpp"
#include <cstdio>
#include <iostream>
#include <common/shader.hpp>
// #include ""

GLFWwindow* window;

static GLfloat g_vertex_buffer_data[] = { 
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f
	};

static GLfloat g_uv_buffer_data[] = { 
		0.000059f, 1.0f-0.000004f, 
		0.000103f, 1.0f-0.336048f, 
		0.335973f, 1.0f-0.335903f, 
		1.000023f, 1.0f-0.000013f, 
		0.667979f, 1.0f-0.335851f, 
		0.999958f, 1.0f-0.336064f, 
		0.667979f, 1.0f-0.335851f, 
		0.336024f, 1.0f-0.671877f, 
		0.667969f, 1.0f-0.671889f, 
		1.000023f, 1.0f-0.000013f, 
		0.668104f, 1.0f-0.000013f, 
		0.667979f, 1.0f-0.335851f, 
		0.000059f, 1.0f-0.000004f, 
		0.335973f, 1.0f-0.335903f, 
		0.336098f, 1.0f-0.000071f, 
		0.667979f, 1.0f-0.335851f, 
		0.335973f, 1.0f-0.335903f, 
		0.336024f, 1.0f-0.671877f, 
		1.000004f, 1.0f-0.671847f, 
		0.999958f, 1.0f-0.336064f, 
		0.667979f, 1.0f-0.335851f, 
		0.668104f, 1.0f-0.000013f, 
		0.335973f, 1.0f-0.335903f, 
		0.667979f, 1.0f-0.335851f, 
		0.335973f, 1.0f-0.335903f, 
		0.668104f, 1.0f-0.000013f, 
		0.336098f, 1.0f-0.000071f, 
		0.000103f, 1.0f-0.336048f, 
		0.000004f, 1.0f-0.671870f, 
		0.336024f, 1.0f-0.671877f, 
		0.000103f, 1.0f-0.336048f, 
		0.336024f, 1.0f-0.671877f, 
		0.335973f, 1.0f-0.335903f, 
		0.667969f, 1.0f-0.671889f, 
		1.000004f, 1.0f-0.671847f, 
		0.667979f, 1.0f-0.335851f
	};


// static const int screenWidth = 1024;
// static const int screenHeight;= 768;
// static const int screenscreenWidth
void ex04()
{
    std::cout << "EX04\n"; 
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return ;
    }

    // glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(screenWidth, screenHeight, "Tutorial 05 - Textured Cube", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return ;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	// glewExperimental = true; // Needed for core profile
	// if (glewInit() != GLEW_OK) {
	// 	fprintf(stderr, "Failed to initialize GLEW\n");
	// 	return;
	// }

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 

    //NOTE --------- load vertex & fragment shaders ----------------
    Shader shaderProgram(
        "/Users/rio/Desktop/glgl/src/exs/ex04/TextureVertex.vert",
        "/Users/rio/Desktop/glgl/src/exs/ex04/TextureFragment.frag");
        // "TextureVertex.vert",
        // "TextureFragment.frag");

    //NOTE --------- retrieve linking to shader program
    GLuint mvpId = glGetUniformLocation(shaderProgram.shaderProgramId, "MVP");
    glm::mat4 ProjectionMat = glm::perspective(
        // glm::radians(45.0f), 4.0f/ 3.0f, 0.1f, 100.0f
        glm::radians(45.0f), 800.f/ 500.f, 0.1f, 100.0f
    );
    glm::mat4 View = glm::lookAt(
        glm::vec3(4, 3, 3),
        // glm::vec3(10, 10, 10),
        glm::vec3(0, 0, 0),
        glm::vec3(0, 0, 1)
    );
    glm::mat4 Model = glm::mat4(1.0f);
    glm::mat4 mvp = ProjectionMat * View * Model;
    


    // glm::vec3 camPos = glm::vec3(4, 4, 4);
    // Camera cam(screenWidth, screenHeight;, camPos);
    // // Camera cam(screenHeight;, screenWidth, glm::vec3(10.0f));
    // // Camera cam(screenHeight;, screenWidth, glm::vec3(0.0f, 0.5f, 0.7f));
    // cam.Orientation = -camPos;
    
        // glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
    // cam.Orientation = glm::vec3(0.0f, 0.0f, 1.0f);

    GLuint texture = loadDDS("/Users/rio/Desktop/glgl/src/exs/ex04/uvtemplate.DDS");
    GLuint textureId = glGetUniformLocation(shaderProgram.shaderProgramId, "myTextureSampler");
    // std::cout << mvp << "\n";

    // Texture tex()

    //NOTE --------- class modularity ---------

    VAO vao;
    vao.Bind();

    VBO vertexBuffer(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
    VBO uvBuffer(g_uv_buffer_data, sizeof(g_uv_buffer_data));

    // NOTE : ------------ linking attributes ------------
    // vao.LinkAttrib(vertexBuffer, 0, 3, GL_FLOAT, 0, (void *)0);
    // vao.LinkAttrib(uvBuffer, 1, 2, GL_FLOAT, 0, (void *)0);

    float start = glfwGetTime();
    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shaderProgram.Activate();
        
        // cam.Inputs(window);
        // cam.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "cam");
        // Model = glm::rotate(Model, glm::radians(2.f), glm::vec3(0.f, 0.f, 1.f));

        float time = glfwGetTime() - start;
        Model = glm::rotate(Model,
            glm::radians(sin(time) * 4),
            glm::vec3(0.f, 0.f, 1.f));
        mvp = ProjectionMat * View * Model;

        // // cam.PaneCamera(shaderProgram, "cam", glm::vec3(0.0f, 0.0f, 1.0f));
        // cam.PaneCamera(shaderProgram, "cam", glm::vec3(1.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(mvpId, 1, GL_FALSE, &mvp[0][0]);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        // * set our "myTextureSampler" sampler to use Texture Unit 0
        glUniform1i(textureId, 0);
        vao.LinkAttrib(vertexBuffer, 0, 3, GL_FLOAT, 0, (void *)0);
        vao.LinkAttrib(uvBuffer, 1, 2, GL_FLOAT, 0, (void *)0);

        // vao.Bind();
        vertexBuffer.Bind();
        uvBuffer.Bind();

        glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
        && glfwWindowShouldClose(window) == 0);

    vao.Delete();
    uvBuffer.Delete();
    vertexBuffer.Delete();
    shaderProgram.Delete();
    glDeleteTextures(1, &texture);
    
    glfwTerminate();
}