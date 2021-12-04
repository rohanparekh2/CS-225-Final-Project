#include "../include/vertex.h"

Vertex::Vertex() {

}

Vertex::Vertex(double dexID) {
    ID = dexID;
    Pokemon::Pokemon poke(dexID);
    pokemon_ = poke;
}

Pokemon::Pokemon Vertex::getInfo() {
    return pokemon_;
}

vector<Edge> Vertex::getEdges() {
    return edges_;
}

bool Vertex::operator ==(const Vertex& v) {
    return ID == v.ID;
}

bool Vertex::operator <(const Vertex& v){
    return ID < v.ID;
}
