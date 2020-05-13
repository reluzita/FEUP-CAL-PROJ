#include "ClientInfo.h"

void ClientInfo::setCity(string city) {
    this->city = city;
}
 
void ClientInfo::setMeansOfTransportation(string meansOfTransportation){
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
string ClientInfo::getCity() {
    return city;
}
 
string ClientInfo::getMeansOfTransportation(){
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
    return  poi;
}
void ClientInfo::addPoi(string point){
    this->poi.push_back(point);
}
void ClientInfo::addAllPoi(vector<string> points){
    this.poi = points;
}
void ClientInfo::removePoi(int index){
    this->poi.erase(index);
}
void ClientInfo::removeAllPoi(){
    this->poi.erase(this->poi.begin(), this->poi.end());
}