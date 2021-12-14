#include "../include/pokemon.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Pokemon::Pokemon() {
    pokedexID_= -1;
    name_ = "null";
    gen_ = -1;
    status_ = "null";
    species_ = "null";
    typeOne_ = "null";
    typeTwo_ = "null";
    height_ = -1;
    weight_ = -1;
    catchRate_ = -1;
}

Pokemon::Pokemon(double dexID, string name, double gen, string status,
            string species, string type1, string type2, double height,
            double weight, double catchRate) {
    pokedexID_ = dexID;
    name_ = name;
    gen_ = gen;
    status_ = status;
    species_ = species;
    typeOne_ = type1;
    typeTwo_ = type2;
    height_ = height;
    weight_ = weight;
    catchRate_ = catchRate;
}

Pokemon::Pokemon(double dexID) {
    bool finished = false;
    fstream read;
    read.open("data/Pokedex.csv", ios::in);
    vector<string> pokemon;
    string line;
    string curr;
    string val;
    while (read >> curr && finished == false) {
        pokemon.clear();
        getline(read, line);
        stringstream p(line);
        while (getline(p, val, ',')) {
            pokemon.push_back(val.substr(1));
        }

        int curr_pokemon = std::stoi(pokemon[0]);
        if (dexID == curr_pokemon) {
            if (pokemon[0] != ""){
                pokedexID_ = stod(pokemon[0]);
            }
            
            name_ = pokemon[1];
            if (pokemon[4] != ""){
                gen_ = stod(pokemon[4]);
            }
            
            status_ = pokemon[5];
            species_ = pokemon[6];
            typeOne_ = pokemon[8];
            typeTwo_ = pokemon[9];
            if (pokemon[10] != ""){
                height_ = stod(pokemon[10]);
            }
            
            if (pokemon[11] != ""){
                weight_ = stod(pokemon[11]);
            }
            
            if (pokemon[23] != ""){
                catchRate_ = stod(pokemon[23]);
            }
            
            finished = true;
        }
        pokemon.clear();
    }
}

double Pokemon::getDexID() {
    return pokedexID_;
}

string Pokemon::getName() {
    return name_;
}

double Pokemon::getGen() {
    return gen_;
}

string Pokemon::getStatus() {
    return status_;
}

string Pokemon::getSpecies() {
    return species_;
}

string Pokemon::getType1() {
    return typeOne_;
}

string Pokemon::getType2() {
    return typeTwo_;
}

double Pokemon::getHeight() {
    return height_;
}

double Pokemon::getWeight() {
    return weight_;
}

double Pokemon::getCatchRate() {
    return catchRate_;
}
