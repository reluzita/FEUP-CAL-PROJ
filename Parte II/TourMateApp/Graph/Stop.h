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
    int ID;
    string stationName;
    int stopNum;

public:
    MetroStation(){}
    MetroStation(int ID, string stationName, int stopNum): ID(ID), stationName(stationName), stopNum(stopNum) {}
    void setStationName(string stationName){ this->stationName = stationName;}
    int getID() {return ID;}
    string getStationName() {return stationName;}
    int getStopNum() {return stopNum;}
};


#endif //TOURMATEAPP_STOP_H
