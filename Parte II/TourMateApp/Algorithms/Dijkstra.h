#ifndef TOURMATEAPP_DIJKSTRA_H
#define TOURMATEAPP_DIJKSTRA_H

#include "../Graph/MutablePriorityQueue.h"
#include "../Graph/Graph.h"
#include <queue>

using namespace std;
/** @defgroup Dijkstra Dijsktra 
 * @{
 *
 * Dijkstra's  Algorithm
 */
 /**
* @brief Dijkstra's Algorithm
* @param g - oriented graph of the city
* @param origin - 
* @param dest - 
* @return 
*/

queue<Vertex*> dijkstraShortestPath(Graph g, const int &origin, const int &dest);

#endif //TOURMATEAPP_DIJKSTRA_H
