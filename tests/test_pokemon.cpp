#include "catch2/catch.hpp"
#include <fstream>
#include "../include/pokemon.h"


TEST_CASE("eec", "[weight=1]") {
	REQUIRE (1 == 1);
}

TEST_CASE("test pokemon", "[weight=5]") {
	Pokemon p(52);
	REQUIRE(p.getName() == "Meowth");
	REQUIRE(p.getDexID() == 52.0);
	REQUIRE(p.getGen() == 1);
	REQUIRE(p.getStatus() == "Normal");
	REQUIRE(p.getSpecies() == "Scratch Cat Pokémon");
}
