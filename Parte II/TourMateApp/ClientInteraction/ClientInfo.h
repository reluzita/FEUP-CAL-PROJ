#include <string>
#include <vector>
using namespace std;


class ClientInfo{
    private:
        string city; //maybe change this
        string meansOfTransportation; 
        int idStart;
        int idEnd;
        int timeAvailable;
        vector<string> poi;

    public: 
        void setCity(string city);
        void setMeansOfTransportation(string meansOfTransportation);
        void setIdStart(int idStart);
        void setIdEnd(int idEnd);
        void setTimeAvailable(int timeAvailable);
        void setPoi(vector <string> poi);
        string getCity();
        string getMeansOfTransportation();
        int getIdStart();
        int getIdEnd();
        int getTimeAvailable();
        vector<string> getPoi();
        void addPoi(string point);
        void addAllPoi(vector<string> points);
        void removePoi(int index);
        void removeAllPoi();
};
