#ifndef TOURMATEAPP_MENU2_H
#define TOURMATEAPP_MENU2_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../Utils/ReadFiles.h"
#include "../Algorithms/BFS.h"
#include "../Utils/util.h"
#include "../Utils/MagicGenerator.h"
#include "../Utils/GraphView.h"
#include "GeneratePathMenu.h"

using namespace std;

/*int standardMenu(string title, vector<string>items, string description,bool firstMenu);
int firstQuestion(ClientInfo *info, Graph g);
int multipleCitysMenu(ClientInfo *info, Graph g);
int citysMenu(ClientInfo *info, Graph g);
int whereAreYou(Graph g);
int whereToGo(int idStart,Graph g);
string meansOfTransportation(string city);
vector<string> pointsOfInterest();
int timeAvailable();
vector<int> poiMenu(vector<string> poi);
int cantGetThere();*/

Graph findCityGraph(const string &city);
int mainMenu(ClientInfo *info);
int generatePath(ClientInfo* info);
int managePreferences(ClientInfo * info);
int viewMaps();
int supriseMe();

#endif //TOURMATEAPP_MENU2_H