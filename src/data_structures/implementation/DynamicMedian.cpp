#include "DynamicMedian.hpp"

#define MAX_DIFF 2

ds::DynamicMedian::DynamicMedian()
	: minHeap(true), maxHeap(false)
{
}

double ds::DynamicMedian::GetMedian() const
{
	if (maxHeap.GetSize() == 0 && minHeap.GetSize() == 0)
	{
		throw "The data structure is empty!";
	}

	if (maxHeap.GetSize() > minHeap.GetSize())
	{
		return maxHeap.GetTop();
	}
	else if (minHeap.GetSize() > maxHeap.GetSize())
	{
		return minHeap.GetTop();
	}

	return (maxHeap.GetTop() + minHeap.GetTop()) / 2;
}

void ds::DynamicMedian::Push(double number)
{
	if (maxHeap.GetSize() == 0)
	{
		maxHeap.Push(number);

		return;
	}

	if (number < maxHeap.GetTop())
	{
		maxHeap.Push(number);
	}
	else
	{
		minHeap.Push(number);
	}

	Balance();
}

int ds::DynamicMedian::GetSize() const
{
	return maxHeap.GetSize() + minHeap.GetSize();
}

void ds::DynamicMedian::Balance()
{
	//The difference in the sizes is going to be at most 2!

	if (maxHeap.GetSize() == minHeap.GetSize() + MAX_DIFF)
	{
		minHeap.Push(maxHeap.GetTop());
		maxHeap.Pop();
	}
	else if (minHeap.GetSize() == maxHeap.GetSize() + MAX_DIFF)
	{
		maxHeap.Push(minHeap.GetTop());
		minHeap.Pop();
	}
}
