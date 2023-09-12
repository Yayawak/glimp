// #include "../headers/stdgl.hpp"
#include "Grid.hpp"

Grid::Grid(int rows, int cols) : rows(rows), cols(cols) 
{
    // Grid(rows, cols, glm::vec3(0.0f, 1.0f, 0.0f));
}
// Grid::Grid(int rows, int cols) : rows(rows), cols(cols), gridData(Panel [100])
// Grid::Grid(int rows, int cols, glm::vec3 color) : rows(rows), cols(cols), color(color)
// // ! still bug on coloring 
// Grid::Grid(int rows, int cols, glm::vec3 _color) : rows(rows), cols(cols), color(_color)
// {
//     // Panel gridPanels[rows * cols];
//     // for 
//     // Panel ps();
//     // gridData = new Panel[100];
//     // gridData = Panel[rows * cols];
//     // gridData = new Panel[rows * cols + 1];
//     // gridData = null;
//     this->color = _color;
// }

void Grid::drawGrid(float x, float y, float size, float offset) 
{
    glm::vec4 rect;

    // color = glm::vec3(0.0f, 0.4f, .5f);

    int k = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // todo : square
            rect = glm::vec4(
                // -0.9f + i * (size + offset),
                // 0.9f - j * (size + offset),
                // x + i * (size + offset),
                // y - j * (size + offset),
                x + j * (size + offset),
                y - i * (size + offset),
                size, size);
            // makePanel(color, rect, "box");

            gridData[k] = new Panel(color, rect, "subgrid");
            gridData[k]->draw();
            k++;
        }
    }
}