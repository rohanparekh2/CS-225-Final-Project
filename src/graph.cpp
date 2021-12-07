#include "../include/graph.h"
#include "../include/vertex.h"
#include "../include/edge.h"
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>

using namespace std;

Graph::Graph() {

}
        
Graph::Graph(std::string file) {

}

Graph::Graph(size_t size) {

}

vector<string> Graph::BFS(int pokeID) {
    vector<string> list;
    vector<bool> visited;
    vector<Edge> edges;
    visited.assign(vertices.size(), false);
    queue<int> queueID;
    int currID = pokeID;

    visited[pokeID] = true;
    queueID.push(pokeID);

    while(!queueID.empty()) {
        currID = queueID.front();
        list.push_back(vertices[currID].getInfo().getName());
        edges = vertices[currID].getEdges();
        queueID.pop();

        for (int i = 0; i < edges.size(); i++) {
            if (!visited[edges[i].getVertexTwo()]) {
                visited[edges[i].getVertexTwo()] = true;
                queueID.push(edges[i].getVertexTwo());
            }
        }
    }

    return list;
}

void Graph::insertVertex(double key) {
    Vertex v(key);
    vertices.push_back(v);
}

void Graph::insertEdge(Vertex v1, Vertex v2, size_t key) {
    Edge e(v1.getID(), v2.getID(), key);
    edges.push_back(e);
}

bool Graph::areAdjacent(Vertex v1, Vertex v2) {
    for (int i = 0; i < edges.size(); i++) {
        if ((edges[i].getVertexOne() == v1.getID() && edges[i].getVertexTwo() == v2.getID())
            || (edges[i].getVertexOne() == v2.getID() && edges[i].getVertexTwo() == v1.getID())) {
            return true;
        }
    }
    return false;
}

std::vector<Edge> Graph::incidentEdges(Vertex v) {
    std::vector<Edge> incident;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].getVertexOne() == v.getID() || edges[i].getVertexTwo() == v.getID()) {
            incident.push_back(edges[i]);
        }
    }
    return incident;
}