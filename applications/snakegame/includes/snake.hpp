#include "../../../src/structure/headers/stdgl.hpp"
// #include <list.h>
#include "glm/fwd.hpp"
#include <cassert>
#include <cstddef>
#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

#define ForTest // NOTE for testing features

enum Directions
{
    north, south, west, east
};

enum SnakeSigs
{
    well,
    failAddTail
};

// ? this enum use with method CalculateNextPostionOfNode()
/*
    for decision that wheather should get back or front of current Node provided in parameter
*/
enum NodeDecisionDirection
{
    front, back
};

typedef struct SSnakeNode
{
public: 
    Panel *node;
    Directions thisNodeFacingDirection;

    SSnakeNode(Panel *node, Directions thisNodeFacingDirection)
        : node(node), thisNodeFacingDirection(thisNodeFacingDirection)
    {

    }

} SnakeNode;

class Snake
{
private:
    // Directions facingDirection;
    // float 
    // linked list 
    glm::vec2 currentTailPosition;
    std::list<SnakeNode> bodyList;
    SnakeNode *head;
    glm::vec3 snakeColor;
    float nodeSize;
    float offsetEachNode;
    size_t countNode = 0;

    // SnakeSigs appendBody(Directions direction);
    // glm::vec2 calculateNextTailPosition(Directions tailDirection);
    // glm::vec2 calculateNextPosition(SnakeNode *currentNode);
    SnakeSigs preventOutOfBorder(SnakeNode *currentNode);
    glm::vec2 calculateNextPosition(SnakeNode *currentNode, NodeDecisionDirection whereToCalculateNextNode);
    SnakeSigs setFacingDirection(Directions dir);
    SnakeSigs updateAllNodeDirection();
    // bool isHeadCollidedTails();
    bool isHeadCollidedTailPosition(glm::vec2 nextPredictedPosition);

    

public:
    Snake(glm::vec2 initPosition, COLORENUM color, float nodeSize, float offsetEachNode);
    SnakeSigs addTail();
    SnakeSigs draw();
    SnakeSigs moveOneStep();
    // FIXME : un handling error occured when there are 2 or more snakes in game
    // so that all snakes are controlled with just one wasd
    // ANCHOR : in future i will use network to control connection of 2 pc
    // * i should use nmap or telnet something easy easy to play this game with friends
    SnakeSigs inputHandler(GLFWwindow *w);
    void printBodyLinkData();
};