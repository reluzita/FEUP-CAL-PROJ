//
// Created by ineso on 5/4/2020.
//

#ifndef TOURMATEAPP_EDGE_H
#define TOURMATEAPP_EDGE_H

class Edge {
    int nodeID;      // destination vertex
    double weight;         // edge weight
public:
    Edge(int nodeID, double w);
    friend class Graph;
    friend class Vertex;
};


#endif //TOURMATEAPP_EDGE_H
