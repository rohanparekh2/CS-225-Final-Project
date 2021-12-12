#include "catch2/catch.hpp"
#include <fstream>
#include "../include/pokemon.h"


TEST_CASE("Pokemon 52: Meowth", "[weight=5]") {
	Pokemon p(52);
	REQUIRE(p.getName() == "Meowth");
	REQUIRE(p.getDexID() == 52.0);
	REQUIRE(p.getGen() == 1);
	REQUIRE(p.getStatus() == "Normal");
	REQUIRE(p.getSpecies() == "Scratch Cat Pokémon");
}

TEST_CASE("Pokemon 571: Zoroark", "[weight=5]") {
	Pokemon p(571);
	REQUIRE(p.getName() == "Zoroark");
	REQUIRE(p.getDexID() == 571.0);
	REQUIRE(p.getGen() == 5);
	REQUIRE(p.getType1() == "Dark");
	REQUIRE(p.getType2() == "");
	REQUIRE(p.getCatchRate() == 45);

}

TEST_CASE("Pokemon 423: Gastrodon", "[weight=5]") {
	Pokemon p(423);
	REQUIRE(p.getName() == "Gastrodon");
	REQUIRE(p.getGen() == 4);
	REQUIRE(p.getType1() == "Water");
	REQUIRE(p.getType2() == "Ground");
	REQUIRE(p.getHeight() == 0.9);
	REQUIRE(p.getWeight() == 29.9);
	REQUIRE(p.getSpecies() == "Sea Slug Pokémon");
}
