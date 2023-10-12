#pragma once

template<typename T>
// * used by Selector to make population
struct DoubleObject
{
	template<typename... Args>
	DoubleObject(Args&&... args)
		: current_buffer(0u)
	{
		buffers[0] = T(args...);
		buffers[1] = T(args...);
	}

	void swap()
	{
		current_buffer = !current_buffer; // 0 <-> 1
	}

	T& getCurrent()
	{
		return buffers[current_buffer];
	}

	T& getLast()
	{
		return buffers[!current_buffer];
	}

	const T& getCurrent() const
	{
		return buffers[current_buffer];
	}

	const T& getLast() const
	{
		return buffers[!current_buffer];
	}

	uint8_t current_buffer; // 0
	T buffers[2];
};


