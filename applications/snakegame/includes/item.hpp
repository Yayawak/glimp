#pragma once
#include "../../../src/structure/headers/stdgl.hpp"

class Item : public Panel
{
private:
    std::string pathToImage;
    GLenum imageFormat;
protected:
    GLfloat *vertices[4 * 5];
    GLuint indices[6] = {
        0, 1, 2,
        2, 3, 0
    };
public:
    Item(glm::vec4 rect, std::string panelName, std::string pathToImage, GLenum imageFormat=GL_RGB);
    void setColor(glm::vec3 color);
    void changeItemImage(std::string path);
    void draw();
    inline glm::vec4 getRect() {return rect; }
};