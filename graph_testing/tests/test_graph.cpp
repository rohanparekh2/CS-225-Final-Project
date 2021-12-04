#include "catch2/catch.hpp"
#include <fstream>
#include <vector>
#include "../include/edge.h"
#include "../include/vertex.h"
#include "../include/graph.h"

TEST_CASE("test edge", "[weight=3]") {
	Edge::Edge e(1.0,2.0,1);
	REQUIRE(e.getVertexOne() == 1.0);
	REQUIRE(e.getVertexTwo() == 2.0);
	REQUIRE(e.getWeight() == 1);
}

TEST_CASE("test vertex", "[weight=1]") {
	Vertex::Vertex v(52.0);
	REQUIRE(v.getEdges == 0);
}

TEST_CASE("test BFS", "[weight=1]") {
	Graph::Graph g("../../data/Pokedex.csv");
	std::vector<std::string> r = {"Zacian", "Zamazenta", "Eternatus"};
	REQUIRE(g.BSF(888) == r);
}