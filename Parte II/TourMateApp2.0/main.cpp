#include <iostream>
#include "UserInteraction/Menu.h"

int main() {
    int res;
    ClientInfo info;
    cout << "Hi! Welcome to TourMateApp\n";
    cout <<"Let's go ahead and fill out the preferences form\n"<<endl;

    Graph<coord> gBi = readMap(true);
    Graph<coord> gUni = readMap(false);
    res = mainMenu(&info, gBi, gUni);

    //magicGenerator(graph, &info);
    system("cls");
    cout <<"\nYou're exiting ...\n";
    cout <<"Thanks for using our app!\n";
    sleep(2);

    return 0;
}