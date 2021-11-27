#include <iostream>
#include <vector>
#include "pokemon.h"

using namespace std;

int main() {
    vector<Pokemon> pokeList;

    size_t i = 0;
    while (pokeList.size() < 11) {
        Pokemon mon = Pokemon(i);
        pokeList.push_back(mon);
        i++;
    }
    
    cout << "pokemon1 name: " << pokemon[0].getName() << endl;
    cout << "pokemon2 name: " << pokemon[1].getName() << endl;
    cout << "pokemon3 name: " << pokemon[2].getName() << endl;
    cout << "pokemon4 gen: " << pokemon[3].getGen() << endl;
    cout << "pokemon5 gen: " << pokemon[4].getGen() << endl;
    cout << "pokemon6 gen: " << pokemon[5].getGen() << endl;
    cout << "pokemon7 height_: " << pokemon[6].getHeight() << endl;
    cout << "pokemon8 height_: " << pokemon[7].getHeight() << endl;
    cout << "pokemon10 height_: " << pokemon[9].getHeight() << endl;

}