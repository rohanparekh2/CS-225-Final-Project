#include "catch2/catch.hpp"
#include <fstream>

TEST_CASE("test pokemon", "[weight=1]") {
	Pokemon p(52);
	REQUIRE(p.getName);
}