#ifndef TOURMATEAPP_INTERESTMANAGER_H
#define TOURMATEAPP_INTERESTMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "ClientInfo.h"
using namespace std;

int addInterest(ClientInfo * info);
int removeInterest(ClientInfo * info);
int viewInterest();


#endif //TOURMATEAPP_INTERESTMANAGER_H