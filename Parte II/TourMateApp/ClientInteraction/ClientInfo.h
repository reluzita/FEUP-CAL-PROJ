#include <string>
#include <vector>
#include <algorithm>
#include "../Graph/Graph.h"

using namespace std;


class ClientInfo{
    private:
        char meansOfTransportation;
        int idStart;
        int idEnd;
        int timeAvailable;
        vector<string> poi;
        double counterFactor;
        Graph poiGraph;

    public:
        void startGraph(Graph g);
        double getDistance(Graph g,int orig, int end);
        void setMeansOfTransportation(char meansOfTransportation);
        void setIdStart(int idStart);
        void setIdEnd(int idEnd);
        void setTimeAvailable(int timeAvailable);
        void setPoi(vector <string> poi);
        void setCounterFactor(double factor);
        char getMeansOfTransportation();
        int getIdStart();
        int getIdEnd();
        int getTimeAvailable();
        vector<string> getPoi();
        double getCounterFactor();
        void addPoi(const string &point);
        void addAllPoi(const vector<string> &points);
        void removePoi(const string& point);
        void removeAllPoi();
};
