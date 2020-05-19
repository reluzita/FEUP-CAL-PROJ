#include "menu.h"

static vector<Graph> graphs; 

Graph searchGraph(const string& city, bool biDir, bool publicTransportation){
    
    for(Graph graph: graphs){
        if(graph.getCityName() == city){

            if((!publicTransportation || graph.getPublicTransportation()) && (graph.getBiDir() == biDir)) //(no publicTransportation or graph has already bus/metro info) and graph is bidir
                return graph;

            else if(publicTransportation && (graph.getBiDir() == biDir)){ //when we need metro/bus info and graph is already bidir
                graph.setPublicTransportation(true);
                readBusFile(graph);
                readMetroFile(graph);
                return graph;
            }
            else if(graph.getBiDir() != biDir){ //when we need to change edges 
                graph.clearEdges();
                graph.setBiDir(biDir);
                string lowercase = city;
                transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
                readEdgesFile(graph, city, lowercase, biDir);
                return graph;
            }
        }
    }

    Graph graph = readMap(city, biDir, publicTransportation);
    graphs.push_back(graph);
    return graph;
}


int mainMenu(ClientInfo *info){
    vector<string> items = {"View Maps", "Generate Path", "Surprise Me", "Manage Preferences", "Quit Program", "main"};
    string description = "Choose one option from the menu (integer number): ";
    
    int value = 0, option;

    do{
        option = displayMenu("Welcome", items, description);

        if(option == 1) value = viewMaps();
        else if (option == 2) value = generatePath(info);
        else if (option == 3) value = supriseMe();
        else if (option == 4) value = managePreferences(info);
        
    } while((option != 5) && (value != -1));

    return 0;
}

int generatePath(ClientInfo* info){ 

    //cidade
    string city = getCity();
    if(city.empty()) return 0;
    info->setCity(city);
    
    //meio de transporte

    int op = getTransportation(city);
    if(op == -1 || op == 0) return op;

    bool publictransportation = (op == 3);
    bool bidir = (op == 1);
    
    Graph graph = searchGraph(city, bidir, publictransportation);

    //inicio --  por coordenadas ou pesquisa nao exata

    int idStart = getStartPoint(graph);
    if(idStart == -1 || idStart == 0) return idStart;
    info->setIdStart(idStart);

    //fim

    int idEnd = getEndPoint(graph, idStart);
    if(idEnd == -1 || idEnd == 0) return idEnd;
    info->setIdEnd(idEnd);

    //tempo

    int time = getAvailableTime();
    if(time == -1 || time == 0) return time;
    info->setTimeAvailable(time);

    //nota: avisar se não houver caminho no tempo indicado

    OptimizedPath optPath = magicGenerator(graph, info);
    GraphViewer* gv = createPathViewer(graph, optPath.path, optPath.visitedId);

    getchar();
    
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

int viewMaps(){
    
    vector<string> items = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto","Viseu", "Back to Main"};
    string description = "Choose a city from the menu (integer number): ";
    int option = displayMenu("View Maps", items, description);
    
    if(option == -1)
        return -1;
    
    if(option == items.size())
        return 0;
    string city = items.at(option - 1);


    Graph g = searchGraph(city, false, false);

    GraphViewer *gv = createMapViewer(g);  

    return 0;
}

int supriseMe(){

    vector<string> items = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto","Viseu", "Back to Main"};
    string description = "Choose a city from the menu (integer number): ";
    int option = displayMenu("Surprise Me", items, description);

    if(option == -1)
        return -1;

        
    if(option == items.size())
        return 0;
    string city = items.at(option - 1);

    //random caminho, não sei como fazer isto ainda

    return 0;
}


