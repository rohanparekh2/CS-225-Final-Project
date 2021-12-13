#include "../include/graph.h"
#include "../include/vertex.h"
#include "../include/edge.h"
#include "../include/pokemon.h"
#include "../include/StickerSheet.h"
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <math.h>

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

    if (target_value == startPokeID) {
        return true;
    }
    if (target_value == 0 || maxRange <= 0) {
        return false;
    }

    vector<Edge> vertEdges;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].getVertexOne() == startPokeID ||
                edges[i].getVertexTwo() == startPokeID) {
            vertEdges.push_back(edges[i]);
        }
    }
    vector<int> verAdjID;
    for (int j = 0; j < vertEdges.size(); j++) {
        if (startPokeID == vertEdges[j].getVertexOne()) {
            verAdjID.push_back(vertEdges[j].getVertexTwo());
        } else {
            verAdjID.push_back(vertEdges[j].getVertexOne());
        }
    }

    for (int k = 0; k < verAdjID.size(); k++) {
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

void Graph::drawGraph() {
    width_ = 1600;
    height_ = 800;
    
    Image sheet;
    Image sticker;
    Image finals;

    Image i1;
    createImages(i1, "Grass");
    Image i2;
    createImages(i2, "Fire");
    Image i3;
    createImages(i3, "Water");
    Image i4;
    createImages(i4, "Normal");
    Image i5;
    createImages(i5, "Fighting");
    Image i6;
    createImages(i6, "Flying");
    Image i7;
    createImages(i7, "Poison");
    Image i8;
    createImages(i8, "Electric");
    Image i9;
    createImages(i9, "Ground");
    Image i10;
    createImages(i10, "Rock");
    Image i11;
    createImages(i11, "Psychic");
    Image i12;
    createImages(i12, "Ice");
    Image i13;
    createImages(i13, "Bug");
    Image i14;
    createImages(i14, "Ghost");
    Image i15;
    createImages(i15, "Steel");
    Image i16;
    createImages(i16, "Dragon");
    Image i17;
    createImages(i17, "Dark");
    Image i18;
    createImages(i18, "Fairy");

    /*Image i1;
    i1.readFromFile("resources/circle.png");
    i1.scale(0.05);
    i1.saturate(1);
    i1.lighten(0.5);
    i1.rotateColor(typeToColor("Grass"));
    Image i2;
    i2.readFromFile("resources/circle.png");
    i2.scale(0.05);
    i2.saturate(1);
    i2.lighten(0.5);
    i2.rotateColor(typeToColor("Fire"));
    Image i3;
    i3.readFromFile("resources/circle.png");
    i3.scale(0.05);
    i3.saturate(1);
    i3.lighten(0.5);
    i3.rotateColor(typeToColor("Water"));
    Image i4;
    i4.readFromFile("resources/circle.png");
    i4.scale(0.05);
    i4.saturate(1);
    i4.lighten(0.5);
    i4.rotateColor(typeToColor("Normal"));
    Image i5;
    i5.readFromFile("resources/circle.png");
    i5.scale(0.05);
    i5.saturate(1);
    i5.lighten(0.5);
    i5.rotateColor(typeToColor("Fighting"));
    Image i6;
    i6.readFromFile("resources/circle.png");
    i6.scale(0.05);
    i6.saturate(1);
    i6.lighten(0.5);
    i6.rotateColor(typeToColor("Flying"));
    Image i7;
    i7.readFromFile("resources/circle.png");
    i7.scale(0.05);
    i7.saturate(1);
    i7.lighten(0.5);
    i7.rotateColor(typeToColor("Poison"));
    Image i8;
    i8.readFromFile("resources/circle.png");
    i8.scale(0.05);
    i8.saturate(1);
    i8.lighten(0.5);
    i8.rotateColor(typeToColor("Electric"));
    Image i9;
    i9.readFromFile("resources/circle.png");
    i9.scale(0.05);
    i9.saturate(1);
    i9.lighten(0.5);
    i9.rotateColor(typeToColor("Ground"));
    Image i10;
    i10.readFromFile("resources/circle.png");
    i10.scale(0.05);
    i10.saturate(1);
    i10.lighten(0.5);
    i10.rotateColor(typeToColor("Rock"));
    Image i11;
    i11.readFromFile("resources/circle.png");
    i11.scale(0.05);
    i11.saturate(1);
    i11.lighten(0.5);
    i11.rotateColor(typeToColor("Psychic"));
    Image i12;
    i12.readFromFile("resources/circle.png");
    i12.scale(0.05);
    i12.saturate(1);
    i12.lighten(0.5);
    i12.rotateColor(typeToColor("Ice"));
    Image i13;
    i13.readFromFile("resources/circle.png");
    i13.scale(0.05);
    i13.saturate(1);
    i13.lighten(0.5);
    i13.rotateColor(typeToColor("Bug"));
    Image i14;
    i14.readFromFile("resources/circle.png");
    i14.scale(0.05);
    i14.saturate(1);
    i14.lighten(0.5);
    i14.rotateColor(typeToColor("Ghost"));
    Image i15;
    i15.readFromFile("resources/circle.png");
    i15.scale(0.05);
    i15.saturate(1);
    i15.lighten(0.5);
    i15.rotateColor(typeToColor("Steel"));
    Image i16;
    i16.readFromFile("resources/circle.png");
    i16.scale(0.05);
    i16.saturate(1);
    i16.lighten(0.5);
    i16.rotateColor(typeToColor("Dragon"));
    Image i17;
    i17.readFromFile("resources/circle.png");
    i17.scale(0.05);
    i17.saturate(1);
    i17.lighten(0.5);
    i17.rotateColor(typeToColor("Dark"));
    Image i18;
    i18.readFromFile("resources/circle.png");
    i18.scale(0.05);
    i18.saturate(1);
    i18.lighten(0.5);
    i18.rotateColor(typeToColor("Fairy"));*/
    
    sheet.resize(width_, height_);
    
    StickerSheet background(sheet, nodes.size() + 1);
    CalculateLocations();

    for (int i = 0; i < nodes.size(); i++) {
        //sticker.readFromFile("resources/circle.png");
        //sticker.scale(0.05);
        double value = typeToColor(nodes[i].getType1());
        //std::cout << "drawing value : " << value << std::endl;

        /*sticker.saturate(1);
        sticker.lighten(0.5);
        sticker.changeColor(value);*/
        switch ((int)value) {
            case 15:
                background.addSticker(i1, locations[i].first, locations[i].second);
                break;
            case 30:
                background.addSticker(i2, locations[i].first, locations[i].second);
                break;
            case 45:
                background.addSticker(i3, locations[i].first, locations[i].second);
                break;
            case 60:
                background.addSticker(i4, locations[i].first, locations[i].second);
                break;
            case 75:
                background.addSticker(i5, locations[i].first, locations[i].second);
                break;
            case 90:
                background.addSticker(i6, locations[i].first, locations[i].second);
                break;
            case 105:
                background.addSticker(i7, locations[i].first, locations[i].second);
                break;
            case 120:
                background.addSticker(i8, locations[i].first, locations[i].second);
                break;
            case 135:
                background.addSticker(i9, locations[i].first, locations[i].second);
                break;
            case 150:
                background.addSticker(i10, locations[i].first, locations[i].second);
                break;
            case 165:
                background.addSticker(i11, locations[i].first, locations[i].second);
                break;    
            case 180:
                background.addSticker(i12, locations[i].first, locations[i].second);
                break;
            case 195:
                background.addSticker(i13, locations[i].first, locations[i].second);
                break;
            case 210:
                background.addSticker(i14, locations[i].first, locations[i].second);
                break;
            case 225:
                background.addSticker(i15, locations[i].first, locations[i].second);
                break;
            case 240:
                background.addSticker(i16, locations[i].first, locations[i].second);
                break;
            case 255:
                background.addSticker(i17, locations[i].first, locations[i].second);
                break;
            case 270:
                background.addSticker(i18, locations[i].first, locations[i].second);
                break;
        }
        //background.addSticker(sticker, locations[i].first, locations[i].second);

        //finals = background.render();

        //StickerSheet background(finals, i);
        // Change pixel color to match type

        //std::cout << locations[i].first << ",   " << locations[i].second << std::endl;

        //background.addSticker(sticker, nodes[i].getGen() * 20, typeToNum(nodes[i].getType1()) * 20);
        
        //cout << "Pokemon: " << nodes[i].getName() << ", Gen: " << nodes[i].getGen() << ", First Type: " << typeToNum(nodes[i].getType1())  << std::endl;
    }
    finals = background.render();
    finals.writeToFile("myImage.png");
}

size_t Graph::typeToNum(string type) {
    if (type == "Grass") {
        return 1;
    }
    if (type == "Fire") {
        return 2;
    }
    if (type == "Water") {
        return 3;
    }
    if (type == "Normal") {
        return 4;
    }
    if (type == "Fighting") {
        return 5;
    }
    if (type == "Flying") {
        return 6;
    }
    if (type == "Poison") {
        return 7;
    }
    if (type == "Electric") {
        return 8;
    }
    if (type == "Ground") {
        return 9;
    }
    if (type == "Rock") {
        return 10;
    }
    if (type == "Psychic") {
        return 11;
    }
    if (type == "Ice") {
        return 12;
    }
    if (type == "Bug") {
        return 13;
    }
    if (type == "Ghost") {
        return 14;
    }
    if (type == "Steel") {
        return 15;
    }
    if (type == "Dragon") {
        return 16;
    }
    if (type == "Dark") {
        return 17;
    }
    if (type == "Fairy") {
        return 18;
    }
    return 0;
}

std::vector<std::pair<int, int>> Graph::CalculateLocations() {
    
    std::pair<int, int> start(width_/4, height_/4);
    locations.push_back(start);
    int gen_diff;
    int status_diff;
    for (int i = 1; i < nodes.size(); i++) {
        gen_diff = 3*(nodes[i].getGen() - nodes[0].getGen());
        status_diff = statusToNum(nodes[i].getStatus()) - statusToNum(nodes[0].getStatus());
        std::pair<int, int> loc(width_/8 + gen_diff * 80, height_/4 + status_diff * 20);
        checkOverLap(loc);
    }
    return locations;
}

std::vector<Edge> Graph::getEdges() {
    return edges;
}
std::vector<Vertex> Graph::getVertices() {
    return vertices;
}

void Graph::checkOverLap(std::pair<int, int> newLocat) {
    if (locations.empty()) {
        locations.push_back(newLocat);
        return;
    }
    
    for (int i = 0; i < locations.size(); i++) {
        if (newLocat.first == locations[i].first &&
                newLocat.second == locations[i].second) {

            bool repeat = true;
            while(repeat) {       
                repeat = false; 
                int randNum = rand() % 4;

                switch (randNum) {
                    case 0:
                        newLocat.first += 13;
                        break;
                    case 1:
                        newLocat.first -= 13;
                        break;
                    case 2:
                        newLocat.second += 13;
                        break;
                    case 3:
                        newLocat.second -= 13;
                        break;
                    
                }

                for (int j = 0; j < locations.size(); j++) {
                    if (newLocat.first == locations[j].first &&
                        newLocat.second == locations[j].second) {
                        repeat = true;
                    }
                }
            }
        }
    }

    locations.push_back(newLocat);
}

double Graph::typeToColor(string type) {
    int rotate = typeToNum(type);
    //std::cout << "typeNUM: " << rotate << std::endl;
    double value = 0;
    switch (rotate) {
        case 1:
            value = 15;
            break;
        case 2:
            value = 30;
            break;
        case 3:
            value = 45;
            break;
        case 4:
            value = 60;
            break;
        case 5:
            value = 75;
            break;
        case 6:
            value = 90;
            break;
        case 7:
            value = 105;
            break;
        case 8:
            value = 120;
            break;
        case 9:
            value = 135;
            break;
        case 10:
            value = 150;
            break;
        case 11:
            value = 165;
            break;
        case 12:
            value = 180;
            break;
        case 13:
            value = 195;
            break;
        case 14:
            value = 210;
            break;
        case 15:
            value = 225;
            break;
        case 16:
            value = 240;
            break;
        case 17:
            value = 255;
            break;
        case 18:
            value = 270;
            break;
    }

    //std::cout << "value: " << value << std::endl;

    return value; 
    //return 0;
}


int Graph::statusToNum(string status) {
    if (status == "Normal") {
        return 2;
    }
    if (status == "Legendary") {
        return 10;
    }
    if (status == "Mythical") {
        return 20;
    }
    return 0;
}

void Graph::createImages(Image& i, std::string type) {
    i.readFromFile("resources/circle.png");
    i.scale(0.05);
    i.saturate(1);
    i.lighten(0.5);
    i.rotateColor(typeToColor(type));
}