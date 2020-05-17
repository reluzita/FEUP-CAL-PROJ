#include "Graph.h"

using namespace std;

Graph::Graph() {
    maxX = INT_MIN;
    minX = INT_MAX;
    maxY = INT_MIN;
    minY = INT_MAX;

    maxLat = INT_MIN;
    minLat = INT_MAX;
    maxLon = INT_MIN;
    minLon = INT_MAX;

    publicTransportation = false;
}

void Graph::initializeGraph() {
    for(auto v: vertexSet) {
        v->dist = INT_MAX;
        v->path = nullptr;
        v->distFromDest = 0;
        v->distSourcToDest = 0;
    }
}

void Graph::initializeForSearch() {
    for(Vertex* v: vertexSet)
        v->visited = false;
}

void Graph::initializeForAStar(const int &orig, const int &dest) {
    Vertex* o = findVertex(orig);
    Vertex* d = findVertex(dest);
    double pathDist = o->distanceLatLon(d);
    for(auto v: vertexSet) {
        v->dist = INT_MAX;
        v->path = nullptr;
        v->distFromDest = v->distanceLatLon(d);
        v->distSourcToDest = pathDist;
    }
}

void Graph::initializeForBirDir() {
    for(Vertex* v: vertexSet){
        v->invertedVisited = false;
    }
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}
void Graph::setVertexSet(vector<Vertex*> vertexSet){
    this->vertexSet = vertexSet;
}


vector<Vertex*> Graph::getVertexSet() const {
    return vertexSet;
}



/*
 * Auxiliary function to find a vertex with a given content.
 */

Vertex * Graph::findVertex(const int &id) const {
    auto it = vertexMap.find(id); 
    if(it == vertexMap.end())
        return nullptr;
    return vertexSet.at(it->second);
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */

bool Graph::addVertex(const int &id, const double &x, const double &y) {
    if ( findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id, x, y, " "));
    if(x > maxX) maxX = x;
    if(x < minX) minX = x;
    if(y > maxY) maxY = y;
    if(y < minY) minY = y;

    vertexMap.insert(make_pair(id, vertexSet.size() - 1));

    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(dest,w);
    return true;
}

bool Graph::addBiDirEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(dest,w);
    v2->addEdge(sourc, w);
    return true;
}


double Graph::getMaxX() const{
    return maxX;
}

double Graph::getMinX() const{
    return minX;
}
double Graph::getMaxY() const{
    return maxY;
}
double Graph::getMinY() const{
    return minY;
}

void Graph::checkLatLon(double lat, double lon) {
    if(lat > maxLat) maxLat = lat;
    if(lat < minLat) minLat = lat;
    if(lon > maxLon) maxLon = lon;
    if(lon < minLon) minLon = lon;
}

double Graph::getMaxLat() const{
    return maxLat;
}

double Graph::getMinLat() const{
    return minLat;
}
double Graph::getMaxLon() const{
    return maxLon;
}
double Graph::getMinLon() const{
    return minLon;
}

string Graph::getCityName() const{
    return cityName;
}

bool Graph::getPublicTransportation() const{
    return publicTransportation;
}

void Graph::setCityName(string name){
    this->cityName = name;
}

void Graph::setPublicTransportation(bool publicTransportation){
    this->publicTransportation = publicTransportation;
}

vector<pair<double,double>> Graph::getCityCoords(){
    vector<pair<double,double>> cityCoords;
    for(auto v: vertexSet){
        pair<double,double> p(v->getLat(),v->getLon());
        cityCoords.push_back(p);
    }
    return cityCoords;
}
vector<pair<double,double>> Graph::idToCoords(const vector<int>& v){
    vector<pair<double,double>> coords;
    
    for(auto id: v){
        Vertex * vertex = findVertex(id);
        pair<double,double> c (vertex->getLat(),vertex->getLon());
        coords.push_back(c);
    }
    return coords;
}

bool Graph::operator== (const Graph &graph) {
    return cityName == graph.cityName;
}


