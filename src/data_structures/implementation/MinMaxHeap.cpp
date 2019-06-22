#include "MinMaxHeap.hpp"
#include <algorithm>

ds::MinMaxHeap::MinMaxHeap(bool isMin)
	: isMin(isMin)
{
	//Starting from index 1 for an easier index management
	elements.push_back(0);
}

void ds::MinMaxHeap::Push(double number)
{
	//We are managing min heap as default
	number = isMin == false ? -number : number;

	elements.push_back(number);
	SiftUp(elements.size() - 1);
}

void ds::MinMaxHeap::Pop()
{
	if (elements.size() == 1)
	{
		return;
	}

	std::swap(elements[1], elements[elements.size() - 1]);
	elements.pop_back();

	SiftDown(1);
}

double ds::MinMaxHeap::GetTop() const
{
	if (elements.size() == 1)
	{
		throw "No elements inside the heap!";
	}

	return isMin == false ? -elements[1] : elements[1];
}

int ds::MinMaxHeap::GetSize() const
{
	return elements.size() - 1;
}

inline int ds::MinMaxHeap::GetLeftChild(int index) const
{
	return index * 2;
}

inline int ds::MinMaxHeap::GetRightChild(int index) const
{
	return index * 2 + 1;
}

int ds::MinMaxHeap::GetParent(int index) const
{
	return index / 2;
}

void ds::MinMaxHeap::SiftUp(int index)
{
	if (index == 1)
	{
		return;
	}

	int parent = GetParent(index);
	if (elements[parent] > elements[index])
	{
		std::swap(elements[parent], elements[index]);
		SiftUp(parent);
	}
}

void ds::MinMaxHeap::SiftDown(int index)
{
	if (index >= elements.size())
	{
		return;
	}

	int left = GetLeftChild(index);
	int right = GetRightChild(index);

	//We are the the bottom already
	if (left >= elements.size()  && right >= elements.size())
	{
		return;
	}

	int min = -1;
	if (left < elements.size())
	{
		min = left;
	}
	if (right < elements.size() && (min == -1 || elements[left] > elements[right]))
	{
		min = right;
	}

	if (elements[min] < elements[index])
	{
		std::swap(elements[min], elements[index]);
		SiftDown(min);
	}
}
