#ifndef TOURMATEAPP_MENU_H
#define TOURMATEAPP_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "../Utils/ReadFiles.h"
#include "../Algorithms/BFS.h"
using namespace std;

int standardMenu(string title, vector<string>items);
void firstQuestion();
void citysMenu();
int whereAreYou(vector<pair<double,double>> v);
int whereToGo(int idStart,Graph g);
string meansOfTransportation(string city);
vector<int>  pointsOfInterest();
int timeAvailable();
vector<string> pairToString(vector<pair<double,double>> v);
vector<int> poiMenu(vector<string> poi);






#endif //TOURMATEAPP_MENU_H