//
// Created by ineso on 5/5/2020.
//


#include "GraphView.h"

GraphViewer* createMapViewer(const Graph &g) {
    double height = g.getMaxY() - g.getMinY();
    double width = g.getMaxX() - g.getMinX();
    int graphSize = 1000;

    GraphViewer *gv = new GraphViewer(graphSize, graphSize, false);
    gv->createWindow(graphSize, graphSize);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(Vertex* vertex: g.getVertexSet()) {
        double y = (vertex->getY() - g.getMinY())/height;
        double x = (vertex->getX() - g.getMinX())/width;

        cout << x << " - " << y << endl;
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