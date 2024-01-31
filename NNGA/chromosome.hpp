#pragma once
#include <thread>
#include <vector>
#include <iostream>
#include "number_generator.hpp"
#include <cstring>
#include "utils.hpp"
#include <random>

const float MAX_RANGE = 10.0f;

struct Gene
{
    float value;

    void mutate(const float mutationRate=0.2f)
    {
        float r = NumberGenerator<float>::getInstance().getUnder(1.f);
        // random
        // float r = (rand() % 100) / 100.f;
        if (r < mutationRate)
        {
            // r += 0.5f;
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
            g.mutate(mutationRate);
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

    Chromosome* copy()
    {
        Chromosome* newC = new Chromosome(this->genes.size());
        // for (uint i(0); i < genes.size(); i++)
        for (uint i(0); i < newC->genes.size(); i++)
        {
            newC->genes[i].value = this->genes[i].value;
        }
        // std::vector<Gene> genes;
        return newC;
    }

    // float& operator[](uint i)
    // Gene& operator[](uint i)
    // {
    //     // return &(this->genes[i].value);
    //     return this->genes[i];
    // }
    ~Chromosome()
    {
        for (uint i(0); i < genes.size(); i++)
        {
            // newC->genes[i].value = this->genes[i].value;
            // delete &genes[i];
        }

    }
};