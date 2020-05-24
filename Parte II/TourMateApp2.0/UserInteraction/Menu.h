#ifndef TOURMATEAPP_MENU_H
#define TOURMATEAPP_MENU_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <zconf.h>
#include "AlgorithmAnalysis.h"

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
int mainMenu(ClientInfo *info, Graph<coord> &g, Graph<coord> &gbdir);
/**
* @brief Function that generates the user intended path
* @param info - Object with the user's info
* @param g - oriented graph of the city
* @param gbdir - bidirectional graph
* @return Returns an integer to deal in the mainMenu
*/
int generatePath(ClientInfo* info, Graph<coord> &g, Graph<coord> &gbdir);
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
int viewMaps(const Graph<coord> &g);
/**
* @brief Function to generate a sugestion to the user
* @return Returns an integer to deal in the mainMenu
*/
int supriseMe();
/*
*
*
*/
int generateCircularPath(ClientInfo * info, Graph<coord> &g, Graph<coord> &gbdir);





#endif //TOURMATEAPP_MENU_H
