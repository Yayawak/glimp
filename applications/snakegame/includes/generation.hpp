#pragma once

#include "food.hpp"
#include <sys/types.h>
#include <glm/glm.hpp>
#include "../../../NNGA/objective.hpp"
#include "../../../NNGA/number_generator.hpp"
// #include "../../../NNGA/swarm.hpp"
#include "snake.hpp"


struct Generation
{
    uint generation_id = 0;
    uint population_size;
    uint foodCountFoodEachPopulation = 10;

    float time = 0;
    float best_fitness = -1;
    uint best_unit_id = 0;

    // std::vector<Objective<Food> > foodObjectiveForEachSnake;
    std::vector<Snake *> population;
    // std::vector<Snake> population;
    // std::vector<Snake> *population;

    Generation(uint population_size) :
        population_size(population_size)
        // foodObjectiveForEachSnake(population_size),
        // population(population_size)
    {
        // for (int i = 0; i < population_size; i++)
        // {
        //     population.push_back()
        // }
        initFoods();
        initSnakes();
    }

    // * for copying
    // Generation(Generation& generation)
    // {
    //     *this = generation;
    // }


    void initFoods()
    {
        // // printf("init food postion to objective object wrapper.\n");
        // // for (uint i(0); i < foods.targets.size(); i++)
        // // for (uint i(0); i < currentGeneration->foodObjectiveForEachSnake.size(); i++)
        // for (uint i(0); i < foodObjectiveForEachSnake.size(); i++)
        // {
        //     // foodObjectiveForEachSnake[j] = 10;
        //     // foodObjectiveForEachSnake[i] = Objective<Food>(foodCountFoodEachPopulation);
        //     foodObjectiveForEachSnake.push_back(
        //         // Objective<Food>(foodCountFoodEachPopulation)
        //         Objective<Food>()
        //     );
        //     for (uint j(0); i < foodCountFoodEachPopulation; i++)
        //     {
        //         // foodObjectiveForEachSnake[i].targets[j] = Food(
        //         Food f = Food(
        //             glm::vec4(
        //                 NumberGenerator<float>::getInstance().get(),
        //                 NumberGenerator<float>::getInstance().get(),
        //                 0.1,
        //                 0.1
        //             ),
        //             "food xx",
        //             "/Users/rio/Desktop/glgl/img/blocks/mario-power-block.png"
        //         );
        //         // foodObjectiveForEachSnake[i]->targets->push_back(f);
        //         foodObjectiveForEachSnake[i].targets.push_back(f);
        //     }
        // }
    }

    void initSnakes()
    {
        // printf("Initialized Snakes Populartion\n");
        for (uint i(0); i < population_size; i++)
        {
            Snake *s = new Snake(
                glm::vec2(
                    NumberGenerator<float>::getInstance().get(),
                    NumberGenerator<float>::getInstance().get()
                ),
                green,
                // 0.0025,
                0.05 / 4,
                0.008
            );
            s->snakeindex = i;
            for (int i = 0; i < 3; i++)
                s->addTail();

            // population->push_back(s);
            population.push_back(s);
            // population.push_back(*s);

            // Objective<Food>& ojt = foodObjectiveForEachSnake[s.snakeindex];
            // ojt.reset();
        }
    }

    ~Generation()
    {
        // delete [] foodObjectiveForEachSnake;
        // delete [] population;
        // delete foodObjectiveForEachSnake;
        // delete population;
        // population.swap(population);

    // std::vector<Objective<Food> >().swap(foodObjectiveForEachSnake); ;
    // std::vector<Snake>().swap(population);
        // foodObjectiveForEachSnake = std::vector<Objective<Food> >();
        // population = std::vector<Snake>();
        for (int i = 0; i < population_size; i++)
        {
            // Snake s = &population[i];
            // delete population->at(i);
            // for (int j = 0; j < population[i].chromosome.)
            // delete &population[i].chromosome;

            // Snake *s = &population[i];
            delete population[i];
        }

    }
};