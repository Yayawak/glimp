#pragma once

#include "unit.hpp"
#include "neural_network.hpp"


struct AiUnit : public Unit
{
	AiUnit()
		: Unit(0)
	{}

	AiUnit(const std::vector<uint64_t>& network_architecture)
	 // ! how many genomes (dna_bits_count)
	 // NOTE : subsequence of creating unit also created dna too
	// ? we parse the total number of parameters used in DNA so we can pre-reserve space array
	// ? for stored genomes
		: Unit(Network::getParametersCount(network_architecture) * 32)
		, network(network_architecture)
	{
		dna.initialize<float>(1.0f);

		// dna.dnalist<float>();
		



		// dna
		// for (int i = 0; i < dna.code.size(); i++)
		// {
		// 	// printf("dna code [%d] = %f\n", i, dna.code[i]);
		// 	std::cout << "dna code " << i << " = " << dna.code[i] << std::endl;
		// }
		// dna.initialize<float>(10.0f);
		updateNetwork();
	}

	void execute(const std::vector<float>& inputs)
	{
		// printf("input goese to NN of a anonymouse snake is \t[");
		// for (int i = 0; i < inputs.size(); i++)
		// {
		// 	printf("%f, ", inputs[i]);
		// }
		// printf("]\n");

		const std::vector<float>& outputs = network.execute(inputs);
		// ! execute -> process
		process(outputs);
	}

// ! most importance how it's integrate with GA
	void updateNetwork()
	{
		// printf("UPDATED NETWORK\n");
		// ! problem getting dna wrong order
		// printf("basic info before tunning dna to layers parameters\n");
		// printf("No. Layers = %lu\n", network.layers.size());
		

		// dna.dnalist<float>();



		uint64_t index = 0;
		for (Layer& layer : network.layers) {
			const uint64_t neurons_count = layer.getNeuronsCount();
			for (uint64_t i(0); i < neurons_count; ++i) {
				// ! from this loop assume that DNA is stored like
				// | biases | weights flatten matrix |
				// * if no_neurons of every layer is 2
				// ? ex in layer 0 (if weight count = 2 per neuron)
				// | 0, -3 | 2 -1 3 4 |
				// layer.bias[i] = dna.get<float>(index++);
				float f = dna.get<float>(index++);
		// 	std::cout << "dna code " << i << " = " << dna.code[i] << std::endl;
				// printf("float get from %f\n", f);
				// std::cout << "dna code " << index << " = " << dna.get<float>(index) << std::endl; 
				// std::cout << "dna code " << i << " = " << f << std::endl; 
				layer.bias[i] = f;
			}

			for (uint64_t i(0); i < neurons_count; ++i) {
				const uint64_t weights_count = layer.getWeightsCount();
				for (uint64_t j(0); j < weights_count; ++j) 
				{
					layer.weights[i][j] = dna.get<float>(index++);
					// std::cout << "dna code " << index << " = " << dna.get<float>(index) << std::endl; 
				}
			}
		}
	}

	void onUpdateDNA() override
	{
		updateNetwork();
	}

	virtual void process(const std::vector<float>& outputs) = 0;

	Network network;
};
