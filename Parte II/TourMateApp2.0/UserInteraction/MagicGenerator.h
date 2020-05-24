#ifndef TOURMATEAPP_MAGICGENERATOR_H
#define TOURMATEAPP_MAGICGENERATOR_H

#include <queue>
#include <cmath>
#include "InterestManager.h"

using namespace std;

struct OptimizedPath{
    queue<Vertex<coord>*> path;
    vector<int> visitedId;
};

OptimizedPath magicGenerator(Graph<coord> &g, ClientInfo* info);
OptimizedPath circularPath(Graph<coord> &g, ClientInfo* info);
void metroPathGenerator(Graph<coord> &g, ClientInfo* info);
OptimizedPath findPoiInPath(Graph<coord> &g, ClientInfo* info, const vector<Vertex<coord>*> &poi, const int &orig, const int &dest, const int &availableTime);

queue<Vertex<coord>*> joinQueue(queue<Vertex<coord>*> frontQ, queue<Vertex<coord>*> backQ);
vector<Vertex<coord>*> POIsInPath(queue<Vertex<coord>*> path, vector<Vertex<coord>*> poi);

int getTransportation(bool circular);
int getAvailableTime();
string getTypeStartPoint();
int getStartPoint(const Graph<coord> &g, const string &typeStart, bool circular);
string getTypeEndPoint();
int getEndPoint(Graph<coord> &g, int orig, const string &typeEnd, const int &availableTime);
#endif //TOURMATEAPP_MAGICGENERATOR_H
