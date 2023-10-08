#include "../includes/inputManager.hpp"

void updateInput(GLFWwindow* w, Mesh &mesh)
{
    // const float speed = 0.01f;
    const float speed = 0.05f;
    // const float deltaScale = 0.1f;
    const float deltaScale = 0.01f;
    const float rotationSpeed = 1.f;

    // * Move Y
    if (glfwGetKey(w, GLFW_KEY_W) == GLFW_PRESS)
    {
        // pos.z -= speed;
        // mesh.move(glm::vec3(0, 0, -speed));
        mesh.move(glm::vec3(0, speed, 0));
    }
    if (glfwGetKey(w, GLFW_KEY_S) == GLFW_PRESS)
    {
        // pos.z += speed;
        // mesh.move(glm::vec3(0, 0, speed));
        mesh.move(glm::vec3(0, -speed, 0));
    }
    // * Move X
    if (glfwGetKey(w, GLFW_KEY_A) == GLFW_PRESS)
    {
        // pos.x -= speed;
        mesh.move(glm::vec3(-speed, 0, 0));
    }
    if (glfwGetKey(w, GLFW_KEY_D) == GLFW_PRESS)
    {
        // pos.x += speed;
        mesh.move(glm::vec3(+speed, 0, 0));
    }
    // * Move Z
    if (glfwGetKey(w, GLFW_KEY_R) == GLFW_PRESS)
    {
        // pos.x -= speed;
        mesh.move(glm::vec3(0, 0, -speed));
    }
    if (glfwGetKey(w, GLFW_KEY_F) == GLFW_PRESS)
    {
        // pos.x += speed;
        mesh.move(glm::vec3(0, 0, +speed));
    }
    // * Rotation Around Y Axis
    if (glfwGetKey(w, GLFW_KEY_Q) == GLFW_PRESS)
    {
        // mesh.setRotation(glm::vec3(0, -speed, 0));
        mesh.rotate(glm::vec3(0, -rotationSpeed, 0));
        // mesh.rotate(glm::vec3(0, 0, -speed));
    }
    if (glfwGetKey(w, GLFW_KEY_E) == GLFW_PRESS)
    {
        // mesh.setRotation(glm::vec3(0, +speed, 0));
        mesh.rotate(glm::vec3(0, +rotationSpeed, 0));
        // mesh.rotate(glm::vec3(0, 0, +speed));
    }
    if (glfwGetKey(w, GLFW_KEY_Z) == GLFW_PRESS)
    {
        mesh.scaleMesh(glm::vec3(1) * deltaScale);
    }
    if (glfwGetKey(w, GLFW_KEY_X) == GLFW_PRESS)
    {
        mesh.scaleMesh(glm::vec3(1) * -deltaScale);
    }
}
