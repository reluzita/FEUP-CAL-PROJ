//
// Created by ineso on 5/5/2020.
//

#ifndef TOURMATEAPP_GRAPHVIEW_H
#define TOURMATEAPP_GRAPHVIEW_H

#include "../Graph/Graph.h"
#include <graphviewer.h>

GraphViewer* createMapViewer(const Graph &g);
GraphViewer* createPathViewer(const Graph &g, queue<Vertex*> path);
void showPOI(GraphViewer* gv, vector<int> points);

#endif //TOURMATEAPP_GRAPHVIEW_H
