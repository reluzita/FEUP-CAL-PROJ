#include "interestManager.h"

#include <utility>

int choice(const string& title, const string& description, vector<string> poi){//returns the index of the option in the poi vector
    int option = -1;
    system("cls");

    cout << "---------------- "<<title <<" ----------------\n\n";
    for(unsigned i=0; i<poi.size();i++){
        cout << i+1 <<" . "<<poi[i]<<"\n";
    }
    cout << "--------------------------------------\n";


    menu_int_options(option,0,poi.size(),description);
    return option-1;
}

int addInterest(ClientInfo * info){
    vector<string> poi = info->getPoi();
    vector<string> availablePOI = {"Information", "Hotel", "Attraction", "ViewPoint", "GuestHouse", "Picnic Site", "Artwork", "Campsite","Museum"};
    vector<string> possibleNew;

    for(const auto & i : availablePOI){
        if(find(poi.begin(), poi.end(),i)== poi.end())
            possibleNew.push_back(i);
    }
    possibleNew.emplace_back("All");
    possibleNew.emplace_back("Back to Main");
    int option = choice("Add interest", "Choose the interest you want to add (integer number): ", possibleNew);
    cin.ignore(1000,'\n');

    string description = "O QUE E PARA ESCREVER AQUI?";

    while((option != possibleNew.size()-1) && (option != possibleNew.size()-2)){
        info->addPoi(possibleNew.at(option));
        menu_int_options(option,0,possibleNew.size()+1,description);
        cin.ignore(1000,'\n');
    }
    
    if(option == possibleNew.size()-2) info->addAllPoi(availablePOI);

    return 0;

}

int removeInterest(ClientInfo * info){
    vector<string> poi = info->getPoi();
    poi.emplace_back("All");
    poi.emplace_back("Back to main");
    int option = choice("Remove interest", "Choose the interest you want to remove (integer number): ", poi);


    option = choice("Add interest", "Choose the interest you want to add (integer number): ", poi /*possibleNew*/);
    cin.ignore(1000,'\n');


    string description = "O QUE E PARA POR AQUI?";

    while((option != poi.size()-1) && (option != poi.size()-2)){
        info->removePoi(poi.at(option));
        menu_int_options(option,0,poi.size()+1,description);
        cin.ignore(1000,'\n');
    }
    
    if(option == poi.size()-2) info->removeAllPoi();
    return 0;

}

int viewInterest(){
    // TO DO 
    return 0;
}