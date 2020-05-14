#include "menu2.h"

static vector<Graph> graphs; 

Graph findCityGraph(const string& city){
    
    for(Graph graph: graphs){
        if(graph.getCityName() == city)
            return graph;
    }

    return Graph();
}

//TO IMPLEMENT:
/*  Graph g = findCityGraph(city);
    if(g == null){
        g = readMap(city, bidir, publicTransportation);
        graphs.push_back(g);
    }
    if(!g.getPublicTransportation() && needTransportation){
        g.setPublicTransportation(true);
        readBusFile(g);
        readMetroFile(g);
    }
*/

int displayMenu(const string& title, vector<string>options, const string& description){
    int option = -1;
    system("cls");

    cout << "---------------- "<<title <<" ----------------\n\n";
    for(unsigned i=0; i<options.size();i++){
        cout << i+1 <<" . "<<options[i]<<"\n";
    }
    cout <<"Insert CTRL+Z to leave the app\n";
    cout << "--------------------------------------\n";


    menu_int_options(option,1,options.size(),description);
    return option;
}


int mainMenu(ClientInfo *info){
    vector<string> items = {"View Maps", "Generate Path", "Surprise Me", "Manage Preferences", "Quit Program"};
    string description = "Choose one option from the menu (integer number): ";
    
    int value = 0, option;

    do{
        option = displayMenu("Welcome", items, description);

        if(option == 1) value = viewMaps();
        else if (option == 2) value = generatePath(info);
        else if (option == 3) value = supriseMe();
        else if (option == 4) value = managePreferences(info);
        
    } while((option != 5) || (value != -1));

    return 0; //idk
}

int generatePath(ClientInfo* info){ 

    //cidade

    vector<string> items = {"Intercity", "Intracity", "Back to main"};
    string description = "Choose one option from the menu (integer number): ";
    int op = displayMenu("Type of tour", items, description);

    while(true) {
        if (op == 1) op = displayMenu("Type of tour", items, description); //To be done...
        else if (op == 2) break;
        else if(op == 3) return 0;
        else return -1;
    }
    
    items = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto","Viseu", "Back to main"};
    description = "Choose one city from the menu (integer number): ";
    op = displayMenu("Citys available", items, description);

    if (op == -1) return -1;
    else if(op == 11) return 0;

    string city = items.at(op-1);
    info->setCity(city);
    
    //meio de transporte

    description = "Choose one means of transportation from the menu (integer number): ";
    if(city == "Porto" || city == "Gondomar" || city == "Maia" || city == "Ermesinde"){
        items = {"Walking/Biking", "Car", "Public Transportations", "Back to main"};
    }
    else{
        items = {"Walking/Biking", "Car", "Back to main"};
    }
    op = displayMenu("How do you want to do your tour?", items, description);
    
    if(op == -1) return -1;
    else if(op == items.size() - 1) return 0;
    
    bool publictransportation = (op == 1 || op == 2);
    bool bidir = (op == 1);
    
    Graph graph = readMap(city, bidir, publictransportation);

    //inicio --  por coordenadas ou pesquisa nao exata

    vector<Vertex*> vertexes = graph.getVertexSet();
    description = "Choose the id of your coordinates at the moment (integer number): ";

    int id = pointsMenu("Where are you?", vertexes, description);

    info->setIdStart(id);

    //fim

    vector<int> v = bfsAll(graph, id);
    vertexes.clear();
    for(int i: v)
        vertexes.push_back(graph.findVertex(i));

    description = "Choose the coordinates you wish to go to from the menu (integer number): ";
    id = pointsMenu("Where do you want to go to?", vertexes ,description);

    info->setIdEnd(id);

    //tempo

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
    
    info->setTimeAvailable(stoi(time));

    //nota: avisar se não houver caminho no tempo indicado

    queue<Vertex*> path = magicGenerator(graph, info);
    
    return 0;
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
    //cin.ignore(1000,'\n');
    
    return option;
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
            viewInterest();//view interest
        }
        else if (option == 4) break;
        else if (option == -1) return -1;
    }  
    return 0;
}

int viewMaps(){
    
    vector<string> items = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto","Viseu"};
    string description = "Choose a city from the menu (integer number): ";
    int option = displayMenu("View Maps", items, description);
    
    if(option == -1)
        return -1;
    
    string city = items.at(option - 1);
    Graph g = findCityGraph(city);

    if(g == Graph()){
        g = readMap(city, false, false);
        graphs.push_back(g);
    }
    
    GraphViewer *gv = createMapViewer(g);  
        
    //add a key to return to menu
    return 0;
}

int supriseMe(){
    return 0;
}


