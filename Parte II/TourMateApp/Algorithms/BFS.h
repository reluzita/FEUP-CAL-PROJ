#ifndef TOURMATEAPP_BFS_H
#define TOURMATEAPP_BFS_H

#include "../Graph/Graph.h"
#include <queue>
#include <iostream>

vector<Vertex*> bfs(Graph g, const int &source, const int &dest);
vector<Vertex*> bfsAll(Graph g, const int &source);

#endif //TOURMATEAPP_BFS_H
