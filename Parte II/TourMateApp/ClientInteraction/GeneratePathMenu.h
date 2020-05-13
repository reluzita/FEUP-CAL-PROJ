#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../Utils/ReadFiles.h"
#include "../Algorithms/BFS.h"
#include "../Utils/MagicGenerator.h"

using namespace std;

int generatePath(ClientInfo* info);
int pointsMenu(string title, vector<Vertex*> items, string description);