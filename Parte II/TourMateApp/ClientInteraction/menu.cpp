#include "menu.h"

int standardMenu(string title, vector<string>items, string description){
    int option;
    system("cls");


    option=-1;
    cout << "---------------- "<<title <<" ----------------\n\n";
    for(int i=0; i<items.size();i++){
        cout << i+1 <<" . "<<items[i]<<"\n";
    }
    cout << "0 . Quit \n\n";
    cout << "--------------------------------------\n";


    menu_int_options(option,0,items.size(),description);

    
    cin.ignore(1000,'\n');
    return option;
}

void firstQuestion(){
    vector<string> items = {"Intercity", "Intracity"};
    string description = "Choose one option from the menu (integer number): ";
    int op = standardMenu("Type of tour",items,description);
    if (op == 1){
        //to do
    }
    else if (op==2){
        citysMenu();
    }
}

void citysMenu(){
    vector<string> items = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto","Viseu"};
    string description = "Choose one city from the menu (integer number): ";
    int op = standardMenu("Citys available",items, description);
    cout <<items.at(op-1)<<endl;
    string m = meansOfTransportation(items.at(op-1));
    char mean;
    if(m == "Walking/Biking") mean = 'W';
    if(m == "Public Transportation") mean = 'P';
    if(m == "Car") mean = 'C';

    Graph g = readMap(items.at(op-1));
    vector<pair<double,double>> cityCoords = g.getCityCoords();

    int idStart = whereAreYou(cityCoords);
    int idEnd = whereToGo(idStart,g);

    int time = timeAvailable();
    vector<int> poi = pointsOfInterest();

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
    return items.at(op-1);
}

int whereAreYou(vector<pair<double,double>> v){ 
    vector<string> cityCoords = pairToString(v);
    string description = "Choose your coordinates at the moment from the menu (integer number): ";
    int op = standardMenu("Where are you?", cityCoords,description);
    return op-1;
}
int whereToGo(int idStart, Graph g){
    cout <<"Hello\n" << endl;
    cout << idStart << " " << g.getVertexSet().at(idStart)->getID() << endl;
    vector <int> v = bfsAll(g,g.getVertexSet().at(idStart)->getID());
    vector<pair<double,double>> coordP = g.idToCoords(v);
    vector<string> coords = pairToString(coordP); //buscar as coordenadas de onde pode ir a partir daquele ponto
    coords.push_back("There is no way of getting to the point you wish from where you are");
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
    int time; 
    cout << "Please enter the time you have available for the tour (in minutes): ";
    cin >> time;
    return time;
}

vector<int> poiMenu(vector<string> poi){
    vector<int> res;
    int option=-1;
    system("cls");
    string description = "Choose your points of interest from the menu (integer numbers): ";

    cout << "---------------- "<<"Points of Interest" <<" ----------------\n\n";
    for(int i=0; i<poi.size();i++){
        cout << i+1 <<" . "<<poi[i]<<"\n\n";
    }
    cout << "0. I've choosen all \n\n";
    cout << "--------------------------------------\n";
    cout <<"Choose one option: ";

    menu_int_options(option,0,poi.size(),description);
    cin.ignore(1000,'\n');
    while(option != 0){
        res.push_back(option-1);
        menu_int_options(option,0,poi.size(),description);
        cin.ignore(1000,'\n');
    }
    
    return res;

}

/*

cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');
    if (option == 0)
        return {};
    result.push_back(option-1);

    cout << endl;
    while (option != 0) {
        system("cls");
        cout << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl;
        for(int i = 0; i < size; i++){
            cout << "Product " << i+1 <<  ": " << restaurant.getProducts().at(i) << endl;
        }

        cout << endl << "Product added to the cart! You currenty have " << result.size() << " products: " << endl;
        float total = 0;
        for (int x: result){
            cout << restaurant.getProducts().at(x).getName() << " - " << restaurant.getProducts().at(x).getPrice() << "$" << endl;
            total += restaurant.getProducts().at(x).getPrice();
        }
        cout << endl << "Total price (w/o tax): " << total << endl;
        cout << endl << "Do you want to order another product? Choose the number of the product (insert 0 to finish the order): ";
        product_menu(option, 0, size);
        cin.ignore(1000, '\n');
        if (option != 0)
            result.push_back(option-1);
    }
    return result;
*/

vector<string> pairToString(vector<pair<double,double>> v){
    vector<string> res;
    string aux;
    for(auto p :v ){
        aux = to_string(p.first) + ", " + to_string(p.second);
        res.push_back(aux);
    }
    return res;
}
