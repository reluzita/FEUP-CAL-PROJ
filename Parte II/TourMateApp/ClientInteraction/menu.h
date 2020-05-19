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

#include "GeneratePathMenu.h"

using namespace std;

int mainMenu(ClientInfo *info, Graph &g);
int generatePath(ClientInfo* info, Graph &g);
int managePreferences(ClientInfo * info);
int viewMaps();
int supriseMe();

#endif //TOURMATEAPP_MENU2_H