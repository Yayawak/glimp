#pragma once
#include "unit.hpp"
#include "neural_network.hpp"

struct AiUnit : public Unit
{
    Network network;

    AiUnit()
        : Unit(0)
    {
    }

    AiUnit(
        const std::vector<uint>& network_architecture
    )
        : Unit(Network::getParametersCount(network_architecture) * 32),
        network(network_architecture)
    {
        float initRangeRandom = 1.f;
        chromosome.initialize(initRangeRandom);
        updateNetwork();
    }

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
				float f = chromosome.genes[i].value;
				layer.bias[i] = f;
			}

			for (uint64_t i(0); i < neurons_count; ++i) {
				const uint64_t weights_count = layer.getWeightsCount();
				for (uint64_t j(0); j < weights_count; ++j) 
				{
                    float f = chromosome.genes[i].value;
					layer.weights[i][j] = f;
				}
			}
		}
	}

	void onUpdateChromosome() override
	{
		updateNetwork();
	}

	void execute(const std::vector<float>& inputs)
	{
		// printf("input goese to NN of a anonymouse snake is \t[");
        // showsvec(inputs);

		const std::vector<float>& outputs = network.execute(inputs);
		// ! execute -> process
		process(outputs);
	}

	virtual void process(const std::vector<float>& outputs) = 0;


};