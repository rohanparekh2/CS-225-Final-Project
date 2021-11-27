#include <iostream>

#include <vector>
#include "../pokemon_testing/include/pokemon.h"
#include <typeinfo>


int main() {
    Pokemon a;
    
    std::cout << typeid(a).name() << std::endl;
    
    /*
    cout << "pokemon1 name: " << pokeList[0]->getName() << endl;
    cout << "pokemon2 name: " << pokeList[1]->getName() << endl;
    cout << "pokemon3 name: " << pokeList[2]->getName() << endl;
    cout << "pokemon4 gen: " << pokeList[3]->getGen() << endl;
    cout << "pokemon5 gen: " << pokeList[4]->getGen() << endl;
    cout << "pokemon6 gen: " << pokeList[5]->getGen() << endl;
    cout << "pokemon7 height_: " << pokeList[6]->getHeight() << endl;
    cout << "pokemon8 height_: " << pokeList[7]->getHeight() << endl;
    */
    
    //cout << "pokemon10 height_: " << 69422 << endl;

    return 0;
}