#include "menu.h"

int standardMenu(const string& title, vector<string>items, const string& description,bool firstMenu){
    int option = -1;
    system("cls");

    cout << "---------------- "<<title <<" ----------------\n\n";
    for(unsigned i=0; i<items.size();i++){
        cout << i+1 <<" . "<<items[i]<<"\n";
    }
    if(!firstMenu)
        cout << "0 . Refill the form \n\n";
    cout <<"Insert CTRL+Z to leave the app\n";
    cout << "--------------------------------------\n";

    if(!firstMenu)
        menu_int_options(option,0,items.size(),description);
    else 
        menu_int_options(option,1,items.size(),description);
    //cin.ignore(1000,'\n');
    
    
    return option;
}

int pointsMenu(const string& title, const vector<Vertex*>& items, const string& description){
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
    //cin.ignore(1000,'\n');
    
    return option;
}

int firstQuestion(ClientInfo *info, Graph g){
    vector<string> items = {"Intercity", "Intracity"};
    string description = "Choose one option from the menu (integer number): ";
    int op = standardMenu("Type of tour",items,description, true);

    while(true){
        if (op == 1) op = multipleCitysMenu(info,g);
        else if (op==2) op = citysMenu(info,g);
        else if(op == 0) break;
        else if(op == -1) return -1;
    }
    cout << "Done with menu" << endl;

    queue<Vertex*> path = magicGenerator(g, info);
    return 0;
}

int multipleCitysMenu(ClientInfo *info, const Graph& g){
    //to do: maybe show the portugal map
    system("cls");
    cout <<"To be done ...\n";
    Sleep(2000);
    return -1;
}


int citysMenu(ClientInfo *info, Graph g){
    vector<string> items = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto","Viseu"};
    string description = "Choose one city from the menu (integer number): ";
    int op = standardMenu("Citys available",items, description,false);
    if(op == 0) return 0;
    else if (op ==-1) return -1;
    info->setCity(items.at(op-1));

    string m = meansOfTransportation(items.at(op-1));
    bool bidir = false, publicTransportation = false;
    if(m == "Walking/Biking") bidir = true;
    else if(m == "Public Transportation") publicTransportation = true;
    //else if(m == "Car") bidir = false;
    if(m.empty()) return 0;
    if(m == "crash") return -1;
    info->setMeansOfTransportation(m);

    g = readMap(items.at(op-1), bidir, publicTransportation);
    

    int idStart = whereAreYou(g);
    //if(idStart==-1) return 0;
    //else if(idStart ==-2) return -1;
    info->setIdStart(idStart);

    int idEnd = whereToGo(idStart,g);
    //if(idEnd==-1) return 0;
    //else if(idEnd ==-2) return -1;
    info->setIdEnd(idEnd);

    int time = timeAvailable();
    if(time == 0) return 0;
    else if(time ==-1) return -1;
    info->setTimeAvailable(time);

    vector<string> poi = pointsOfInterest();
    if(poi.empty()) return -1;//crl +z
    if(poi.at(0) == "crash") return 0;
    if(poi.at(0)=="None in particular")poi = {};
    info->setPoi(poi);


    return 0;
}

string meansOfTransportation(const string& city){
    vector<string> items;
    string description = "Choose one means of transportation from the menu (integer number): ";
    if(city == "Porto" || city == "Gondomar" || city == "Maia" || city == "Ermesinde"){
        items = {"Walking/Biking", "Public Transportations", "Car"};
    }
    else{
        items = {"Walking/Biking", "Car"};
    }
    int op = standardMenu("How do you want to do your tour?",items, description,false);
    if(op == 0) return ""; 
    if(op == -1) return "crash";
    return items.at(op-1);
}

int whereAreYou(Graph g){ 
    vector<pair<double,double>> cityCoords = g.getCityCoords();
    vector<string> coords = pairToString(cityCoords);
    string description = "Choose your coordinates at the moment from the menu (integer number): ";

    int op = standardMenu("Where are you?", coords, description, false);

    return g.getVertexSet().at(op-1)->getID();
}
int whereToGo(int idStart, Graph g){
    vector<int> v = bfsAll(g,g.getVertexSet().at(idStart)->getID());
    vector<pair<double,double>> coordP = g.idToCoords(v);
    vector<string> coords = pairToString(coordP); 
    coords.emplace_back("There is no way of getting to the point you wish from where you are!");
    string description = "Choose the coordinates you wish to go to from the menu (integer number): ";

    int op = standardMenu("Where do you want to go to?", coords,description,false);
    if(op != coords.size())
        return v.at(op-1);
    return cantGetThere();
}

vector<string> pointsOfInterest(){
    vector<string> res; 
    vector<string> items = {"Information", "Hotel", "Attraction", "ViewPoint", "GuestHouse", "Picnic Site", "Artwork", "Campsite","Museum","None in particular"};
    vector<int> op = poiMenu(items);

    if(op.empty()){//ctrl+z
        return res;
    }
    if (op.at(0)==-1){//re do 
        res.emplace_back("crash");
        return res;
    }
    for(int i: op){
        res.push_back(items.at(i-1));
    }
    return res;
}

int timeAvailable(){
    string time;
    cout << "Please enter the time you have available for the tour (in minutes, insert 0 to refill the form and CTRL+Z to leave the app): ";
    getline(cin, time);
    while(cin.fail() && cin.eof()){
        if(cin.eof()){
            cin.clear();
            return -1;
        }
        cin.clear();
        cout <<"why are you here\n";
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, time);
    }
    verification_int(time);
    cout <<time <<endl;
    return stoi(time);
}


vector<int> poiMenu(vector<string> poi){
    vector<int> res;
    int option=-1;
    unsigned i=0;
    system("cls");
    string description = "Choose your points of interest from the menu (integer numbers): ";

    cout << "---------------- "<<"Points of Interest" <<" ----------------\n\n";
    for(i=0; i<poi.size();i++){
        cout << i+1 <<" . "<<poi[i]<<"\n\n";
    }
    cout << i+1 << " . I've choosen all\n\n";
    cout << "0. Refill the form \n\n";
    cout <<"Insert CTRL+Z to leave the app\n";
    cout << "--------------------------------------\n";

    menu_int_options(option, 0, poi.size()+1,description);

    if(option == -1) {
        res = {};
        return res;
    }
    if(option == 0){
        res = {-1};
        return res;
    }
    cin.ignore(1000,'\n');

    while(option != 11 && option != 10){
        res.push_back(option-1);
        menu_int_options(option,0,poi.size()+1,description);

        if(option == -1) {
            res = {};
            return res;
        }
        if(option == 0){
            res = {-1};
            return res;
        }
        cin.ignore(1000,'\n');
    }
    if(option == 10){
        res.clear();
        res.push_back(option);
    }
    return res;
}

int cantGetThere(){
    int option;
    system("cls");
    string description = "What do you wish to do? (choose an integer number) ";
    cout <<" 1. Refill the form\n";
    cout <<" 2. Leave the app \n";
    menu_int_options(option,1,2,description);
    if(option == -1 || option == 2)
        return -2;
    else
        return -1;
}