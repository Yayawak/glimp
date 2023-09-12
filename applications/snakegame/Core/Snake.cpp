#include "../includes/snake.hpp"

Snake::Snake(glm::vec2 initPosition, COLORENUM color, float nodeSize, float offsetEachNode) 
    // : snakeColor(glm::vec3(200.0, 0, 0)), currentTailPosition(initPosition),
    : currentTailPosition(initPosition),
        nodeSize(nodeSize), offsetEachNode(offsetEachNode)
{
    #ifdef ForTest
    // snakeColor = glm::vec3(200.0, 10., 10.);
    snakeColor = glm::vec3(0.0, 210., 10.);
    #endif

    addTail();
}

static std::string getDirectionName(Directions dir)
{
    if (dir == north)
        return "north";
    else if (dir == south)
        return "south";
    else if (dir == west)
        return "west";
    else if (dir == east)
        return "east";
    return "in valid direction";
}

SnakeSigs Snake::preventOutOfBorder(SnakeNode *currentNode)
{
    if (currentNode->node->rect.x > 1)    
    {
        currentNode->node->rect.x = -1;
    }
    else if (currentNode->node->rect.x < -1)    
    {
        currentNode->node->rect.x = 1;
    }
    else if (currentNode->node->rect.y > 1)    
    {
        currentNode->node->rect.y = -1;
    }
    else if (currentNode->node->rect.y < -1)    
    {
        currentNode->node->rect.y = 1;
    }
    return (well);
}

// glm::vec2 Snake::calculateNextTailPosition(Directions tailDirection)
glm::vec2 Snake::calculateNextPosition(SnakeNode *currentNode, NodeDecisionDirection whereToCalculateNextNode)
{
    preventOutOfBorder(currentNode);
    int directionMultiplier = (whereToCalculateNextNode == front) ? 1 : -1;
    // std::cout << "old tail direction : " << currentNode->thisNodeFacingDirection << "\n";
    glm::vec2 *nextPos = NULL;
    switch (currentNode->thisNodeFacingDirection) {
        case north:
            nextPos = 
                new glm::vec2(
                    currentNode->node->rect.x,
                    currentNode->node->rect.y + (nodeSize + offsetEachNode) * directionMultiplier
                );
            break;
        case south:
            nextPos = 
                new glm::vec2(
                    currentNode->node->rect.x,
                    currentNode->node->rect.y - (nodeSize + offsetEachNode) * directionMultiplier
                );
            break;
        case west:
            nextPos = 
                new glm::vec2(
                    currentNode->node->rect.x - (nodeSize + offsetEachNode) * directionMultiplier,
                    currentNode->node->rect.y
                );
            break;
        case east:
            nextPos = 
                new glm::vec2(
                    currentNode->node->rect.x + (nodeSize + offsetEachNode) * directionMultiplier,
                    currentNode->node->rect.y
                );
            break;
    }
    assert(&nextPos != NULL);
    // currentNode->node->rect = *nextPos;
    // currentNode->thisNodeFacingDirection = 
    return (*nextPos);
}

SnakeSigs Snake::addTail()
{
    // glm::vec4 rectangle();
    // tail.
    if (bodyList.size() == 0)
    {
        std::cout << "init node head\n";
        glm::vec2 wh(nodeSize, nodeSize);
        glm::vec4 rect(currentTailPosition, wh);
        head = new SnakeNode(
            // new Panel(snakeColor, rect, "a body"),
            // new Panel(glm::vec3(255, 0, 255), rect, "H"),
            new Panel(glm::vec3(230, 100, 60), rect, "H"),
            south
            // south
        );
        
        bodyList.push_front(*head);

        head = &bodyList.front();
        countNode++;
        return (well);
    }

    SnakeNode oldTail = bodyList.back();
    glm::vec2 nextPos = calculateNextPosition(&oldTail, back);
    currentTailPosition = nextPos;
    glm::vec2 wh(nodeSize, nodeSize);
    glm::vec4 rect( nextPos, wh );

    SnakeNode *newTail = new SnakeNode(
        // new Panel(snakeColor, rect, "a body"),
        new Panel(snakeColor, rect, std::to_string(countNode)),
        oldTail.thisNodeFacingDirection    
    );
    bodyList.push_back(*newTail);
    countNode++;
    return (well);
}

