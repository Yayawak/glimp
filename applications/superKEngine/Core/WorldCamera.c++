#include "../includes/WorldCamera.hpp"
#include "glm/ext/matrix_clip_space.hpp"


WorldCamera::WorldCamera(int width, int height, glm::vec3 position,
            GLFWwindow* window,
            Shader* shader) 
{
    this->width = width;
    this->height = height;
    this->position = position;
    windowWhoOwnedCamera = window;
    this->shader = shader;

}

void WorldCamera::updateProjectionMatrix()
{
    // ProjectionMatrix = glm::perspective(
    //     glm::radians(FovDegree),
    //     static_cast<float>(screenWidth) / screenHeight,
    //     nearPlane,
    //     farPlane
    // );
    // ProjectionMatrix = glm::ortho(0, 0, screenWidth, screenHeight);
    // glm::ortho()
    // ProjectionMatrix = glm::ortho(0.0f, 200.0f, 0.0f, 200.0f, 0.1f, 100.0f);
    // ProjectionMatrix = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f,

    // // 0.5f, 1.5f
    //     -5.f, 20.f
    // );

    float scale = 8.0f;
    float aspect = static_cast<float>(width) / static_cast<float>(height);
    // glm::ortho(-aspect * scale, aspect * scale, -scale, scale, zNear, zFar);
    ProjectionMatrix = glm::ortho(-aspect * scale, aspect * scale, -scale, scale,
        0.1f, 100.f
    );


}


void WorldCamera::updateViewMatrix()
{
    ViewMatrix = glm::mat4(1.f);
    ViewMatrix = glm::lookAt(position, position + cameraFacingDirection, worldUpDirection);
    // ViewMatrix = glm::lookAt(position, glm::vec3(0), worldUpDirection);
}

void WorldCamera::updateUniform()
{
    updateProjectionMatrix();
    updateViewMatrix();
    // updateProjectionMatrix(fov, float nearPlane, float farPlane)

    // std::cout << "update cam\n";
    // shader->setMat4fv(this->ModelMatrix, "ModelMatrix");
    shader->setMat4fv(this->ViewMatrix, "ViewMatrix");
    shader->setMat4fv(this->ProjectionMatrix, "ProjectionMatrix");
}

void WorldCamera::setViewMatrix(float fovDegree, float nearPlane, float farPlane)
{
    this->FovDegree = fovDegree;
    this->nearPlane = nearPlane;
    this->farPlane = farPlane;
}

void WorldCamera::setProjectionMatrix(glm::vec3 cameraFacingDirection, glm::vec3 worldUpDirection)
{
    this->cameraFacingDirection = cameraFacingDirection;
    this->worldUpDirection = worldUpDirection;
}

void WorldCamera::setPosition(glm::vec3 newPosition)
{
    this->position = newPosition;
}