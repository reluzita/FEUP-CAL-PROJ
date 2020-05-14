//
// Created by ineso on 5/12/2020.
//

#include "MagicGenerator.h"

using namespace std;

queue<Vertex*> magicGenerator(Graph &g, ClientInfo* info) {
    cout << "Makin sum magic" << endl;
    queue<Vertex*> res;

    vector<int> points = bfsAll(g, info->getIdStart());
    if(find(points.begin(), points.end(), info->getIdEnd()) == points.end()) {
        cout << "no path!" << endl;
        return res;
    }

    for(int point: points) {
        cout << "Points in the path: " << point << endl;
    }

    Vertex* start = g.findVertex(info->getIdStart());
    Vertex* end = g.findVertex(info->getIdEnd());

    queue<Vertex*> path = dijkstraShortestPath(g, info->getIdStart(), info->getIdEnd());
    double distance = distancePath(path);

    if(minutesFromDistance(distance, info->getMeansOfTransportation()) > info->getTimeAvailable()) {
        //gerar caminho mais curto
        cout << "no time!" << endl;
        return res;
    }

    vector<int> poi;
    for(int point: points) {
        Vertex* v = g.findVertex(point);
        if(v->getType() != " ") {
            if(info->getPoi().empty())
                poi.push_back(point);
            else if (find(info->getPoi().begin(), info->getPoi().end(), v->getType()) != info->getPoi().end())
                poi.push_back(point);
        }
    }

    for(int point: poi) {
        cout << "Generated poi: " << point << endl;
    }

    int done;
    cin >> done;

    return res;
}