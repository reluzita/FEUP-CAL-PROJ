#include "interestManager.h"

int choice(const string& title, const string& description, vector<string> poi){
    int option = -1;
    system("cls");

    cout << "---------------- "<<title <<" ----------------\n\n";
    for(unsigned i=0; i<poi.size();i++){
        cout << i+1 <<" . "<<poi[i]<<"\n";
    }
    cout << "--------------------------------------\n";


    menu_int_options(option,1,poi.size(),description);
    cout <<option <<endl;
    return option;
}

void addInterest(ClientInfo * info){
    vector<string> poi = info->getPoi();
    vector<string> availablePOI = {"Information", "Hotel", "Attraction", "ViewPoint", "GuestHouse", "Picnic Site", "Artwork", "Campsite","Museum"};
    vector<string> possibleNew;

    for(const auto & i : availablePOI){
        if(find(poi.begin(), poi.end(),i)== poi.end())
            possibleNew.push_back(i);
    }

    if(possibleNew.empty()){
        system("cls");
        cout << "\nThere aren't any interests to add. You will be redirected to the previous menu\n\n";
        sleep(2);
        return;
    }
    possibleNew.emplace_back("All");
    possibleNew.emplace_back("Back to Main");
    string description = "Choose the interest you want to add (integer number): ";
    int option = choice("Add interest",description , possibleNew);//retorna o indice no vetor
    cin.ignore(1000,'\n');


    while((option != possibleNew.size()-1) && (option != possibleNew.size())){
        info->addPoi(possibleNew.at(option-1));
        menu_int_options(option,1,possibleNew.size(),description);
        cin.ignore(1000,'\n');
    }

    if(option == (possibleNew.size()-1)) info->addAllPoi(availablePOI);

    return;

}

void removeInterest(ClientInfo * info){
    vector<string> poi = info->getPoi();
    poi.emplace_back("All");
    poi.emplace_back("Back to main");
    if(poi.empty()){
        system("cls");
        cout << "\nThere aren't any interests to remove. You will be redirected to the previous menu\n\n";
        sleep(2);
        return;
    }

    string description = "Choose the interest you want to remove (integer number): ";
    int option = choice("Remove interest",description , poi);
    cin.ignore(1000,'\n');

    while((option != poi.size()-1) && (option != poi.size())){
        info->removePoi(poi.at(option-1));
        menu_int_options(option,1,poi.size(),description);
        cin.ignore(1000,'\n');
    }

    if(option == (poi.size()-1)) info->removeAllPoi();
    return;

}

void viewInterest(ClientInfo* info){//a verficaçao do input so está certa para ints
    vector<string> poi = info->getPoi();

    system("cls");
    if(poi.empty()){
        cout <<"\nYou have no interests defined\n\n";
    }
    else {
        cout << "\nThese are you defined interests at the moment:\n\n";
        for (int i = 0; i < poi.size(); i++) {
            cout << poi.at(i) << endl;
        }
    }
    int op;
    cout <<"\nPress 0 to go back to the menu: ";
    cin >> op;
    while(op!=0){
        if(cin.fail()||cin.eof()){
            cin.clear();
            cin.ignore(1000,'\n');
        }
        cout <<"Invalid input. Try again: ";
        cin >> op;
    }
    return;
}