#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "Utils/ReadFiles.h"
#include "Algorithms/Dijkstra.h"
#include "Algorithms/DFS.h"
#include "Algorithms/BFS.h"

int main() {
    Graph g = readMap(R"(C:\Users\ineso\OneDrive\Documentos\Ines-Universidade\2 ano\2 semestre\CAL-Proj\Parte II\TourMateApp\resources\GridGraphs\8x8\nodes.txt)",R"(C:\Users\ineso\OneDrive\Documentos\Ines-Universidade\2 ano\2 semestre\CAL-Proj\Parte II\TourMateApp\resources\GridGraphs\8x8\edges.txt)" );
    /*queue<Vertex*> q = dijkstraShortestPath(g, 1, 17);
    while(!q.empty()) {
        cout << q.front()->getID()<< endl;
        q.pop();
    }*/
    vector<int> v = bfs(g, 0, 80);
    if(v.empty())
        cout << "Fucked up" << endl;
    for(int i: v)
        cout << i << endl;
    return 0;
}
