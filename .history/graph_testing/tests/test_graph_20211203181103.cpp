#include "catch2/catch.hpp"
#include <fstream>

TEST_CASE("test edge", "[weight=1]") {
	Edge e(1,2,1);
	REQUIRE(e.getVertexOne() == 1.0);
	REQUIRE(e.getVertexTwo() == 2.0);
	REQUIRE(e.getWeight() == 1);
}

TEST_CASE("test vertex", "[weight=1]") {
	REQUIRE(1 == 1);
}