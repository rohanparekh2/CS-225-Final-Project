#include "../include/graph.h"
#include "../include/vertex.h"
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace

vector<string> Graph::BFS(int pokeID, string trait) {
    int i = 0;
    char str[] = trait;
    char curr;
    vector<string> List;
    queue<Pokemon> discover;
    vector<bool> visited;
    visited.assign(vertices.size(), false);

    string traitL = "";  
    while (str[i]) {
        curr = str[i];
        curr = (char)tolower(curr);
        traitL += curr;
        i++;
    }

    List.push_back(vertices[pokeID].getInfo().getName());
    visited[pokeID] = true;

    if (traitL.compare("dexid")) {
 
    } else if (traitL.compare("name")) {

    } else if (traitL.compare("gen")) {

    } else if (traitL.compare("status")) {

    } else if (traitL.compare("typeone")) {

    } else if (traitL.compare("typetwo")) {

    } else if (traitL.compare("height")) {

    } else if (traitL.compare("weight")) {

    } else if (traitL.compare("catchrate")) {

    } else if (traitL.compare("species")) {

    } else {

    }
}

void Graph::insertVertex(double key) {
    Vertex v(key);
    vertices.push_back(v);
}

Graph::insertEdge(vertex v1, vertex v2, size_t key) {
    Edge e(v1, v2, key);
    edges.push_back(e);
}