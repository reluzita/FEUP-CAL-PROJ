#include "BFS.h"

using namespace std;

vector<Vertex*> bfs(Graph g, const int &source, const int &dest) {
    vector<Vertex*> res;
    if(source == dest)
        return res;
    queue<Vertex*> q;
    g.initializeForSearch();

    Vertex* s = g.findVertex(source);
    q.push(s);
    s->setVisited(true);

    while (!q.empty()) {
        Vertex* temp = q.front();
        q.pop();
        res.push_back(temp);
  
        for(Edge edge: temp->getAdj()) {
            Vertex *d = g.findVertex(edge.getDest());
            if(d == g.findVertex(dest)) {
                res.push_back(d);
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

vector<Vertex*> bfsAll(Graph g, const int & source) {
    vector<Vertex*> res;
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
        res.push_back(temp);
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
