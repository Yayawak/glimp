#include "../../../src/structure/headers/stdgl.hpp"

class Item : Panel
{
private:

public:
    Item(glm::vec4 rect, std::string panelName);
    void setColor(glm::vec3 color);
    void changeItemImage(const char *full);
    void draw();
};

Item::Item(glm::vec4 rect, std::string imageName)
    : Panel(glm::vec3(0, 0, 0), rect, imageName)
{
    shaderProgram = useShaderProgram(
        "/Users/rio/Desktop/glgl/src/resources/duals/basicPosAndColor/default.vert",
        "/Users/rio/Desktop/glgl/src/resources/duals/basicPosAndColor/default.frag"
    );
}

void Item::draw()
{
}