//
// Created by ineso on 5/4/2020.
//

#include "ReadFiles.h"

using namespace std;

Graph readMap(string nodesfile, string edgesfile)
{
    /*
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
*/
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
        size_t pos = 1;
        size_t next = line.find(",");
        id = stoi(line.substr(pos, next));
        line.erase(0, next + 2);
        pos = line.find(",");
        x = stoi(line.substr(0, pos));
        line.erase(0, pos + 2);
        pos = line.find(")");
        y = stoi(line.substr(0, pos));
        graph.addVertex(id, x, y);
    }
    nodes.close();

    getline(edges, line);
    int numEdges = stoi(line);
    for (int i = 0; i < numEdges; i++) {
        getline(edges, line);
        int n1, n2;
        size_t pos = 1;
        size_t next = line.find(",");
        n1 = stoi(line.substr(pos, next));
        line.erase(0, next + 2);
        pos = line.find(")");
        n2 = stoi(line.substr(0, pos));
        graph.addEdge(n1, n2, 1);
    }
    edges.close();
    return graph;
}