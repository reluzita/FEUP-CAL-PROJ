#ifndef TOURMATEAPP_GRAPHVIEW_H
#define TOURMATEAPP_GRAPHVIEW_H


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <queue>
#include "graphviewer.h"
#include "../UserInteraction/ClientInfo.h"


GraphViewer* createMapViewer(const Graph<coord> &g);

GraphViewer* createRealPOIPath(const Graph<coord> &g, queue<Vertex<coord>*> path, vector<int> visitedPoi);

void showPath(GraphViewer* gv, queue<Vertex<coord>*> path, vector<int> visitedPoi);

void showPOI(GraphViewer* gv, const vector<Vertex<coord>*> &points, const int &orig);

void showPathWithMetro(GraphViewer* gv, Graph<coord> g, queue<Vertex<coord>*> path1, queue<Vertex<coord>*> path2, vector<int> visitedPoi,  MetroStation origStop, MetroStation endStop);

string poiName(Vertex<coord> * v);



#endif //TOURMATEAPP_GRAPHVIEW_H
