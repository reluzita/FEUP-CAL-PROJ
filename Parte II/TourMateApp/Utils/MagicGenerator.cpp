#include "MagicGenerator.h"

static int visitedPoi=0; 


/*------------------------------------------------- Magic Generator function --------------------------------------------------*/
OptimizedPath magicGenerator(Graph &g, ClientInfo* info) {
    cout << "Makin sum magic" << endl;
    OptimizedPath res;

    if(bfs(g, info->getIdStart(), info->getIdEnd()).empty()) {
        cout << "no path!" << endl;
        return res;
    }

    queue<Vertex*> path = dijkstraShortestPath(g, info->getIdStart(), info->getIdEnd());
    double distance = distancePath(path);

    if(minutesFromDistance(distance, info->getMeansOfTransportation()) > info->getTimeAvailable()) {
        double time = minutesFromDistance(distance, info->getMeansOfTransportation());
        cout << "There is no time to get from where you are to the point you want!" << endl;
        cout << "However, we have found the quickest way to get there ..."<< endl;
        cout << "It takes "<< time << " minutes "<<endl;
        res.path = path;
        return res;
    }

    vector<Vertex*> poi = bfsAllPOI(g, info->getIdStart(), info->getPoi(), info->getTimeAvailable());
    res = findPoiInPath(g, poi, info->getIdStart(), info->getIdEnd(), info->getTimeAvailable(), info->getMeansOfTransportation(), info->getCounterFactor());

    return res;
}


/*------------------------------------------------- Public Transportation function --------------------------------------------------*/

void metroPathGenerator(Graph &g, ClientInfo* info) {
    Vertex* orig = g.findVertex(info->getIdStart());
    Vertex* end = g.findVertex(info->getIdEnd());

    queue<Vertex*> fromOrig;
    queue<Vertex*> toEnd;

    double origDist = INT_MAX, endDist = INT_MAX;
    int stopOrig, stopEnd;

    for(MetroStation station: g.getMetroStations()) {
        if(!bfs(g, info->getIdStart(), station.getID()).empty()) {
            queue<Vertex*> path = dijkstraShortestPath(g, info->getIdStart(), station.getID());
            double dist = distancePath(path);
            if (dist < origDist) {
                fromOrig = path;
                origDist = dist;
                stopOrig = station.getStopNum();
            }
        }
        if(!bfs(g, station.getID(), info->getIdEnd()).empty()) {
            queue<Vertex*> path = dijkstraShortestPath(g, station.getID(), info->getIdEnd());
            double dist = distancePath(path);
            if (dist < endDist) {
                toEnd = path;
                endDist = dist;
                stopEnd = station.getStopNum();
            }
        }
    }

    int timeLeft = info->getTimeAvailable() - g.getMetroTime(stopOrig, stopEnd);

    if(timeLeft <= 0) {
        cout << "No time for the metro trip" << endl;
        return; //no time to do the metro trip
    }

    int origTime = pathTime(fromOrig, 'w');
    int endTime = pathTime(toEnd, 'w');

    cout << "Metro: " << timeLeft << " p1: " << origTime << " p2: " << endTime << endl;
    if(origTime + endTime >= timeLeft) {
        cout << "No time to get to the metro" << endl;
        return;
    }

    int origFactor = timeLeft * origTime / (endTime + origTime);

    vector<Vertex*> poi = bfsAllPOI(g, info->getIdStart(), info->getPoi(), origFactor);

    cout << "Found " << poi.size() << " points" << endl;

    OptimizedPath pathFromOrig = findPoiInPath(g, poi, info->getIdStart(), g.findStationID(stopOrig), origFactor, 'w', info->getCounterFactor());

    cout << "Done first generator" << endl;

    double endFactor = timeLeft * (double)endTime / (endTime + origTime);

    poi = bfsAllPOI(g, g.findStationID(stopEnd), info->getPoi(), endFactor);

    cout << "Found " << poi.size() << " points" << endl;

    OptimizedPath pathToEnd = findPoiInPath(g, poi, g.findStationID(stopEnd), info->getIdEnd(), endFactor, 'w', info->getCounterFactor());

    cout << "Done second generator" << endl;

    for(int id: pathToEnd.visitedId)
        pathFromOrig.visitedId.push_back(id);

    GraphViewer* gv = createMapViewer(g);

    showPathWithMetro(gv, pathFromOrig.path, pathToEnd.path, pathFromOrig.visitedId, g, stopOrig, stopEnd);

    getchar();

    gv->closeWindow();

}


/*--------------------------------------------- Circular Path ---------------------------------------------------------------------*/


OptimizedPath circularPath(Graph &g, ClientInfo* info, double counterFactor){
    cout <<"We're building something\n";
    OptimizedPath res;

    //getting all points acessible from the orig
    vector<Vertex*> points = bfsAllPOI(g, info->getIdStart(), info->getPoi(), info->getTimeAvailable());
    if(points.empty()) {
        cout << "Cant get anywhere!" << endl;
        return res;
    }

    cout << points.size() << endl;
    int counter = ceil(points.size()*counterFactor);
    for(Vertex* point: points) {
        if(counter == 0)
            break;

        queue<Vertex*> path = dijkstraShortestPath(g, info->getIdStart(), point->getID());

        int timeLeft = hasTime(path, info->getMeansOfTransportation(),info->getTimeAvailable());
        timeLeft -= point->getDuration();
        if(timeLeft <= 0) {
            counter--;
            continue;
        }

        vector<Vertex*> poi = bfsAllPOI(g, point->getID(), info->getPoi(), timeLeft);

        vector<Vertex *> POIs = POIsInPath(path, points);
        vector<Vertex *> aux;

        for (Vertex *vertex: POIs) {
            auto it = find(poi.begin(), poi.end(), vertex);
            if (it != poi.end())
                poi.erase(it);
        }

        //cout << "Going to find POI" << endl;
        OptimizedPath optPath = findPoiInPath(g, poi, point->getID(), info->getIdStart(), timeLeft, info->getMeansOfTransportation(), counterFactor);
        if(optPath.path.empty()) {
            counter--;
            continue;
        }

        OptimizedPath newOpt;
        path.pop();
        newOpt.path = joinQueue(optPath.path, path);
        newOpt.visitedId = optPath.visitedId;
        newOpt.visitedId.push_back(point->getID());

        if(newOpt.visitedId.size() > res.visitedId.size())
            res = newOpt;
    }
    if(res.path.empty())
        cout << "Not enough time to see any points of interest!" << endl;
    return res;
}

