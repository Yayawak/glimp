#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <GLFW/glfw3.h>
// #include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "shaderClass.hpp"

class Camera
{
    private:
        GLFWwindow *windowWhoOwnedCamera;
    public:
        glm::vec3 position;
        // glm::vec3 Orientation = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 transf = glm::mat4(1.0f);

        int width;
        int height;
        bool firstClick = true;

        float speed = 0.1f;
        float sensitivity = 100.0f;

        // Camera(int width, int height, glm::vec3 position, GLFWwindow *w);
        Camera(int width, int height, glm::vec3 position);

        void Matrix(float FovDeg, float nearPlane, float farPlane,
            Shader& shaderProgram, const char *uniform
        );
        void Inputs(GLFWwindow *window);
        void PaneCamera(Shader& shaderProgram, const char *uniform);
        void PaneCamera(Shader& shaderProgram, const char *uniform, glm::vec3 rotation);

        // void 
        // void computeMatricesFromInputs(GLFWwindow* window);
        void computeMatricesFromInputs(GLFWwindow* window, Shader shaderProgram, const char *uniform);
        // void computeMatricesFromInputs(Shader shaderProgram, const char *uniform);
};

#endif