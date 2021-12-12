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
    fstream fin;
    fin.open("data/Pokedex.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    while (fin >> temp && finished == false) {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word.substr(1));
        }
        int curr_pokemon = std::stoi(row[0]);
        if (dexID == curr_pokemon) {
            if (row[0] != ""){
                pokedexID_ = stod(row[0]);
            }
            //pokedexID_ = stod(row[0]);
            name_ = row[1];
            if (row[4] != ""){
                gen_ = stod(row[4]);
            }
            //gen_ = stod(row[4]);
            status_ = row[5];
            species_ = row[6];
            typeOne_ = row[8];
            typeTwo_ = row[9];
            if (row[10] != ""){
                height_ = stod(row[10]);
            }
            //height_ = stod(row[10]);
            if (row[11] != ""){
                weight_ = stod(row[11]);
            }
            //weight_ = stod(row[11]);
            if (row[23] != ""){
                catchRate_ = stod(row[23]);
            }
            //catchRate_ = stod(row[23]);
            finished = true;
        }
        row.clear();
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
