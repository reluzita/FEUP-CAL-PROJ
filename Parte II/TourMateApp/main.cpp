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

double distance(Graph g, int orig, int dest) {
    Vertex* o = g.findVertex(orig);
    Vertex* d = g.findVertex(dest);

    return sqrt((o->getX() - d->getX())*(o->getX() - d->getX()) + (o->getY() - d->getY())*(o->getY() - d->getY()));
}

int main() {
    Graph g = readMap("Lisboa");

    cout << "map is read" << endl;
    int orig = 1117958148;
    vector<int> allPoints = bfsAll(g, orig);
    vector<int> pointsOfInterest = readTags(g, "../resources/TagExamples/Lisboa/t03_tags_lisboa.txt");

    int dest = orig;
    for(int p: allPoints) {
        if(find(pointsOfInterest.begin(), pointsOfInterest.end(), p) != pointsOfInterest.end() && p!=orig) {
            if(distance(g, orig, p) > distance(g, orig, dest))
                dest = p;
            break;
        }
    }
    cout << "going to dijkstra" << endl;
    queue<Vertex*> q = dijkstraShortestPath(g, orig, dest);

    GraphViewer *gv = createPathViewer(g, q);
    getchar();
    return 0;
}


