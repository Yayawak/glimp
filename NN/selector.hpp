#pragma once
#include "dna_utils.hpp"
#include "neural_network.hpp"
#include "selection_wheel.hpp"
#include "unit.hpp"
#include "double_buffer.hpp"
#include <fstream>
#include <sstream>
#include "dna_loader.hpp"
#include <thread>


const float population_elite_ratio = 0.05f;
const float population_conservation_ratio = 0.25f;


template<typename T>
struct Selector
{
	const uint32_t population_size;
	const uint32_t survivings_count;
	const uint32_t elites_count;
	
	// !!!!!!!!!!!!!! What the heck is Double Object ????? (((( It's wrote by the author))))
	DoubleObject<std::vector<T> > population; // ? current pop
	SelectionWheel wheel;
	std::string out_file;
	uint32_t dump_frequency = 10;
	uint32_t generation;




// ! agents_count is no_of_snake = 8
	Selector(const uint32_t agents_count)
		: population(agents_count)
		, population_size(agents_count)
		, generation(0)
		// Y x 25%
		, survivings_count(as<uint32_t>(agents_count * population_conservation_ratio))
		// elits_count = 80 * 0.05 = 4
		, elites_count(as<uint32_t>(agents_count * population_elite_ratio))
		, wheel(survivings_count)
	{
		// const std::string base_filename = "../selector_output";
		const std::string base_filename = "./NN/outputs/selector_output";
		std::string filename = base_filename + ".bin";
		std::ifstream ifs(filename);
		uint32_t try_count = 0;
		while (ifs) {
			ifs.close();
			++try_count;
			std::stringstream sstr;
			sstr << base_filename << "_" << try_count << ".bin";
			filename = sstr.str();
			ifs.open(filename);
		}
		ifs.close();
		out_file = filename;

		std::cout << "Writing dumps in " << filename << std::endl;
	}

// !!!!!!!!!!!!!!!!!!!!!!!!!!  most important progression
	void nextGeneration()
	{
		// Create selection wheel
		sortCurrentPopulation();
		
		// This is the pointers to those 2 objects
		std::vector<T>& current_units = population.getCurrent(); // it's just popu normally
		std::vector<T>& next_units    = population.getLast();
		
		wheel.addFitnessScores(current_units);
		// Replace the weakest
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << "Gen: " << generation << " Best: " << current_units[0].fitness << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 2));
		if ((generation%dump_frequency) == 0) {
			DnaLoader::writeDnaToFile(out_file, getCurrentPopulation()[0].dna);
		}

		// The top best survive;
		uint32_t evolve_count = 0;
		for (uint32_t i(0); i < elites_count; ++i) {
			next_units[i] = current_units[i];
		}



		printf("popularion_size = %d\n", population_size);
		printf("elites_count = %d\n", elites_count);
        // std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::this_thread::sleep_for(std::chrono::milliseconds(300));




  // ! bug from here
		for (uint32_t i(elites_count); i < population_size; ++i) {
			const T& unit_1 = wheel.pick(current_units);
			const T& unit_2 = wheel.pick(current_units);
			const float mutation_proba = 1.0f / sqrt(unit_1.fitness + unit_2.fitness);
			if (unit_1.dna == unit_2.dna) {
				++evolve_count;
				// exit(-1);
				// assert(false);
				// ! load dna
				next_units[i].loadDNA(
					DNAUtils::evolve<float>(unit_1.dna, mutation_proba, mutation_proba)
				);
			}
			else {
				next_units[i].loadDNA(DNAUtils::makeChild<float>(unit_1.dna, unit_2.dna, mutation_proba));
			}
		}
		printf("evolve count = %d\n", evolve_count);
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));


  // swap for not recovery anymore ?
		switchPopulation();
	}

	void sortCurrentPopulation()
	{
		std::vector<T>& current_units = population.getCurrent();
		std::sort(current_units.begin(), current_units.end(), [&](const T& a1, const T& a2) {return a1.fitness > a2.fitness; });
	}

	const T& getBest() const
	{
		return getNextPopulation()[0];
	}

	void switchPopulation()
	{
		population.swap();
		++generation;
	}

	std::vector<T>& getCurrentPopulation()
	{
		return population.getCurrent();
	}

	const std::vector<T>& getCurrentPopulation() const
	{
		return population.getCurrent();
	}

	std::vector<T>& getNextPopulation()
	{
		return population.getLast();
	}

	const std::vector<T>& getNextPopulation() const
	{
		return population.getLast();
	}
};

