#ifndef TOURMATEAPP_GRAPHVIEW_H
#define TOURMATEAPP_GRAPHVIEW_H

#include "../Graph/Graph.h"
#include <graphviewer.h>

GraphViewer* createMapViewer(const Graph &g);
GraphViewer* createPathViewer(const Graph &g, queue<Vertex*> path);
void showPOI(GraphViewer* gv, const vector<int> &points);

#endif //TOURMATEAPP_GRAPHVIEW_H
