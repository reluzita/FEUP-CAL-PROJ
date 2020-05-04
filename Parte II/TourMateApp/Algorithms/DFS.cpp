//
// Created by ineso on 5/4/2020.
//

#include "DFS.h"

vector<int> dfs(Graph g, const int &source, const int &dest) {
    vector<int> res;
    for(Vertex* v: g.getVertexSet()) //fazer funcao em graph
        v->setVisited(false);
    Vertex* s = g.findVertex(source);
    Vertex* d = g.findVertex(dest);
    if(!dfsVisit(g, s, d, res))
        res.clear();
    return res;
}

bool dfsVisit(Graph g, Vertex *s, Vertex* d, vector<int> & res){
    s->setVisited(true);
    res.push_back(s->getID());
    for(Edge edge: s->getAdj()) {
        Vertex *dest = g.findVertex(edge.getDest());
        if(dest == d) {
            res.push_back(dest->getID());
            return true;
        }
        if (!(dest->isVisited()))
            return dfsVisit(g, dest, d, res);
    }
    return false;
}