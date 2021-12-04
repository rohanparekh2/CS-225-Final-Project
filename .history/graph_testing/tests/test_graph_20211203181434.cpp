#include "catch2/catch.hpp"
#include <fstream>

TEST_CASE("test edge", "[weight=3]") {
	Edge e(1.0,2.0,1);
	REQUIRE(e.getVertexOne() == 1.0);
	REQUIRE(e.getVertexTwo() == 2.0);
	REQUIRE(e.getWeight() == 1);
}

TEST_CASE("test vertex", "[weight=1]") {
	Vertex v(52.0);
	REQUIRE(v.getEdges == 0);
}