#include "Edge.h"

Edge::Edge(int destID, double w, bool strong): destID(destID), weight(w), strong(strong) {}

int Edge::getDest() {
    return destID;
}

double Edge::getWeight() {
    return weight;
}

bool Edge::isStrong() {
    return strong;
}

void Edge::setStrong(bool strong) {
    this->strong = strong;
}