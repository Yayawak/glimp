#pragma once
#include <cstdint>
#include <sys/types.h>
#include <vector>


template<typename T>
struct Objective
{
	uint target_id;
	float time_in;
	float time_out;
	float points;
	// std::vector<T>& targets;
	std::vector<T> targets;
	// std::vector<T>* targets;

	// Objective(const std::vector<T>& targets)
	// Objective(uint target_size)
	Objective()
		// : 
		// targets(target_size)
	{
		// targets = new std::vector<T>(target_size);
		// this->targets = targets;
	}

	// T& operator()(const uint i)
	// // T& operator{}(const uint i)
	// {
	// 	return targets[i];
	// }

	void reset()
	{
		target_id = 0;
		time_in = 0.0f;
		time_out = 0.0f;
		points = 0.0f;
	}

	// template<typename T>
	// const T& getTarget() const
	const T& getTarget()
	// const T* getTarget()
	// const T* getTarget()
	{
		// return this->targets[target_id];
		return this->targets[0];
		// return this->targets(target_id);
		// return &targets[target_id];
	}

	// template<typename T>
	// void nextTarget()
	void archiveCurrentTarget()
	{
		target_id = (target_id + 1) % targets.size();
		// target_id = (target_id + 1) % targets->size();
		time_in = 0.0f;
		time_out = 0.0f;
	}

	void addTimeIn(float dt)
	{
		time_in += dt;
	}

	void addTimeOut(float dt)
	{
		time_in = 0.0f;
		time_out += dt;
	}
};
