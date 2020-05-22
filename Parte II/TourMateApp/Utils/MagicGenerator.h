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
#include "../Utils/GraphView.h"
#include <algorithm>
#include <vector>
using namespace std;

struct OptimizedPath{
    queue<Vertex*> path;
    vector<int> visitedId;
};


OptimizedPath magicGenerator(Graph &g, ClientInfo* info);
OptimizedPath circularPath(Graph &g, ClientInfo* info);
void metroPathGenerator(Graph &g, ClientInfo* info);

OptimizedPath findPoiInPath(Graph &g, const vector<Vertex*> &poi, const int &orig, const int &dest, const int &availableTime, char transportation);

queue<Vertex*> joinQueue(queue<Vertex*> frontQ, queue<Vertex*> backQ);
int hasTime(queue<Vertex*> path, char transportation, int availableTime);
vector<Vertex*> POIsInPath(queue<Vertex*> path, vector<Vertex*> poi);
OptimizedPath circularPath(Graph &g, ClientInfo* info);
int pathTime(queue<Vertex*> path, char transportation);


#endif //TOURMATEAPP_MAGICGENERATOR_H
