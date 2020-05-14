#ifndef TOURMATEAPP_UTIL_H
#define TOURMATEAPP_UTIL_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include "../Graph/Vertex.h"

using namespace std;

void menu_int_options(int &option, int omin, int nmax, const string &description);
int displayMenu(const string &title, vector<string>options,const string &description);
double distancePath(queue<Vertex*> path);
int minutesFromDistance(double distance, const char& transportation);
void trim(string &str);
void verification_int(string &aux);
vector<string> pairToString(const vector<pair<double,double>>& v);
int generateRandomTime(string type);

#endif //TOURMATEAPP_UTIL_H
