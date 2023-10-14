#pragma once

#include "food.hpp"
#include <sys/types.h>
#include <glm/glm.hpp>
#include "../../../NNGA/objective.hpp"
#include "../../../NNGA/number_generator.hpp"
#include "../../../NNGA/swarm.hpp"
#include "snake.hpp"

struct Generation
{
    uint generation_id = 0;
    uint population_size;
    uint foodCountFoodEachPopulation = 10;

    float time;
    float best_fitness;
    uint best_unit_id;

    std::vector<Objective<Food> > foodObjectiveForEachSnake;
    std::vector<Snake> population;

    Generation() :
        population_size(8)
        // foodObjectiveForEachSnake(population_size),
        population(population_size)
    {
        // for (int i = 0; i < population_size; i++)
        // {
        //     population.push_back()
        // }
        initFoods();
        // initSnakes();
    }

    // * for copying
    Generation(Generation& generation)
    {
        *this = generation;
    }


    void initFoods()
    {
        printf("init food postion to objective object wrapper.\n");
        // for (uint i(0); i < foods.targets.size(); i++)
        // for (uint i(0); i < currentGeneration->foodObjectiveForEachSnake.size(); i++)
        // for (uint i(0); i < foodObjectiveForEachSnake.size(); i++)
        // {
            // foodObjectiveForEachSnake[j] = 10;
            // foodObjectiveForEachSnake[i] = Objective<Food>(foodCountFoodEachPopulation);
            // for (uint j(0); i < foodCountFoodEachPopulation; i++)
            // {
            //     // foodObjectiveForEachSnake[i].targets[j] = Food(
            //     Food f = Food(
            //         glm::vec4(
            //             NumberGenerator<float>::getInstance().get(),
            //             NumberGenerator<float>::getInstance().get(),
            //             0.1,
            //             0.1
            //         ),
            //         "food xx",
            //         "/Users/rio/Desktop/glgl/img/blocks/mario-power-block.png"
            //     );
            //     foodObjectiveForEachSnake[i].targets->push_back(f);
            // }
        // }
    }

    void initSnakes()
    {
        // printf("Initialized Snakes Populartion\n");
        // for (uint i(0); i < population_size; i++)
        // {
        //     Snake s = Snake(
        //         glm::vec2(
        //             NumberGenerator<float>::getInstance().get(),
        //             NumberGenerator<float>::getInstance().get()
        //         ),
        //         green,
        //         0.0025,
        //         0.008
        //     );
        //     s.snakeindex = i;

        //     Objective<Food>& ojt = foodObjectiveForEachSnake[s.snakeindex];
        //     ojt.reset();
        // }
    }
};

struct Farm
{
public:
    // glm::vec2 farmShape;
    // Objective<Food> foods;
    std::vector<Generation> generations;
    Generation* currentGeneration;
    swrm::Swarm swarm;

    Farm(uint population_size
        // glm::vec2 farmShape
    )
        :
        // : population_size(population_size),
        // farmShape(farmShape),
        generations(0),
        currentGeneration(0),
        swarm(8)
        // foods(10)
        // foodObjectiveForEachSnake(population_size)
    {
        Generation *firstGeneration;
        currentGeneration = firstGeneration;
        // firstGeneration.
        // generations.push_back()
    }


    void updateFarm(const float dt)
    {
		// const uint64_t population_size = currentGeneration->population_size;
        // // printf("population size is %llu\n", population_size);

		// auto group_update = swarm.execute([&](uint32_t thread_id, uint32_t max_thread) {
		// 	const uint64_t thread_width = population_size / max_thread;
		// 	for (uint64_t i(thread_id * thread_width); i < (thread_id + 1) * thread_width; ++i) {
		// 		// updateDrone(i, dt, update_smoke);
        //         // printf("updaing snake");
        //         // NOTE
        //         updateSnakeByIndexing(i, dt);
		// 	}
		// });
		// group_update.waitExecutionDone();
		// currentGeneration->time += dt;
    }

    void updateSnakeByIndexing(const uint snakeIndex, const float dt)
    {
        // Snake& s = currentPopulation[snakeIndex];
        // Snake& s = currentGeneration->population[snakeIndex];
        // if (!s.alive)
        // {
        //     return;
        // }
        // Objective<Food>& thisSnakeObjective = currentGeneration->
        //     foodObjectiveForEachSnake[snakeIndex];

        // // glm::vec2 toFoodVec = thisSnakeObjective.getTarget().getPosition();
        // glm::vec2 toFoodVec = 
        //     // thisSnakeObjective.getTarget().getPosition() - s.getHead()->node->getPosition();
        //     thisSnakeObjective.getTarget()->getPosition() -
        //     s.getHead()->node->getPosition();
        // const float distToFood = getLength(toFoodVec);

        // const std::vector<float> input = {
        //     toFoodVec.x,
        //     toFoodVec.y
        // };
        // s.execute(input);

        // s.fitness += 1. / (1.0 + distToFood);
        // float collectFoodRadius = 0.5f;
        // if (distToFood < collectFoodRadius)
        // {
        //     s.fitness += 100;
        //     thisSnakeObjective.archiveCurrentTarget();
        // }

        // s.draw();

        // updateBestSnakeFitness(s.fitness, s.snakeindex);
    }

    void updateBestSnakeFitness(float fitness, uint snakeId)
    {
        if (fitness > currentGeneration->best_fitness)
        {
            currentGeneration->best_fitness = fitness;
            currentGeneration->best_unit_id = snakeId;
        }
    }
};