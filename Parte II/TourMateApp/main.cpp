#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>

#include "Utils/ReadFiles.h"
#include "Algorithms/Dijkstra.h"
#include "Algorithms/DFS.h"
#include "Algorithms/BFS.h"
#include "Algorithms/AStar.h"
#include "Utils/GraphView.h"
#include "ClientInteraction/menu.h"

using namespace std::chrono;

double distance(Graph g, int orig, int dest) {
    Vertex* o = g.findVertex(orig);
    Vertex* d = g.findVertex(dest);

    return sqrt((o->getX() - d->getX())*(o->getX() - d->getX()) + (o->getY() - d->getY())*(o->getY() - d->getY()));
}

int main() {
   /* string city = "Coimbra";
    Graph g = readMap(city);
    vector<int> pointsOfInterest = readTags(g, city);

    cout << "map is read" << endl;

    int orig = 206155870, dest;


    vector<int> visit = dfsTemp(g, orig);
    int i = visit.size() - 1;
    while(true) {
        if(g.findVertex(visit[i])->getType() != " ") {
            dest = visit[i];
            break;
        }
        i--;
    }

    cout << orig << " " << dest << endl;
    vector<int> temp = dfs(g, orig, dest);
    if(temp.empty()) return 0;*/

    //vector<int> allPoints = bfsAll(g, orig);


    //int dest = orig;
    /*
    for(int p: allPoints) {
        Vertex* vertex = g.findVertex(p);
        cout <<  p << " " << vertex->getType() << endl;
    }
*/
    //GraphViewer *gv = createMapViewer(g);
    //showPOI(gv, pointsOfInterest);

    //cout << "going to dijkstra" << endl;

   /* milliseconds t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    queue<Vertex*> qStar = aStar(g, orig, dest);
    milliseconds t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());


    milliseconds t2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    queue<Vertex*> qDijkstra = dijkstraShortestPath(g, orig, dest);
    milliseconds t3 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    cout << "A*: " << distancePath(qStar) << endl;
    cout << "Execution time: " << t1.count() - t0.count() << endl;

    cout << "D: " << distancePath(qDijkstra) << endl;
    cout << "Execution time: " << t3.count() - t2.count() << endl;
    //cout << "D: " << distancePath(qDijkstra) << endl;

    GraphViewer *gv = createPathViewer(g, qStar);
    getchar();*/

    //devia ir para  main

    int res;
    cout << "Hi! Welcome to TourMateApp\n";
    cout <<"Let's go ahead and fill out the preferences form\n"<<endl;
    do{
        res = firstQuestion();
    }
    while(res!=-1 && res == 0);
    system("cls");
    cout <<"\nYou're exiting ...\n";
    cout <<"Thanks for using our app!\n";
    Sleep(2000);

    return 0;
}


