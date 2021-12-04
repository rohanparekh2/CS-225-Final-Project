#include "catch2/catch.hpp"
#include <fstream>
#include "../include/pokemon.h"

TEST_CASE("test pokemon", "[weight=1]") {
	Pokemon::Pokemon p ;
	REQUIRE(p.getName() == "Meowth");
}