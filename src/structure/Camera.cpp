#include "headers/Camera.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/quaternion_geometric.hpp"
#include "glm/fwd.hpp"
#include "glm/geometric.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "glm/trigonometric.hpp"
#include "headers/shaderClass.hpp"

Camera::Camera(int width, int height, glm::vec3 position) 
{
    Camera::width = width;
    Camera::height = height;
    Camera::position = position;
}

void Camera::Matrix(float FovDeg, float nearPlane, float farPlane,
    Shader& shaderProgram, const char *uniform
)
{
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(position, position + Orientation, Up);
    // glm::vec3 lookAtWhere = glm::vec3(0.0f);
    // view = glm::lookAt(position, lookAtWhere, Up);
    projection = glm::perspective(glm::radians(FovDeg),
        // (float)(width / height),
        ((float)width / (float)height),
        nearPlane, farPlane
    );
    glUniformMatrix4fv(
        glGetUniformLocation(shaderProgram.shaderProgramId, uniform),
        1, GL_FALSE, glm::value_ptr(projection * view)
    );
}

void Camera::PaneCamera(Shader& shaderProgram, const char *uniform)
{
    PaneCamera(shaderProgram, uniform, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::PaneCamera(Shader& shaderProgram, const char *uniform, glm::vec3 rotation)
{
    transf = glm::rotate(transf, glm::radians(1.f),
        // glm::vec3(0.0f, 1.0f, 0.0f)
        // glm::vec3(0.0f, 0.0f, 1.0f)
        rotation
    );
    glUniformMatrix4fv(
        glGetUniformLocation(shaderProgram.shaderProgramId, uniform),
        1, GL_FALSE, glm::value_ptr(transf)
    );
}

float horizontalAngle = 3.14f;
float verticalAngle = .0f;
// float 
float mouseSpeed = 0.005f;


// can use extern window use not well way.
void Camera::computeMatricesFromInputs(GLFWwindow* window, Shader shaderProgram, const char *uniform)
{
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();

    // Compute time difference between current and last frame
    float deltaTime = float(currentTime - lastTime);

    int screenWidth = 1024;
    int screenHeight = 768;
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY); 
    // glfwSetCursorPos(window, screenWidth / 2, screenHeight / 2);

    horizontalAngle += mouseSpeed * float(screenWidth / 2 - mouseX);
    verticalAngle += mouseSpeed * float(screenHeight / 2 - mouseY);

    // Spherical coordinates to Catesian coordinates conversion
    glm::vec3 direction(
        cos(verticalAngle) * sin(horizontalAngle),
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle)
    );

    glm::vec3 right = glm::vec3(
        sin(horizontalAngle - 3.14f / 2.0f),
        0,
        cos(horizontalAngle - 3.14f / 2.0f)
    );
    glm::vec3 up = glm::cross(right, direction);

    // Move forward
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        position += direction * deltaTime * speed;
    }
    // Move backwrad
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        position -= direction * deltaTime * speed;
    }
    // Starfe right
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        position += right * deltaTime * speed;
    }
    // Starfe left
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        position -= right * deltaTime * speed;
    }

    glm::mat4 view = glm::lookAt(position, position + direction, Up);
    // glm::vec3 lookAtWhere = glm::vec3(0.0f);
    // view = glm::lookAt(position, lookAtWhere, Up);
    // glm::mat4 projection = glm::perspective(glm::radians(FovDeg),
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),
        // (float)(width / height),
        ((float)width / (float)height),
        0.1f, 100.0f
    );
    glUniformMatrix4fv(
        glGetUniformLocation(shaderProgram.shaderProgramId, uniform),
        1, GL_FALSE, glm::value_ptr(projection * view)
    );

    lastTime = currentTime;
}

void Camera::Inputs(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        position += speed * Orientation;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        position += speed * -glm::normalize(glm::cross(Orientation, Up));
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        position += speed * -Orientation;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        position += speed * glm::normalize(glm::cross(Orientation, Up));
    }
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        position += speed * Up;
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        position += speed * -Up;
    }
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
    {
        speed = 0.4f;
    }
    else if (glfwGetKey(window, GLFW_KEY_V) == GLFW_RELEASE)
    {
        speed = 0.1f;
    }


    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        return ;

        if (firstClick)
        {
            glfwSetCursorPos(window, (width / 2.f), (height / 2.f));
            firstClick = false;
        }

        double mouseX;
        double mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);
        printf("mouse[%f, %f]\n", mouseX, mouseY);

        // normalize mouse position
        float rotX = sensitivity * (float)(mouseY - (height / 2.f) / height);
        float rotY = sensitivity * (float)(mouseX - (height / 2.f) / height);

        // calcualte upcoming vertical change in the orientation
        glm::vec3 newOrientation = glm::rotate(
            Orientation,
            glm::radians(-rotX),
            glm::normalize(glm::cross(Orientation, Up))
        );

        // decide whetehre or not hte next vertical Orietaion is legal or not
        if (!(
            (glm::angle(newOrientation, Up) <= glm::radians(5.0f))
            ||
            (glm::angle(newOrientation, -Up) <= glm::radians(-5.0f))
            )
        )
        {
            Orientation = newOrientation;
        }
        // Rotates the Oritation left and right
        Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);
        // Set mouse cursor to middle of the screen that it's doesn't end up roaming around
        glfwSetCursorPos(window, (width / 2.f), (height / 2.f));
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstClick = true;
    }
}

// void KK() 
// {
//     void BB()
//     {

//     }
// }