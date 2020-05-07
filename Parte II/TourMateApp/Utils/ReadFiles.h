//
// Created by ineso on 5/4/2020.
//

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

Graph readMap(const string &cityName);
vector<int> readTags(Graph &g , const string &cityName);

#endif //READFILES_H
