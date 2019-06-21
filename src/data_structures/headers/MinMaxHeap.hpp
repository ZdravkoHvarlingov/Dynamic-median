#ifndef MIN_MAX_HEAP_HPP
#define MIN_MAX_HEAP_HPP

#include <vector>

namespace ds
{
	class MinMaxHeap
	{
	public:
		MinMaxHeap(bool isMin = true);

		void Push(double number);
		void Pop();
		double GetTop() const;

		size_t GetSize() const;

	private:

		int GetLeftChild(int index) const;
		int GetRightChild(int index) const;
		int GetParent(int index) const;

		void SiftUp(int index);
		void SiftDown(int index);

		bool isMin;
		std::vector<double> elements;
	};
}

#endif