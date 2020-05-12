//
// Created by ineso on 5/12/2020.
//

#include "MagicGenerator.h"

using namespace std;

queue<Vertex*> magicGenerator(Graph &g, ClientInfo* info) {
    queue<Vertex*> res;

    vector<int> points = bfsAll(g, info->getIdStart());
    if(find(points.begin(), points.end(), info->getIdEnd()) == points.end()) {
        //no path!
        return res;
    }

    Vertex* start = g.findVertex(info->getIdStart());
    Vertex* end = g.findVertex(info->getIdEnd());

    queue<Vertex*> path = dijkstraShortestPath(g, info->getIdStart(), info->getIdEnd());
    double distance = distancePath(path);

    if(minutesFromDistance(distance, info->getMeansOfTransportation()) > info->getTimeAvailable()) {
        //no time!
        return res;
    }

    vector<int> poi;
    for(int point: points) {
        Vertex* v = g.findVertex(point);
        if(v->getType() != " ") {
            if (find(info->getPoi().begin(), info->getPoi().end(), v->getType()) != info->getPoi().end())
                poi.push_back(point);
        }
    }

    for(int point: poi) {
        cout << point << endl;
    }
    return res;
}