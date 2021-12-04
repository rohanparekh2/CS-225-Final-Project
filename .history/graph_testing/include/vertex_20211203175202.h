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
    private:
        double ID;
        vector<Edge> edges_;
        Pokemon::Pokemon pokemon_;
}


Edge::Edge() {

}

Edge::Edge(double v1, double v2, size_t w) {
    vertex1 = v1;
    vertex2 = v2;
    weight = w;
}

bool Edge::operator ==(const Edge& e) {
    if (vertex1 != e.vertex1 || vertex2 != e.vertex2 || weight != e.weight) {
        return false;
    }
    return true;
}

bool Edge::operator <(const Edge& e){
    return weight < e.weight;
}

double Edge::getVertexOne() {
    return vertex1;
}

double Edge::getVertexTwo() {
    return vertex2;
}

double Edge::getWeight() {
    return weight;
}

