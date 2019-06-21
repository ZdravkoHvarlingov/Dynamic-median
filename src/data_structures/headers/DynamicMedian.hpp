#ifndef DYNAMIC_MEDIAN_HPP
#define DYNAMIC_MEDIAN_HPP

#include "MinMaxHeap.hpp"

namespace ds
{
	class DynamicMedian
	{
	public:
		
		DynamicMedian();

		double GetMedian() const;
		void Push(double number);
		size_t GetSize() const;

	private:
		void Balance();

		MinMaxHeap maxHeap;
		MinMaxHeap minHeap;
	};
}

#endif