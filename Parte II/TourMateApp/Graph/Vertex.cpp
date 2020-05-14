//
// Created by ineso on 5/4/2020.
//

#include "Vertex.h"

#include <utility>

using namespace std;


Vertex::Vertex(int id, double x, double y, string type): id(id), x(x), y(y), type(type) {
    this->visited = false;
}

int Vertex::getID() {
    return id;
}

double Vertex::getX() {
    return x;
}

double Vertex::getY() {
    return y;
}

double Vertex::getLat() {
    return lat;
}

double Vertex::getLon() {
    return lon;
}

int Vertex::getDuration() {
    return duration;
}

void Vertex::setLat(double lat) {
    this->lat = lat;
}

void Vertex::setLon(double lon) {
    this->lon = lon;
}

void Vertex::setBusStop(BusStop* busStop) {
    this->busStop = busStop;
}

void Vertex::setMetroStation(MetroStation* metroStation) {
    this->metroStation = metroStation;
}

void Vertex::setDuration(int dur) {
    this->duration = dur;
}

void Vertex::addEdge(const int &dest, double w) {
    adj.emplace_back(dest, w);
}

double Vertex::getDist() {
    return dist;
}

void Vertex::setDist(double dist) {
    this->dist = dist;
}

double Vertex::getDistFromDest() {
    return distFromDest;
}

void Vertex::setDistFromDest(double dist) {
    distFromDest = dist;
}

string Vertex::getType() {
    return type;
}
void Vertex::setType(string type) {
    this->type = type;
}

Vertex* Vertex::getPath() {
    return path;
}

void Vertex::setPath(Vertex* v) {
    path = v;
}

Vertex* Vertex::getInvertedPath() {
    return invertedPath;
}

void Vertex::setInvertedPath(Vertex* v) {
    invertedPath = v;
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

bool Vertex::isInvertedVisited() {
    return invertedVisited;
}

void Vertex::setInvertedVisited(bool visited) {
    this->invertedVisited = visited;
}

double Vertex::distanceLatLon(Vertex* v2) {
    double deg2radMultiplier =  PI / 180;
    double lon1 = lon * deg2radMultiplier;
    double lat1 = lat * deg2radMultiplier;
    double lat2 = v2->getLat() * deg2radMultiplier;
    double lon2 = v2->getLon() * deg2radMultiplier;

    double radius = 6378.137; // earth mean radius defined by WGS84
    double dlon = lon2 - lon1;
    double distance = acos( sin(lat1) * sin(lat2) +  cos(lat1) * cos(lat2) * cos(dlon)) * radius;

    return distance;
}



bool Vertex::operator<(Vertex & vertex) const {
    return (this->dist - this->distSourcToDest + this->distFromDest) < (vertex.dist - this->distSourcToDest + vertex.distFromDest);
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