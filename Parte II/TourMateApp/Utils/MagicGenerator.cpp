#include "MagicGenerator.h"

static int visitedPoi=0; 

queue<Vertex*> magicGenerator(Graph &g, ClientInfo* info) {
    cout << "Makin sum magic" << endl;
    queue<Vertex*> res;

    vector<Vertex*> points = bfsAll(g, info->getIdStart());
    if(find(points.begin(), points.end(), g.findVertex(info->getIdEnd())) == points.end()) {
        cout << "no path!" << endl;
        return res;
    }

    for(Vertex* point: points) {
        cout << "Points in the path: " << point->getID() << endl;
    }

    queue<Vertex*> path = dijkstraShortestPath(g, info->getIdStart(), info->getIdEnd());
    double distance = distancePath(path);

    if(minutesFromDistance(distance, info->getMeansOfTransportation()) > info->getTimeAvailable()) {
        double time = minutesFromDistance(distance, info->getMeansOfTransportation());
        cout << "There is no time to get from where you are to the point you want!" << endl;
        cout << "However, we have found the quickest way to get there ..."<< endl;
        cout << "It takes "<< time << " minutes "<<endl;
        return path;
    }

    vector<Vertex*> poi;
    for(Vertex* point: points) {
        if(point->getType() != " ") {
            if(info->getPoi().empty())
                poi.push_back(point);
            else if (find(info->getPoi().begin(), info->getPoi().end(), point->getType()) != info->getPoi().end())
                poi.push_back(point);
        }
    }

    res = findPoiInPath(g, poi, info->getIdStart(), info->getIdEnd(), info->getTimeAvailable(), info->getMeansOfTransportation());
    visitedPoi = 0;
    return res;
}


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
}

int hasTime(queue<Vertex*> path, char transportation, int availableTime) {
    double distance = distancePath(path);
    return availableTime - minutesFromDistance(distance, transportation);
}


queue<Vertex*> findPoiInPath(Graph &g, vector<Vertex*> poi, const int &orig, const int &dest, const int &availableTime, char transportation) {

}

//chamar funcao outra vez
    //pôr o static int a 0


int countPOIs(queue<Vertex*> path) {
    int res = 0;
    while(!path.empty()) {
        if(path.front()->getType() != " ") 
            res++;
        path.pop();
    }
    return res;
}

vector<Vertex*> POIsInPath(queue<Vertex*> path) {
    vector<Vertex*> res;
    while(!path.empty()) {
        if(path.front()->getType() != " ")
            res.push_back(path.front());
        path.pop();
    }
    return res;
}



//Encontra todos os pontos acessiveis entre a origem e o final
//Filtra os pontos de interesse
//Encontra todos os caminhos entre pares de pontos de interesse
//Calcula a melhor combinação para percorrer o maximo de pontos dentro do tempo pedido