#include "GeneratePathMenu.h"

int getTransportation() {
    vector<string> items = {"Walking/Biking", "Car", "Public Transportations", "Back to main"};

    string description = "Choose one means of transportation from the menu (integer number): ";
 
    int op = displayMenu("How do you want to do your tour?", items, description);

    if(op == items.size()) return 0;

    return op;
}
string getTypeStartPoint(){
    vector<string> items = {"Information", "Hotel", "Attraction", "ViewPoint", "Guest_House", "Picnic_Site", "Artwork", "Camp_Site","Museum","Generic", "Back to main"};

    string description = "Choose what type of point where your journey starts (integer number):";
    string title = "Type of start point";
    
    int op = displayMenu(title, items, description);

    if(op == items.size()) return "";
    if(op == items.size()-1) return " ";

    string lowercase = items.at(op-1);
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    return lowercase;
}

int getStartPoint(const Graph &g, string typeStart) {
    //mudar para usar o graphviewer
    GraphViewer* gv = createMapViewer(g);
    //filtrar para mostrar
    vector<Vertex*> poi;
    for(Vertex* vertex: g.getVertexSet()) {
        if(vertex->getType() == typeStart)
            poi.push_back(vertex);
    }
    //mostrar
    showPOI(gv, poi);
    //escolher o ponto
    int op;
    string description = "Choose the id of your starting point on the map (integer number): ";
    menu_int_options(op,1, poi.size(), description);
    gv->closeWindow();
    return poi.at(op)->getID();
}

string getTypeEndPoint(){
    vector<string> items = {"Information", "Hotel", "Attraction", "ViewPoint", "Guest_House", "Picnic_Site", "Artwork", "Camp_site","Museum","Generic", "Back to main"};

    string description = "Choose what type of point where your journey ends (integer number):";
    string title = "Type of end point";
    
    int op = displayMenu(title, items, description);

    if(op == items.size()) return "";
    if(op == items.size()-1) return " ";

    string lowercase = items.at(op-1);
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    return lowercase;
}

int getEndPoint(const Graph &g, int orig, string typeEnd) {
    GraphViewer* gv = createMapViewer(g);

    vector<Vertex*> v = bfsAll(g, orig);
    vector<Vertex*> poi;
    for(Vertex* i: v) {
        if(i->getType() == typeEnd)
            poi.push_back(i);
    }
    cout << "poi " << poi.size() << endl;
    showPOI(gv, poi);

    gv->setVertexColor(orig, "green");
    gv->setVertexSize(orig, 15);
    gv->setVertexLabel(orig, "You're here");

    int op;
    string description = "Choose the id of your starting point on the map (integer number): ";
    menu_int_options(op,1, poi.size(), description);
    gv->closeWindow();
    return poi.at(op)->getID();
}

int getAvailableTime() {
    int time;
    cout << "Please enter the time you have available for the tour (in minutes, insert 0 to go back and CTRL+Z to leave the app): ";
    cin >> time;
    while(cin.fail() && cin.eof()){
        if(cin.eof()){
            cin.clear();
            return -1;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please insert a valid integer: ";
        cin >> time;
    }
    return time;
}

/*int pointsMenu(const string& title, const vector<Vertex*>& items, const string& description) {
    int option = -1;
    system("cls");

    cout << "---------------- "<< title <<" ----------------\n\n";
    for(Vertex* v: items){
        cout << v->getID() <<" . "<< v->getLat() << ", " << v->getLon() << endl;
    }
    cout << "0 . Refill the form \n\n";
    cout <<"Insert CTRL+Z to leave the app\n";
    cout << "--------------------------------------\n";

    cout << endl << description;
    cin >> option;
    while (cin.fail()) {
        if (cin.eof()) { //caso de ter sido introduzido o 'crtl+z'
            cin.clear();
            return -1;
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

    return option;
}*/

