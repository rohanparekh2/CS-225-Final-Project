#pragma once
#include <stdio.h>
#include <ctype.h>

class Edge {
    public:
        Edge();
        Edge(double v1, double v2, size_t w);
        bool operator ==(const Edge& e) const;

        double getVertexOne();
        double getVertexTwo();
        size_t getWeight();
    private:
        double vertex1;
        double vertex2;
        size_t weight;
};

