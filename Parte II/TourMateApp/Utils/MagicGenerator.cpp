#include "MagicGenerator.h"

static int visitedPoi=0; 

OptimizedPath magicGenerator(Graph &g, ClientInfo* info) {
    cout << "Makin sum magic" << endl;
    OptimizedPath res;

    vector<Vertex*> points = bfsAll(g, info->getIdStart());
    if(find(points.begin(), points.end(), g.findVertex(info->getIdEnd())) == points.end()) {
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

    vector<Vertex*> poi;
    for(Vertex* point: points) {
        if(point->getType() != " " && point->getDuration() < info->getTimeAvailable()) {
            if(info->getPoi().empty())
                poi.push_back(point);
            else if (find(info->getPoi().begin(), info->getPoi().end(), point->getType()) != info->getPoi().end())
                poi.push_back(point);
        }
    }

    res = findPoiInPath(g, poi, info->getIdStart(), info->getIdEnd(), info->getTimeAvailable(), info->getMeansOfTransportation());
    return res;
}

/*
queue<Vertex*> findPoiInPath(Graph &g, vector<Vertex*> poi, const int &orig, const int &dest, const int &availableTime, char transportation) {
    queue<Vertex*> empty;
    queue<Vertex*> best = dijkstraShortestPath(g, orig, dest);
    if(hasTime(best, transportation, availableTime) < 0) {
        return empty;
    }

    //escolher um poi do vetor
    for(Vertex* point: poi) {
        cout << "Starting at point " << point->getID() << endl;
        cout << endl << "Time available: " << availableTime << endl << endl;
        queue<Vertex*> res;
        // ver caminho entre inicio e o ponto
        if(bfs(g, orig, point->getID()).empty())
            continue; //é continue??

        queue<Vertex*> pathFromOrig = dijkstraShortestPath(g, orig, point->getID());

        int timeleft = hasTime(pathFromOrig, transportation, availableTime);
        //se nao tiver tempo para chegar do inicio ao ponto passa ao seguinte
        if(timeleft - point->getDuration() > 0) {
            timeleft -= point->getDuration();
            cout << endl << "Time calculated: " << timeleft << endl << endl;
            res = pathFromOrig;
        }
        else {
            continue;
        }

        // ver caminho entre ponto e o destino
        if(bfs(g, point->getID(), dest).empty())
            continue; // é continue??
        queue<Vertex*> pathToDest = dijkstraShortestPath(g, point->getID(), dest);

        if(hasTime(pathToDest, transportation, timeleft)) {
            vector<Vertex*> temp = poi;
            temp.erase(find(temp.begin(), temp.end(), point));

            vector<Vertex*> temp2 = POIsInPath(pathToDest);
            for(Vertex* aux: temp2) {
                auto it = find(temp.begin(), temp.end(), aux);
                if(it != temp.end())
                    temp.erase(it);
            }

            queue<Vertex*> found = findPoiInPath(g, temp, point->getID(), dest, timeleft, transportation);
            if(found.empty()) {
                queue<Vertex*> a;
                return a;
            }
            while(!found.empty()) {
                res.push(found.front());
                found.pop();
            }
            cout << "POINT OF INTEREST STOP: " << point->getID() << endl;
            return res;
            if(countPOIs(best) < countPOIs(res)) {
                cout << "better!" << endl;
                best = res;
            }
        }
    }
    return best;
} */

int hasTime(queue<Vertex*> path, char transportation, int availableTime) {
    double distance = distancePath(path);
    int dur = minutesFromDistance(distance, transportation);
    return availableTime - dur;
}

/*struct OptimizedPath{
    queue<Vertex*> path;
    vector<int> visitedPoi;
};*/


OptimizedPath findPoiInPath(Graph &g, const vector<Vertex*> &poi, const int &orig, const int &dest, const int &availableTime, char transportation) {
    struct OptimizedPath empty;  //empty queue to return when cant find path
    struct OptimizedPath best;
    best.path = dijkstraShortestPath(g, orig, dest);

    int time = hasTime(best.path, transportation, availableTime);
    if(time <= 0) {
        return empty;   //no time to go straight from orig to dest
    }

    for (Vertex* point: poi) {
        if (point->getID() == orig || point->getID() == dest)
            continue;   //point is the same as orig or dest

        if (bfs(g, orig, point->getID()).empty())
            continue;   //no path between orig and point

        queue<Vertex *> pathFromOrig = dijkstraShortestPath(g, orig, point->getID());
        int remainingTime = hasTime(pathFromOrig, transportation, availableTime) - point->getDuration();
        if (remainingTime <= 0) {
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

        OptimizedPath optPathToDest = findPoiInPath(g, aux, point->getID(), dest, remainingTime, transportation);
        pathToDest = optPathToDest.path;

        if (pathToDest.empty()) {
            continue;     //couldn't find path
        }

        //update best with path found recursively
        res = joinQueue(pathToDest, pathFromOrig);

        time = hasTime(res, transportation, availableTime);
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
    cout << "Nodes in path: " << best.path.size() << " Visited nodes: " << best.visitedId.size() << endl;
    return best;
}

template <class T>
queue<T> joinQueue(queue<T> frontQ, queue<T> backQ) {
    while(!backQ.empty()) {
        frontQ.push(backQ.front());
        backQ.pop();
    }
    return frontQ;
}

int countPOIs(queue<Vertex*> path, vector<Vertex*> poi) {
    int res = 0;
    while(!path.empty()) {
        if(find(poi.begin(), poi.end(), path.front()) != poi.end())
            res++;
        path.pop();
    }
    return res;
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



//Encontra todos os pontos acessiveis entre a origem e o final
//Filtra os pontos de interesse
//Encontra todos os caminhos entre pares de pontos de interesse
//Calcula a melhor combinação para percorrer o maximo de pontos dentro do tempo pedido