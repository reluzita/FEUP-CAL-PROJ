#include "interestManager.h"

int choice(string title, string description, vector<string> poi){//returns the index of the option in the poi vector
    int option = -1;
    system("cls");

    cout << "---------------- "<<title <<" ----------------\n\n";
    for(int i=0; i<items.size();i++){
        cout << i+1 <<" . "<<items[i]<<"\n";
    }
    cout << "--------------------------------------\n";


    menu_int_options(option,0,items.size(),description);    
    return option-1;
}

void addInterest(ClientInfo * info){
    vector<string> poi = info->getPoi();
    vector<string> availablePOI = {"Information", "Hotel", "Attraction", "ViewPoint", "GuestHouse", "Picnic Site", "Artwork", "Campsite","Museum"};
    vector<string> possibleNew;

    for(int i =0; i<availablePOI.size();i++){
        if(find(poi.begin(), poi.end(),availablePOI.at(i))== poi.end())
            possibleNew.push_back(availablePOI.at(i));
    }
    possibleNew.push_back("All");
    possibeNew.push_back("Back to Main");
    int option = choice("Add interest", "Choose the interest you want to add (integer number): ", possibleNew);
    cin.ignore(1000,'\n');

    while((option != possibleNew.size()-1) && (option != possibleNew.size()-2){
        info->addPoi(possibleNew.at(option));
        menu_int_options(option,0,possibleNew.size()+1,description);
        cin.ignore(1000,'\n');
    }
    
    if(option == possibleNew.size()-2) info->addAllPoi(availablePOI);

    return ;

}

void removeInterest(ClientInfo * info){
    vector<string> poi = info->getPoi();
    poi.push_back("All");
    poi.push_back("Back to main");
    int option = choice("Remove interest", "Choose the interest you want to remove (integer number): ", poi);


    int option = choice("Add interest", "Choose the interest you want to add (integer number): ", possibleNew);
    cin.ignore(1000,'\n');

    while((option != poi.size()-1) && (option != poi.size()-2){
        info->removePoi(option);
        menu_int_options(option,0,poi.size()+1,description);
        cin.ignore(1000,'\n');
    }
    
    if(option == possibleNew.size()-2) info->removeAllPoi(availablePOI);
    return;

}

void viewInterest(ClientInfo* info){
    vector<string> poi = info->getPoi();
    cout << "These are you defined interests at the moment: \n";
    for(int i =0; i<poi.size();i++){
        cout <<poi.at(i)<<endl;
    }
    int op;
    cout <<"Press 0 to go back to the menu: ";
    cin >> op;
    if(op ==0) return;
}