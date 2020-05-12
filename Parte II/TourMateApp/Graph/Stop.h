//
// Created by ineso on 5/12/2020.
//

#ifndef TOURMATEAPP_STOP_H
#define TOURMATEAPP_STOP_H

#include <string>
#include <vector>

using namespace std;

class BusStop {
    string codStop;
    string codLine;
    string codZone;
    string county;
    string parish;
    string address;
    string type;

public:
    BusStop(){}
    //BusStop(string codStop, string codLine, string codZone, string concelho, string freguesia, string address, string type): codStop(codStop), codLine(codLine), codZone(codZone), concelho(concelho), freguesia(freguesia), address(address), type(type) {}
    void setCodStop(string codStop){ this->codStop =codStop;}
    void setCodLine(string codLine){ this->codLine =codLine;}
    void setCodZone(string codZone){ this->codZone = codZone;}
    void setCounty(string county){ this->county = county;}
    void setParish(string parish){ this->parish = parish;}
    void setAddress(string address){ this->address = address;}
    void setType(string type){ this->type = type;}
};

class MetroStation {
    string stationName;
    vector<string> lines;

public:
    MetroStation(){}
    MetroStation(string stationName, vector<string> lines): stationName(stationName), lines(lines) {}
    void setStationName(string stationName){ this->stationName = stationName;}
    void addLine(string line){this->lines.push_back(line);}
};


#endif //TOURMATEAPP_STOP_H
