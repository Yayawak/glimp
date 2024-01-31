#ifndef Panel_H
#define Panel_H
#include "EBO.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "shaderClass.hpp"
#include <glm/glm.hpp>
#include <string>
#include <GLFW/glfw3.h>


class Panel
{
private:
    glm::vec3 color;
    // glm::vec4 rect;
    
    // NOTE : retrieve shaders from specific path
    // Shader useShaderProgram();
protected:
    // VAO *vao = NULL;
    // VBO *vbo = NULL;
    // EBO *ebo = NULL;
    VAO *vao = new VAO();
    // VBO *vbo = new VBO();
    VBO *vbo = NULL;
    EBO *ebo = NULL;
    // GLuint *indices[6];
    GLfloat *vertices[4 * 6];
    // GLfloat **vertices; // not worked
    GLuint indices[6] = 
        {
            0, 1, 2,
            2, 3, 0
        };

    Shader shaderProgram;
    virtual Shader useShaderProgram(std::string vertSource, std::string fragSource);
    // virtual void init();

public:
    std::string panelName;
    glm::vec4 rect = glm::vec4(0);
    // Panel(glm::vec3 color, glm::vec4 rect, std::string panelName) : 
    //     color(color), rect(rect), panelName(panelName), shaderProgram(useShaderProgram());
    Panel(glm::vec3 color, glm::vec4 rect, std::string panelName);
    void setColor(glm::vec3 color);
    //     color(color), rect(rect), panelName(panelName), shaderProgram(useShaderProgram());
    // {
    //     // printf("color = (%f, %f, %f)\n", color.x, color.y, color.z);
    //     // printf("rect = (%f, %f, %f, %f)\n", rect.x, rect.y, rect.z, rect.w);
    // }
    virtual void draw();
    void shiftByVec(float x, float y);
    void setPosition(float x, float y);
    void clean();
    // bool isCollideWith(Panel *other);
    // inline const glm::vec2 getPosition() const { return glm::vec2(rect.x, rect.y); }
    glm::vec2 getPosition();

};


#endif