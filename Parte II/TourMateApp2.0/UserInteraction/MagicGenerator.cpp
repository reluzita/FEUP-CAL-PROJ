#include "MagicGenerator.h"

/*------------------------------------------------- Magic Generator function --------------------------------------------------*/
OptimizedPath magicGenerator(Graph<coord> &g, ClientInfo* info) {
    OptimizedPath res;

    int time = info->getMinutes(g, info->getIdStart(), info->getIdEnd());
    if(time == -1) {
        cout << "There is no path between starting and end point" << endl;
        return res;
    }

    if(time > info->getTimeAvailable()) {
        cout << "There is no time to get from where you are to the point you want!" << endl;
        cout << "However, we have found the quickest way to get there ..."<< endl;
        res.path = info->getPath(g, info->getIdStart(), info->getIdEnd());
        cout << "It takes " << g.minutesFromDistance(g.distancePath(res.path), info->getMeansOfTransportation()) << " minutes." << endl;
        return res;
    }

    vector<Vertex<coord>*> poi = g.bfsAllPOI(info->getIdStart(), info->getPoi(), info->getTimeAvailable());
    res = findPoiInPath(g, info, poi, info->getIdStart(), info->getIdEnd(), info->getTimeAvailable());

    return res;
}

/*------------------------------------------------- Public Transportation function --------------------------------------------------*/

void metroPathGenerator(Graph<coord> &g, ClientInfo* info) {
    double origDist = INT_MAX, endDist = INT_MAX;
    MetroStation stopOrig, stopEnd;

    for(MetroStation station: g.getMetroStations()) {
        double dist = info->getDistance(g, info->getIdStart(), station.getID());
        if(dist < origDist) {
            origDist = dist;
            stopOrig = station;
        }
        dist = info->getDistance(g, station.getID(), info->getIdEnd());
        if (dist < endDist) {
            endDist = dist;
            stopEnd = station;
        }
    }

    if(stopOrig.getStopNum() == stopEnd.getStopNum()){
        cout << "It's better to just walk this route! Please select a different menu." << endl;
        return;
    }

    int timeLeft = info->getTimeAvailable() - g.getMetroTime(stopOrig, stopEnd);

    if(timeLeft <= 0) {
        cout << "No time for the metro trip" << endl;
        return; //no time to do the metro trip
    }

    int origTime = info->getMinutes(g, info->getIdStart(), stopOrig.getID());
    int endTime = info->getMinutes(g, stopEnd.getID(), info->getIdEnd());

    //cout << "Metro: " << timeLeft << " p1: " << origTime << " p2: " << endTime << endl;
    if(origTime + endTime >= timeLeft) {
        cout << "No time to get to the metro" << endl;
        return;
    }

    int origFactor = timeLeft * origTime / (endTime + origTime);
    vector<Vertex<coord>*> poi = g.bfsAllPOI(info->getIdStart(), info->getPoi(), origFactor);
    cout << "Found " << poi.size() << " points" << endl;

    OptimizedPath pathFromOrig = findPoiInPath(g, info, poi, info->getIdStart(), stopOrig.getID(), origFactor);
    cout << "Done first generator" << endl;

    double endFactor = timeLeft * (double)endTime / (endTime + origTime);
    poi = g.bfsAllPOI(stopEnd.getID(), info->getPoi(), endFactor);
    cout << "Found " << poi.size() << " points" << endl;

    OptimizedPath pathToEnd = findPoiInPath(g, info, poi, stopEnd.getID(), info->getIdEnd(), endFactor);
    cout << "Done second generator" << endl;

    for(int id: pathToEnd.visitedId)
        pathFromOrig.visitedId.push_back(id);

    GraphViewer* gv = createMapViewer(g);
    showPathWithMetro(gv, g, pathFromOrig.path, pathToEnd.path, pathFromOrig.visitedId, stopOrig, stopEnd);

    getchar();
    gv->closeWindow();
}


/*--------------------------------------------- Circular Path ---------------------------------------------------------------------*/

