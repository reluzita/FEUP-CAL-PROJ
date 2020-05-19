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

Graph readMap(bool bidir);
void readNodesFile(Graph &graph);
void readEdgesFile(Graph &graph, bool bidir);
void readLatLonFile(Graph &graph);
vector<int> readTags(Graph &g);
void readMetroFile(Graph &g);
void readBusFile(Graph &g);

#endif //READFILES_H
