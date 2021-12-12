#pragma once
#include <vector>
#include "vertex.h"
#include "edge.h"
#include "pokemon.h"


using namespace std;

class Graph {
    public:
        Graph();
        Graph(size_t size);
        void insertVertex(double key);
        void insertEdge(Vertex v1, Vertex v2, size_t key);
        bool areAdjacent(Vertex v1, Vertex v2);
        std::vector<Edge> incidentEdges(Vertex v);
        vector<string> BFS(int pokeID);
        void createGraph();
        std::vector<Edge> getEdges();
        std::vector<Vertex> getVertices();
    private:
        std::vector<Vertex> vertices;
        std::vector<Edge> edges;
        std::vector<Pokemon> nodes;
        

};