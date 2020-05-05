//
// Created by ineso on 5/4/2020.
//

#ifndef TOURMATEAPP_EDGE_H
#define TOURMATEAPP_EDGE_H

class Edge {
    int destID;      // destination vertex
    double weight;         // edge weight
public:
    Edge(int destID, double w);

    int getDest();
    double getWeight();
    friend class Graph;
    friend class Vertex;
};


#endif //TOURMATEAPP_EDGE_H
