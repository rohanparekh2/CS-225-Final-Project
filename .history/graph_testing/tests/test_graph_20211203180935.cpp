#include "catch2/catch.hpp"
#include <fstream>

TEST_CASE("test edge", "[weight=1]") {
	Edge e()
	REQUIRE(1 == 1);
}

TEST_CASE("test vertex", "[weight=1]") {
	REQUIRE(1 == 1);
}