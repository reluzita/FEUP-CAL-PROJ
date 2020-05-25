#include <iostream>
#include "UserInteraction/Menu.h"

using namespace std::chrono;
int main() {
    int res;
    ClientInfo info;
    cout << "Hi! Welcome to TourMateApp\n";
    cout <<"Let's go ahead and fill out the preferences form\n"<<endl;

    Graph<coord> gBi = readMap(true);
    Graph<coord> gUni = readMap(false);

    info.startGraph(gBi);
    info.setMeansOfTransportation('w');
    info.setPoi({"*"});
    info.setIdStart(30413);
    info.setIdEnd( 36869);
    info.setTimeAvailable(60);
    info.setCounterFactor(0.3);
    //res = mainMenu(&info, gBi, gUni);

    cout << "Running dfs for each node..." << endl;
    double sum = 0;
    for(Vertex<coord>* vertex: gUni.getVertexSet()) {
        gUni.dfs(vertex->getId());
        sum += (double)gUni.numOfVisitedNodes() / gUni.getVertexSet().size();
    }
    cout << "Average percentage of nodes reached: " << sum / gUni.getVertexSet().size() << endl;

/*
    info.setCounterFactor(1);
    milliseconds t0 = duration_cast<milliseconds >(system_clock::now().time_since_epoch());
    //OptimizedPath path = circularPath(gBi, &info);
    OptimizedPath path = magicGenerator(gBi, &info);
    milliseconds t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    cout << "Execution time processing all points: "<< t1.count()- t0.count()<< " milliseconds"<<endl;
    cout << "found path with " << gBi.distancePath(path.path) << "km and " << path.visitedId.size() << " points" << endl;

    info.setCounterFactor(0.5);
    t0 = duration_cast<milliseconds >(system_clock::now().time_since_epoch());
    //OptimizedPath path = circularPath(gBi, &info);
    path = magicGenerator(gBi, &info);
    t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    cout << "Execution time giving up when 50% of points fail: "<< t1.count()- t0.count()<< " milliseconds"<<endl;
    cout << "found path with " << gBi.distancePath(path.path) << "km and " << path.visitedId.size() << " points" << endl;

    info.setCounterFactor(0.3);
    t0 = duration_cast<milliseconds >(system_clock::now().time_since_epoch());
    //OptimizedPath path = circularPath(gBi, &info);
    path = magicGenerator(gBi, &info);
    t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    cout << "Execution time giving up when 30% of points fail: "<< t1.count()- t0.count()<< " milliseconds"<<endl;
    cout << "found path with " << gBi.distancePath(path.path) << "km and " << path.visitedId.size() << " points" << endl;

    info.setCounterFactor(0.10);
    t0 = duration_cast<milliseconds >(system_clock::now().time_since_epoch());
    //OptimizedPath path = circularPath(gBi, &info);
    path = magicGenerator(gBi, &info);
    t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    cout << "Execution time giving up when 10% of points fail: "<< t1.count()- t0.count()<< " milliseconds"<<endl;
    cout << "found path with " << gBi.distancePath(path.path) << "km and " << path.visitedId.size() << " points" << endl;

    info.setCounterFactor(0.05);
    t0 = duration_cast<milliseconds >(system_clock::now().time_since_epoch());
    //OptimizedPath path = circularPath(gBi, &info);
    path = magicGenerator(gBi, &info);
    t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    cout << "Execution time giving up when 5% of points fail: "<< t1.count()- t0.count()<< " milliseconds"<<endl;
    cout << "found path with " << gBi.distancePath(path.path) << "km and " << path.visitedId.size() << " points" << endl;
*/

    //getchar();
    //compareAllGrid();

    system("cls");
    cout <<"\nYou're exiting ...\n";
    cout <<"Thanks for using our app!\n";
    sleep(2);

    return 0;
}