//
// Created by ineso on 5/4/2020.
//

#include "Edge.h"

Edge::Edge(int destID, double w): destID(destID), weight(w) {}

int Edge::getDest() {
    return destID;
}

int Edge::getWeight() {
    return weight;
}