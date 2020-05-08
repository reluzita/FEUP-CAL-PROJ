#include "util.h"
using namespace std;


void menu_int_options(int &option, int omin, int nmax, string description){
    cout << endl << description;
    cin >> option;
    while (cin.fail() || option > nmax || option < omin) {
        if (cin.eof()) { //caso de ter sido introduzido o 'crtl-z'
            cin.clear();
            cout << "Invalid operation, please insert a valid one: ";
            cin >> option;
        }
        else { //qualquer outro caso que nao corresponda ao input pretendido
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid operation, please insert a valid one: ";
            cin >> option;
        }
    }
}


double distancePath(queue<Vertex*> path) {
    if(path.empty())
        return 0;
    double res = 0;
    Vertex * v1 = path.front();
    path.pop();
    Vertex* v2;
    while(!path.empty()) {
        v2 = path.front();
        path.pop();
        for(Edge e: v2->getAdj()) {
            if (e.getDest() == v1->getID()) {
                res += e.getWeight();
                break;
            }
        }
        v1 = v2;
    }
    return res;
}

