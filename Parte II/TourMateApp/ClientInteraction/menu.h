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

Graph searchGraph(const string& city, bool biDir, bool publicTransportation);
int mainMenu(ClientInfo *info);
int generatePath(ClientInfo* info);
int managePreferences(ClientInfo * info);
int viewMaps();
int supriseMe();

#endif //TOURMATEAPP_MENU2_H