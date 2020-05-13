#ifndef TOURMATEAPP_INTERESTMANAGER_H
#define TOURMATEAPP_INTERESTMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "ClientInfo.h"
#inclue "../Utils/util.h"
using namespace std;

int choice(string title, string description, vector<string> poi);
void addInterest(ClientInfo * info);
void removeInterest(ClientInfo * info);
void viewInterest(ClientInfo* info);


#endif //TOURMATEAPP_INTERESTMANAGER_H