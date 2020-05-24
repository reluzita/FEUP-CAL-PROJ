#include "ClientInfo.h"

void ClientInfo::startGraph(Graph<coord> g) {
    for(Vertex<coord>* vertex: g.getVertexSet())
        poiGraph.addVertex(vertex->getId());
}

double ClientInfo::getDistance(Graph<coord> g, int orig, int end) {
    return poiGraph.getDist(g, orig, end);
}

queue<Vertex<coord>*> ClientInfo::getPath(Graph<coord> g, int orig, int end) {
    return poiGraph.getPath(g, orig, end);
}

int ClientInfo::getMinutes(Graph<coord> g,int orig, int end) {
    cout << "getting minutes" << endl;
    double dist = poiGraph.getDist(g, orig, end);
    cout << "got minutes" << endl;
    if(dist == -1)
        return -1;
    return g.minutesFromDistance(dist, meansOfTransportation);
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