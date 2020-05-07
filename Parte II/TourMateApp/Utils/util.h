//
// Created by ineso on 5/7/2020.
//

#ifndef TOURMATEAPP_UTIL_H
#define TOURMATEAPP_UTIL_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include "../Graph/Vertex.h"

using namespace std;

void menu_int_options(int &option, int omin, int nmax);
double distancePath(queue<Vertex*> path);

#endif //TOURMATEAPP_UTIL_H
