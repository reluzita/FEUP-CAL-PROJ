//
// Created by ineso on 5/4/2020.
//

#ifndef READFILES_H
#define READFILES_H

#include <string>
#include <iostream>
#include <fstream>
#include <graphviewer.h>
#include "../Graph/Graph.h"

Graph readMap(const string& nodesfile, const string& edgesfile);

#endif //READFILES_H
