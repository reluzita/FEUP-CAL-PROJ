#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>

#include "ClientInteraction/menu2.h"

using namespace std::chrono;

double distance(Graph g, int orig, int dest) {
    Vertex* o = g.findVertex(orig);
    Vertex* d = g.findVertex(dest);

    return sqrt((o->getX() - d->getX())*(o->getX() - d->getX()) + (o->getY() - d->getY())*(o->getY() - d->getY()));
}

int main() {
    /*
    string city = "Porto";
    Graph g = readMap(city, true, true);

    cout << "Max lat: " << g.getMaxLat() << endl;
    cout << "Min lat: " << g.getMinLat() << endl;
    cout << "Max lon: " << g.getMaxLon() << endl;
    cout << "Min lon: " << g.getMinLon() << endl;

    readBusFile(g);
    readMetroFile(g);
*/
    //vector<int> pointsOfInterest = readTags(g, city);

    //cout << "map is read" << endl;

    /*
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
    ClientInfo info;
    cout << "Hi! Welcome to TourMateApp\n";
    cout <<"Let's go ahead and fill out the preferences form\n"<<endl;
    
    res = mainMenu(&info);

    //magicGenerator(graph, &info);
    system("cls");
    cout <<"\nYou're exiting ...\n";
    cout <<"Thanks for using our app!\n";
    sleep(2);

    return 0;
}
