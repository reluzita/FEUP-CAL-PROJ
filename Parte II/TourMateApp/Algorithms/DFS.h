//
// Created by ineso on 5/4/2020.
//

#ifndef TOURMATEAPP_DFS_H
#define TOURMATEAPP_DFS_H

#include "../Graph/Graph.h"

vector<int> dfs(Graph g, const int &source, const int &dest);
bool dfsVisit(Graph g,  Vertex *s, Vertex* d, vector<int> & res);

#endif //TOURMATEAPP_DFS_H
