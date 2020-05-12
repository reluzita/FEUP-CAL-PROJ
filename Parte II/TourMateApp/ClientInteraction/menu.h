#ifndef TOURMATEAPP_MENU_H
#define TOURMATEAPP_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../Utils/ReadFiles.h"
#include "../Algorithms/BFS.h"
#include "ClientInfo.h"
using namespace std;

int standardMenu(string title, vector<string>items, string description,bool firstMenu);
int firstQuestion(ClientInfo *info, Graph g);
int multipleCitysMenu(ClientInfo *info, Graph g);
int citysMenu(ClientInfo *info, Graph g);
int whereAreYou(vector<pair<double,double>> v);
int whereToGo(int idStart,Graph g);
string meansOfTransportation(string city);
vector<string> pointsOfInterest();
int timeAvailable();
vector<int> poiMenu(vector<string> poi);
int cantGetThere();





#endif //TOURMATEAPP_MENU_H