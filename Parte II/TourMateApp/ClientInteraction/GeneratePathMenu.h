#ifndef TOURMATEAPP_GENERATEPATHMENU_H
#define TOURMATEAPP_GENERATEPATHMENU_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../Utils/util.h"
#include "../Graph/Graph.h"
#include "../Algorithms/BFS.h"
#include "../Utils/GraphView.h"

using namespace std;

string getTypeStartPoint();
string getTypeEndPoint();
int getTransportation();
int getStartPoint(const Graph &g, const string &typeStart);
int getEndPoint(const Graph &g, int orig, const string &typeEnd);
int getAvailableTime();
//int pointsMenu(const string& title, const vector<Vertex*>& items, const string& description);

#endif //TOURMATEAPP_GENERATEPATHMENU_H