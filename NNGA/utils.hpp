#pragma once
// #ifndef NNUtil_H
// #define NNUtil_H

#include <iostream>
#include <sstream>
#include <random>
#include <iomanip>
#include <glm/glm.hpp>

const float PI = 3.14159265f;
const float HalfPI = PI * 0.5f;
const float RAD_TO_DEG = 57.2958f;


// static std::random_device rd;
// static std::mt19937 gen(0);
// static std::mt19937 gen_no_reset(rd());

// template<typename T>
// void showsvec(std::vector<T>& vct)
// void showsvec(std::vector<float>& vct, std::string& desc)

// void showsvec(std::vector<float>& vct, char *desc=0)
// {
// 	// printf(desc.c_str());
// 	std::cout << desc << "\n";
// 	// printf("\n");
// 	for (uint i = 0; i < vct.size(); i++)
// 	{
// 		// char *format;
// 		// if (sizeof(T) == sizeof())
// 		printf("%.3f, ", vct.at(i));
// 	}
// 	printf("\n");
// }

// void resetRand()
// {
// 	gen = std::mt19937(0);
// }

// float getRandRange(float width)
// {
// 	std::uniform_real_distribution<float> distr(-width, width);
// 	return distr(gen);
// }

// float getRandUnder(float width)
// {
// 	std::uniform_real_distribution<float> distr(0.0f, width);
// 	return distr(gen);
// }

// uint32_t getIntUnder(const uint32_t max)
// {
// 	std::uniform_int_distribution<std::mt19937::result_type> distr(0, max);
// 	return  distr(gen);
// }

// float getRandRange(float width, std::mt19937& generator)
// {
// 	std::uniform_real_distribution<float> distr(-width, width);
// 	return distr(generator);
// }

// float getRandUnder(float width, std::mt19937& generator)
// {
// 	std::uniform_real_distribution<float> distr(0.0f, width);
// 	return distr(generator);
// }

// uint32_t getIntUnder(const uint32_t max, std::mt19937& generator)
// {
// 	std::uniform_int_distribution<std::mt19937::result_type> distr(0, max);
// 	return  distr(generator);
// }

// float getRandRangeNonReset(float width)
// {
// 	std::uniform_real_distribution<float> distr(-width, width);
// 	return distr(gen_no_reset);
// }

// float getRandUnderNonReset(float width)
// {
// 	std::uniform_real_distribution<float> distr(0.0f, width);
// 	return distr(gen_no_reset);
// }

// uint32_t getIntUnderNonReset(const uint32_t max)
// {
// 	std::uniform_int_distribution<std::mt19937::result_type> distr(0, max);
// 	return  distr(gen_no_reset);
// }

// float normalize(float value, float range)
// {
// 	return value / range;
// }

// float getFastRandUnder(float max)
// {
// 	const int32_t m = 10000;
// 	const float im = 1.0f / float(m);
// 	return max * (rand()%m * im);
// }

// template<typename T>
// float getLength(const sf::Vector2<T>& v)
// float getLength(const glm::vec2<float>& v)

// float getLength(const glm::vec2& v)
// {
// 	return sqrt(v.x * v.x + v.y * v.y);
// }

// void showvec(const glm::vec2 &v, const char *des)
// { 
// 	printf("%s\t", des);
// 	printf("vec[%f, %f]\n", v.x, v.y);
// }

// float getAngle(const glm::vec2 v)
// {
// 	const float a = acos(v.x / getLength(v));
// 	return v.y > 0.0f ? a : -a;
// }

// float normalize(float value, float range);




template<typename T, typename U>
T as(const U& u)
{
	return static_cast<T>(u);
}

template<typename T>
std::string toString(const T& v, const uint8_t decimals = 2)
{
	std::stringstream sx;
	sx << std::setprecision(decimals) << std::fixed;
	sx << v;

	return sx.str();
}

template<typename T>
T clamp(const T& min_val, const T& max_val, const T& value)
{
	return std::min(max_val, std::max(min_val, value));
}

// #endif