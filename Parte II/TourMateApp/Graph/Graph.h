//
// Created by ineso on 5/4/2020.
//

#ifndef TOURMATEAPP_GRAPH_H
#define TOURMATEAPP_GRAPH_H

#include "Vertex.h"

class Graph {
    std::vector<Vertex*> vertexSet;    // vertex set
    //vector<vector<int>> D;

public:
    Graph();
    Vertex *findVertex(const int &id) const;
    bool addVertex(const int &id, const int &x, const int &y);
    bool addEdge(const int &sourc, const int &dest, double w);
    int getNumVertex() const;
    std::vector<Vertex*> getVertexSet() const;
/*
    // Fp05 - single source
    void unweightedShortestPath(const int &s);    //TODO...
    void dijkstraShortestPath(const int &s);      //TODO...
    void bellmanFordShortestPath(const int &s);   //TODO...
    vector<T> getPathTo(const int &dest) const;   //TODO...

    // Fp05 - all pairs
    void floydWarshallShortestPath();   //TODO...
    vector<T> getfloydWarshallPath(const int &origin, const int &dest) const;   //TODO...
*/
};



#endif //TOURMATEAPP_GRAPH_H
