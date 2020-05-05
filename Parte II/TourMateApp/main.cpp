#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "Utils/ReadFiles.h"
#include "Algorithms/Dijkstra.h"
#include "Algorithms/DFS.h"
#include "Algorithms/BFS.h"
#include "Utils/GraphView.h"

int main() {
    Graph g = readMap("C:\\Users\\ineso\\OneDrive\\Documentos\\Ines-Universidade\\2 ano\\2 semestre\\CAL-Proj\\Parte II\\TourMateApp\\resources\\PortugalMaps\\PortugalMaps\\Fafe\\nodes_x_y_fafe.txt","C:\\Users\\ineso\\OneDrive\\Documentos\\Ines-Universidade\\2 ano\\2 semestre\\CAL-Proj\\Parte II\\TourMateApp\\resources\\PortugalMaps\\PortugalMaps\\Fafe\\edges_fafe.txt" );
    /*queue<Vertex*> q = dijkstraShortestPath(g, 1, 17);
    while(!q.empty()) {
        cout << q.front()->getID()<< endl;
        q.pop();
    }
    vector<int> v = bfs(g, 26018641, 701143519);
    if(v.empty())
        cout << "Fucked up" << endl;
    for(int i: v)
        cout << i << endl;*/

    GraphViewer *gv = createMapViewer(g);
    getchar();
    return 0;
}