OptimizedPath circularPath(Graph<coord> &g, ClientInfo* info){
    OptimizedPath res;

    //getting all points acessible from the orig
    vector<Vertex<coord>*> points = g.bfsAllPOI(info->getIdStart(), info->getPoi(), info->getTimeAvailable());
    if(points.empty()) {
        cout << "Cant get anywhere!" << endl;
        return res;
    }

    int counter = ceil(points.size()*info->getCounterFactor());
    cout << points.size() << endl;
    for(Vertex<coord>* point: points) {
        if(counter == 0) {
            cout << "gave up!" << endl;
            break;
        }

        int timeLeft = info->getTimeAvailable() - g.minutesFromDistance(info->getDistance(g, info->getIdStart(), point->getId()), info->getMeansOfTransportation());
        timeLeft -= point->getDuration();
        if(timeLeft <= 0) {
            counter--;
            continue;
        }

        vector<Vertex<coord>*> poi = g.bfsAllPOI(point->getId(), info->getPoi(), timeLeft);
        queue<Vertex<coord>*> path = info->getPath(g, info->getIdStart(), point->getId());
        vector<Vertex<coord>*> POIs = POIsInPath(path, points);

        for (Vertex<coord>*vertex: POIs) {
            auto it = find(poi.begin(), poi.end(), vertex);
            if (it != poi.end())
                poi.erase(it);
        }

        cout << "Going to find POI" << endl;
        OptimizedPath optPath = findPoiInPath(g, info, poi, point->getId(), info->getIdStart(), timeLeft);
        if(optPath.path.empty()) {
            counter--;
            continue;
        }

        if(optPath.visitedId.size() + 1 > res.visitedId.size()) {
            OptimizedPath newOpt;
            newOpt.path = joinQueue(optPath.path, path);
            newOpt.visitedId = optPath.visitedId;
            newOpt.visitedId.push_back(point->getId());

            res = newOpt;
        }
    }
    if(res.path.empty())
        cout << "Not enough time to see any points of interest!" << endl;
    return res;
}


/*----------------------------------------------- Find poi in path ---------------------------------------------------------------*/

OptimizedPath findPoiInPath(Graph<coord> &g, ClientInfo* info, const vector<Vertex<coord>*> &poi, const int &orig, const int &dest, const int &availableTime) {
    struct OptimizedPath empty;  //empty queue to return when cant find path
    struct OptimizedPath best;

    int time = info->getMinutes(g, orig, dest);
    if(time > availableTime) {
        return empty;   //no time to go straight from orig to dest
    }
    else if(time == availableTime) {
        best.path = info->getPath(g, orig, dest);
        return best;
    }

    int counter = ceil(poi.size()*info->getCounterFactor());
    cout << "Size: " << poi.size() << endl;
    for (Vertex<coord>* point: poi) {
        if(counter == 0) {
            cout << "gave up" << endl;
            break;
        }

        if (point->getId() == orig || point->getId() == dest)
            continue;   //point is the same as orig or dest

        int time = info->getMinutes(g, orig, point->getId());
        if(time == -1) {
            counter--;
            continue;
        }
        int remainingTime = availableTime - time - point->getDuration();
        if (remainingTime <= 0) {
            counter--;
            continue;   //no time to go from orig to point
        }

        time = info->getMinutes(g, point->getId(), dest);
        if(time == -1) {
            counter--;
            continue;
        }

        int finalTime = remainingTime - time;

        if (finalTime <= 0) {
            counter--;
            continue;       //no time to go from orig to point to dest
        }

        if (best.visitedId.empty()) {
            //cout << "Found a path ( didnt make recursive call) " << endl;
            best.path = joinQueue(info->getPath(g, point->getId(), dest), info->getPath(g, orig, point->getId()));
            best.visitedId = {point->getId()};
        }

        //remove points of interest already visited in the way from orig to point
        //remove points of interest that cant go to from point
        vector<Vertex<coord>*> POIsFromOrig = POIsInPath(info->getPath(g, orig, point->getId()), poi);
        vector<Vertex<coord>*> vec = g.bfsAll(point->getId());
        vector<Vertex<coord>*> aux;

        for (Vertex<coord>* vertex: poi) {
            if (find(vec.begin(), vec.end(), vertex) != vec.end() &&
                find(POIsFromOrig.begin(), POIsFromOrig.end(), vertex) == POIsFromOrig.end() &&
                vertex->getDuration() < remainingTime)
                aux.push_back(vertex);
        }

        OptimizedPath optPathToDest = findPoiInPath(g, info, aux, point->getId(), dest, remainingTime);

        if (optPathToDest.path.empty()) {
            counter--;
            continue;     //couldn't find path
        }

        //update best with path found recursively
        optPathToDest.visitedId.push_back(point->getId());
        if (optPathToDest.visitedId.size() > best.visitedId.size()) {
            best.path = joinQueue(optPathToDest.path, info->getPath(g, orig, point->getId()));
            best.visitedId = optPathToDest.visitedId;
        }
    }
    cout << "Nodes in path: " << best.path.size() << " Visited nodes: " << best.visitedId.size() << endl;
    return best;
}

