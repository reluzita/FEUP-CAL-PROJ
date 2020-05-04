//
// Created by ineso on 5/4/2020.
//

#include "BFS.h"

using namespace std;

vector<int> bfs(Graph g, const int &source, const int &dest) {
    vector<int> res;
    queue<Vertex*> q;
    for(Vertex* v: g.getVertexSet()) //fazer funcao em graph
        v->setVisited(false);

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
    return res;
}
