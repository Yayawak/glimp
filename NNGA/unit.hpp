#pragma once

#include "chromosome.hpp"

struct Unit
{
    Chromosome chromosome;
    float fitness;
    bool alive;

    // Unit() = default;
    Unit(const uint genes_size)
        : chromosome(genes_size),
        fitness(0),
        alive(true)
    {
    }
	virtual void onUpdateChromosome() = 0; // ! this called updateNewWork (in ai_unit) too (to reprocess all)

    // void load

};