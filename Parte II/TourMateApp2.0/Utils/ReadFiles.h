#ifndef TOURMATEAPP_READFILES_H
#define TOURMATEAPP_READFILES_H

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "../UserInteraction/MagicGenerator.h"

using namespace std;

Graph<coord> readMap(bool bidir);

void readNodesFile(Graph<coord> &graph);

void readEdgesFile(Graph<coord> &graph, bool bidir);

void readLatLonFile(Graph<coord> &graph);

vector<int> readTags(Graph<coord> &g);

void readMetroFile(Graph<coord> &g);

int generateRandomTime(Vertex<coord>* v);

int checkRealPoi(int id);

#endif //TOURMATEAPP_READFILES_H
