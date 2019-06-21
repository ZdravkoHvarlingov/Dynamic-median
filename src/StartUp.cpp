#include <iostream>
#include "DynamicMedian.hpp"

int main()
{
    std::cout << "StartUp file compiled!" << std::endl;
	ds::DynamicMedian dm;
	dm.Push(10);
	dm.Push(11);

	std::cout << dm.GetMedian() << std::endl;
}