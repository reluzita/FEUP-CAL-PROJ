#ifndef TOURMATEAPP_MAGICGENERATOR_H
#define TOURMATEAPP_MAGICGENERATOR_H

//Encontra todos os pontos acessiveis entre a origem e o final
//Filtra os pontos de interesse
//Encontra todos os caminhos entre pares de pontos de interesse
//Calcula a melhor combinação para percorrer o maximo de pontos dentro do tempo pedido

#include <queue>
#include "../Graph/Graph.h"
#include "../Algorithms/BFS.h"
#include "../Algorithms/Dijkstra.h"
#include "../ClientInteraction/interestManager.h"
//#include "../Utils/util.h"
#include <algorithm>
#include <vector>
using namespace std;

struct OptimizedPath{
    queue<Vertex*> path;
    vector<int> visitedId;
};

queue<Vertex*> magicGenerator(Graph &g, ClientInfo* info);
OptimizedPath findPoiInPath(Graph &g, vector<Vertex*> poi, const int &orig, const int &dest, const int &availableTime, char transportation);
template <class T>
queue<T> joinQueue(queue<T> frontQ, queue<T> backQ);
int hasTime(queue<Vertex*> path, char transportation, int availableTime);
int countPOIs(queue<Vertex*> path, vector<Vertex*> poi);
vector<Vertex*> POIsInPath(queue<Vertex*> path, vector<Vertex*> poi);


#endif //TOURMATEAPP_MAGICGENERATOR_H
