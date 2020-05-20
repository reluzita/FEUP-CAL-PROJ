#ifndef TOURMATEAPP_BIDIRDIJKSTRA_H
#define TOURMATEAPP_BIDIRDIJKSTRA_H

#include "../Graph/Graph.h"
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include "BFS.h"
using namespace std;
/** @defgroup Bidirectional Dijkstra 
 * @{
 *
 * Bidirectional Dijkstra Algorithm
 */

 /**
* @brief Function that checks if there is a way from source to dest
* @param g - oriented graph of the city
* @param source - id of the source node
* @param dest - id of the destination node
* @return Returns all the node it goes through from the source to the dest
*/

int biDirSearch(int s, int t, int numberNodes);
void bfsAux(list<int> *queue, bool *visited, int *parent);
void addReverseEdges(Graph *reverse, Graph g);



#endif //TOURMATEAPP_BIDIRDIJKSTRA_H
