#include "../includeedge.h"
#include "../pokemon_helpers/pokemon.h"
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
