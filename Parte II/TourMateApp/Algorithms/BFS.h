//
// Created by ineso on 5/4/2020.
//

#ifndef TOURMATEAPP_BFS_H
#define TOURMATEAPP_BFS_H

#include "../Graph/Graph.h"
#include <queue>
#include <iostream>

vector<int> bfs(Graph g, const int &source, const int &dest);
vector<int> bfsAll(Graph g, const int &source);

#endif //TOURMATEAPP_BFS_H
