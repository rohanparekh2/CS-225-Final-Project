#include "../include/graph.h"
#include "../include/vertex.h"
#include "../include/edge.h"
#include "../include/pokemon.h"
#include "../CImgLib/CImg.h"
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
    queue<int> queueID;
    int currID = pokeID;

    visited.assign(vertices.size(), false);
    visited.at(currID - 1) = true;
    queueID.push(currID);

    while (!queueID.empty()) {
        currID = queueID.front();
        list.push_back(vertices[currID - 1].getInfo().getName());
        
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].getVertexOne() == currID ||
                    edges[i].getVertexTwo() == currID) {
                vertEdges.push_back(edges[i]);
            }
        }
        
        queueID.pop();
        for (int i = 0; i < vertEdges.size(); i++) {
            if (currID == vertEdges[i].getVertexOne()) {
                if (!visited[vertEdges[i].getVertexTwo() - 1]) {
                    visited[vertEdges[i].getVertexTwo() - 1] = true;
                    queueID.push(vertEdges[i].getVertexTwo());
                }

            } else {
                if (!visited[vertEdges[i].getVertexOne() - 1]) {
                    visited[vertEdges[i].getVertexOne() - 1] = true;
                    queueID.push(vertEdges[i].getVertexOne());
                }
            }
        }
    }
    
    return list;
}

bool Graph::IDDFS(int startPokeID, string target, int maxRange) {
    int i = 0;
    
    while (i < maxRange) {
        if (depthLimitedSearch(startPokeID, target, i)) {
            return true;
        }
        i++;
    }
    return false;
}

bool Graph::depthLimitedSearch(int startPokeID, string target, int maxRange) {
    int target_value = 0;
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].getName() == target) {
            target_value = nodes[i].getDexID();
            break;        
        }
    }

    //std::cout << "trg val:" << target_value << std::endl;
    if (target_value == startPokeID) {
        return true;
    }
    if (target_value == 0 || maxRange <= 0) {
        return false;
    }


    vector<Edge> vertEdges;
    for (int i = 0; i < edges.size(); i++) {
        std::cout << "edgePair: " << edges[i].getVertexOne() <<
                    ", " << edges[i].getVertexTwo() << std::endl;
        if (edges[i].getVertexOne() == startPokeID ||
                edges[i].getVertexTwo() == startPokeID) {
            vertEdges.push_back(edges[i]);
        }
    }
    vector<int> verAdjID;
    for (int j = 0; j < vertEdges.size(); j++) {
        if (startPokeID == vertEdges[j].getVertexOne()) {
            verAdjID.push_back(vertEdges[j].getVertexOne());
        } else {
            verAdjID.push_back(vertEdges[j].getVertexTwo());
        }
    }

    for (int k = 0; k < verAdjID.size(); k++) {
        std::cout << "newStartID: " << verAdjID[k]<< std::endl; 
        if (depthLimitedSearch(verAdjID[k], target, maxRange - 1)) {
            return true;
        }
    }


        



    return false;
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