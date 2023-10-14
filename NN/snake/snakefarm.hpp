#pragma once

#include "../selector.hpp"
#include "snake.hpp"
#include "../objective.hpp"
#include "../swarm.hpp"
#include <thread>
// #include <windows.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// Test
// #define TT 

struct Iteration
{
    float time;
    float best_fitness;
    uint32_t best_unit;

    void reset()
    {
        time = 0.0f;
        best_fitness = 0.0f;
        best_unit = 0;
    }
};

struct SnakeFarm
{
    Selector<Snake> selector;
    std::vector<Objective> objectiveOfAllSnakes;
    uint32_t foodCount;
    std::vector<glm::vec2 > foodPositions;
    uint32_t popSize;
    glm::vec2 farmShape;

	Iteration current_iteration;
	swrm::Swarm swarm;
	float max_iteration_time;

    SnakeFarm(uint16_t no_pops, glm::vec2 farm_shape)
        :
        selector(no_pops),
        popSize(no_pops),
        foodCount(10),
        foodPositions(foodCount),
        objectiveOfAllSnakes(no_pops),
        farmShape(farm_shape),
        swarm(8),
        // max_iteration_time(500) // * normal
        // max_iteration_time(100) // * normal
        // max_iteration_time(10) // * normal
        // max_iteration_time(dt * 30 times) // * too much (we plus by dt = 0.008)

        max_iteration_time(0.8f) // * normal
        // max_iteration_time(0.4f) //  fast
        // max_iteration_time(0.2f) //  fast
        // max_iteration_time(100 / 2) // * normal
        // max_iteration_time(1) // too fast
        // max_iteration_time(1 * 1000)
    {

    }


    void initFoods()
    {
        // const 
		for (uint32_t i(0); i < foodCount; ++i)
        {
            // foodPositions[i] = glm::
			foodPositions[i] = 
                // glm::vec2(border + getRandUnder(area_size.x - 2.0f * border),
                //             border + getRandUnder(area_size.y - 2.0f * border));
                glm::vec2(getRandUnder(farmShape.x),
                            getRandUnder(farmShape.y));
        }

    }

    void initSnakes()
    {
        // printf("reinit snakes\n");
        std::vector<Snake>& snakes = selector.getCurrentPopulation();
        size_t i(0);

        #ifdef TT
        printf("called init snakes function to set init postion of its\n");
        #endif
        for (Snake& s : snakes)
        {
            s.index = i++;
            s.position = glm::vec2(farmShape.x / 2, farmShape.y / 2);
            // s.position = glm::vec2(5, 5);
            // s.position = glm::vec2(5, 3);
            // s.position = glm::vec2(0,0);
            s.reset();

            Objective& ojt = objectiveOfAllSnakes[s.index];
            ojt.reset();
            ojt.points = getLength(s.position - foodPositions[0]);
        }
    }

    bool checkIsSnakeOutOfBoard(const Snake& snk)
    {
        // printf("checking alive.\n");
        float farmWidth = farmShape.x;
        float farmHeight = farmShape.y;
        // printf("farm w,h = [%f, %f]\n", farmWidth, farmHeight);

        if (snk.position.x > farmWidth - 1|| snk.position.x < 0)
            return false;
        if (snk.position.y > farmHeight - 1|| snk.position.y < 0)
            return false;
        return true;
    }



    uint32_t getAliveCount() const
    {
        uint32_t count = 0;
        // const std::vector<Snake>& snakes = 
        for (const Snake& s : selector.getCurrentPopulation())
        {
            // alive is bool
            count += s.alive;
        }
        return count;
    }

