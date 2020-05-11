#include "util.h"
using namespace std;


int menu_int_options(int &option, int omin, int nmax, string description){
    cout << endl << description;
    cin >> option;
    while (cin.fail() || option > nmax || option < omin) {
        if (cin.eof()) { //caso de ter sido introduzido o 'crtl-z'
            cin.clear();
            //cout << "Invalid operation, please insert a valid one: ";
            //cin >> option;
            option = -1;
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

void trim(string &str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}


void verification_int(string &aux) {
    string numbers = "0123456789";

    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            trim(aux);
            isValid = (aux.find_last_not_of(numbers) == string::npos);
        }
        if (!isValid) {
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }
}

