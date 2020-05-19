#ifndef TOURMATEAPP_GRAPHVIEW_H
#define TOURMATEAPP_GRAPHVIEW_H

#include "../Graph/Graph.h"
#include <graphviewer.h>
#include <algorithm>

GraphViewer* createMapViewer(const Graph &g);
GraphViewer* createPathViewer(const Graph &g, queue<Vertex*> path, vector<int> visitedPoi);
void showPOI(GraphViewer* gv, const vector<Vertex*> &points);

#endif //TOURMATEAPP_GRAPHVIEW_H
