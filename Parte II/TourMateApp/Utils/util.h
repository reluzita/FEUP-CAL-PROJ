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

int menu_int_options(int &option, int omin, int nmax, string description);
double distancePath(queue<Vertex*> path);
void trim(string &str);
void verification_int(string &aux);

#endif //TOURMATEAPP_UTIL_H
