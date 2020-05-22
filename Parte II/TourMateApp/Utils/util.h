#ifndef TOURMATEAPP_UTIL_H
#define TOURMATEAPP_UTIL_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include "../Graph/Vertex.h"

using namespace std;

/** @defgroup util util
 * @{
 *
 * Utils functions to general use in the program 
 */


/**
* @brief Function that checks if the option from an integer menu is valid 
* @param option - Option inserted by the user
* @param omin - Minimum integer option valid
* @param nmax - Maximum integer option valid
* @param description - Description of the menu 
*/
void menu_int_options(int &option, int omin, int nmax, const string &description);
/**
* @brief Function that displays menus
* @param title - Title of the menu
* @param options - Options of the menu
* @param description - Description of the menu 
* @return Returns the index of the option choosen in the options vector
*/
int displayMenu(const string &title, vector<string>options,const string &description);
/**
* @brief Function that calculates the total distance of a path
* @param path - path whose distance is being calculated
* @return Returns the total distance of the path
*/
double distancePath(queue<Vertex*> path);
/**
* @brief Function that calculates the time taken to do a path
* @param distance - Total distance of the path
* @param transportation - Mean of transportation 
* @return Returns the time taken to do the path
*/
int minutesFromDistance(double distance, const char& transportation);
/**
* @brief Function that takes a vector of pairs and makes it a vector of strings
* @param v - vector of pairs to be transformed in string
* @return Returns a vector of strings made with the pairs
*/
vector<string> pairToString(const vector<pair<double,double>>& v);
/**
* @brief Generates a random duration for each type of point of interest 
* @param type - Type of point of interest
* @return Returns a vector of strings made with the pairs
*/
int generateRandomTime(const string &type);

#endif //TOURMATEAPP_UTIL_H
