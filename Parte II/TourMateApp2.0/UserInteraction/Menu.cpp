#include "Menu.h"

int mainMenu(ClientInfo *info, Graph<coord> &g, Graph<coord> &gbdir){
    vector<string> items = {"View Map", "Generate Path","Generate Circular Path", "Surprise Me", "Manage Preferences","Algorithm Analysis", "Quit Program", "main"};
    string description = "Choose one option from the menu (integer number): ";
    
    int value = 0, option;

    do{
        option = displayMenu("Welcome", items, description);

        if(option == 1) value = viewMaps(g);
        else if (option == 2) value = generatePath(info, g, gbdir);
        else if (option == 3) value = generateCircularPath(info, g, gbdir);
        else if (option == 4) value = supriseMe();
        else if (option == 5) value = managePreferences(info);
        else if (option == 6) value = algorithmAnalysis(g, gbdir);
    } while((option != 7) && (value != -1));

    return 0;
}

int generatePath(ClientInfo* info, Graph<coord> &g, Graph<coord> &gbdir){

//nota: avisar se não houver caminho no tempo indicado

    //meio de transporte
    int op = getTransportation(false);
    if(op == -1 || op == 0) return op;

    bool bidir = (op == 1);
    if(op==1) info->setMeansOfTransportation('w');
    else if(op==2) info->setMeansOfTransportation('c');
    else if(op==3) info->setMeansOfTransportation('p');


    //tempo
    int time = getAvailableTime();
    if(time == -1 || time == 0) return time;
    info->setTimeAvailable(time);


    //coordenadas de inicio

    string typeStart = getTypeStartPoint();
    if(typeStart.empty()) return 0;
    if(typeStart == "crash") return -1;

    int idStart = getStartPoint(g, typeStart, false, (op==3));
    if(idStart == -1 || idStart == 0) return idStart;
    info->setIdStart(idStart);

    //coordenadas de fim
    string typeEnd = getTypeEndPoint();
    if(typeEnd.empty()) return 0;
    if(typeStart == "crash") return -1;

    int idEnd = getEndPoint(g, idStart, typeEnd, time, (op==3));
    if(idEnd == -1 || idEnd == 0) return idEnd;
    info->setIdEnd(idEnd);

    //escolheu o mesmo ponto para fim e inicio -- circular path
    if(idStart == idEnd){
        cout << "If you want a path starting and ending in the same point choose Generate Circular Path in the main menu"<<endl;
        cout << "We're redirecting you to the main menu ..."<<endl;
        sleep(3);
        return 0;
    }

    //nota: avisar se não houver caminho no tempo indicado

    if(op == 3){
        metroPathGenerator(gbdir, info);
        return 0;
    }

    OptimizedPath optPath;
    if(bidir) {
        optPath = magicGenerator(gbdir, info);
    } 
    else {
        optPath = magicGenerator(g, info);
    }

    if(optPath.path.empty()) return 0;

    GraphViewer *gv = createMapViewer(g);
    showPath(gv, optPath.path, optPath.visitedId);

    int input;
    cin >> input;

    gv->closeWindow();
    return 0;

}
int generateCircularPath(ClientInfo * info, Graph<coord> &g, Graph<coord> &gbdir){
    
//nota: avisar se não houver caminho no tempo indicado

    //meio de transporte
    int op = getTransportation(true);
    if(op == -1 || op == 0) return op;

    bool bidir = (op == 1);
    if(op==1) info->setMeansOfTransportation('w');
    else if(op==2) info->setMeansOfTransportation('c');

    //tempo
    int time = getAvailableTime();
    if(time == -1 || time == 0) return time;
    info->setTimeAvailable(time);


    //escolher o ponto onde começa e acaba o caminho
    string typeStart = getTypeStartPoint();
    if(typeStart.empty()) return 0;
    if(typeStart == "crash") return -1;

    int idStart = getStartPoint(g, typeStart, true, false);
    if(idStart == -1 || idStart == 0) return idStart;
    info->setIdStart(idStart);

    OptimizedPath optPath;
    
    if(bidir)
        optPath = circularPath(gbdir, info);
    else
        optPath = circularPath(g, info);
    
    if(optPath.path.empty()) {
        cout << endl << endl << "No time! Insert any key to return to the menu..." << endl;
        char input;
        cin >> input;
        return 0;
    }

    double dist = g.distancePath(optPath.path);
    cout << "Total distance: " << dist << "km" << endl;
    cout << "Moving time: " << g.minutesFromDistance(dist, info->getMeansOfTransportation()) << "m" << endl;
    if(!optPath.visitedId.empty()) {
        cout << "Average time in visited points:" << endl;
        for(int id: optPath.visitedId) {
            Vertex<coord>* v = g.findVertex(id);
            cout << id << " - " << v->getType() << " - " << v->getDuration() << "m" << endl;
        }
    }

    cout << endl;
    queue<Vertex<coord>*> aux = optPath.path;
    while(!aux.empty()) {
        cout << aux.front()->getId() << " - ";
        aux.pop();
    }
    cout << endl;

    GraphViewer *gv = createMapViewer(g);
    showPath(gv, optPath.path, optPath.visitedId);

    cout << endl << endl << "Insert any key to return to the menu..." << endl;
    char input;
    cin >> input;

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


int viewMaps(const Graph<coord> &g){
    GraphViewer *gv = createMapViewer(g);

    getchar();
    gv->closeWindow();

    return 0;
}

int supriseMe(){

    //escolher o ponto incial
    //random caminho, não sei como fazer isto ainda

    return 0;
}

int algorithmAnalysis(Graph<coord> &g, Graph<coord> &gbdir){
    vector<string> items = {"Comparing Dijkstra and AStar in small path", "Comparing Dijkstra and AStar in big path", "Comparing bidirectional Dijkstra and bidirectional AStar", "Comparing DFS and BFS", "Comparing Dijkstra, AStar and Floyd-Warshall in grid graphs"};
    string description = "Choose one option from the menu(integer number): ";
    int option = displayMenu("Manage Preferences", items, description);

    if(option == 1) comparePath(g, 30413, 36869);
    else if (option == 2) comparePath(g, 30413, 36869);
    else if (option == 3) compareBidirectional(gbdir);
    else if (option == 4) compareDFSBFS(g);
    else if (option == 5) compareAllGrid();
    
    return 0;
}