/*----------------------------------------------- Find poi in path ---------------------------------------------------------------*/


OptimizedPath findPoiInPath(Graph &g, const vector<Vertex*> &poi, const int &orig, const int &dest, const int &availableTime, char transportation, double counterFactor) {
    struct OptimizedPath empty;  //empty queue to return when cant find path
    struct OptimizedPath best;

    best.path = dijkstraShortestPath(g, orig, dest);

    if(hasTime(best.path, transportation, availableTime) <= 0) {
        return empty;   //no time to go straight from orig to dest
    }

    int counter = ceil(poi.size()*counterFactor);
    cout << "Size: " << poi.size() << endl;
    for (Vertex* point: poi) {
        if(counter == 0) {
            cout << "gave up" << endl;
            break;
        }

        if (point->getID() == orig || point->getID() == dest)
            continue;   //point is the same as orig or dest

        if (bfs(g, orig, point->getID()).empty())
            continue;   //no path between orig and point

        queue<Vertex *> pathFromOrig = dijkstraShortestPath(g, orig, point->getID());
        int remainingTime = hasTime(pathFromOrig, transportation, availableTime) - point->getDuration();
        if (remainingTime <= 0) {
            counter--;
            continue;   //no time to go from orig to point
        }

        vector<Vertex *> vec = bfsAll(g, point->getID());

        if (find(vec.begin(), vec.end(), g.findVertex(dest)) == vec.end()) {
            continue;   //no path between point and dest
        }

        queue<Vertex *> pathToDest = dijkstraShortestPath(g, point->getID(), dest);

        queue<Vertex *> res = joinQueue(pathToDest, pathFromOrig);


        int finalTime = hasTime(pathToDest, transportation, remainingTime);

        if (finalTime <= 0) {
            counter--;
            continue;       //no time to go from orig to point to dest
        }

        vector<int> temp;
        temp.push_back(point->getID());
        if (temp.size() > best.visitedId.size()) {
            //cout << "Found a path ( didnt make recursive call): " << hasTime(res, transportation, availableTime - point->getDuration()) << endl;
            best.path = res;
            while(!res.empty()) {
                res.pop();
            }
            best.visitedId = temp;
        }

        //remove points of interest already visited in the way from orig to point
        //remove points of interest that cant go to from point
        vector<Vertex *> POIsFromOrig = POIsInPath(pathFromOrig, poi);
        vector<Vertex *> aux;

        for (Vertex *vertex: poi) {
            if (find(vec.begin(), vec.end(), vertex) != vec.end() &&
                find(POIsFromOrig.begin(), POIsFromOrig.end(), vertex) == POIsFromOrig.end() &&
                vertex->getDuration() < remainingTime)
                aux.push_back(vertex);
        }

        OptimizedPath optPathToDest = findPoiInPath(g, aux, point->getID(), dest, remainingTime, transportation, aux.size());
        pathToDest = optPathToDest.path;

        if (pathToDest.empty()) {
            continue;     //couldn't find path
        }

        //update best with path found recursively
        res = joinQueue(pathToDest, pathFromOrig);

        int time = hasTime(res, transportation, availableTime);
        for(int id : optPathToDest.visitedId)
            time -= g.findVertex(id)->getDuration();

        if(time <= 0)
            continue;

        //cout << "Found a path: " << hasTime(res, transportation, availableTime) << endl;
        temp = optPathToDest.visitedId;
        temp.push_back(point->getID());
        if (temp.size() > best.visitedId.size()) {
            best.path = res;
            while(!res.empty()) {
                res.pop();
            }
            best.visitedId = temp;
        }
    }
    queue<Vertex*> aux = best.path;
    while(!aux.empty()) {
        aux.pop();
    }
    //cout << "Nodes in path: " << best.path.size() << " Visited nodes: " << best.visitedId.size() << endl;
    return best;
}


/*------------------------------------------Auxiliar functions-----------------------------------------*/

int hasTime(queue<Vertex*> path, char transportation, int availableTime) {
    double distance = distancePath(path);
    int dur = minutesFromDistance(distance, transportation);
    return availableTime - dur;
}

int pathTime(queue<Vertex*> path, char transportation) {
    double distance = distancePath(path);
    return minutesFromDistance(distance, transportation);
}

queue<Vertex*> joinQueue(queue<Vertex*> frontQ, queue<Vertex*> backQ) {
    while(!backQ.empty()) {
        frontQ.push(backQ.front());
        backQ.pop();
    }
    return frontQ;
}

vector<Vertex*> POIsInPath(queue<Vertex*> path, vector<Vertex*> poi) {
    vector<Vertex*> res;
    while(!path.empty()) {
        if(find(poi.begin(), poi.end(), path.front()) != poi.end())
            res.push_back(path.front());
        path.pop();
    }
    return res;
}


