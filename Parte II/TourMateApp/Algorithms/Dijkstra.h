#ifndef TOURMATEAPP_DIJKSTRA_H
#define TOURMATEAPP_DIJKSTRA_H

#include "../Graph/MutablePriorityQueue.h"
#include "../Graph/Graph.h"
#include <queue>

using namespace std;

queue<Vertex*> dijkstraShortestPath(Graph g, const int &origin, const int &dest);

#endif //TOURMATEAPP_DIJKSTRA_H
