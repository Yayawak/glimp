#pragma once

#include "../../../NNGA/number_generator.hpp"
#include "generation.hpp"

const float mutationRate = 0.2f;

struct Crossoverer
{
    // Snake* getMaxPropSnakeFromRouletteWheel(Generation *originGeneration)
    Chromosome* getMaxPropChromosomeFromRouletteWheel(Generation *originGeneration, std::vector<float> accumulatedProps)
    {
        float randomToSelectMaxFitness = NumberGenerator<float>::getInstance().getUnder(1.0f);
        uint selectedIndex = 1;
        for (int i = 0; i < originGeneration->population_size - 1; i++)
        {
            if (accumulatedProps[i] < randomToSelectMaxFitness &&
                randomToSelectMaxFitness < accumulatedProps[i + 1]
            )
            {
                selectedIndex = i;
            }
        }
        // Snake *s = new Snake();
        // Snake *s = new Snake(
        //     glm::vec2(
        //         NumberGenerator<float>::getInstance().get(),
        //         NumberGenerator<float>::getInstance().get()
        //     ),
        //     green,
        //     // 0.0025,
        //     0.05 / 2,
        //     0.008
        // );
        // s->snakeindex = i;
        // return originGeneration->population[selectedIndex].chromosome.copy();
        return originGeneration->population[selectedIndex]->chromosome.copy();
        // return originGeneration->population->at(selectedIndex).chromosome.copy();
    }

    Generation* makeNewGeneration(Generation* originGeneration)
    {
        float sumFitness = 0.0f;
        for (int i = 0; i < originGeneration->population_size; i++)
        {
            // sumFitness += originGeneration->population[i].fitness;
            sumFitness += originGeneration->population[i]->fitness;
            // sumFitness += originGeneration->population->at(i).fitness;
        }
        std::vector<float> propEachSnake;
        for (int i = 0; i < originGeneration->population_size; i++)
        {
            // float p = originGeneration->population[i].fitness / sumFitness;
            float p = originGeneration->population[i]->fitness / sumFitness;
            // float p = originGeneration->population->at(i).fitness / sumFitness;
            // printf("prop = %f\n", p);
            propEachSnake.push_back(p);
        }
        std::vector<float> accumulatedProps;
        accumulatedProps.push_back(propEachSnake[0]);
        for (int i = 1; i < originGeneration->population_size; i++)
        {
            float val = accumulatedProps[i - 1] + propEachSnake[i];
            accumulatedProps.push_back(val);
            // printf("val = %f\n", val);
        }


        Generation *newGeneration = new Generation(originGeneration->population_size);
        newGeneration->generation_id = originGeneration->generation_id + 1;
        newGeneration->initSnakes();
        // newGeneration->time = 0;
        for (int i = 0; i < originGeneration->population_size; i++)
        {
            // newGeneration->population[i].chromosome = *getMaxPropChromosomeFromRouletteWheel(originGeneration, accumulatedProps);
            Chromosome *c1 = getMaxPropChromosomeFromRouletteWheel(originGeneration, accumulatedProps);
            Chromosome *c2 = getMaxPropChromosomeFromRouletteWheel(originGeneration, accumulatedProps);

            size_t N = c1->genes.size();
            size_t mid = N / 2;
            Chromosome *c3 = c1->copy();
            // // Chromosome *c4 = c1.
            // // for (int i = 0; i < c1->genes.size(); i++)
            for (size_t j = 0; j < N; j++)
            // for (size_t i = 0; i < mid; i++)
            {
                if (j < mid)
                {
                    // c3[j] = c2[j];
                    // c3[j].value = c2[j];
                    // c3[j].
                    c3->genes[j].value = c2->genes[j].value;
                    // c3->genes[j]
                    // c4[]
                }
                else
                {
                    c3->genes[j].value = c1->genes[j].value;
                    // c3[i] = c1[i - mid];
                    // c3[j] = c1[j];
                }
            }
            // newGeneration->population[i].chromosome = *c3;
            // newGeneration->population[i].chromosome.mutateChromosome();
            newGeneration->population[i]->chromosome = *c3;
            newGeneration->population[i]->chromosome.mutateChromosome();
            // newGeneration->population->at(i).chromosome = *c3;
            // newGeneration->population->at(i).chromosome.mutateChromosome();
        }
        delete originGeneration;
        // free(originGeneration);
        return newGeneration;
    }
};