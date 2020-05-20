#include "menu.h"


int mainMenu(ClientInfo *info, Graph &g, Graph &gbdir){
    vector<string> items = {"View Map", "Generate Path", "Surprise Me", "Manage Preferences", "Quit Program", "main"};
    string description = "Choose one option from the menu (integer number): ";
    
    int value = 0, option;

    do{
        option = displayMenu("Welcome", items, description);

        if(option == 1) value = viewMaps(g);
        else if (option == 2) value = generatePath(info, g, gbdir);
        else if (option == 3) value = supriseMe();
        else if (option == 4) value = managePreferences(info);
        
    } while((option != 5) && (value != -1));

    return 0;
}

int generatePath(ClientInfo* info, Graph &g, Graph &gbdir){
    
    //inicio --  por coordenadas ou pesquisa nao exata

    string typeStart = getTypeStartPoint();
    if(typeStart.empty()) return 0;

    int idStart = getStartPoint(g, typeStart);
    if(idStart == -1 || idStart == 0) return idStart;
    info->setIdStart(idStart);

    //fim
    string typeEnd = getTypeEndPoint();
    if(typeEnd.empty()) return 0;

    int idEnd = getEndPoint(g, idStart, typeEnd);
    if(idEnd == -1 || idEnd == 0) return idEnd;
    info->setIdEnd(idEnd);

    //meio de transporte
    int op = getTransportation();
    if(op == -1 || op == 0) return op;


    bool bidir = (op == 1);

    //tempo

    int time = getAvailableTime();
    if(time == -1 || time == 0) return time;
    info->setTimeAvailable(time);

    //nota: avisar se não houver caminho no tempo indicado

    OptimizedPath optPath = magicGenerator(g, info);
    GraphViewer* gv = createPathViewer(g, optPath.path, optPath.visitedId);

    getchar();
    gv->closeWindow();
    return 0;
}

int managePreferences(ClientInfo * info){
    vector<string> items = {"Add interest", "Remove interest", "View current interests", "Back to Main"};
    string description = "Choose one option from the menu(integer number): ";
    int option = displayMenu("Manage Preferences", items, description);  
    
    while(true){
        if(option==1){
            addInterest(info);
        }
        else if (option==2){
            removeInterest(info);
        }
        else if(option == 3){
            viewInterest(info);//view interest
        }
        else if (option == 4) break;
        else if (option == -1) return -1;

        option = displayMenu("Manage Preferences", items, description);
    }  
    return 0;
}

int viewMaps(const Graph &g){

    GraphViewer *gv = createMapViewer(g);  

    return 0;
}

int supriseMe(){

    //escolher o ponto incial
    //random caminho, não sei como fazer isto ainda

    return 0;
}


