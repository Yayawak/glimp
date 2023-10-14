#pragma once
#include <iostream>
#include "utils.hpp"

struct Layer
{
	Layer(const uint64_t neurons_count, const uint64_t prev_count)
		: weights(neurons_count)
		, values(neurons_count)
		, bias(neurons_count)
	{
		for (std::vector<float>& v : weights) {
			v.resize(prev_count);
		}
	}

	uint64_t getNeuronsCount() const
	{
		return bias.size();
	}

	uint64_t getWeightsCount() const
	{
		return weights.front().size();
	}

	void process(const std::vector<float>& inputs)
	{
		const uint64_t neurons_count = bias.size();
		const uint64_t inputs_count = inputs.size();
		// For each neuron
		for (uint64_t i(0); i < neurons_count; ++i) {
			float result = bias[i];
			// Compute weighted sum of inputs
			for (uint64_t j(0); j < inputs_count; ++j) {
				result += weights[i][j] * inputs[j];
			}
			// Output result
			values[i] = tanh(4.0f * result);
		}
	}

//  # print values 
	void print() const
	{
		std::cout << "--- layer ---" << std::endl;
		const uint64_t neurons_count = values.size();
		for (uint64_t i(0); i < neurons_count; ++i) {
			const uint64_t inputs_count = getWeightsCount();
			// Compute weighted sum of inputs
			std::cout << "Neuron " << i << " bias " << bias[i] << std::endl;
			for (uint64_t j(0); j < inputs_count; ++j) {
				std::cout << weights[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "--- end ---\n" << std::endl;
	}

	std::vector<std::vector<float> > weights;
	std::vector<float> values;
	std::vector<float> bias;
};