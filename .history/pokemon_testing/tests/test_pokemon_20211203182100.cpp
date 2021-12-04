#include "catch2/catch.hpp"
#include <fstream>
#include "../include/pokemon.h"

TEST_CASE("test pokemon", "[weight=1]") {
	Pokemon::Pokemon p(52);
	REQUIRE(p.getName() == "Meowth");
	REQUIRE(p.getID() == 52.0);
	REQUIRE(p.getGen() == 1);
}