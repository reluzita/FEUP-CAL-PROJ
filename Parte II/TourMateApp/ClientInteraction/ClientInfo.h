#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class ClientInfo{
    private:
        string city; //maybe change this
        char meansOfTransportation;
        int idStart;
        int idEnd;
        int timeAvailable;
        vector<string> poi;

    public: 
        void setCity(string city);
        void setMeansOfTransportation(char meansOfTransportation);
        void setIdStart(int idStart);
        void setIdEnd(int idEnd);
        void setTimeAvailable(int timeAvailable);
        void setPoi(vector <string> poi);
        string getCity();
        char getMeansOfTransportation();
        int getIdStart();
        int getIdEnd();
        int getTimeAvailable();
        vector<string> getPoi();
        void addPoi(const string &point);
        void addAllPoi(const vector<string> &points);
        void removePoi(const string& point);
        void removeAllPoi();
};
