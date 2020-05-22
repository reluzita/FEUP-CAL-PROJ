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
/*
    int res;
    ClientInfo info;
    cout << "Hi! Welcome to TourMateApp\n";
    cout <<"Let's go ahead and fill out the preferences form\n"<<endl;

    Graph gBi = readMap(true);
    Graph gUni = readMap(false);
    res = mainMenu(&info, gBi, gUni);

    //magicGenerator(graph, &info);
    system("cls");
    cout <<"\nYou're exiting ...\n";
    cout <<"Thanks for using our app!\n";
    sleep(2);
*/

    //FOR TESTING MAGIC GENERATOR//

    /*
    Graph g = readMap(true);

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

    //FOR TESTING GRAPHVIEWER///
    Graph g = readMap(false);

    ClientInfo info;

    info.setIdStart(26999);
    info.setIdEnd(24112);
    info.setTimeAvailable(60);
    vector<string> types = {"information"};
    info.setPoi(types);
    info.setMeansOfTransportation('w');

    vector<Vertex*> points = bfsAllPOI(g, info.getIdStart(), info.getPoi(), info.getTimeAvailable());

    cout << "100%" << endl;
    milliseconds t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    OptimizedPath op = circularPath(g, &info, 1);
    milliseconds t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    double distance = distancePath(op.path);
    cout << "Distance = " << distance << " Num POIs: " << op.visitedId.size() << endl;
    int dur = minutesFromDistance(distance, 'w');
    cout << "Duration = " << dur << endl;
    cout << "Execution time: " << t1.count() - t0.count() << endl << endl;

    cout << "50%" << endl;
    t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    op = circularPath(g, &info, 0.5);
    t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());


    distance = distancePath(op.path);
    cout << "Distance = " << distance << " Num POIs: " << op.visitedId.size() << endl;
    dur = minutesFromDistance(distance, 'w');
    cout << "Duration = " << dur << endl;
    cout << "Execution time: " << t1.count() - t0.count() << endl << endl;

    cout << "30%" << endl;
    t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    op = circularPath(g, &info, 0.3);
    t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());


    distance = distancePath(op.path);
    cout << "Distance = " << distance << " Num POIs: " << op.visitedId.size() << endl;
    dur = minutesFromDistance(distance, 'w');
    cout << "Duration = " << dur << endl;
    cout << "Execution time: " << t1.count() - t0.count() << endl << endl;

    cout << "25%" << endl;
    t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    op = circularPath(g, &info, 0.25);
    t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());


    distance = distancePath(op.path);
    cout << "Distance = " << distance << " Num POIs: " << op.visitedId.size()<< endl;
    dur = minutesFromDistance(distance, 'w');
    cout << "Duration = " << dur << endl;
    cout << "Execution time: " << t1.count() - t0.count() << endl << endl;

    cout << "10%" << endl;
    t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    op = circularPath(g, &info, 0.1);
    t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());


    distance = distancePath(op.path);
    cout << "Distance = " << distance << " Num POIs: " << op.visitedId.size()<< endl;
    dur = minutesFromDistance(distance, 'w');
    cout << "Duration = " << dur << endl;
    cout << "Execution time: " << t1.count() - t0.count() << endl << endl;

    GraphViewer* gv = createPathViewer(g, op.path, op.visitedId);


/*
    int stopOrig = 1, stopEnd = 8;
    queue<Vertex *> path = dijkstraShortestPath(g, 26999, 1969);
    queue<Vertex *> path2 = dijkstraShortestPath(g, 27817, 24112);


    metroPathGenerator(g, &info);*/
/*
    if(bfs(g, 27772, 28445).empty()) {
        cout << "No path! " << endl;
        return 0;
    }
//18083
    vector<Vertex*> poi = {g.findVertex(1144), g.findVertex(41230), g.findVertex(14820), g.findVertex(24107), g.findVertex(18083), g.findVertex(41920), g.findVertex(3295), g.findVertex(35225), g.findVertex(17238)};
    OptimizedPath p = findPoiInPath(g, poi, 27772, 28445, 200, 'w');

    double distance = distancePath(p.path);
    cout << endl << "Distance = " << distance << endl;
    int dur = minutesFromDistance(distance, 'w');
    cout << endl << "Duration = " << dur << endl;

    GraphViewer* gv = createRealPOIPath(g, p.path, p.visitedId);*/

    //showPathWithMetro(gv, path, path2, v, g, stopOrig, stopEnd);

    getchar();
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