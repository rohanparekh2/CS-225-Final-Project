#pragma once
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

#include <iostream>

using namespace std;

class Pokemon {
  private:
    double pokedexID_;
    string name_;
    double gen_;
    string status_;
    string species_;
    string typeOne_;
    string typeTwo_;
    double height_;
    double weight_;
    double catchRate_;

  public:
    Pokemon();

    Pokemon(double dexID, string name, double gen, string status,
            string species, string type1, string type2, double height,
            double weight, double catchRate);
    
    Pokemon(double dexID);

    double getDexID();

    string getName();

    double getGen();
    
    string getStatus();

    string getType1();

    string getType2();

    double getHeight();

    double getWeight();

    double getCatchRate();

    string getSpecies();
};
