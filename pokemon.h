#pragma once


using namespace std;

class Pokemon {
  private:
    size_t pokedexID_;
    string name_;
    size_t gen_;
    string status_;
    string species_;
    string typeOne_;
    string typeTwo_;
    double height_;
    double weight_;
    double catchRate_;
    string test1;
    string test2;

  public:
    Pokemon();

    Pokemon(size_t dexID, string name, size_t gen, string status,
            string species, string type1, string type2, double height,
            double weight, double catchRate);
    
    Pokemon(size_t dexID);

    size_t getDexID();

    string getName();
    string getT1();
    string getT2();

    size_t getGen();
    
    string getStatus();

    string getType1();

    string getType2();

    double getHeight();

    double getWeight();

    double getCatchRate();
}