//
// Created by ineso on 5/12/2020.
//

#ifndef TOURMATEAPP_MAGICGENERATOR_H
#define TOURMATEAPP_MAGICGENERATOR_H

//Encontra todos os pontos acessiveis entre a origem e o final
//Filtra os pontos de interesse
//Encontra todos os caminhos entre pares de pontos de interesse
//Calcula a melhor combinação para percorrer o maximo de pontos dentro do tempo pedido

#include <queue>
#include "../Graph/Graph.h"
#include "../Algorithms/BFS.h"
#include "../Algorithms/Dijkstra.h"
#include "../ClientInteraction/interestManager.h"
//#include "../Utils/util.h"
#include <algorithm>
#include <vector>

queue<Vertex*> magicGenerator(Graph &g, ClientInfo* info);


#endif //TOURMATEAPP_MAGICGENERATOR_H
