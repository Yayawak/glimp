#ifndef Grid_H
#define Grid_H
#include "../headers/panel.hpp"

class Grid 
{
private:
    int rows;
    int cols;
    // Panel *gridData;
    // Panel *gridData[100];
    glm::vec3 color;
    Panel *gridData[100];
public:
    Grid(int rows, int cols);
    // Grid(int rows, int cols, glm::vec3 color);

    void drawGrid(float x, float y, float size, float offset);// 
};

#endif