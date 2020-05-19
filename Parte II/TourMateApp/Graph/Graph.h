#ifndef TOURMATEAPP_GRAPH_H
#define TOURMATEAPP_GRAPH_H

#include "Vertex.h"
#include <string>
#include <map>
#include <utility>
#include <unordered_map>

using namespace std;
class Graph {
    std::vector<Vertex*> vertexSet;    // vertex set
    unordered_map<int, int> vertexMap; //<id, index>

    double maxX;
    double minX;
    double maxY;
    double minY;

    double maxLat;
    double minLat;
    double maxLon;
    double minLon;

    bool publicTransportation;
    bool biDir;

    std::string cityName;
    //vector<vector<int>> D;

public:
    Graph();
    void initializeGraph();
    void initializeForSearch();
    void initializeForAStar(const int &orig, const int &dest);
    void initializeForFindPOI();
    void initializeForBirDir();
    Vertex *findVertex(const int &id) const;
    bool addVertex(const int &id, const double &x, const double &y);
    bool addEdge(const int &sourc, const int &dest, double w);
    bool addBiDirEdge(const int &sourc, const int &dest, double w);
    int getNumVertex() const;
    std::vector<Vertex*> getVertexSet() const;
    void setVertexSet(vector<Vertex*> vertexSet);
    void setCityName(string name );
    void setPublicTransportation(bool publicTransportation);
    void setBiDir(bool biDir);

    double getMaxX() const;
    double getMinX() const;
    double getMaxY() const;
    double getMinY()const;
    void checkLatLon(double lat, double lon);
    double getMaxLat() const;
    double getMinLat() const;
    double getMaxLon() const;
    double getMinLon()const;
    string getCityName() const;
    bool getPublicTransportation() const;
    bool getBiDir() const;

    void clearEdges();

/*
    // Fp05 - single source
    void unweightedShortestPath(const int &s);    //TODO...
          //TODO...
    void bellmanFordShortestPath(const int &s);   //TODO...
    vector<T> getPathTo(const int &dest) const;   //TODO...

    // Fp05 - all pairs
    void floydWarshallShortestPath();   //TODO...
    vector<T> getfloydWarshallPath(const int &origin, const int &dest) const;   //TODO...
*/
    vector<pair<double,double>> getCityCoords();
    vector<pair<double,double>> idToCoords(const vector<int> &v);

    bool operator ==(const Graph &graph);
};



#endif //TOURM&ATEAPP_GRAPH_H
