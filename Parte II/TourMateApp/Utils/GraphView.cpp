#include <queue>
#include "GraphView.h"

GraphViewer* createMapViewer(const Graph &g) {
    double height = g.getMaxY() - g.getMinY();
    double width = g.getMaxX() - g.getMinX();

    int graphHeight, graphWidth;
    if(width/height < 2) {
        graphHeight = 600;
        graphWidth = (width * graphHeight) / height;
    }
    else {
        graphWidth = 1500;
        graphHeight = (height * graphWidth) / width;
    }

    auto *gv = new GraphViewer(graphWidth, graphHeight, false);
    gv->createWindow(graphWidth, graphHeight);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(Vertex* vertex: g.getVertexSet()) {
        if(vertex->getStrong()){
            double y = (vertex->getY() - g.getMinY())/height;
            double x = (vertex->getX() - g.getMinX())/width;

            gv->addNode(vertex->getID(), (int)(x*graphWidth), (int)(y*graphHeight));
            gv->setVertexSize(vertex->getID(), 1);
        }
    }
    gv->rearrange();
    return gv;
}

GraphViewer* createPathViewer(const Graph &g, queue<Vertex*> path, vector<int> visitedPoi) {

    double height = abs(g.getMaxY() - g.getMinY());
    double width = abs(g.getMaxX() - g.getMinX());

    int graphHeight, graphWidth;
    if(width/height < 2) {
        graphHeight = 600;
        graphWidth = (width * graphHeight) / height;
    }
    else {
        graphWidth = 1500;
        graphHeight = (height * graphWidth) / width;
    }

    auto *gv = new GraphViewer(graphWidth, graphHeight, false);
    gv->createWindow(graphWidth, graphHeight);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(Vertex* vertex: g.getVertexSet()) {
        if(vertex->getStrong()){
            double y = abs(vertex->getY() - g.getMinY())/height;
            double x = abs(vertex->getX() - g.getMinX())/width;

            gv->addNode(vertex->getID(), (int)(x*graphWidth), (int)(y*graphHeight));
            gv->setVertexSize(vertex->getID(), 2);
        }
    }

    int i = 0;
    gv->setVertexColor(path.front()->getID(), "yellow");
    while(!path.empty()) {
        Vertex* vertex = path.front();
        path.pop();

        for(Edge edge: path.front()->getAdj()) {
            if (edge.getDest() == vertex->getID() && edge.isStrong()) {
                gv->addEdge(i, path.front()->getID(), vertex->getID(), EdgeType::DIRECTED);
                i++;
            }
        }
        if(path.empty())
            gv->setVertexColor(vertex->getID(), "green");
        else if(find(visitedPoi.begin(), visitedPoi.end(), vertex->getID()) != visitedPoi.end()) {
            gv->setVertexColor(vertex->getID(), "red");
            gv->setVertexLabel(vertex->getID(), /*to_string(vertex->getID())*/vertex->getType() + "-" + to_string(vertex->getDuration()));
        } else if(vertex->getType() != " ") {
            gv->setVertexColor(vertex->getID(), "pink");
            gv->setVertexLabel(vertex->getID(), /*to_string(vertex->getID())*/vertex->getType() + "-" + to_string(vertex->getDuration()));
        }
        gv->setVertexSize(vertex->getID(), 10);
    }

    gv->rearrange();
    return gv;
}

void showPOI(GraphViewer* gv, const vector<Vertex*>& points) {
    for(int i = 0; i < points.size(); i++) {
        gv->setVertexColor(points.at(i)->getID(), "red");
        gv->setVertexLabel(points.at(i)->getID(), points.at(i)->getType() +" - " + to_string(i+1));
        gv->setVertexSize(points.at(i)->getID(), 10);
    }

    gv->rearrange();
}

