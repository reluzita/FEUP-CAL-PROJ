#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "Utils/ReadFiles.h"

int main() {
    Graph g = readMap("C:\\Users\\ineso\\OneDrive\\Documentos\\Ines-Universidade\\2 ano\\2 semestre\\CAL-Proj\\Parte II\\TourMateApp\\resources\\GridGraphs\\8x8\\nodes.txt","C:\\Users\\ineso\\OneDrive\\Documentos\\Ines-Universidade\\2 ano\\2 semestre\\CAL-Proj\\Parte II\\TourMateApp\\resources\\GridGraphs\\8x8\\edges.txt" );
    cout << "Acabou yey" << endl;
    return 0;
}
