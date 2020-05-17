#ifndef TOURMATEAPP_BIDIRDIJKSTRA_H
#define TOURMATEAPP_BIDIRDIJKSTRA_H

#include "../Graph/Graph.h"
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include "BFS.h"
using namespace std;


int biDirSearch(int s, int t, int numberNodes);
void bfsAux(list<int> *queue, bool *visited, int *parent);
void addReverseEdges(Graph *reverse, Graph g);



#endif //TOURMATEAPP_BIDIRDIJKSTRA_H
