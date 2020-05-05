//
// Created by ineso on 5/4/2020.
//

#include "ReadFiles.h"

using namespace std;

Graph readMap(const string &nodesfile, const string &edgesfile)
{

    Graph graph;

    ifstream nodes, edges;
    nodes.open(nodesfile);
    edges.open(edgesfile);

    string line;
    getline(nodes, line);
    int numNodes = stoi(line);
    for (int i = 0; i < numNodes; i++) {
        getline(nodes, line);
        int id, x, y;
        size_t pos = line.find(',');
        id = stoi(line.substr(1, pos));
        line.erase(0, pos + 2);
        pos = line.find(',');
        x = stoi(line.substr(0, pos));
        line.erase(0, pos + 2);
        pos = line.find(')');
        y = stoi(line.substr(0, pos));
        graph.addVertex(id, x, y);
    }
    nodes.close();

    getline(edges, line);
    int numEdges = stoi(line);
    for (int i = 0; i < numEdges; i++) {
        getline(edges, line);
        int n1, n2;
        size_t pos = line.find(',');
        n1 = stoi(line.substr(1, pos));
        line.erase(0, pos + 2);
        pos = line.find(')');
        n2 = stoi(line.substr(0, pos));

        Vertex* v1 = graph.findVertex(n1);
        Vertex* v2 = graph.findVertex(n2);
        double weight = sqrt((v2->getX() - v1->getX())*(v2->getX() - v1->getX()) + (v2->getY() - v1->getY())*(v2->getY() - v1->getY()));
        graph.addEdge(n1, n2, weight);
    }
    edges.close();
    return graph;
}