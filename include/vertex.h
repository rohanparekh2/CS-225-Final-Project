#pragma once
#include "edge.h"
#include "pokemon.h"
#include <vector>

class Vertex {
    public:
        Vertex();
        Vertex(double dexID);

        Pokemon getInfo();
        vector<Edge> getEdges();
        double getID();
    private:
        double ID;
        vector<Edge> edges_;
        Pokemon pokemon_;
};




