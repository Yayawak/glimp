#include "headers/panel.hpp"
#include "headers/shaderClass.hpp"

    // Panel(glm::vec3 color, glm::vec4 rect, std::string panelName) : 
    //     color(color), rect(rect), panelName(panelName), shaderProgram(useShaderProgram());
Panel::Panel(glm::vec3 color, glm::vec4 rect, std::string panelName) 
    :
    rect(rect), panelName(panelName), 
    // ! cant do this line : you can't send NULL to there shaderProgram becasue it's will find file that point to NULL with erorr
    // shaderProgram(NULL, NULL)
    shaderProgram(useShaderProgram(
        "/Users/rio/Desktop/glgl/src/resources/duals/basicPosAndColor/default.vert",
        "/Users/rio/Desktop/glgl/src/resources/duals/basicPosAndColor/default.frag"
    ))
{
    // printf("color = (%f, %f, %f)\n", color.x, color.y, color.z);
    // printf("rect = (%f, %f, %f, %f)\n", rect.x, rect.y, rect.z, rect.w);
    // init();
    setColor(color);
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
    // printf("\twith xy = (%f, %f)\n", rect.x, rect.y);
}

// void Panel::init()
// {
//     // printf("setting color : %s (%f, %f, %f)\n", panelName.c_str(), color.x, color.y, color.z);
//     // GLfloat vertices[] = 

//     // vertices = 
//     GLfloat temp_v[] = 
//     {
//         //*  position                          | color
//         rect.x         , rect.y,          0.0f, color.x, color.y, color.z,
//         rect.x + rect.z, rect.y,          0.0f, color.x, color.y, color.z,
//         rect.x + rect.z, rect.y - rect.w, 0.0f, color.x, color.y, color.z,
//         rect.x         , rect.y - rect.w, 0.0f, color.x, color.y, color.z,
//     };

//     *vertices = temp_v;
//     // just for a normal rectangle
//     // GLuint indices[] = 
//     // *indices = NULL;
//     // *indices[] = 
//     // {
//     //     0, 1, 2,
//     //     2, 3, 0
//     // };
//     // VAO vao;

//     // *vao = VAO();

//     vao->Bind();

//     // VBO vbo(vertices, sizeof(vertices));
//     // EBO ebo(indices, sizeof(indices));
//     // *vbo = VBO(vertices, sizeof(vertices));
//     vbo = new VBO(*vertices, sizeof(vertices));
//     ebo = new EBO(indices, sizeof(indices));

//     //! FIXME must use specific shaders
//     vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
//     vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));
// }

void Panel::draw()
{
    GLfloat temp_v[] = 
    {
        //*  position                          | color
        rect.x         , rect.y,          0.0f, color.x, color.y, color.z,
        rect.x + rect.z, rect.y,          0.0f, color.x, color.y, color.z,
        rect.x + rect.z, rect.y - rect.w, 0.0f, color.x, color.y, color.z,
        rect.x         , rect.y - rect.w, 0.0f, color.x, color.y, color.z,
    };
    *vertices = temp_v;

    vao->Bind();
    //! must called this line every time you change data in vertices
    vbo = new VBO(*vertices, sizeof(vertices));
    ebo = new EBO(indices, sizeof(indices));

    vbo = new VBO(*vertices, sizeof(vertices));
    // ebo = new EBO(indices, sizeof(indices));
    vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
    vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

    shaderProgram.Activate();
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int),
        GL_UNSIGNED_INT, 0
    );

    vbo->Delete();
    ebo->Delete();

    delete [] vbo;
    delete [] ebo;
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
    // sp.Activate();
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

void Panel::clean()
{
    vao->Delete();
    vbo->Delete();
    ebo->Delete();
    shaderProgram.Delete();
}