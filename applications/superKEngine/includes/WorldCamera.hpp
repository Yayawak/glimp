#ifndef WCam_H
#define WCam_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../../../src/structure/headers/stdgl.hpp"
#include "glm/detail/qualifier.hpp"
#include "glm/fwd.hpp"

class WorldCamera
{
    private:
        GLFWwindow *windowWhoOwnedCamera;
        glm::mat4 ViewMatrix;
        glm::mat4 ProjectionMatrix;
        Shader *shader;
        float FovDegree = 90.f;
        float nearPlane = 0.1f;
        float farPlane = 100.f;        

        glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f);
        glm::vec3 cameraFacingDirection = glm::vec3(0, 0, -1);
        // glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 worldUpDirection = glm::vec3(0.0f, 1.0f, 0.0f);

        void updateViewMatrix();
        void updateProjectionMatrix();

    public:
        // glm::mat4 transf = glm::mat4(1.0f);
        // glm::vec3 *lookAtPosition = NULL;

        int width;
        int height;

        WorldCamera(int width, int height, glm::vec3 position,
            GLFWwindow* window,
            Shader* shader
        );

        void updateUniform();

        void setViewMatrix(float fovDegree, float nearPlane, float farPlane);
        void setProjectionMatrix(glm::vec3 cameraFacingDirection, glm::vec3 worldUpDirection); ///
        void setPosition(glm::vec3 newPosition);
        inline glm::vec3 getPosition() { return position; }
};


#endif