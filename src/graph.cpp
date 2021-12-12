#include "../include/graph.h"
#include "../include/vertex.h"
#include "../include/edge.h"
#include "../include/pokemon.h"
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>

using namespace std;

Graph::Graph() {

}

Graph::Graph(size_t size) {
    for (int i = 1; i <= size; i++) {
        Pokemon p(i);
        nodes.push_back(p);
    }
    createGraph();
}

vector<string> Graph::BFS(int pokeID) {
    vector<string> list;
    if (vertices.empty()){
        list.push_back("GRAPH_IS_EMPTY");
        return list;
    }
    if (vertices.size() < pokeID || 0 > pokeID) {
        list.push_back("POKEMON_ID_NOT_FOUND_IN_GRAPH");
        return list;
    }

    vector<bool> visited;
    vector<Edge> vertEdges;
    visited.assign(vertices.size(), false);

    queue<int> queueID;
    int currID = pokeID;

    visited.at(currID - 1) = true;
        //std::cout << "test1.2" << std::endl;

    queueID.push(currID);

    //std::cout << "test2" << std::endl;

    while (!queueID.empty()) {
        currID = queueID.front();
        list.push_back(vertices[currID - 1].getInfo().getName());
        //std::cout << "CurrID: " << currID << std::endl;
        
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].getVertexOne() == currID ||
                    edges[i].getVertexTwo() == currID) {
                vertEdges.push_back(edges[i]);
            }
        }
        
        queueID.pop();

    //std::cout << "test3" << std::endl;
//std::cout << "CurrID: " << currID << std::endl;

        for (int i = 0; i < vertEdges.size(); i++) {
            if (currID == vertEdges[i].getVertexOne()) {
                if (!visited[vertEdges[i].getVertexTwo() - 1]) {
                    //std::cout << "vE::Vet2: " << vertEdges[i].getVertexTwo() << std::endl;

                    visited[vertEdges[i].getVertexTwo() - 1] = true;
                    queueID.push(vertEdges[i].getVertexTwo());
                }

            } else {
                if (!visited[vertEdges[i].getVertexOne() - 1]) {
                    //std::cout << "vE::Vet1: " << vertEdges[i].getVertexOne() << std::endl;

                    visited[vertEdges[i].getVertexOne() - 1] = true;
                    queueID.push(vertEdges[i].getVertexOne());
                }
                
            }
        }
    }
        //std::cout << "test6" << std::endl;


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

void Graph::createGraph() {
    int count = 1;
    for (int i = 1; i <= nodes.size(); i++) {
        insertVertex(i);
    }

    for (int i = 1; i < nodes.size(); i++) {
        for (int j = i + 1; j <= nodes.size(); j++) {
            if (nodes[i - 1].getGen() == nodes[j - 1].getGen() || nodes[i - 1].getType1() == nodes[j - 1].getType1()) {
                insertEdge(vertices[i - 1], vertices[j - 1], count);
                count++;
            }
        }
    }
}

std::vector<Edge> Graph::getEdges() {
    return edges;
}
std::vector<Vertex> Graph::getVertices() {
    return vertices;
}