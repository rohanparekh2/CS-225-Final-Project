#pragma once
#include <vector>
#include "vertex.h"
#include "edge.h"
#include "pokemon.h"
#include "StickerSheet.h"
#include "Image.h"


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
        bool IDDFS(int startPokeID, string target, int maxRange);
        bool depthLimitedSearch(int startPokeID, string target, int maxRange);
        void createGraph();
        std::vector<Edge> getEdges();
        std::vector<Vertex> getVertices();
        void drawGraph();
        std::vector<std::pair<int,int>> CalculateLocations();
        
    private:
        std::vector<Vertex> vertices;
        std::vector<Edge> edges;
        std::vector<Pokemon> nodes;
        std::vector<std::pair<int, int>> locations;
        int width_;
        int height_;
        size_t typeToNum(string type);
        int statusToNum(string status);
        void checkOverLap(std::pair<int, int> newLocat);
        double typeToColor(string type);
        void createImages(Image& i, std::string type);
};