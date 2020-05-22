#include "ClientInfo.h"

void ClientInfo::startGraph(Graph g) {
    for(Vertex* vertex: g.getVertexSet()) {
        poiGraph.addVertex(vertex->getID(), vertex->getX(), vertex->getY());
        Vertex* v = poiGraph.findVertex(vertex->getID());
        v->setLat(vertex->getLat());
        v->setLon(vertex->getLon());
    }
}

double ClientInfo::getDistance(Graph g, int orig, int end) {
    Vertex* v = poiGraph.findVertex(orig);
    for (Edge edge: v->getAdj()) {
        if(edge.getDest() == end) {
            return edge.getWeight();
        }
    }

    queue<Vertex*> path = g.dijkstraShortestPath(orig, end);
    double distance = distancePath(path);

    poiGraph.addEdge(orig, end, distance);
    return distance;
}

void ClientInfo::setMeansOfTransportation(char meansOfTransportation){
    this->meansOfTransportation = meansOfTransportation;
}
 
void ClientInfo::setIdStart(int idStart){
    this->idStart = idStart;
}
 
void ClientInfo::setIdEnd(int idEnd){
    this->idEnd = idEnd;
}  
 
void ClientInfo::setTimeAvailable(int timeAvailable){
    this->timeAvailable = timeAvailable;
}
 
void ClientInfo::setPoi(vector <string> poi){
    this->poi = poi;
}

void ClientInfo::setCounterFactor(double factor) {
    this->counterFactor = factor;
}

char ClientInfo::getMeansOfTransportation(){
    return meansOfTransportation;
}
 
int ClientInfo::getIdStart(){
    return idStart;
}
 
int ClientInfo::getIdEnd(){
    return idEnd;
}
 
int ClientInfo::getTimeAvailable(){
    return timeAvailable;
}
 
vector<string> ClientInfo::getPoi(){
    return poi;
}

double ClientInfo::getCounterFactor() {
    return counterFactor;
}

void ClientInfo::addPoi(const string& point){
    this->poi.push_back(point);
}
void ClientInfo::addAllPoi(const vector<string> &points){
    this->poi = points;
}
void ClientInfo::removePoi(const string& point){
    auto it = find(poi.begin(), poi.end(), point);
    if(it != poi.end())
        this->poi.erase(it);
}
void ClientInfo::removeAllPoi(){
    this->poi.erase(this->poi.begin(), this->poi.end());
}