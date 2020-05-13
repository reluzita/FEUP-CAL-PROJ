#include "util.h"

void menu_int_options(int &option, int omin, int nmax, string description){
    cout << endl << description;
    cin >> option;
    while (cin.fail() || option > nmax || option < omin) {
        if (cin.eof()) { //caso de ter sido introduzido o 'crtl+z'
            cin.clear();
            option = -1;
            return;
        }
        else if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid operation, please insert a valid one: ";
            cin >> option;
        }
        else { //qualquer outro caso que nao corresponda ao input pretendido
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

int minutesFromDistance(double distance, string transportation) {
    if (transportation == "w") //walking
        return 5*distance*60;
    else if(transportation == "c") //car
        return 30*distance*60;
    else if (transportation == "p") //public
        return 20*distance*60;
    return 0;
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
            if (cin.fail()) {
                if(cin.eof()){
                    cin.clear();
                    aux = "-1";
                    return;
                }
                cin.clear();
                continue;
            }
        }
    }
}

vector<string> pairToString(vector<pair<double,double>> v){
    vector<string> res;
    string aux;
    for(auto p :v ){
        aux = to_string(p.first) + ", " + to_string(p.second);
        res.push_back(aux);
    }
    return res;
}