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

/*
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

    vector<int> visit = bfsAll(g, orig);
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
    if(temp.empty()) return 0;
*/
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

/*
    string city = "Porto";
    Graph g = readMap(city, false, false);

    int orig = 1223751712, dest = 447867546;

    vector<Vertex*> visit = bfsAll(g, orig);
    vector<Vertex*> poi;
    //unsigned i = visit.size() - 1;
    for(Vertex* p: visit) {
        if(p->getType() != " ") {
            poi.push_back(p);
        }
    }

    queue<Vertex*> path = findPoiInPath(g, poi, orig, dest, 120, 'c');
    GraphViewer* gv = createPathViewer(g, path);
*/
    //GraphViewer* gv = createMapViewer(g);
    //showPOI(gv, poi);

    //queue<Vertex*> path = dijkstraShortestPath(g, orig, dest);

    /*
    int orig = 275996469, dest = 1338726423;
    queue<Vertex*> path = dijkstraShortestPath(g, orig, dest);
    double distance = distancePath(path);
    cout << "Time: " << minutesFromDistance(distance, 'w') << endl;

    vector<int> points = bfsAll(g, orig);

    vector<int> poi;
    for(int point: points) {
        Vertex* vertex = g.findVertex(point);
        if (vertex->getType() != " " && point != orig && point != dest)
            poi.push_back(vertex->getID());
    }

    //cout << "Going to find poi" << endl;
*/



    getchar();

    return 0;
}
