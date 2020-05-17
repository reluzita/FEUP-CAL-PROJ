#include "util.h"

void menu_int_options(int &option, int omin, int nmax, const string& description){
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

int displayMenu(const string& title, vector<string>options, const string& description){
    int option = -1;
    system("cls");

    cout << "---------------- "<<title <<" ----------------\n\n";
    for(unsigned i=0; i<options.size();i++){
        cout << i+1 <<" . "<<options[i]<<"\n";
    }
    cout <<"\nInsert CTRL+Z to leave the app\n";
    cout << "--------------------------------------\n";


    menu_int_options(option,1,options.size(),description);
    return option;
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



int minutesFromDistance(double distance, const char& transportation) {
    if (transportation == 'w') //walking
        return (distance/5.0)*60;
    else if(transportation == 'c') //car
        return (distance/30.0)*60;
    else if (transportation == 'p') //public
        return (distance/20.0)*60;
    return 0;
}

void trim(string &str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}


void verification_int(string &aux) {
    string numbers = "0123456789";

    bool isValid = false;

    while (!isValid || aux.empty()) {
        if (aux.empty()) {
            trim(aux);
            isValid = (aux.find_last_not_of(numbers) == string::npos);
        }
        if (!isValid) {
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
            if (cin.fail()) {
                if (cin.eof()) {
                    cin.clear();
                    aux = "-1";
                    return;
                }
            }
        }
    }
}

int generateRandomTime(string type) {

    if(type == "information") return rand()%11 + 10;
    
    else if(type == "hotel") return rand()%31 + 90;

    else if(type == "attraction") return rand()%31 + 60;
    
    else if(type == "viewpoint") return rand()%16 + 30;
    
    else if(type == "guest_house") return rand()%31 + 90;
    
    else if(type == "picnic_site") return rand()%31 + 30;
    
    else if(type == "artwork") return rand()%16 + 15;
    
    else if(type == "camp_site") return rand()%31 + 90;
    
    else if(type == "museum") return rand()%31 + 90;
    
    return rand()%11 + 10;
}               

vector<string> pairToString(const vector<pair<double,double>>& v){
    vector<string> res;
    string aux;
    for(auto p :v ){
        aux = to_string(p.first) + ", " + to_string(p.second);
        res.push_back(aux);
    }
    return res;
}