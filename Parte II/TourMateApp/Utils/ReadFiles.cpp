//
// Created by ineso on 5/4/2020.
//

#include "ReadFiles.h"

using namespace std;

class <template T>
void readMap(string nodesfile, string edgesfile)
{
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    ifstream nodes, edges;
    nodes.open("../resources/mapa1/nos.txt");
    edges.open("../resources/mapa1/arestas.txt");

    string line;
    while(getline(nodes, line)) {
        int id, x, y;
        size_t pos = 0;
        pos = line.find(";");
        id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        pos = line.find(";");
        x = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        y = stoi(line);
        gv->addNode(id, x, y);
    }
    nodes.close();
    while(getline(edges, line)) {
        int id, n1, n2;
        size_t pos = 0;
        pos = line.find(";");
        id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        pos = line.find(";");
        n1 = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        n2 = stoi(line);
        gv->addEdge(id, n1, n2, EdgeType::UNDIRECTED);
    }
    edges.close();
    gv->rearrange();
}