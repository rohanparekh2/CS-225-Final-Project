#include <iostream>
#include "include/pokemon.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>


int main() {
    std::cout << "a" << std::endl;
    fstream fin;
  
    // Open an existing file
    fin.open("data/Pokedex.csv", ios::in);
    std::cout << "b" << std::endl;
  
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    std::cout << "c" << std::endl;
    string line, word, temp;
    std::cout << "d" << std::endl;
  
    while (fin >> temp) {
        std::cout << "e" << std::endl;
  
        row.clear();
  
        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
        std::cout << line << std::endl;
        //std::cout << fin << std::endl;
  
        // used for breaking words
        stringstream s(line);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, '\n')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);
            std::cout << word << std::endl;
        }

        getline(fin, line);
        //std::cout << fin << std::endl;
  
        // used for breaking words
        //stringstream s(line);
        while (getline(s, word, '\n')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);
            std::cout << word << std::endl;
        }

    }
    return 0;
}
