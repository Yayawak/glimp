#include "headers/panel.hpp"
#include "headers/shaderClass.hpp"

    // Panel(glm::vec3 color, glm::vec4 rect, std::string panelName) : 
    //     color(color), rect(rect), panelName(panelName), shaderProgram(useShaderProgram());
Panel::Panel(glm::vec3 color, glm::vec4 rect, std::string panelName) 
    :
    rect(rect), panelName(panelName), 
{
    // printf("color = (%f, %f, %f)\n", color.x, color.y, color.z);
    // printf("rect = (%f, %f, %f, %f)\n", rect.x, rect.y, rect.z, rect.w);
    setColor(color);
    shaderProgram = useShaderProgram(
        "/Users/rio/Desktop/glgl/src/resources/duals/basicPosAndColor/default.vert",
        "/Users/rio/Desktop/glgl/src/resources/duals/basicPosAndColor/default.frag"
    );
}

// NOTE should move this function to utiliy class instead
void Panel::setColor(glm::vec3 _color)
{
    // color = glm::vec3(color.x / 255.f, color.y / 255.f, color.z / 255.f);
    // color.x = color.x / 255.f;
    // color.y = color.y / 255.f;
    // color.z = color.z / 255.f;
    this->color = _color / 255.f;

    printf("setting color : %s (%f, %f, %f)\n", panelName.c_str(), color.x, color.y, color.z);
}

void Panel::draw()
{
    // printf("setting color : %s (%f, %f, %f)\n", panelName.c_str(), color.x, color.y, color.z);
    GLfloat vertices[] = 
    {
        //*  position                          | color
        rect.x         , rect.y,          0.0f, color.x, color.y, color.z,
        rect.x + rect.z, rect.y,          0.0f, color.x, color.y, color.z,
        rect.x + rect.z, rect.y - rect.w, 0.0f, color.x, color.y, color.z,
        rect.x         , rect.y - rect.w, 0.0f, color.x, color.y, color.z,
    };
    // just for a normal rectangle
    GLuint indices[] = 
    {
        0, 1, 2,
        2, 3, 0
    };
    VAO vao;
    vao.Bind();

    VBO vbo(vertices, sizeof(vertices));
    EBO ebo(indices, sizeof(indices));

    //! FIXME must use specific shaders
    vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
    vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int),
        GL_UNSIGNED_INT, 0
    );

    // shaderProgram.D
}

// Shader Panel::useShaderProgram()
// Shader Panel::useShaderProgram(char *vertSource, char *fragSource)
Shader Panel::useShaderProgram(std::string vertSource, std::string fragSource)
{
    // Shader sp(
    //     "/Users/rio/Desktop/glgl/src/resources/duals/basicPosAndColor/default.vert",
    //     "/Users/rio/Desktop/glgl/src/resources/duals/basicPosAndColor/default.frag"
    // );
    Shader sp(vertSource.c_str(), fragSource.c_str());
    sp.Activate();
    return (sp);
}

void Panel::shiftByVec(float x, float y)
{
    rect = glm::vec4(
        rect.x + x,
        rect.y + y,
        rect.z,
        rect.w);
}

void Panel::setPosition(float x, float y)
{
    rect = glm::vec4(
        x, 
        y, 
        rect.z,
        rect.w);
}

// glm::vec2 mapPosToNormal(int x, int y)
// {
//     // todo : x y fault calculation
//     return glm::vec2(
//         2.f / screenWidth * x - 1.f,
//         2.f / screenHeight * y - 1.f
//     );
// }
