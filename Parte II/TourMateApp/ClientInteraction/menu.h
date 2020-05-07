#ifndef TOURMATEAPP_MENU_H
#define TOURMATEAPP_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "../Utils/util.cpp"
#include "../Utils/ReadFile.cpp"
#include "../Graph/Graph.cpp"
using namespace std;

int standardMenu(string title, vector<string>items);
void firstQuestion();
void citysMenu();
int whereAreYou(vector<pair<double,double>> v);
int whereToGo(int idStart,Graph g);
string meansOfTransportation();
vector<int>  pointsOfInterest();
int timeAvailable();
vector<string> pairToString(vector<pair<double,double>> v);
vector<int> poiMenu(vector<string> poi);






#endif //TOURMATEAPP_MENU_H