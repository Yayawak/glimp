#pragma once

#include <thread>
#include <vector>
#include <iostream>
#include "number_generator.hpp"
#include <cstring>
#include "utils.hpp"

// constexpr float MAX_RANGE = 10.0f;
const float MAX_RANGE = 10.0f;


struct DNA
{
	using byte = uint8_t;

	DNA(const uint64_t bits_count)
		: code(bits_count / 8u + bool(bits_count % 8 && bits_count > 8))
	{}

	template<typename T>
	void initialize(const float range)
	{
		const uint64_t element_count = getElementsCount<T>();
		for (uint64_t i(element_count); i--;) {
			const T value = NumberGenerator<>::getInstance().get(range);
			// printf("value from randommed distribtion = %f", value);
			// const T value = 5;
			set(i, value);
			// std::cout << "dna code " << i << " = " << code[i] << std::endl;
			// std::cout << "dna code " << i << " = " << get<float>(i) << std::endl; // ! this is worked
		}
	}

	template<typename T>
	T get(const uint64_t offset) const
	{
		T result;
		const uint64_t dna_offset = offset * sizeof(T);
		memcpy(&result, &code[dna_offset], sizeof(T));
		return result;
	}

	template<typename T>
	void set(const uint64_t offset, const T& value)
	{
		const float checked_value = clamp(-MAX_RANGE, MAX_RANGE, value);
		const uint64_t dna_offset = offset * sizeof(T);
		memcpy(&code[dna_offset], &value, sizeof(T));
	}

	uint64_t getBytesCount() const
	{
		return code.size();
	}

	template<typename T>
	uint64_t getElementsCount() const
	{
		return code.size() / sizeof(T);
	}

	void mutateBits(const float probability)
	{
		for (byte& b : code) {
			for (uint64_t i(0); i < 8; ++i) {
				if (NumberGenerator<>::getInstance().getUnder(1.0f) < probability) {
					const uint8_t mask = 256 >> i;
					b ^= mask;
				}
			}
		}
	}

	template<typename T>
	void mutate(const float probability)
	{
		// constexpr uint32_t type_size = sizeof(T);
		const uint32_t type_size = sizeof(T);
		const uint64_t element_count = code.size() / type_size;
		for (uint64_t i(0); i < element_count; ++i) {
			if (NumberGenerator<>::getInstance().getUnder(1.0f) < probability) {
				const T value = NumberGenerator<>::getInstance().get(MAX_RANGE);
				set(i, value);
			}
		}
	}

	bool operator==(const DNA& other) const
	{
		const uint64_t code_length = getBytesCount();
		if (other.getBytesCount() != code_length) {
			return false;
		}

		for (uint64_t i(0); i < code_length; ++i) {
			if (code[i] != other.code[i]) {
				return false;
			}
		}

		return true;
	}

	template<typename T>
	void dnalist()
	{
		// printf("LIST OF DNA CODE : \t");
		// for (uint64_t i(getElementsCount<float>()); i--;) {
		for (uint64_t i(getElementsCount<T>()); i--;) {
			// std::cout << "dna code " << i << " = " << dna.get<float>(i) << std::endl; 
			float f = get<float>(i);
			// std::cout <<  << ", ";
			printf("%.2f, ", f);
		}
		// std::this_thread::sleep_for(std::chrono::milliseconds(10));
		// std::this_thread::sleep_for(std::chrono::milliseconds(1));
		printf("\n");
	}

	std::vector<byte> code;
};
