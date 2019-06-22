#include "DoubleEquality.hpp"
#include <cmath>
#include <limits>

bool AreEqual(double first, double second)
{
	return std::fabs(first - second) < std::numeric_limits<double>::epsilon();
}