//
// Created by ineso on 5/4/2020.
//

#include "BFS.h"

using namespace std;

vector<int> bfs(Graph g, const int &source, const int &dest) {
    vector<int> res;
    queue<Vertex*> q;
    g.initializeForSearch();

    Vertex* s = g.findVertex(source);
    q.push(s);
    s->setVisited(true);

    while (!q.empty()) {
        Vertex* temp = q.front();
        q.pop();
        res.push_back(temp->getID());

        for(Edge edge: temp->getAdj()) {
            Vertex *d = g.findVertex(edge.getDest());
            if(d == g.findVertex(dest)) {
                res.push_back(d->getID());
                return res;
            }
            if (!d->isVisited()) {
                q.push(d);
                d->setVisited(true);
            }
        }
    }
    res.clear();
    return res;
}

vector<int> invertedBfs(Graph g, const int &source, const int &dest) {
    vector<int> res;
    queue<Vertex*> q;
    g.initializeForBirDir();

    Vertex* s = g.findVertex(source);
    q.push(s);
    s->setInvertedVisited(true);

    while (!q.empty()) {
        Vertex* temp = q.front();
        q.pop();
        res.push_back(temp->getID());

        for(Edge edge: temp->getAdj()) {
            Vertex *d = g.findVertex(edge.getDest());
            if(d == g.findVertex(dest)) {
                res.push_back(d->getID());
                return res;
            }
            if (!d->isInvertedVisited()) {
                q.push(d);
                d->setInvertedVisited(true);
            }
        }
    }
    res.clear();
    return res;
}
vector<int> bfsAll(Graph g, const int &source) {
    vector<int> res;
    queue<Vertex*> q;
    g.initializeForSearch();

    Vertex* s = g.findVertex(source);
    if(s == nullptr)
        return res;
    q.push(s);
    s->setVisited(true);

    while (!q.empty()) {
        Vertex* temp = q.front();
        q.pop();
        res.push_back(temp->getID());
        cout << temp->getID() << endl;
        for(Edge edge: temp->getAdj()) {
            Vertex *d = g.findVertex(edge.getDest());
            if (!d->isVisited()) {
                q.push(d);
                d->setVisited(true);
            }
        }
    }
    return res;
}
