#ifndef TOURMATEAPP_READFILES_H
#define TOURMATEAPP_READFILES_H

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "../UserInteraction/MagicGenerator.h"

using namespace std;

/** @defgroup ReadFiles ReadFiles
 * @{
 *
 * Functions to read the files 
 */

/**
* @brief F
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
* @return ...
*/
Graph<coord> readMap(bool bidir);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void readNodesFile(Graph<coord> &graph);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void readEdgesFile(Graph<coord> &graph, bool bidir);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void readLatLonFile(Graph<coord> &graph);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
vector<int> readTags(Graph<coord> &g);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void readMetroFile(Graph<coord> &g);

int generateRandomTime(Vertex<coord>* v);
int checkRealPoi(int id);

#endif //TOURMATEAPP_READFILES_H
