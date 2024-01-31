#pragma once

#include "food.hpp"
#include <sys/types.h>
#include <glm/glm.hpp>
#include "../../../NNGA/objective.hpp"
#include "../../../NNGA/number_generator.hpp"
#include "../../../NNGA/swarm.hpp"
#include "snake.hpp"
#include "generation.hpp"
#include "crossover.hpp"

struct Farm
{
public:
    // glm::vec2 farmShape;
    // Objective<Food> foods;
    // std::vector<Generation> generations;
    Generation* currentGeneration;
    float maxTimeGeneration = 0.2f;
    // swrm::Swarm swarm;
    Crossoverer crossoverer;

    Farm(uint population_size
        // glm::vec2 farmShape
    )
        // :
        // : population_size(population_size),
        // farmShape(farmShape),
        // generations(0),
        // currentGeneration(NULL)
        // swarm(8)
        // foods(10)
        // foodObjectiveForEachSnake(population_size)
    {
        Generation *firstGeneration = new Generation(population_size);
        currentGeneration = firstGeneration;
        // firstGeneration.
        // generations.push_back()
    }


    void updateFarm(const float dt)
    {
        if (isThisGenerationEnd())
        {
            // currentGeneration = .makingNewGeneration(currentGeneration);
            currentGeneration = crossoverer.makeNewGeneration(currentGeneration);

        }


		const uint64_t population_size = currentGeneration->population_size;
        // printf("population size is %llu\n", population_size);

		// auto group_update = swarm.execute([&](uint32_t thread_id, uint32_t max_thread) {
		// 	// const uint64_t thread_width = population_size / max_thread;
		// 	const uint thread_width = population_size / max_thread;
		// 	// for (uint64_t i(thread_id * thread_width); i < (thread_id + 1) * thread_width; ++i) {
		// 	for (uint i(thread_id * thread_width); i < (thread_id + 1) * thread_width; ++i) {
		// 		// updateDrone(i, dt, update_smoke);
        //         // printf("updaing snake");
        //         // NOTE
        //         // updateSnakeByIndexing(i, dt);
        //         // printf("%u\n", i);
		// 	}
		// });
		// group_update.waitExecutionDone();
        for (uint i(0); i < currentGeneration->population_size; i++)
        {
            updateSnakeByIndexing(i, dt);
        }

		currentGeneration->time += dt;
    }

    void updateSnakeByIndexing(const uint snakeIndex, const float dt)
    {
        // Snake& s = currentPopulation[snakeIndex];
        Snake& s = *currentGeneration->population[snakeIndex];
        // Snake& s = currentGeneration->population->at(snakeIndex);
        // s.update(dt);
        // Snake& s = currentGeneration->population[snakeIndex];
        if (!s.alive)
        {
            return;
        }
        // printf("sss\n");

        // Objective<Food>& thisSnakeObjective = currentGeneration->
        //     foodObjectiveForEachSnake[snakeIndex];

        // glm::vec2 toFoodVec = thisSnakeObjective.getTarget().getPosition();
        glm::vec2 toFoodVec = 
            // thisSnakeObjective.getTarget().getPosition() - s.getHead()->node->getPosition();
            // thisSnakeObjective.getTarget()->getPosition() -
            // thisSnakeObjective.getTarget().getPosition() -
            glm::vec2(0, 0) -
            // glm::vec2(-3, 2);
            //! problem here
            s.getHead()->node->getPosition();
            // s.getHead()->node->getPosition();
        // // const float distToFood = getLength(toFoodVec);
        const float distToFood = 
            sqrt(toFoodVec.x * toFoodVec.x + toFoodVec.y * toFoodVec.y);


        // const std::vector<float> input = {
        //     toFoodVec.x,
        //     toFoodVec.y
        // };

        const std::vector<float> input = {
            toFoodVec.x,
            toFoodVec.y
            // s.livingTime
        };

        s.execute(input);

        s.fitness += 1. / (1.0 + distToFood);
        float collectFoodRadius = 0.1f;
        if (distToFood < collectFoodRadius)
        {
            s.fitness += 30;
            // thisSnakeObjective.archiveCurrentTarget();
        }

        updateBestSnakeFitness(s.fitness, s.snakeindex);
        s.update(dt);
    

    
    }

    void updateBestSnakeFitness(float fitness, uint snakeId)
    {
        if (fitness > currentGeneration->best_fitness)
        {
            currentGeneration->best_fitness = fitness;
            currentGeneration->best_unit_id = snakeId;
        }
    }

    bool isAllSnakesDie()
    {
        int countAlive = 0;
        for (uint i(0); i < currentGeneration->population_size; i++)
            // countAlive += currentGeneration->population[i].alive;
            countAlive += currentGeneration->population[i]->alive;
            // countAlive += currentGeneration->population->at(i).alive;
            // currentGeneration->population->at
        return countAlive == 0;
    }

    bool isThisGenerationEnd()
    {
        // printf("current generation time %f\n", currentGeneration->time);
        if (currentGeneration->time > maxTimeGeneration || isAllSnakesDie())
        {
            // printf("Making new generation due to time exceeded.\n");
            printf("Generation %d -> Best fitness: %f\n", currentGeneration->generation_id, currentGeneration->best_fitness);
            uint maxid = currentGeneration->best_unit_id;
            // currentGeneration->population[maxid].getHead()->node->setColor(glm::vec3(0, 1, 0));
            // currentGeneration->population[maxid].getHead()->node->draw();
            currentGeneration->population[maxid]->getHead()->node->setColor(glm::vec3(0, 1, 0));
            currentGeneration->population[maxid]->getHead()->node->draw();
            // currentGeneration->population->at(maxid).getHead()->node->setColor(glm::vec3(0, 1, 0));
            // currentGeneration->population->at(maxid).getHead()->node->draw();
            // std::this_thread::sleep_for(std::chrono::milliseconds(100));
            currentGeneration->time = 0;
            return true;
        }
        return false;
    
    }


};