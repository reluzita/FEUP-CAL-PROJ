#ifndef TOURMATEAPP_BFS_H
#define TOURMATEAPP_BFS_H

#include "../Graph/Graph.h"
#include <queue>
#include <iostream>


/** @defgroup BFS BFS
 * @{
 *
 * BFS algorithm
 */

 /**
* @brief Function that checks if there is a way from source to dest
* @param g - oriented graph of the city
* @param source - id of the source node
* @param dest - id of the destination node
* @return Returns the ids of all the node it goes through from the source to the dest
*/

vector<Vertex*> bfs(Graph g, const int &source, const int &dest);

 /**
* @brief Functions that checks all nodes reachable from the source node
* @param g - oriented graph of the city
* @param source - id of the source node
* @return Returns all the nodes reachable from the source
*/
vector<Vertex*> bfsAll(Graph g, const int &source);

vector<Vertex*> bfsAllPOI(Graph g, const int & source, vector<string> types, int dur);

#endif //TOURMATEAPP_BFS_H
