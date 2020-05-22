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
/** @defgroup Menu menu
 * @{
 *
 * Menu functions
 */


/**
* @brief Main menu function
* @param info - Object with the user's info
* @param g - oriented graph of the city
* @param gbdir - bidirectional graph
* @return Returns an integer to deal in the main
*/
int mainMenu(ClientInfo *info, Graph &g, Graph &gbdir);
/**
* @brief Function that generates the user intended path
* @param info - Object with the user's info
* @param g - oriented graph of the city
* @param gbdir - bidirectional graph
* @return Returns an integer to deal in the mainMenu
*/
int generatePath(ClientInfo* info, Graph &g, Graph &gbdir);
/**
* @brief Function to manage the user preferences
* @param info - Object with the user's info
* @return Returns an integer to deal in the mainMenu
*/
int managePreferences(ClientInfo * info);
/**
* @brief Function to view the map of the city
* @param g - oriented graph of the city
* @return Returns an integer to deal in the mainMenu
*/
int viewMaps(const Graph &g);
/**
* @brief Function to generate a sugestion to the user
* @return Returns an integer to deal in the mainMenu
*/
int supriseMe();


int generateCircularPath(ClientInfo * info, Graph &g, Graph &gbdir);
#endif //TOURMATEAPP_MENU2_H