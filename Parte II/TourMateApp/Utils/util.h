#ifndef TOURMATEAPP_UTIL_H
#define TOURMATEAPP_UTIL_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include "../Graph/Vertex.h"

using namespace std;

void menu_int_options(int &option, int omin, int nmax, const string &description);
double distancePath(queue<Vertex*> path);
int minutesFromDistance(double distance, const string& transportation);
void trim(string &str);
void verification_int(string &aux);
vector<string> pairToString(const vector<pair<double,double>>& v);

#endif //TOURMATEAPP_UTIL_H
