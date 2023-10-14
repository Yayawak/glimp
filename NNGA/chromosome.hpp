#pragma once
#include <thread>
#include <vector>
#include <iostream>
#include "number_generator.hpp"
#include <cstring>
#include "utils.hpp"

const float MAX_RANGE = 10.0f;

struct Gene
{
    float value;

    void mutate(const float mutationRate=0.2f)
    {
        if (float r = NumberGenerator<>::getInstance().getUnder(1.f) < mutationRate)
        {
            r += 0.5f;
            value *= r;
        }
    }
};

struct Chromosome
{
    // uint no_genes;
    std::vector<Gene> genes;
    std::string chromosomeName;

    Chromosome(const uint no_genes) 
        // : no_genes(no_genes)
        : genes(no_genes)
    {

    }

    void initialize(const float range)
    {
        for (uint i(genes.size()); i--;)
        {
            // set
            genes[i].value = NumberGenerator<float>::getInstance().get(range);
        }
    }

    void mutateChromosome(const float mutationRate=0.2f)
    {
        for (Gene& g : genes)
        {
            g.mutate();
        }
    }

    void showChromosome() const
    {
        printf("printing chormosome\n");
        for (uint i(0); i < genes.size(); i--)
        {
            printf("%.4f, ", genes[i].value);
        }
        printf("\n");
    }
};