#pragma once
#include <vector>
#include <unordered_map>
#include "vertex.h"
#include "edge.h"
#include "../pokemon_testing/include/pokemon.h"


using namespace std;

class Graph {
    public:
        Graph();
        Graph(std::string file);
        Graph(size_t size);
        void insertVertex(double key);
        void insertEdge(double v1, double v2, size_t key);
        bool areAdjacent(Vertex v1, Vertex v2);
        std::vector<Edge> incidentEdges(Vertex v);
        vector<string> BFS(int pokeID);
    private:
        std::vector<Vertex> vertices;
        std::vector<Edge> edges;
        

};