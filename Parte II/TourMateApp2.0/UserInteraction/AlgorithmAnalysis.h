#ifndef TOURMATEAPP_ALGORITHMANALYSIS_H
#define TOURMATEAPP_ALGORITHMANALYSIS_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "../Utils/ReadFiles.h"
using namespace std;

void compareAllSmallPath(Graph<coord> &g);
void compareAllBigPath(Graph<coord> &g);
void compareBidirectional(Graph<coord> &g);
void compareDFSBFS(Graph<coord> &g);







#endif //TOURMATEAPP_ALGORITHMANALYSIS_H
