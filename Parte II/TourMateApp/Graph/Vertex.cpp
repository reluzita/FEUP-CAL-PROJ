#include "Vertex.h"

using namespace std;


Vertex::Vertex(int id, double x, double y, string type): id(id), x(x), y(y), type(type) {
    this->visited = false;
    this->duration = 0;
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
void Vertex::setDist(double dist) {
    this->dist = dist;
}

void Vertex::setDistFromDest(double dist) {
    distFromDest = dist;
}

void Vertex::setType(string type) {
    this->type = type;
}


void Vertex::setInvertedVisited(bool visited) {
    this->invertedVisited = visited;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex::setUsedInPath(bool stopped) {
    this->usedInPath = stopped;
}

void Vertex::setPath(Vertex* v) {
    path = v;
}

void Vertex::setInvertedPath(Vertex* v) {
    invertedPath = v;
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

double Vertex::getDist() {
    return dist;
}

double Vertex::getDistFromDest() {
    return distFromDest;
}

string Vertex::getType() {
    return type;
}

Vertex* Vertex::getPath() {
    return path;
}

bool Vertex::isUsedInPath() {
    return usedInPath;
}

Vertex* Vertex::getInvertedPath() {
    return invertedPath;
}


vector<Edge> Vertex::getAdj() {
    return adj;
}

bool Vertex::isVisited() {
    return visited;
}


bool Vertex::isInvertedVisited() {
    return invertedVisited;
}

void Vertex::clearEdges() {
    adj.clear();
    cout << "clearing: " << adj.size() << endl;
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

void Vertex::addEdge(const int &dest, double w) {
    adj.emplace_back(dest, w);
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