/*------------------------------------------Auxiliar functions-----------------------------------------*/

queue<Vertex<coord>*> joinQueue(queue<Vertex<coord>*> frontQ, queue<Vertex<coord>*> backQ) {
    while(!backQ.empty()) {
        frontQ.push(backQ.front());
        backQ.pop();
    }
    return frontQ;
}

vector<Vertex<coord>*> POIsInPath(queue<Vertex<coord>*> path, vector<Vertex<coord>*> poi) {
    vector<Vertex<coord>*> res;
    while(!path.empty()) {
        if(find(poi.begin(), poi.end(), path.front()) != poi.end())
            res.push_back(path.front());
        path.pop();
    }
    return res;
}

/*------------------------------------ Functions to get client info --------------------------*/
int getTransportation(bool circular) {
    vector<string> items;
    if(circular) items = {"Walking/Biking", "Car", "Back to main"};
    else items = {"Walking/Biking", "Car", "Public Transportations", "Back to main"};

    string description = "Choose one means of transportation from the menu (integer number): ";

    int op = displayMenu("How do you want to do your tour?", items, description);

    if(op == items.size()) return 0;

    return op;
}
int getAvailableTime() {
    int time;
    cout << "Please enter the time you have available for the tour (in minutes, insert 0 to go back and CTRL+Z to leave the app): ";
    cin >> time;
    while(cin.fail() && cin.eof()){
        if(cin.eof()){
            cin.clear();
            return -1;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please insert a valid integer: ";
        cin >> time;
    }
    return time;
}
string getTypeStartPoint(){
    vector<string> items = {"Information", "Hotel", "Attraction", "ViewPoint", "Guest_House", "Picnic_Site", "Artwork", "Camp_Site","Museum","Generic", "Back to main"};

    string description = "Choose what type of point where your journey starts (integer number):";
    string title = "Type of start point";

    int op = displayMenu(title, items, description);

    if(op == items.size()) return "";
    if(op == items.size()-1) return " ";
    if(op == -1) return "crash";

    string lowercase = items.at(op-1);
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    return lowercase;
}

int getStartPoint(const Graph<coord> &g, const string &typeStart, bool circular) {
    GraphViewer* gv = createMapViewer(g);
    //filtrar para mostrar
    vector<Vertex<coord>*> poi;
    for(Vertex<coord>* vertex: g.getVertexSet()) {
        if(vertex->getType() == typeStart)
            poi.push_back(vertex);
    }
    //mostrar
    showPOI(gv, poi, -1);

    //escolher o ponto
    int op;
    string description;
    if(circular ) description = "Choose the id of the point where your journey starts and ends on the map (integer number): ";
    else description = "Choose the id of your starting point on the map (integer number): ";
    menu_int_options(op,1, poi.size(), description);
    gv->closeWindow();

    return poi.at(op-1)->getId();
}

string getTypeEndPoint(){
    vector<string> items = {"Information", "Hotel", "Attraction", "ViewPoint", "Guest_House", "Picnic_Site", "Artwork", "Camp_site","Museum","Generic", "Back to main"};

    string description = "Choose what type of point where your journey ends (integer number):";
    string title = "Type of end point";

    int op = displayMenu(title, items, description);

    if(op == items.size()) return "";
    if(op == items.size()-1) return " ";
    if(op == -1) return "crash";

    string lowercase = items.at(op-1);
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    return lowercase;
}

int getEndPoint(Graph<coord> &g, int orig, const string &typeEnd, const int &availableTime) {
    GraphViewer* gv = createMapViewer(g);
    //filtrar para mostrar
    vector<Vertex<coord>*> v = g.bfsAllPOI(orig,{typeEnd},availableTime);
    vector<Vertex<coord>*> poi;
    for(Vertex<coord>* i: v) {
        if(i->getType() == typeEnd)
            poi.push_back(i);
    }
    //mostrar
    showPOI(gv, poi, orig);

    //escolher o ponto
    int op;
    string description = "Choose the id of your ending point on the map (integer number): ";
    menu_int_options(op,1, poi.size(), description);
    gv->closeWindow();

    return poi.at(op-1)->getId();
}

