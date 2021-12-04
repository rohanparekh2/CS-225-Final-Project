#pragma once
#include "../include/edge.h"
#include "../pokemon_testing/include/pokemon.h"
#include <vector>

class Vertex {
    public:
        Vertex();
        Vertex(double dexID);
        bool operator ==(const Vertex& v);
        bool operator <(const Vertex& v);

        Pokemon getInfo();
        vector<Edge> getEdges();
        double getVertexOne();
    private:
        double ID;
        vector<Edge> edges_;
        Pokemon pokemon_;
};




