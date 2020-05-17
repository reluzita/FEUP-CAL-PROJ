#include "GeneratePathMenu.h"

string getCity() {
    vector<string> items = {"Intercity", "Intracity", "Back to main"};
    string description = "Choose one option from the menu (integer number): ";
    int op = displayMenu("Type of tour", items, description);

    while(true) {
        if (op == 1) op = displayMenu("Type of tour", items, description); //To be done...
        else if (op == 2) break;
        else return "";
    }

    items = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto","Viseu", "Back to main"};
    description = "Choose one city from the menu (integer number): ";
    op = displayMenu("Citys available", items, description);

    if (op < 0 || op >= items.size() - 1) return "";

    return items.at(op-1);
}

int getTransportation(string city) {
    vector<string> items;

    string description = "Choose one means of transportation from the menu (integer number): ";
    if(city == "Porto" || city == "Gondomar" || city == "Maia" || city == "Ermesinde"){
        items = {"Walking/Biking", "Car", "Public Transportations", "Back to main"};
    }
    else{
        items = {"Walking/Biking", "Car", "Back to main"};
    }
    int op = displayMenu("How do you want to do your tour?", items, description);

    if(op == items.size()) return 0;

    return op;
}

int getStartPoint(const Graph &g) {
    vector<Vertex*> vertexes = g.getVertexSet();
    string description = "Choose the id of your coordinates at the moment (integer number): ";

    return pointsMenu("Where are you?", vertexes, description);
}

int getEndPoint(const Graph &g, int orig) {
    vector<Vertex*> v = bfsAll(g, orig);
    vector<Vertex*> vertices;
    for(Vertex* i: v)
        vertices.push_back(i);

    string description = "Choose the coordinates you wish to go to from the menu (integer number): ";
    return pointsMenu("Where do you want to go to?", vertices ,description);
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

int pointsMenu(const string& title, const vector<Vertex*>& items, const string& description) {
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
}