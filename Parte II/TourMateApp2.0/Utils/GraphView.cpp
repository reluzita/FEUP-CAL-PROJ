#include "GraphView.h"


GraphViewer* createMapViewer(const Graph<coord> &g) {
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
    gv->defineEdgeCurved(false);

    for(Vertex<coord>* vertex: g.getVertexSet()) {
        double y = (vertex->getInfo().second - g.getMinY()) / height;
        double x = (vertex->getInfo().first - g.getMinX()) / width;

        gv->addNode(vertex->getId(), (int) (x * graphWidth), (int) (y * graphHeight));
        gv->setVertexSize(vertex->getId(), 1);
    }

    gv->rearrange();
    return gv;
}

GraphViewer* createRealPOIPath(const Graph<coord> &g, queue<Vertex<coord>*> path, vector<int> visitedPoi) {

    double height = abs(g.getMaxY() - g.getMinY());
    double width = abs(g.getMaxX() - g.getMinX());

    int graphHeight, graphWidth;
    if (width / height < 2) {
        graphHeight = 600;
        graphWidth = (width * graphHeight) / height;
    } else {
        graphWidth = 1500;
        graphHeight = (height * graphWidth) / width;
    }

    auto *gv = new GraphViewer(graphWidth, graphHeight, false);
    gv->createWindow(graphWidth, graphHeight);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for (Vertex<coord> *vertex: g.getVertexSet()) {
        double y = abs(vertex->getInfo().second - g.getMinY()) / height;
        double x = abs(vertex->getInfo().first - g.getMinX()) / width;

        gv->addNode(vertex->getId(), (int) (x * graphWidth), (int) (y * graphHeight));
        gv->setVertexSize(vertex->getId(), 2);

    }

    int i = 0;
    gv->setVertexColor(path.front()->getId(), "yellow");
    while (!path.empty()) {
        Vertex<coord> *vertex = path.front();
        path.pop();

        if (!path.empty()) {
            gv->addEdge(i, path.front()->getId(), vertex->getId(), EdgeType::DIRECTED);
            i++;
        }

        if (path.empty())
            gv->setVertexColor(vertex->getId(), "green");
        else if (find(visitedPoi.begin(), visitedPoi.end(), vertex->getId()) != visitedPoi.end()) {
            string name = poiName(vertex);
            if (name != "") {
                gv->setVertexColor(vertex->getId(), "red");
                gv->setVertexLabel(vertex->getId(), name + to_string(vertex->getDuration()));
            }
        } else if (vertex->getType() != " ") {
            string name = poiName(vertex);
            if (name != "") {
                gv->setVertexColor(vertex->getId(), "pink");
                gv->setVertexLabel(vertex->getId(), name + to_string(vertex->getDuration()));
            }
        }
        gv->setVertexSize(vertex->getId(), 10);
    }

    gv->rearrange();
    return gv;
}



void showPath(GraphViewer* gv, queue<Vertex<coord>*> path, vector<int> visitedPoi) {
    int i = 0;
    gv->setVertexColor(path.front()->getId(), "yellow");
    while(!path.empty()) {
        Vertex<coord>* vertex = path.front();
        path.pop();

        if(!path.empty()) {
            gv->addEdge(i, path.front()->getId(), vertex->getId(), EdgeType::DIRECTED);
            i++;
        }

        if(path.empty())
            gv->setVertexColor(vertex->getId(), "green");
        else if(find(visitedPoi.begin(), visitedPoi.end(), vertex->getId()) != visitedPoi.end()) {
            gv->setVertexColor(vertex->getId(), "red");
            gv->setVertexLabel(vertex->getId(),vertex->getType() + "-" + to_string(vertex->getDuration()) + "m");
        } else if(vertex->getType() != " ") {
            gv->setVertexColor(vertex->getId(), "pink");
            gv->setVertexLabel(vertex->getId(),vertex->getType() + "-" + to_string(vertex->getDuration()) + "m");
        }
        gv->setVertexSize(vertex->getId(), 10);
    }

    gv->rearrange();
}

void showTestPath(GraphViewer* gv, queue<Vertex<coord>*> path) {
    int i = 0;
    gv->setVertexColor(path.front()->getId(), "yellow");
    gv->setVertexSize(path.front()->getId(), 10);
    gv->setVertexLabel(path.front()->getId(), "End");
    int s = 3;
    while(!path.empty()) {
        Vertex<coord>* vertex = path.front();
        path.pop();

        if(!path.empty()) {
            if(s == 0) {
                gv->addEdge(i, path.front()->getId(), vertex->getId(), EdgeType::DIRECTED);
                s = 3;
            }
            else {
                gv->addEdge(i, path.front()->getId(), vertex->getId(), EdgeType::UNDIRECTED);
                s--;
            }
            gv->setEdgeColor(i, "yellow");
            gv->setEdgeThickness(i, 10);
            i++;
        }

        if(path.empty()) {
            gv->setVertexColor(vertex->getId(), "green");
            gv->setVertexSize(vertex->getId(), 10);
            gv->setVertexLabel(vertex->getId(), "Start");
        }
    }

    gv->rearrange();
}

