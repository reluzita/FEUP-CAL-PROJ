//
// Created by ineso on 5/4/2020.
//

#include "Dijkstra.h"

using namespace std;

queue<Vertex*> dijkstraShortestPath(Graph g, const int &origin, const int &dest) {
    g.initializeGraph();
    Vertex * vertex = g.findVertex(origin);
    vertex->setDist(0);
    MutablePriorityQueue<Vertex> q;
    q.insert(vertex);
    while(!q.empty()) {
        Vertex* temp = q.extractMin();
        for(Edge edge: temp->getAdj()) {
            Vertex * v = g.findVertex(edge.getDest());
            bool notFound = (v->getDist() == INT_MAX);
            if(v->getDist() > temp->getDist() + edge.getWeight()) {
                v->setDist(temp->getDist() + edge.getWeight());
                v->setPath( temp);
                if(notFound)
                    q.insert(v);
                else
                    q.decreaseKey(v);
            }
        }
    }

    Vertex* final = g.findVertex(dest);
    queue<Vertex*> path;
    path.push(final);
    Vertex* previous = final->getPath();
    path.push(previous);
    while(previous != vertex) {
        previous = previous->getPath();
        path.push(previous);
    }

    return path;
}

