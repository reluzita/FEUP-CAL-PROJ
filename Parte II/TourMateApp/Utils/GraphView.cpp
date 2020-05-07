//
// Created by ineso on 5/5/2020.
//


#include <queue>
#include "GraphView.h"

GraphViewer* createMapViewer(const Graph &g) {
    cout << g.getMinY()<< " " << g.getMaxY() << endl;
    cout << g.getMinX() << " " << g.getMaxY() << endl;

    double height = g.getMaxY() - g.getMinY();
    double width = g.getMaxX() - g.getMinX();

    cout << height << " " << width << endl;
    int graphSize = 2000;

    auto *gv = new GraphViewer(graphSize, graphSize, false);
    gv->createWindow(graphSize, graphSize);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(Vertex* vertex: g.getVertexSet()) {
        double y = (vertex->getY() - g.getMinY())/height;
        double x = (vertex->getX() - g.getMinX())/width;

        gv->addNode(vertex->getID(), (int)(x*graphSize), (int)(y*1341));
        gv->setVertexSize(vertex->getID(), 5);
    }
    int id = 0;
    for(Vertex* vertex: g.getVertexSet()) {
        for(Edge edge: vertex->getAdj()) {
            gv->addEdge(id, vertex->getID(), edge.getDest(), EdgeType::UNDIRECTED);
            id++;
        }
    }
    gv->rearrange();
    return gv;
}
GraphViewer* createPathViewer(const Graph &g, queue<Vertex*> path) {

    double height = abs(g.getMaxY() - g.getMinY());
    double width = abs(g.getMaxX() - g.getMinX());

    cout << height << " " << width << endl;
    int graphSize = 1130;

    auto *gv = new GraphViewer(graphSize, graphSize, false);
    gv->createWindow(graphSize, graphSize);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(Vertex* vertex: g.getVertexSet()) {
        double y = abs(vertex->getY() - g.getMinY())/height;
        double x = abs(vertex->getX() - g.getMinX())/width;

        gv->addNode(vertex->getID(), (int)(x*graphSize), (int)(y*524));
        gv->setVertexSize(vertex->getID(), 5);
    }

    int i = 0;
    while(!path.empty()) {
        Vertex* vertex = path.front();
        path.pop();

        if(vertex->getPath() != nullptr) {
            gv->addEdge(i, vertex->getID(), (vertex->getPath())->getID(), EdgeType::UNDIRECTED);
            i++;
        }
        gv->setVertexColor(vertex->getID(), "red");
        gv->setVertexSize(vertex->getID(), 10);
    }

    gv->rearrange();
    return gv;
}

void showPOI(GraphViewer* gv, vector<int> points) {
    for(int p: points) {
        gv->setVertexColor(p, "red");
        gv->setVertexLabel(p, to_string(p));
    }
    gv->rearrange();
}