    // NOTE : called by updateFarm()
    void updateSnakeByIndexing(uint64_t i, float dt)
    {
        // printf("current snake index: %llu\n", i);
        Snake& s = selector.getCurrentPopulation()[i];
        updateBestFitness(s.fitness, s.index);
        // printf("s.x = %f, s.y = %f\n", s.position.x, s.position.y);
        // showvec(s.position, "current snk position : "); // ! bug from here (nan,nan vec)
        if (!s.alive)
        {
            return;
        }
        else
        {
            // printf("set time of snake.\n");
            s.livingTime = current_iteration.time;
        }

        Objective& ojt = objectiveOfAllSnakes[s.index];        

        // ! problem is getTarget
        glm::vec2 currentFoodPosition =  ojt.getTarget(foodPositions);
        // showvec(currentFoodPosition, "currentFood position : ");
        // showvec(s.position, "current snk position : "); // ! bug from here (nan,nan vec)
        glm::vec2 toFoodVec = ojt.getTarget(foodPositions) - s.position;
        float toFoodDist = getLength(toFoodVec);
        // showvec(toFoodVec, "food dist : "); // !nan

        const std::vector<float> input = {
            toFoodVec.x,
            toFoodVec.y
            // s.livingTime
        };

        s.execute(input);
        s.update(dt);



        s.alive = checkIsSnakeOutOfBoard(s);
        if (s.alive == false)
        {
            s.fitness -= 150;
        }
        // if (!s.alive)
        // {
        //     printf("snake died");
        // }
        // else
        //     printf("snake alived");

        // s.fitness += 1.0f / (1.0f + toFoodDist);
        // s.fitness += (2 + (s.livingTime)) / (1.0f + toFoodDist);
        // s.fitness += (2 + (sqrt(s.livingTime))) / (1.0f + toFoodDist);
        // if shape[x, y] = [20, 20] -> max furthest distance is sqrt(20 ** 2 + 20 ** 2) = 28

        s.fitness += 1  / (1.0f + toFoodDist);


        // NOTE :  value from above formular should lay between [0, 1]
        // s.fitness += 100 + s.livingTime / (1.0f + toFoodDist);
        // s.fitness += 1;
        	// We don't want weirdos
		// const float score_factor = std::pow(cos(d.angle), 2.0f);
		// const float target_time = 10.0f;

        // float score_factor = std::pow(toFoodDist, 8);
        // float score_factor = std::pow(toFoodDist, 8);
        // float score_factor = 1 / std::pow(toFoodDist, 9);
		// !!!!!!!!!!!!! evaluation funccion goes here
		// if (to_target_dist < target_radius + d.radius) {
        float collectFoodRadius = 1.f;
        ojt.addTimeIn(dt);
		if (toFoodDist < collectFoodRadius) {
			// objective.addTimeIn(dt);
            #ifdef TT
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            #endif

            current_iteration.time = 0; // reset time reward
            // ojt.addTimeIn(dt);

			// if (ojt.time_in > target_time) {
			// if (ojt.time_in > target_time) {
			// if (ojt.time_in < target_time) {
				// d.fitness += score_factor * objective.points / (1.0f + objective.time_out);
				// s.fitness += 1 + ojt.points / (1.0f + ojt.time_out);
				// s.fitness += score_factor * ojt.points / (1.0f + ojt.time_out);
				// s.fitness += 100000 * ojt.points / (1.0f + ojt.time_out);
				s.fitness += 300;
                // s.fitness += ojt.points;
                // s.
            // ! next target must be done (food must be eated)
				ojt.nextTarget(foodPositions);
				// objective.points = getLength(d.position - objective.getTarget(targets));
				ojt.points = getLength(s.position - ojt.getTarget(foodPositions));
                // printf("Get Food in time (%f)\n", ojt.time_in);
                // std::this_thread::sleep_for(std::chrono::milliseconds(2000));

                // exit(-2);

			// }
		}
		else {
			// ojt.addTimeOut(dt);
		}

        // printf("s.lving time = %f\n", s.livingTime);// ok
        // printf("to food dist = %f\n", toFoodDist); // !nan

        // if (toFoodDist < )

        updateBestFitness(s.fitness, s.index);
    }

	void updateBestFitness(float fitness, uint32_t id)
	{
        // printf("updating best")
        // nan
        // printf("finess of considering snake is %f\n", fitness);
		if (fitness > current_iteration.best_fitness) {
			current_iteration.best_fitness = fitness;
			current_iteration.best_unit = id;
		}
	}

