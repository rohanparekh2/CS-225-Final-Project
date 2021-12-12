#include "catch2/catch.hpp"
#include <fstream>
#include "../include/edge.h"
#include "../include/vertex.h"
#include "../include/graph.h"


TEST_CASE("etc", "[weight=1]") {
	REQUIRE (1 == 1);
}


TEST_CASE("test edge", "[weight=3]") {
	Edge e(1.0,2.0,1);
	REQUIRE(e.getVertexOne() == 1.0);
	REQUIRE(e.getVertexTwo() == 2.0);
	REQUIRE(e.getWeight() == 1);
}


TEST_CASE("test vertex", "[weight=1]") {
	Vertex v(52.0);
	std::vector<Edge> x;
	REQUIRE(v.getEdges() == x);
	REQUIRE(v.getID() == 52.0);
}

/*TEST_CASE("test vertices", "[weight=1]") {
	Graph g(10);
	REQUIRE(g.vertices[0].getID() == 1);
	REQUIRE(g.vertices[1].getID() == 2);
	REQUIRE(g.vertices[2].getID() == 3);
}*/


TEST_CASE("test BFS", "[weight=1]") {
	//Graph g("../data/Pokedex.csv");
	Graph g(10);
	std::vector<std::string> r = {"Zacian", "Zamazenta", "Eternatus"};
	std::vector<std::string> test;
	test = g.BFS(1);

	for (int i = 0; i < test.size(); i++) {
		std::cout << test[i] << std::endl;
	}
	REQUIRE(g.BFS(1) == r);
}




