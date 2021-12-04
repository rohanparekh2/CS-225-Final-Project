#include "../include/graph.h"
#include "../include/vertex.h"
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace std;

vector<string> Graph::BFS(int pokeID, string trait) {
    vector<string> list;
    list.push_bCK
}

void Graph::insertVertex(double key) {
    Vertex v(key);
    vertices.push_back(v);
}

void Graph::insertEdge(double v1, double v2, size_t key) {
    Edge e(v1, v2, key);
    edges.push_back(e);
}