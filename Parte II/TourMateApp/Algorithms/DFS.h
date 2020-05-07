//
// Created by ineso on 5/4/2020.
//

#ifndef TOURMATEAPP_DFS_H
#define TOURMATEAPP_DFS_H

#include "../Graph/Graph.h"
#include <iostream>

vector<int> dfs(Graph g, const int &source, const int &dest);
bool dfsVisit(const Graph& g,  Vertex *s, Vertex* d, vector<int> & res);

vector<int> dfsTemp(Graph g);
void dfsVisitTemp(const Graph &g, Vertex*v, vector<int> & res);

#endif //TOURMATEAPP_DFS_H
