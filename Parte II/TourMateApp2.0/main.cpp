#include <iostream>
#include "UserInteraction/Menu.h"

using namespace std::chrono;
int main() {
    int res;
    ClientInfo info;
    cout << "Hi! Welcome to TourMateApp\n";
    cout <<"Let's go ahead and fill out the preferences form\n"<<endl;

    Graph<coord> gBi = readMap(true);
    //Graph<coord> gUni = readMap(false);

    info.startGraph(gBi);
    info.setMeansOfTransportation('w');
    info.setIdStart(30413);
    info.setIdEnd( 36869);
    info.setTimeAvailable(30);
    //res = mainMenu(&info, gBi, gUni);

    //magicGenerator(graph, &info);

    milliseconds t0 = duration_cast<milliseconds >(system_clock::now().time_since_epoch());
    //OptimizedPath path = circularPath(gBi, &info);
    OptimizedPath path = magicGenerator(gBi, &info);
    milliseconds t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    cout << "AStar execution time: "<< t1.count()- t0.count()<< " milliseconds"<<endl;

    GraphViewer* gv = createMapViewer(gBi);
    showPath(gv, path.path, path.visitedId);

    getchar();
    //compareAllSmallPath(gBi);

    system("cls");
    cout <<"\nYou're exiting ...\n";
    cout <<"Thanks for using our app!\n";
    sleep(2);

    return 0;
}