SnakeSigs Snake::draw()
{
    std::list<SnakeNode>::iterator it;

    it = bodyList.begin();
    while (it != bodyList.end())
    {
        SnakeNode currentNode = *it;
        currentNode.node->draw();
        it++;
    }

    return (well);
}

SnakeSigs Snake::updateAllNodeDirection()
{
    // std::cout << "processing reverse polaris\n";
    std::list<SnakeNode>::reverse_iterator it = bodyList.rbegin();

    SnakeNode *prevNode = NULL;
    while (it != bodyList.rend())
    {
        SnakeNode *currentNode = &(*it);

        // printf("current (from tail ) = %s\n", currentNode->node->panelName.c_str());
        if (prevNode != NULL)
        {
            // printf("setting direction [%s -> %s] : [%s -> %s]\n",
            //     currentNode->node->panelName.c_str(),
            //     prevNode->node->panelName.c_str(),
            //     getDirectionName(currentNode->thisNodeFacingDirection).c_str(),
            //     getDirectionName(prevNode->thisNodeFacingDirection).c_str()
            // );
            prevNode->thisNodeFacingDirection = currentNode->thisNodeFacingDirection;
        }
        prevNode = currentNode;
        // printBodyLinkData();
        it++;
    }
    // std::cout << "after reverse shift value from tail...";
    // printBodyLinkData();
    // std::cout << "\n";

    return (well);
}


SnakeSigs Snake::moveOneStep()
{
    // updateAllNodeDirection();

    std::list<SnakeNode>::iterator it = bodyList.begin();
    // std::cout << "moveOneStep\n";
    while (it != bodyList.end())
    {
        // SnakeNode currentNode = *it;
        SnakeNode *currentNode = &(*it);
        // currentNode->
        // calculateNextTailPosition(Directions tailDirection)
        glm::vec2 nextPos = calculateNextPosition(currentNode, front);
        // printf("nextPos = (%f, %f)\n", nextPos.x, nextPos.y);
        currentNode->node->setPosition(nextPos.x, nextPos.y);
        it++;
    }

    updateAllNodeDirection();
    // printBodyLinkData();
    return (well);
}

SnakeSigs Snake::setFacingDirection(Directions dir)
{
    head->thisNodeFacingDirection = dir;
    // printf("head direction      : %d\n", head->thisNodeFacingDirection);
    // printf("real head direction : %d\n", bodyList.front().thisNodeFacingDirection);
    return (well);
}

SnakeSigs Snake::inputHandler(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && head->thisNodeFacingDirection != south)
    {
        setFacingDirection(north);
    }
    // if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && head->thisNodeFacingDirection != east)
    {
        setFacingDirection(west);
    }
    // if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && head->thisNodeFacingDirection != north)
    {
        setFacingDirection(south);
    }
    // if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && head->thisNodeFacingDirection != west)
    {
        setFacingDirection(east);
    }
    // std::cout << "facingDirection: " <<facingDirection << std::endl;
    return (well);
}

void Snake::printBodyLinkData()
{
    auto it = bodyList.begin();

    SnakeNode *node;
    std::stringstream ss;
    ss << "HEAD : ";
    while (it != bodyList.end())
    {
        // Directions[0];

        node = &*it;
        
        ss << "["
        // << node->node->rect.x * 100
        // << ","
        // << node->node->rect.y * 100
        << node->node->panelName
        << ","
        << getDirectionName(node->thisNodeFacingDirection)
        << "] -> ";
        // std::string

        it++;
    }
    ss << "NULL";

    std::cout << ss.str() << std::endl;
}