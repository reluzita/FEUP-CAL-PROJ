#include "Edge.h"

Edge::Edge(int destID, double w): destID(destID), weight(w) {}

int Edge::getDest() {
    return destID;
}

double Edge::getWeight() {
    return weight;
}