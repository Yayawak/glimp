#ifndef Panel_H
#define Panel_H
#include "EBO.hpp"
#include "VAO.hpp"
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
    Shader shaderProgram;
    virtual Shader useShaderProgram(std::string vertSource, std::string fragSource);

public:
    std::string panelName;
    glm::vec4 rect;
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


};


#endif