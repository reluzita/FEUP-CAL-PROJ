#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>

#include "ClientInteraction/menu.h"

using namespace std::chrono;

int main() {

    //FOR TESTING MENUS//

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


    //FOR TESTING MAGIC GENERATOR//
/*
    string city = "Porto";
    Graph g = readMap(city, true, false);

    //int orig = 1223751712, dest = 447867546;
    int orig = 90380348;

    vector<Vertex*> visit = bfsAll(g, orig);
    int dest = visit[visit.size()/2]->getID();
    vector<Vertex*> poi;
    int i = 0;
    for(Vertex* p: visit) {
        if(p->getType() != " ") {
            poi.push_back(p);
            i++;
        }
        if(i > 30)
            break;
    }

    //cout << poi.size() << endl;

   // g.initializeForFindPOI();
    OptimizedPath optPath = findPoiInPath(g, poi, orig, dest, 200, 'w');
    queue<Vertex*> path = optPath.path;
    GraphViewer* gv = createPathViewer(g, path, optPath.visitedId);
    cout << endl << hasTime(path, 'w', 200) << endl;

    //GraphViewer* gv = createMapViewer(g);
    //showPOI(gv, poi);

    getchar();
*/

    return 0;
}

// CONFUSING THINGS //

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