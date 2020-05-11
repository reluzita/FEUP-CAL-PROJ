#include "menu.h"

int standardMenu(string title, vector<string>items, string description){
    int option;
    system("cls");


    option=-1;
    cout << "---------------- "<<title <<" ----------------\n\n";
    for(int i=0; i<items.size();i++){
        cout << i+1 <<" . "<<items[i]<<"\n";
    }
    cout << "0 . Refill the form \n\n";
    cout <<"Insert CTRL + Z to leave the app\n";
    cout << "--------------------------------------\n";


    menu_int_options(option,0,items.size(),description);
    cin.ignore(1000,'\n');
    

    return option;
}

int firstQuestion(){
    vector<string> items = {"Intercity", "Intracity"};
    string description = "Choose one option from the menu (integer number): ";
    int op = standardMenu("Type of tour",items,description);
    while(1){
        if (op == 1){
        //to do: maybe show the portugal map 
        }
        else if (op==2){
            op = citysMenu();
        }
        else if(op == 0){
            return 0;
        }
        else if(op==-1){
            return -1;
        }
    }
   
}

int citysMenu(){
    vector<string> items = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto","Viseu"};
    string description = "Choose one city from the menu (integer number): ";
    int op = standardMenu("Citys available",items, description);

    if(op == 0) return 0;
    else if (op ==-1) return -1;
    cout <<items.at(op-1)<<endl;

    string m = meansOfTransportation(items.at(op-1));//ainda falta por neste o crlz e o 0
    char mean;
    if(m == "Walking/Biking") mean = 'W';
    if(m == "Public Transportation") mean = 'P';
    if(m == "Car") mean = 'C';
    if(m == "") return 0;
    if(m == "crash") return -1;

    Graph g = readMap(items.at(op-1));
    vector<pair<double,double>> cityCoords = g.getCityCoords();

    int idStart = whereAreYou(cityCoords);
    if(idStart==-1) return 0;
    else if(idStart ==-2) return -1;

    int idEnd = whereToGo(idStart,g);
    if(idEnd==-1) return 0;
    else if(idEnd ==-2) return -1;

    int time = timeAvailable();
    if(time ==0) return 0;
    else if(time ==-1) return -1;

    vector<int> poi = pointsOfInterest();
    if(poi.empty())
        return -1;
    if(poi.at(0) == -1)
        return 0;

    return 0;

}
string meansOfTransportation(string city){
    vector<string> items;
    string description = "Choose one means of transportation from the menu (integer number): ";
    if(city == "Porto"){
        items = {"Walking/Biking", "Public Transportations", "Car"};
    }
    else{
        items = {"Walking/Biking", "Car"};
    }
    int op = standardMenu("How do you want to do your tour?",items, description);
    if(op == 0) return ""; //sem isto da porcaria! verificar se esta correto
    if(op == -1) return "crash";
    return items.at(op-1);
}

int whereAreYou(vector<pair<double,double>> v){ 
    vector<string> cityCoords = pairToString(v);
    string description = "Choose your coordinates at the moment from the menu (integer number): ";
    int op = standardMenu("Where are you?", cityCoords,description);

    return op-1;
}
int whereToGo(int idStart, Graph g){
    vector <int> v = bfsAll(g,g.getVertexSet().at(idStart)->getID());
    vector<pair<double,double>> coordP = g.idToCoords(v);
    vector<string> coords = pairToString(coordP); 
    coords.push_back("There is no way of getting to the point you wish from where you are!");
    string description = "Choose the coordinates you wish to go to from the menu (integer number): ";
    int op = standardMenu("Where do you want to go to?", coords,description);
    return op-1;
}

vector<int> pointsOfInterest(){
    vector<string> items = {"Information", "Hotel", "Attraction", "ViewPoint", "GuestHouse", "Picnic Site", "Artwork", "Campsite","Museum","None in particular"};
    vector<int> op = poiMenu(items);
    return op;
}

int timeAvailable(){
    string time;
    cout << "Please enter the time you have available for the tour (in minutes, insert 0 to refill the form and CTRL+Z to leave the app): ";
    getline(cin, time);
    while(cin.fail() && cin.eof()){
        cin.clear();
        if(cin.eof()){
            return -1;
        }
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, time);
    }
    verification_int(time);
    return stoi(time);
}


vector<int> poiMenu(vector<string> poi){
    vector<int> res;
    int option=-1;
    system("cls");
    string description = "Choose your points of interest from the menu (integer numbers): ";

    cout << "---------------- "<<"Points of Interest" <<" ----------------\n\n";
    int i=0;
    for(i=0; i<poi.size();i++){
        cout << i+1 <<" . "<<poi[i]<<"\n\n";
    }
    i+=2;
    cout << i << " . I've choosen all\n\n";
    cout << "0. Refill the form \n\n";
    cout <<"Insert CTRL + Z to leave the app\n";
    cout << "--------------------------------------\n";

    menu_int_options(option,0,poi.size(),description);

    if(option == -1) {
        res = {};
        return res;
    }
    if(option == 0){
        res = {-1};
        return res;
    }
    cin.ignore(1000,'\n');
    while(option != i){
        res.push_back(option-1);
        menu_int_options(option,0,poi.size(),description);
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
    
    return res;

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
