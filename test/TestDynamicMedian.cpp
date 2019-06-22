#include "catch.hpp"
#include "DoubleEquality.hpp"
#include "DynamicMedian.hpp"

TEST_CASE("DynamicMedian pushing even amount of numbers", "[DynamicMedian]")
{
	ds::DynamicMedian dm;
	REQUIRE(dm.GetSize() == 0);

	SECTION("Median from an empty data structure")
	{
		REQUIRE_THROWS(dm.GetMedian());
	}
	SECTION("Pushing equal numbers")
	{
		for (int i = 0; i < 100; ++i)
		{
			dm.Push(11);
		}
		REQUIRE(AreEqual(dm.GetMedian(), 11));
	}
	SECTION("Pushing wave numbers")
	{
		for (int i = 1; i <= 50; i++)
		{
			dm.Push(i);
			dm.Push(50 + i);
		}
		const double EXPECTED_RESULT = (1.0 * 50 + 51) / 2;
		REQUIRE(AreEqual(dm.GetMedian(), EXPECTED_RESULT));
	}
	SECTION("Pushing in ascending order")
	{
		for (int i = 0; i < 100; ++i)
		{
			dm.Push(i + 1);
		}
		const double EXPECTED_RESULT = (1.0 * 50 + 51) / 2;
		REQUIRE(AreEqual(dm.GetMedian(), EXPECTED_RESULT));
	}
	SECTION("Pushing in descending order")
	{
		for (int i = 100; i > 0; --i)
		{
			dm.Push(i);
		}
		const double EXPECTED_RESULT = (1.0 * 50 + 51) / 2;
		REQUIRE(AreEqual(dm.GetMedian(), EXPECTED_RESULT));
	}
}

TEST_CASE("DynamicMedian pushing odd amount of numbers", "[DynamicMedian]")
{
	ds::DynamicMedian dm;
	REQUIRE(dm.GetSize() == 0);

	SECTION("Pushing single number")
	{
		dm.Push(111);
		REQUIRE(AreEqual(dm.GetMedian(), 111));
		REQUIRE(dm.GetSize() == 1);
	}
	SECTION("Pushing equal numbers")
	{
		for (int i = 0; i < 99; ++i)
		{
			dm.Push(11);
		}
		REQUIRE(AreEqual(dm.GetMedian(), 11));
	}
	SECTION("Pushing wave numbers")
	{
		for (int i = 1; i <= 50; i++)
		{
			dm.Push(i);
			dm.Push(50 + i);
		}
		dm.Push(0);
		REQUIRE(AreEqual(dm.GetMedian(), 50));
	}
	SECTION("Pushing in ascending order")
	{
		for (int i = 0; i < 99; ++i)
		{
			dm.Push(i + 1);
		}
		REQUIRE(AreEqual(dm.GetMedian(), 50));
	}
	SECTION("Pushing in descending order")
	{
		for (int i = 99; i > 0; --i)
		{
			dm.Push(i);
		}
		REQUIRE(AreEqual(dm.GetMedian(), 50));
	}
}

TEST_CASE("DynamicMedian pushing a lot of numbers", "[DynamicMedian]")
{
	ds::DynamicMedian dm;
	REQUIRE(dm.GetSize() == 0);

	SECTION("Pushing even amount of numbers")
	{
		for (int i = 1; i <= 500000; i++)
		{
			dm.Push(i);
			dm.Push(500000 + i);
		}
		const double EXPECTED_RESULT = (1.0 * 500000 + 500001) / 2;
		REQUIRE(AreEqual(dm.GetMedian(), EXPECTED_RESULT));
	}
	SECTION("Pushing odd amount of numbers")
	{
		for (int i = 1; i <= 500000; i++)
		{
			dm.Push(i);
			dm.Push(500000 + i);
		}
		dm.Push(1000001);
		REQUIRE(AreEqual(dm.GetMedian(), 500001));
	}
}