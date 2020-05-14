#ifndef TOURMATEAPP_GENERATEPATHMENU_H
#define TOURMATEAPP_GENERATEPATHMENU_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../Utils/util.h"
#include "../Graph/Graph.h"
#include "../Algorithms/BFS.h"

using namespace std;

string getCity();
int getTransportation(string city);
int getStartPoint(const Graph &g);
int getEndPoint(const Graph &g, int orig);
int getAvailableTime();
int pointsMenu(const string& title, const vector<Vertex*>& items, const string& description);

#endif //TOURMATEAPP_GENERATEPATHMENU_H