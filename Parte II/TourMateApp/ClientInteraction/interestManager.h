#ifndef TOURMATEAPP_INTERESTMANAGER_H
#define TOURMATEAPP_INTERESTMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "ClientInfo.h"
#include "../Utils/util.h"
using namespace std;

int choice(const string& title, const string& description, vector<string> poi);
int addInterest(ClientInfo * info);
int removeInterest(ClientInfo * info);
int viewInterest();


#endif //TOURMATEAPP_INTERESTMANAGER_H