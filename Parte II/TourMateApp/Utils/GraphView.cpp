//
// Created by ineso on 5/5/2020.
//


#include <queue>
#include "GraphView.h"

GraphViewer* createMapViewer(const Graph &g) {
    double height = g.getMaxY() - g.getMinY();
    double width = g.getMaxX() - g.getMinX();
    int graphSize = 1000;

    auto *gv = new GraphViewer(graphSize, graphSize, false);
    gv->createWindow(graphSize, graphSize);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(Vertex* vertex: g.getVertexSet()) {
        double y = (vertex->getY() - g.getMinY())/height;
        double x = (vertex->getX() - g.getMinX())/width;

        gv->addNode(vertex->getID(), (int)(x*graphSize), (int)(y*graphSize));
        gv->setVertexSize(vertex->getID(), 5);
    }
    int id = 0;
    for(Vertex* vertex: g.getVertexSet()) {
        for(Edge edge: vertex->getAdj()) {
            gv->addEdge(id, vertex->getID(), edge.getDest(), edge.getWeight());
            id++;
        }
    }
    gv->rearrange();
    return gv;
}
GraphViewer* createPathViewer(const Graph &g, queue<Vertex*> path) {
    double height = g.getMaxY() - g.getMinY();
    double width = g.getMaxX() - g.getMinX();
    int graphSize = 1000;

    auto *gv = new GraphViewer(graphSize, graphSize, false);
    gv->createWindow(graphSize, graphSize);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    while(!path.empty()) {
        Vertex* vertex = path.front();
        path.pop();

        double y = (vertex->getY() - g.getMinY())/height;
        double x = (vertex->getX() - g.getMinX())/width;

        gv->addNode(vertex->getID(), (int)(x*graphSize), (int)(y*graphSize));
        gv->setVertexSize(vertex->getID(), 5);
    }
    /*
    int id = 0;
    for(Vertex* vertex: g.getVertexSet()) {
        for(Edge edge: vertex->getAdj()) {
            gv->addEdge(id, vertex->getID(), edge.getDest(), edge.getWeight());
            id++;
        }
    }*/
    gv->rearrange();
    return gv;
}

void showPath(GraphViewer* gv, queue<Vertex*> path) {

    while(!path.empty()) {
        Vertex* v = path.front();
        path.pop();
        gv->setVertexColor(v->getID(), "red");
    }

    gv->rearrange();
}

