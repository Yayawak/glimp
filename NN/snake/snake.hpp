#pragma once

#include "../ai_unit.hpp"

// const std::vector<uint64_t arch = {7, 9, 9, 4};
// ! inputs -> {dist to foodx, distToFoodY, survie_time}
// ! outputs is 4 dires
const std::vector<uint64_t> arch = {3, 9, 9, 4};
// const std::vector<uint64_t> arch = {3, 2, 2, 4};
// const std::vector<uint64_t> arch = {3, 3, 3, 4};

struct Snake : public AiUnit
{
    glm::vec2 position;
    uint32_t index;
    float livingTime = 0;
    // glm::vec2 velocity;

    Snake()
        : AiUnit(arch)
        , position(glm::vec2(4, 4))
    {

    }

    Snake(glm::vec2& pos)
        : AiUnit(arch)
        , position(pos)
    {
        
    }

    void update(float dt)
    {
        // position += velocity;
        // if (alive)
        //     livingTime += dt;
    }

    void reset()
    {
        // position = glm::vec2(0);
        alive = true;
    }

    static int findMaxIndex(const std::vector<float>& v)
    {
        float maxVal = -9999999.f;
        int maxIndex = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > maxVal)
            {
                maxVal = v[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }

	void process(const std::vector<float>& outputs) override
    {
        // outputs has 4 elemnts (r, t, l, b)    
        // printf("output 4 dir decision is [%f, %f, %f, %f]\n\n",
        //     outputs[0], outputs[1], outputs[2], outputs[3]
        // );
        // printf("\n");
        // int maxindex
        int maxi = findMaxIndex(outputs);

        if (maxi == 0)
        {
            position += glm::vec2(1, 0);
        }
        else if (maxi == 1)
        {
            position += glm::vec2(0, 1);
        }
        else if (maxi == 2)
        {
            position += glm::vec2(-1, 0);
        }
        else if (maxi == 3)
        {
            position += glm::vec2(0, -1);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // position += glm::vec2(outputs[0], 0);
        // position += glm::vec2(0, outputs[1]);
        // position += glm::vec2(-outputs[2], 0);
        // position += glm::vec2(0, -outputs[3]);

    }
};