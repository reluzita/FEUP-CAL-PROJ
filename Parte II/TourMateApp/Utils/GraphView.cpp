#include <queue>
#include "GraphView.h"

GraphViewer* createMapViewer(const Graph &g) {
    cout << g.getMinY()<< " " << g.getMaxY() << endl;
    cout << g.getMinX() << " " << g.getMaxY() << endl;

    double height = g.getMaxY() - g.getMinY();
    double width = g.getMaxX() - g.getMinX();

    cout << height << " " << width << endl;
    int graphHeight, graphWidth;
    if(width/height < 2) {
        graphHeight = 600;
        graphWidth = (width * graphHeight) / height;
    }
    else {
        graphWidth = 1500;
        graphHeight = (height * graphWidth) / width;
    }

    cout << graphHeight << " " << graphWidth << endl;

    auto *gv = new GraphViewer(graphWidth, graphHeight, false);
    gv->createWindow(graphWidth, graphHeight);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(Vertex* vertex: g.getVertexSet()) {
        double y = (vertex->getY() - g.getMinY())/height;
        double x = (vertex->getX() - g.getMinX())/width;

        gv->addNode(vertex->getID(), (int)(x*graphWidth), (int)(y*graphHeight));
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

GraphViewer* createPathViewer(const Graph &g, queue<Vertex*> path, vector<int> visitedPoi) {

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
        gv->setVertexSize(vertex->getID(), 2);
    }

    int i = 0;
    gv->setVertexColor(path.front()->getID(), "yellow");
    while(!path.empty()) {
        Vertex* vertex = path.front();
        path.pop();

        for(Edge edge: path.front()->getAdj()) {
            if (edge.getDest() == vertex->getID()) {
                //cout << vertex->getID() << " <- " << path.front()->getID() << endl;
                gv->addEdge(i, path.front()->getID(), vertex->getID(), EdgeType::DIRECTED);
                i++;
            }
        }
        if(path.empty())
            gv->setVertexColor(vertex->getID(), "green");
        else if(find(visitedPoi.begin(), visitedPoi.end(), vertex->getID()) != visitedPoi.end()) {
            gv->setVertexColor(vertex->getID(), "red");
            gv->setVertexLabel(vertex->getID(), to_string(vertex->getID()) + "-" + to_string(vertex->getDuration()));
        }
        gv->setVertexSize(vertex->getID(), 10);
    }

    gv->rearrange();
    return gv;
}
/*
GraphViewer* createPathViewer(const Graph &g, queue<Vertex*> path) {
    double maxX = INT_MIN, minX = INT_MAX, maxY = INT_MIN, minY = INT_MAX;

    queue<Vertex*> aux;
    while(!path.empty()) {
        Vertex* v = path.front();
        path.pop();
        aux.push(v);
        if(v->getX() > maxX) maxX = v->getX();
        if(v->getX() < minX) minX = v->getX();
        if(v->getY() > maxY) maxY = v->getY();
        if(v->getY() < minY) minY = v->getY();
    }
    cout << maxX << " " << minX << endl;
    cout << maxY << " " << minY << endl;

    double height = abs(maxY - minY);
    double width = abs(maxX - minX);

    cout << height << " " << width << endl;
    int graphHeight, graphWidth;
    if(width/height < 2) {
        graphHeight = 800;
        graphWidth = (width * graphHeight) / height;
    }
    else {
        graphWidth = 1800;
        graphHeight = (height * graphWidth) / width;
    }

    cout << graphHeight << " " << graphWidth << endl;

    auto *gv = new GraphViewer(graphWidth, graphHeight, false);
    gv->createWindow(graphWidth, graphHeight);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(Vertex* vertex: g.getVertexSet()) {
        if(vertex->getX() >= minX && vertex->getX() <= maxX && vertex->getY() >= minY && vertex->getY() <= maxY) {
            double y = abs(vertex->getY() - g.getMinY()) / height;
            double x = abs(vertex->getX() - g.getMinX()) / width;

            gv->addNode(vertex->getID(), (int) (x * graphWidth), (int) (y * graphHeight));
            gv->setVertexSize(vertex->getID(), 5);
        }
    }

    int i = 0;
    while(!aux.empty()) {
        Vertex* vertex = aux.front();
        aux.pop();

        if(vertex->getPath() != nullptr) {
            cout << "found one" << endl;
            gv->addEdge(i, vertex->getID(), (vertex->getPath())->getID(), EdgeType::UNDIRECTED);
            i++;
        }
        gv->setVertexColor(vertex->getID(), "red");
        gv->setVertexSize(vertex->getID(), 10);
    }

    gv->rearrange();
    return gv;
}
*/
void showPOI(GraphViewer* gv, const vector<int>& points) {
    for(int p: points) {
        gv->setVertexColor(p, "red");
        gv->setVertexLabel(p, to_string(p));
    }

    gv->rearrange();
}

