//
// Created by ineso on 5/4/2020.
//

#include "Vertex.h"

#include <utility>

using namespace std;


Vertex::Vertex(int id, double x, double y, string type): id(id), x(x), y(y), type(type) {}

int Vertex::getID() {
    return id;
}

double Vertex::getX() {
    return x;
}

double Vertex::getY() {
    return y;
}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */

void Vertex::addEdge(const int &dest, double w) {
    adj.emplace_back(dest, w);
}

double Vertex::getDist() {
    return dist;
}

void Vertex::setDist(double dist) {
    this->dist = dist;
}


Vertex* Vertex::getPath() {
    return path;
}

void Vertex::setPath(Vertex* v) {
    path = v;
}

vector<Edge> Vertex::getAdj() {
    return adj;
}

bool Vertex::isVisited() {
    return visited;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}


bool Vertex::operator<(Vertex & vertex) const {
    return this->dist < vertex.dist;
}
/*
template <class T>
T Vertex<T>::getInfo() const {
    return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
    return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
    return this->path;
}
 */