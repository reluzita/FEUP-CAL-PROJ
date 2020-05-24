#ifndef TOURMATEAPP_UTIL_H
#define TOURMATEAPP_UTIL_H

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

using namespace std;

/** @defgroup util util
 * @{
 *
 * Utils functions to general use in the program 
 */



/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void menu_int_options(int &option, int omin, int nmax, const string &description);
/**
* @brief Function that displays menus
* @param title - Title of the menu
* @param options - Options of the menu
* @param description - Description of the menu 
* @return Returns the index of the option choosen in the options vector
*/
int displayMenu(const string &title, vector<string>options,const string &description);

/**
* @brief Generates a random duration for each type of point of interest 
* @param type - Type of point of interest
* @return Returns a vector of strings made with the pairs
*/

void showPathWithMetro(GraphViewer* gv, Graph<coord> g, queue<Vertex<coord>*> path1, queue<Vertex<coord>*> path2, vector<int> visitedPoi,  MetroStation origStop, MetroStation endStop);
/**
* @brief Function to create a GraphViewer  with all the points of the city
* @param g - Graph to view
* @return Returns a graphViewer
*/
GraphViewer* createMapViewer(const Graph<coord> &g);
/**
* @brief Function to create a GraphViewer with only the points in the path
* @param g - Graph to view
* @return Returns a graphViewer
*/
void showPath(GraphViewer* gv, queue<Vertex<coord>*> path, vector<int> visitedPoi);
/**
* @brief Function that differentiates the points where the user stopped
* @param gv - GraphViewer
* @param points - Points the user stopped
*/
void showPOI(GraphViewer* gv, const vector<Vertex<coord>*> &points, const int &orig);


string poiName(Vertex<coord> * v);

GraphViewer* createRealPOIPath(const Graph<coord> &g, queue<Vertex<coord>*> path, vector<int> visitedPoi);

#endif //TOURMATEAPP_UTIL_H
