#include "../include/vertex.h"

Vertex::Vertex() {

}

Vertex::Vertex(double dexID) {
    ID = dexID;
    Pokemon poke(dexID);
    pokemon_ = poke;
}

Pokemon Vertex::getInfo() {
    return pokemon_;
}

vector<Edge> Vertex::getEdges() {
    return edges_;
}

double Vertex::getID(){
    return ID;
}
