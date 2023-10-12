#pragma once

#include <vector>
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


struct Network
{
	Network()
		: input_size(0)
		, last_input(0)
	{}

	Network(const uint64_t input_size_)
		: input_size(input_size_)
		, last_input(input_size_)
	{}

	Network(const std::vector<uint64_t>& layers_sizes)
		: input_size(layers_sizes[0])
		, last_input(input_size)
	{
		// for (uint64_t i(1); i < layers_sizes.size(); ++i) {
		for (uint64_t i(0); i < layers_sizes.size(); ++i) {
			addLayer(layers_sizes[i]);
		}
		printf("---------------------\n");
	}

	void addLayer(const uint64_t neurons_count)
	{
		// // if (!layers.empty()) {
		// if (layers.empty()) {
		// 	printf("now nn layers = 0 (empty) creating fisrt layer.\n");
		// 	// layers.emplace_back(neurons_count, layers.back().getNeuronsCount());
		// 	Layer l = Layer(neurons_count, layers.back().getNeuronsCount());
		// 	layers.push_back(l);
		// 	// layers.pus
		// }
		// else {
		// 	Layer l = Layer(neurons_count, input_size);
		// 	// layers.emplace_back(neurons_count, input_size);
		// 	layers.push_back(l);
		// 	printf("Creating nn layers = %lu\n", layers.size());
		// }



		if (!layers.empty()) {
			layers.emplace_back(neurons_count, layers.back().getNeuronsCount());
		}
		else {
			layers.emplace_back(neurons_count, input_size);
		}

		printf("Created layer %lu\n", layers.size());
	}

	const std::vector<float>& execute(const std::vector<float>& input)
	{
		// printf("NO of layers is %lu\n", input.size());
		last_input = input;
		if (input.size() == input_size) {
			layers.front().process(input);
			const uint64_t layers_count = layers.size();
			for (uint64_t i(1); i < layers_count; ++i) {
				layers[i].process(layers[i - 1].values);
			}
		}
		else
			fprintf(stderr,
			"Error : mismatch provided input_size (%lu)  and expected input size (%llu)\n"
			, 
			input.size(),
			input_size
		);

		// print();

		// ? return the right most layers (output layer) values
		return layers.back().values;
	}

	uint64_t getParametersCount() const
	{
		uint64_t result = 0;
		for (const Layer& layer : layers) {
			result += layer.bias.size() * (1 + layer.weights.front().size());
		}
		return result;
	}

	static uint64_t getParametersCount(const std::vector<uint64_t>& layers_sizes)
	{
		// ! ex architecturs = {3, 2, 2, 1}
		// layers_sizes[1] = 2
		// count first time = 2 * (1 + 3) = 2 * 4 = 8
		// count second time = 2 * (1 + 2) = 6
		// count second time = 1 * (1 + 2) = 3

		// accum count = 8 + 6 + 3 = 17 ?
		uint64_t count = 0;
		for (uint64_t i(1); i < layers_sizes.size(); ++i) {
			count += layers_sizes[i] * (1 + layers_sizes[i - 1]);
		}
		return count;
	}

	void print() const
	{
		printf("\n**********************************************************************************************\n");
		printf("PRINTING NN ALL LAYERS\n\n");
		for (uint64_t i(0); i < layers.size(); ++i) 
		{
			printf("Layer %llu\n", i);
			layers[i].print();
		}
		// printf("\n");
		printf("**********************************************************************************************\n");
	}

	uint64_t input_size;
	std::vector<Layer> layers;
	std::vector<float> last_input;
};