void showPOI(GraphViewer* gv, const vector<Vertex<coord>*>& points, const int &orig) {
    for(int i = 1; i < points.size(); i++) {
        gv->setVertexColor(points.at(i)->getId(), "red");
        gv->setVertexLabel(points.at(i)->getId(), points.at(i)->getType() +" - " + to_string(i+1));
        gv->setVertexSize(points.at(i)->getId(), 10);
    }
    if(orig != -1) {
        cout <<"orig: "<<points.at(0)->getId()<<endl;
        gv->setVertexColor(points.at(0)->getId(), "green");
        gv->setVertexSize(points.at(0)->getId(), 15);
        gv->setVertexLabel(points.at(0)->getId(), "You're here: " + to_string(1));//atençao a isto
    }
    gv->rearrange();
}



void showPathWithMetro(GraphViewer* gv, Graph<coord> g, queue<Vertex<coord>*> path1, queue<Vertex<coord>*> path2, vector<int> visitedPoi, MetroStation origStop, MetroStation endStop) {
    int i = 0;
    while (!path1.empty()) {
        Vertex<coord> *vertex = path1.front();
        path1.pop();

        if (!path1.empty()) {
            gv->addEdge(i, path1.front()->getId(), vertex->getId(), EdgeType::DIRECTED);
            i++;
        }
        if (path1.empty())
            gv->setVertexColor(vertex->getId(), "yellow");
        if (find(visitedPoi.begin(), visitedPoi.end(), vertex->getId()) != visitedPoi.end()) {
            gv->setVertexColor(vertex->getId(), "red");
            gv->setVertexLabel(vertex->getId(), vertex->getType() + "-" + to_string(vertex->getDuration()) + "m");
        } else if (vertex->getType() != " ") {
            gv->setVertexColor(vertex->getId(), "pink");
            gv->setVertexLabel(vertex->getId(), vertex->getType() + "-" + to_string(vertex->getDuration()) + "m");
        }
        gv->setVertexSize(vertex->getId(), 10);
    }

    int s = origStop.getID(), increment;
    if (origStop.getID() < endStop.getID())
        increment = 1;
    else
        increment = -1;
    while (s != endStop.getID()) {
        gv->addEdge(i, g.findStationID(s), g.findStationID(s + increment), EdgeType::DIRECTED);
        gv->setEdgeThickness(i, 5);
        gv->setEdgeColor(i, "yellow");
        s += increment;
        i++;
    }

    gv->setVertexColor(path2.front()->getId(), "green");
    while (!path2.empty()) {
        Vertex<coord> *vertex = path2.front();
        path2.pop();

        if (!path2.empty()) {
            gv->addEdge(i, path2.front()->getId(), vertex->getId(), EdgeType::DIRECTED);
            i++;
        } else if (find(visitedPoi.begin(), visitedPoi.end(), vertex->getId()) != visitedPoi.end()) {
            gv->setVertexColor(vertex->getId(), "red");
            gv->setVertexLabel(vertex->getId(), vertex->getType() + "-" + to_string(vertex->getDuration()) + "m");
        } else if (vertex->getType() != " ") {
            gv->setVertexColor(vertex->getId(), "pink");
            gv->setVertexLabel(vertex->getId(), vertex->getType() + "-" + to_string(vertex->getDuration()) + "m");
        }
        gv->setVertexSize(vertex->getId(), 10);
    }
    gv->rearrange();
}


string poiName(Vertex<coord> * v){
    vector<int> poiId = {1144, 41230, 28445, 14820, 24107, 27772, 18083, 41920, 3295, 35225, 17238};
    vector<string> poiName = {"Museu do Vinho do Porto", "Clerigos", "Palacio da Bolsa", "Ribeira", "Aliados", "Jardins do Palacio de Cristal", "Santa Catarina",
                              "Hard Club", "Livraria Lello", "Sao Bento", "Se do Porto"};

    for(int i = 0; i < poiId.size(); i++){
        if(v->getId() == poiId.at(i)){
            return poiName.at(i) + "-";
        }
    }

    return "";
}