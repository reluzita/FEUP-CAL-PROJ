#ifndef READFILES_H
#define READFILES_H

#include <string>
#include <iostream>
#include <fstream>
#include <graphviewer.h>
#include <cmath>
#include <algorithm>
#include "../Graph/Graph.h"
#include "util.h"

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
Graph readMap(bool bidir);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void readNodesFile(Graph &graph);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void readEdgesFile(Graph &graph, bool bidir);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void readLatLonFile(Graph &graph);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
vector<int> readTags(Graph &g);
/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void readMetroFile(Graph &g);

#endif //READFILES_H
