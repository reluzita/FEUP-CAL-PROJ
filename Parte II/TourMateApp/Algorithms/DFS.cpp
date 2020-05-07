//
// Created by ineso on 5/4/2020.
//

#include "DFS.h"

using namespace std;

vector<int> dfs(Graph g, const int &source, const int &dest) {
    vector<int> res;
    g.initializeForSearch();
    Vertex* s = g.findVertex(source);
    Vertex* d = g.findVertex(dest);
    if(!dfsVisit(g, s, d, res))
        res.clear();
    return res;
}

bool dfsVisit(const Graph& g, Vertex *s, Vertex* d, vector<int> & res){
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

////TEMPORARIO!!!

vector<int> dfsTemp(Graph g) {
    vector<int> res;
    g.initializeForSearch();
    for (auto v : g.getVertexSet())
        if (! v->isVisited())
            dfsVisitTemp(g,v, res);
    return res;
}

void dfsVisitTemp(const Graph &g, Vertex*v, vector<int> & res) {
    v->setVisited(true);
    res.push_back(v->getID());
    cout << v->getID() << endl;
    for (auto & e : v->getAdj()) {
        auto w = g.findVertex(e.getDest());
        if ( ! w->isVisited())
            dfsVisitTemp(g, w, res);
    }
}