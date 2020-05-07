//
// Created by ineso on 5/4/2020.
//

#ifndef TOURMATEAPP_VERTEX_H
#define TOURMATEAPP_VERTEX_H

#include "Edge.h"
#include "MutablePriorityQueue.h"
#include <string>
#include <vector>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

class Vertex {
    int id;
    double x;
    double y;
    double lat;
    double lon;
    string type;            // content of the vertex
    vector<Edge> adj;		// outgoing edges

    double dist = 0;
    double distFromDest = 0;
    Vertex *path = nullptr;
    int queueIndex = 0; 		// required by MutablePriorityQueue

    bool visited = false;		// auxiliary field
    bool processing = false;	// auxiliary field

    void addEdge(const int &dest, double w);



public:
    Vertex(int id, double x, double y, std::string type);
    int getID();
    double getX();
    double getY();
    double getLon();
    double getLat();
    void setLat(double lat);
    void setLon(double lon);
    double getDist();
    void setDist(double dist);
    double getDistFromDest();
    void setDistFromDest(double dist);
    string getType();
    void setType(string type);
    Vertex* getPath();
    void setPath(Vertex* v);
    vector<Edge> getAdj();
    bool isVisited();
    void setVisited(bool visited);


    double distanceLatLon(Vertex* v2);
    /*T getInfo() const;
    double getDist() const;
    Vertex *getPath() const;
*/
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue

    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;

};
#endif //TOURMATEAPP_VERTEX_H
