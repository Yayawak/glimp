#pragma once

#include "dna.hpp"


// !once you created Unit -> you created DNA of it
struct Unit
{
	Unit() = default;
	Unit(const uint64_t dna_bits_count)
		: dna(dna_bits_count)
		, fitness(0.0f)
		, alive(true)
	{}

	void loadDNA(const DNA& new_dna)
	{
		fitness = 0.0f;
		dna = new_dna;

		onUpdateDNA(); // ! load dan called onUpdateDNA
	}

	virtual void onUpdateDNA() = 0; // ! this called updateNewWork (in ai_unit) too (to reprocess all)

	DNA dna;
	float fitness;
	bool alive;
};