    void updateFarm(float dt)
    {
        // printf("updating farm \n");
		const uint64_t population_size = selector.getCurrentPopulation().size();
        // printf("population size is %llu\n", population_size);

		auto group_update = swarm.execute([&](uint32_t thread_id, uint32_t max_thread) {
			const uint64_t thread_width = population_size / max_thread;
			for (uint64_t i(thread_id * thread_width); i < (thread_id + 1) * thread_width; ++i) {
				// updateDrone(i, dt, update_smoke);
                // printf("updaing snake");
                // NOTE
                updateSnakeByIndexing(i, dt);
			}
		});
		group_update.waitExecutionDone();

		current_iteration.time += dt;
    }

	bool isFirstIteration() const
	{
		return selector.generation == 0;
	}

    bool isThisGenerationEnd()
    {
		if ( getAliveCount() == 0)
		{
			printf("making new generation dueto no snakes alive.\n");
            return true;
		}
		if( current_iteration.time > max_iteration_time )
		{
            printf("making new generation due to time exceeded.\n");
            // printf("generation_current_time = %f\n", current_iteration.time);
            // printf("max_iteration_time      = %f\n", max_iteration_time);
            // std::this_thread::sleep_for(std::chrono::milliseconds(5000));

            return true;
		}
		if ( isFirstIteration())
		{
            printf("making new generation due to it's first generation -> skipped.\n");
            return true;
		}
        return false;
        // return getAliveCount() == 0
        //     || current_iteration.time > max_iteration_time
        //     || isFirstIteration();
    }

	void CreateNewGeneration()
	{
        // printFarmWithBestSnakeInCurrentPopulation();
		// printf("start new iteration (new gen)\n");
		selector.nextGeneration();
		initFoods();
		initSnakes();
		current_iteration.reset();
	}

    // printf()
    void printFarmWithBestSnakeInCurrentPopulation()
    {
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        // std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // const Snake& s = selector.getBest();
        const Snake& s = selector.getCurrentPopulation()[current_iteration.best_unit];
        // printf()
        uint32_t currentUnEatedId = objectiveOfAllSnakes[ current_iteration.best_unit ].target_id;
        glm::vec2 foodPos = foodPositions[currentUnEatedId];

        printf("position of best snake    [%f, %f]\n", s.position.x, s.position.y);
        printf("position of current food  [%f, %f]\n", foodPos.x, foodPos.y);

        for (int i(0); i < farmShape.y; i++)
        {
            // if (i == 0 || i == farmShape.y - 1)
            // if (i == 0)
            // {
            //     for (int j(0); j < farmShape.x; j++)
            //     {
            //         printf("-*");
            //     }
            // }
            for (int j(0); j < farmShape.x; j++)
            {
                // if (i == 0 || i == farmShape.y - 1)
                // {
                //     printf("-");
                // }
                // if (j == 0 || j == farmShape.x - 1)
                // if (!(i == 0 || i == farmShape.y - 1) && (j == 0 || j == farmShape.x - 1))
                // {
                //     printf("| ");
                // }
                // if (j == 0 && (i != farmShape.y - 1 || i != 0))

                // if (j == 0 && i != 0)
                // // if (j == 0 )
                // {
                //     printf("|");
                // }



                if ((int)(s.position.x) == j
                    && (int)(s.position.y) == i
                )
                {
                    // printf("* ");
                    // system("Color 40");
                    printf(GRN "X " RESET);
                }
                else if ((int)(foodPos.x) == j
                    && (int)(foodPos.y) == i
                )
                {
                    // system("Color 20");
                    printf(RED "F " RESET);
                    // std
                }
                else
                {
                    // system("Color 70");
                    printf("• ");
                    // printf("  ");
                }

                // if (j == farmShape.x - 1 && (i != farmShape.y - 1 || i != 0))
                // if (j == farmShape.x - 1)
                // if (j == farmShape.x - 1 && i != farmShape.y - 1 && i != 0)
                // // if (j == 0 && i == farmShape.x - 1)
                // {
                //     printf("|");
                // }

            }
            // if (i == farmShape.y - 1)
            // {
            //     for (int j(0); j < farmShape.x; j++)
            //     {
            //         printf("-*");
            //     }
            // }
            printf("\n");
        }
        // printf("\n\n\n\n");
        printf("\n\n");
    }
};