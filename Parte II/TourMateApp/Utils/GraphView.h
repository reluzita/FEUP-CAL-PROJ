#ifndef TOURMATEAPP_GRAPHVIEW_H
#define TOURMATEAPP_GRAPHVIEW_H

#include "../Graph/Graph.h"
#include <graphviewer.h>
#include <algorithm>


/** @defgroup GraphViewer GraphViewer
 * @{
 *
 * Functions to view the Graph
 */

/**
* @brief Function to create a GraphViewer  with all the points of the city
* @param g - Graph to view
* @return Returns a graphViewer
*/
GraphViewer* createMapViewer(const Graph &g);
/**
* @brief Function to create a GraphViewer with only the points in the path
* @param g - Graph to view
* @return Returns a graphViewer
*/
GraphViewer* createPathViewer(const Graph &g, queue<Vertex*> path, vector<int> visitedPoi);
/**
* @brief Function that differentiates the points where the user stopped
* @param gv - GraphViewer
* @param points - Points the user stopped
*/
void showPOI(GraphViewer* gv, const vector<Vertex*> &points);

#endif //TOURMATEAPP_GRAPHVIEW_H
