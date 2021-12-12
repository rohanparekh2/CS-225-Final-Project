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
	Graph g1(10);
	std::vector<std::string> r = {"Zacian", "Zamazenta", "Eternatus"};
	for (int i = 0; i < g1.getEdges().size(); i++) {
		std::cout << "edgePair: " << g1.getEdges()[i].getVertexOne() <<
                    ", " << g1.getEdges()[i].getVertexTwo() << std::endl;

	}
}*/


TEST_CASE("Test BFS", "[weight=1]") {
	Graph g(10);
	std::vector<std::string> r = { "Charmeleon", "Bulbasaur", "Ivysaur", "Venusaur", "Charmander",
  "Charizard", "Squirtle", "Wartortle", "Blastoise", "Caterpie" };
	std::vector<std::string> test;
	test = g.BFS(5);
	REQUIRE(g.BFS(5) == r);
}


TEST_CASE("Test Big BFS", "[weight=1]") {
	Graph g(420);
	std::vector<std::string> r = { "Bellsprout", "Bulbasaur", "Ivysaur", "Venusaur", "Charmander",
  "Charmeleon", "Charizard", "Squirtle", "Wartortle", "Blastoise", "Caterpie",
  "Metapod", "Butterfree", "Weedle", "Kakuna", "Beedrill", "Pidgey",
  "Pidgeotto", "Pidgeot", "Rattata", "Raticate", "Spearow", "Fearow", "Ekans",
  "Arbok", "Pikachu", "Raichu", "Sandshrew", "Sandslash", "Nidoran♀",
  "Nidorina", "Nidoqueen", "Nidoran♂", "Nidorino", "Nidoking", "Clefairy",
  "Clefable", "Vulpix", "Ninetales", "Jigglypuff", "Wigglytuff", "Zubat",
  "Golbat", "Oddish", "Gloom", "Vileplume", "Paras", "Parasect", "Venonat",
  "Venomoth", "Diglett", "Dugtrio", "Meowth", "Persian", "Psyduck", "Golduck",
  "Mankey", "Primeape", "Growlithe", "Arcanine", "Poliwag", "Poliwhirl",
  "Poliwrath", "Abra", "Kadabra", "Alakazam", "Machop", "Machoke", "Machamp",
  "Weepinbell", "Victreebel", "Tentacool", "Tentacruel", "Geodude", "Graveler",
  "Golem", "Ponyta", "Rapidash", "Slowpoke", "Slowbro", "Magnemite",
  "Magneton", "Farfetch'd", "Doduo", "Dodrio", "Seel", "Dewgong", "Grimer",
  "Muk", "Shellder", "Cloyster", "Gastly", "Haunter", "Gengar", "Onix",
  "Drowzee", "Hypno", "Krabby", "Kingler", "Voltorb", "Electrode", "Exeggcute",
  "Exeggutor", "Cubone", "Marowak", "Hitmonlee", "Hitmonchan", "Lickitung",
  "Koffing", "Weezing", "Rhyhorn", "Rhydon", "Chansey", "Tangela",
  "Kangaskhan", "Horsea", "Seadra", "Goldeen", "Seaking", "Staryu", "Starmie",
  "Mr. Mime", "Scyther", "Jynx", "Electabuzz", "Magmar", "Pinsir", "Tauros",
  "Magikarp", "Gyarados", "Lapras", "Ditto", "Eevee", "Vaporeon", "Jolteon",
  "Flareon", "Porygon", "Omanyte", "Omastar", "Kabuto", "Kabutops",
  "Aerodactyl", "Snorlax", "Articuno", "Zapdos", "Moltres", "Dratini",
  "Dragonair", "Dragonite", "Mewtwo", "Mew", "Chikorita", "Bayleef",
  "Meganium", "Bellossom", "Hoppip", "Skiploom", "Jumpluff", "Sunkern",
  "Sunflora", "Treecko", "Grovyle", "Sceptile", "Seedot", "Nuzleaf", "Shiftry",
  "Shroomish", "Breloom", "Roselia", "Cacnea", "Cacturne", "Tropius",
  "Turtwig", "Grotle", "Torterra", "Budew", "Roserade", "Cherubi", "Cyndaquil",
  "Quilava", "Typhlosion", "Slugma", "Magcargo", "Magby", "Entei", "Ho-oh",
  "Torchic", "Combusken", "Blaziken", "Numel", "Camerupt", "Torkoal",
  "Chimchar", "Monferno", "Infernape", "Totodile", "Croconaw", "Feraligatr",
  "Chinchou", "Lanturn", "Marill", "Azumarill", "Politoed", "Wooper",
  "Quagsire", "Slowking", "Qwilfish", "Corsola", "Remoraid", "Octillery",
  "Mantine", "Kingdra", "Suicune", "Mudkip", "Marshtomp", "Swampert", "Lotad",
  "Lombre", "Ludicolo", "Wingull", "Pelipper", "Carvanha", "Sharpedo",
  "Wailmer", "Wailord", "Barboach", "Whiscash", "Corphish", "Crawdaunt",
  "Feebas", "Milotic", "Clamperl", "Huntail", "Gorebyss", "Relicanth",
  "Luvdisc", "Kyogre", "Piplup", "Prinplup", "Empoleon", "Buizel", "Floatzel",
  "Ledyba", "Ledian", "Spinarak", "Ariados", "Yanma", "Pineco", "Forretress",
  "Scizor", "Shuckle", "Heracross", "Wurmple", "Silcoon", "Beautifly",
  "Cascoon", "Dustox", "Surskit", "Masquerain", "Nincada", "Ninjask",
  "Shedinja", "Volbeat", "Illumise", "Kricketot", "Kricketune", "Burmy",
  "Wormadam Plant Cloak", "Mothim", "Combee", "Vespiquen", "Sentret", "Furret",
  "Hoothoot", "Noctowl", "Igglybuff", "Aipom", "Girafarig", "Dunsparce",
  "Teddiursa", "Ursaring", "Porygon2", "Stantler", "Smeargle", "Miltank",
  "Blissey", "Zigzagoon", "Linoone", "Taillow", "Swellow", "Slakoth",
  "Vigoroth", "Slaking", "Whismur", "Loudred", "Exploud", "Azurill", "Skitty",
  "Delcatty", "Spinda", "Swablu", "Zangoose", "Castform", "Kecleon", "Starly",
  "Staravia", "Staraptor", "Bidoof", "Bibarel", "Crobat", "Gulpin", "Swalot",
  "Seviper", "Pichu", "Mareep", "Flaaffy", "Ampharos", "Elekid", "Raikou",
  "Electrike", "Manectric", "Plusle", "Minun", "Shinx", "Luxio", "Luxray",
  "Pachirisu", "Gligar", "Phanpy", "Donphan", "Trapinch", "Vibrava", "Flygon",
  "Baltoy", "Claydol", "Groudon", "Cleffa", "Togepi", "Togetic", "Snubbull",
  "Granbull", "Tyrogue", "Hitmontop", "Makuhita", "Hariyama", "Meditite",
  "Medicham", "Natu", "Xatu", "Espeon", "Unown", "Wobbuffet", "Lugia",
  "Celebi", "Ralts", "Kirlia", "Gardevoir", "Spoink", "Grumpig", "Chimecho",
  "Wynaut", "Deoxys Normal Forme", "Sudowoodo", "Larvitar", "Pupitar",
  "Tyranitar", "Nosepass", "Lunatone", "Solrock", "Lileep", "Cradily",
  "Anorith", "Armaldo", "Regirock", "Cranidos", "Rampardos", "Shieldon",
  "Bastiodon", "Misdreavus", "Shuppet", "Banette", "Duskull", "Dusclops",
  "Swinub", "Piloswine", "Delibird", "Smoochum", "Snorunt", "Glalie", "Spheal",
  "Sealeo", "Walrein", "Regice", "Altaria", "Bagon", "Shelgon", "Salamence",
  "Latias", "Latios", "Rayquaza", "Umbreon", "Murkrow", "Steelix", "Sneasel",
  "Skarmory", "Houndour", "Houndoom", "Poochyena", "Mightyena", "Sableye",
  "Mawile", "Aron", "Lairon", "Aggron", "Absol", "Beldum", "Metang",
  "Metagross", "Registeel", "Jirachi" };
	std::vector<std::string> test;

	REQUIRE(g.BFS(69) == r);
}

TEST_CASE("Empty BFS", "[weight=1]") {
	Graph g(0);
	std::vector<std::string> r = {"GRAPH_IS_EMPTY"};
	std::vector<std::string> test;

	REQUIRE(g.BFS(0) == r);
}

TEST_CASE("BFS Too Big ID", "[weight=1]") {
	Graph g(30);
	std::vector<std::string> r = {"POKEMON_ID_NOT_FOUND_IN_GRAPH"};
	std::vector<std::string> test;

	REQUIRE(g.BFS(31) == r);
}

TEST_CASE("BFS Negative ID", "[weight=1]") {
	Graph g(46);
	std::vector<std::string> r = {"POKEMON_ID_NOT_FOUND_IN_GRAPH"};
	std::vector<std::string> test;

	REQUIRE(g.BFS(-1) == r);
}

TEST_CASE("Test Found IDDFS", "[weight=1]") {
	Graph g(10);
	bool b = true;

	REQUIRE(g.IDDFS(1, "Charmander", 8) == b);
}

TEST_CASE("Test Not Found IDDFS", "[weight=1]") {
	Graph g(10);
	bool b = false;

	REQUIRE(g.IDDFS(1, "Charizard", 2) == b);
}