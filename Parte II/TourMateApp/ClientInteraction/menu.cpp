#include "menu.h"

int mainMenu(string title, vector<string>items){
    int option;

    cout << "Hi! Welcome to TourMateApp\n";
    system("cls");

    while(1){
        option=-1;
        cout << "---------------- "<<title <<" ----------------\n\n";
        for(int i=0; i<items.size();i++){
            cout << i+1 <<" . "<<items[i]<<"\n\n";
        }
        cout << "0. Back \n\n";
        cout << "--------------------------------------\n";
        cout <<"Choose one option: ";

        menu_int_options(option,0,items.size());

    }
    
    cin.ignore(1000,'\n');
    return option;
}

void firstQuestion(){
    vector<string> items = {"Intercity, Intracity"};
    int op = mainMenu("Type of tour",items);
    if (op == 1){
        citysMenu();
    }
    else{

    }
}

void citysMenu(){
    vector<string> items = {"Aveiro, Braga, Coimbra, Ermesinde, Fafe, Gondomar, Lisboa, Maia, Porto,Viseu"};
    int op = mainMenu("Citys available",items);
    reapMap(items.at(op));
}
void whereAreYou(){
    vector<string> coords = {};//buscar as coordenadas dos pontos daquela cidade 
    int op= mainMenu("Where are you?", coords);
}
int whereToGo(){
    vector<string> coords = {}; //buscar as coordenadas de onde pode ir a partir daquele ponto
    int op = mainMenu("Where do you want to go to?", coords);
}
int meansOfTransportation(){
    vector<string> items = {"Walking/Biking", "Public Transportations", "Car"};
    int op = mainMenu("How do you want to do your tour?",items);
}
int pointsOfInterest(){
    vector<string> items = {"Information", "Hotel", "Attraction", "ViewPoint", "GuestHouse", "Picnic Site", "Artwork", "Campsite","Museum","None in particular"};
    int op = mainMenu("Points of interest", items);
}
