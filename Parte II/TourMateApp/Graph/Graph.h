//
// Created by ineso on 5/4/2020.
//

#ifndef TOURMATEAPP_GRAPH_H
#define TOURMATEAPP_GRAPH_H

#include "Vertex.h"

class Graph {
    std::vector<Vertex*> vertexSet;    // vertex set

    double maxX;
    double minX;
    double maxY;
    double minY;
    //vector<vector<int>> D;

public:
    Graph();
    void initializeGraph();
    void initializeForSearch();
    void initializeForAStar(const int &dest);
    Vertex *findVertex(const int &id) const;
    bool addVertex(const int &id, const double &x, const double &y);
    bool addEdge(const int &sourc, const int &dest, double w);
    int getNumVertex() const;
    std::vector<Vertex*> getVertexSet() const;

    double getMaxX() const;
    double getMinX() const;
    double getMaxY() const;
    double getMinY()const;

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
    vector<pair<double,double>> idToCoords(vector<int> v);
};



#endif //TOURMATEAPP_GRAPH_H
