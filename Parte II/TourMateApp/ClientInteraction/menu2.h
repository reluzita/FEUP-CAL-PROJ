#ifndef TOURMATEAPP_MENU2_H
#define TOURMATEAPP_MENU2_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../Utils/ReadFiles.h"
#include "../Algorithms/BFS.h"
#include "../Utils/MagicGenerator.h"
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

int generatePath(ClientInfo* info);
int pointsMenu(string title, vector<Vertex*> items, string description);

#endif //TOURMATEAPP_MENU2_H