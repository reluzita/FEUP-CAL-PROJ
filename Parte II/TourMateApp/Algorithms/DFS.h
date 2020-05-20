#ifndef TOURMATEAPP_DFS_H
#define TOURMATEAPP_DFS_H

#include "../Graph/Graph.h"
#include <iostream>

/** @defgroup DFS DFS 
 * @{
 *
 * DFS  Algorithm
 */
 /**
* @brief Dfs algorithm
* @param g - oriented graph of the city
* @param source - id of the source node
* @param dest - id of the destination node
* @return Returns the ids of all the node it goes through from the source to the dest
*/
vector<int> dfs(Graph g, const int &source, const int &dest);
 /**
* @brief 
* @param g - oriented graph of the city
* @param source -  source node
* @param dest - destination node
* @param res - ...
* @return ..
*/
bool dfsVisit(const Graph& g,  Vertex *s, Vertex* d, vector<int> & res);
 /**
* @brief Dfs algorithm
* @param g - oriented graph of the city
* @param source -  source node
* @return  ...
*/
vector<int> dfsAll(Graph g, const int &source);
 /**
* @brief Dfs algorithm
* @param g - oriented graph of the city
* @param v -  
* @param res - 
* @return ...
*/
void dfsVisitAll(const Graph &g, Vertex*v, vector<int> & res);

#endif //TOURMATEAPP_DFS_H
