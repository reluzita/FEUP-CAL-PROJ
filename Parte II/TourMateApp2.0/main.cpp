#include <iostream>
#include "UserInteraction/Menu.h"

using namespace std::chrono;
int main() {
    int res;
    ClientInfo info, info2;
    cout << "Hi! Welcome to TourMateApp\n";
    cout <<"Let's go ahead and fill out the preferences form\n"<<endl;

    Graph<coord> gBi = readMap(true);
    Graph<coord> gUni = readMap(false);

    info.startGraph(gBi);
    info.setMeansOfTransportation('w');
    info.setPoi({"picnic_site"});
    info.setIdStart(231);
    info.setIdEnd( 38);
    info.setTimeAvailable(60);
    info.setCounterFactor(0.3);
    //res = mainMenu(&info, gBi, gUni);

    //magicGenerator(graph, &info);

    milliseconds t0 = duration_cast<milliseconds >(system_clock::now().time_since_epoch());
    //OptimizedPath path = circularPath(gBi, &info);
    OptimizedPath path = magicGenerator(gBi, &info);
    milliseconds t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    cout << "First execution time: "<< t1.count()- t0.count()<< " milliseconds\t d = " << gBi.distancePath(path.path) << endl;

    /*GraphViewer* gv = createMapViewer(gBi);
    showPath(gv, path.path, path.visitedId);

    info2.startGraph(gUni);
    info2.setMeansOfTransportation('c');
    info2.setPoi({"picnic_site"});
    info2.setIdStart(17238);
    info2.setIdEnd( 17001);
    info2.setTimeAvailable(60);
    info2.setCounterFactor(0.3);

    t0 = duration_cast<milliseconds >(system_clock::now().time_since_epoch());
    //OptimizedPath path = circularPath(gBi, &info);
    path = magicGenerator(gUni, &info2);
    t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    cout << "Second execution time: "<< t1.count()- t0.count()<< " milliseconds\t d = " << gUni.distancePath(path.path) << endl;*/

    //GraphViewer* gv2 = createMapViewer(gUni);
    //showPath(gv2, path.path, path.visitedId);


    /*Graph<coord> graph = readMap(true);
    vector<int> ola = readTags(graph);
    vector<Vertex<coord>*> v;

    for(int i = 0; i < ola.size(); i++){
        v.push_back(graph.findVertex(ola.at(i)));
    }

    GraphViewer* gv = createMapViewer(graph);
    showPOI(gv, v, 123);*/

    getchar();
    //compareAllGrid();

    system("cls");
    cout <<"\nYou're exiting ...\n";
    cout <<"Thanks for using our app!\n";
    sleep(2);

    return 0;
}