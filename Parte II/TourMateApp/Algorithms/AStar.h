#ifndef TOURMATEAPP_ASTAR_H
#define TOURMATEAPP_ASTAR_H


#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>
#include <set>
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>
#include "../Graph/Graph.h"
#include <queue> 
#include <cmath>


queue<Vertex*> aStar(Graph g, const int &origin, const int &dest);
using namespace std; 
  
#define ROW 9 
#define COL 10 

#endif //TOURMATEAPP_ASTAR_H
