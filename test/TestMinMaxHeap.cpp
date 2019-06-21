#include "catch.hpp"
#include "MinMaxHeap.hpp"

TEST_CASE("MinHeap push is correct", "[Heap]")
{
	ds::MinMaxHeap minHeap;
	REQUIRE(minHeap.GetSize() == 0);

	SECTION("Top from an empty heap")
	{
		REQUIRE_THROWS(minHeap.GetTop());
	}
	SECTION("Pushing different numbers")
	{
		minHeap.Push(10);
		REQUIRE(minHeap.GetSize() == 1);
		REQUIRE(minHeap.GetTop() == 10);

		minHeap.Push(-10);
		REQUIRE(minHeap.GetTop() == -10);

		minHeap.Push(-3);
		REQUIRE(minHeap.GetTop() == -10);

		minHeap.Push(-11);
		REQUIRE(minHeap.GetTop() == -11);
	}
	SECTION("Pushing equal numbers")
	{
		for (int i = 0; i < 100; i++)
		{
			minHeap.Push(10);
			REQUIRE(minHeap.GetTop() == 10);
		}
	}
	SECTION("Pushing in ascending order")
	{
		for (int i = 0; i < 100; ++i)
		{
			minHeap.Push(i + 1);
			REQUIRE(minHeap.GetTop() == 1);
		}
	}
	SECTION("Pushing in descending order")
	{
		for (int i = 99; i >= 0; --i)
		{
			minHeap.Push(i + 1);
			REQUIRE(minHeap.GetTop() == i + 1);
		}
	}
}

TEST_CASE("MaxHeap push is correct", "[Heap]")
{
	ds::MinMaxHeap maxHeap(false);
	REQUIRE(maxHeap.GetSize() == 0);

	SECTION("Top from an empty heap")
	{
		REQUIRE_THROWS(maxHeap.GetTop());
	}
	SECTION("Pushing different numbers")
	{
		maxHeap.Push(10);
		REQUIRE(maxHeap.GetSize() == 1);
		REQUIRE(maxHeap.GetTop() == 10);

		maxHeap.Push(-10);
		REQUIRE(maxHeap.GetTop() == 10);

		maxHeap.Push(-3);
		REQUIRE(maxHeap.GetTop() == 10);

		maxHeap.Push(11);
		REQUIRE(maxHeap.GetTop() == 11);
	}
	SECTION("Pushing equal numbers")
	{
		for (int i = 0; i < 100; i++)
		{
			maxHeap.Push(10);
			REQUIRE(maxHeap.GetTop() == 10);
		}
	}
	SECTION("Pushing in ascending order")
	{
		for (int i = 0; i < 100; ++i)
		{
			maxHeap.Push(i + 1);
			REQUIRE(maxHeap.GetTop() == i + 1);
		}
	}
	SECTION("Pushing in descending order")
	{
		for (int i = 99; i >= 0; --i)
		{
			maxHeap.Push(i + 1);
			REQUIRE(maxHeap.GetTop() == 100);
		}
	}
}

TEST_CASE("MinHeap push and pop are correct", "[Heap]")
{
	ds::MinMaxHeap minHeap;
	REQUIRE(minHeap.GetSize() == 0);

	SECTION("Push and pop different numbers")
	{
		minHeap.Push(10);
		REQUIRE(minHeap.GetTop() == 10);

		minHeap.Pop();
		REQUIRE(minHeap.GetSize() == 0);

		for (int i = 0; i < 10; ++i)
		{
			minHeap.Push(i + 1);
		}
		minHeap.Pop();
		REQUIRE(minHeap.GetTop() == 2);

		minHeap.Pop();
		minHeap.Push(-1);
		REQUIRE(minHeap.GetTop() == -1);
	}
	SECTION("Pushing equal numbers")
	{
		for (int i = 0; i < 100; i++)
		{
			minHeap.Push(10);
		}
		for (int i = 0; i < 99; i++)
		{
			minHeap.Pop();
			REQUIRE(minHeap.GetTop() == 10);
		}
	}
}

TEST_CASE("MaxHeap push and pop are correct", "[Heap]")
{
	ds::MinMaxHeap maxHeap(false);
	REQUIRE(maxHeap.GetSize() == 0);

	SECTION("Push and pop different numbers")
	{
		maxHeap.Push(10);
		REQUIRE(maxHeap.GetTop() == 10);

		maxHeap.Pop();
		REQUIRE(maxHeap.GetSize() == 0);

		for (int i = 0; i < 10; ++i)
		{
			maxHeap.Push(i + 1);
		}
		maxHeap.Pop();
		REQUIRE(maxHeap.GetTop() == 9);

		maxHeap.Pop();
		maxHeap.Push(-1);
		REQUIRE(maxHeap.GetTop() == 8);
	}
	SECTION("Pushing equal numbers")
	{
		for (int i = 0; i < 100; i++)
		{
			maxHeap.Push(10);
		}
		for (int i = 0; i < 99; i++)
		{
			maxHeap.Pop();
			REQUIRE(maxHeap.GetTop() == 10);
		}
	}
}