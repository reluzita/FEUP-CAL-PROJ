#include "ReadFiles.h"

using namespace std;

Graph readMap(bool bidir)
{
    Graph graph;

    readNodesFile(graph);
    readLatLonFile(graph);
    readEdgesFile(graph, bidir);
    readTags(graph);

    readBusFile(graph);
    readMetroFile(graph);

    graph.setBiDir(bidir);
    return graph;
}

void readNodesFile(Graph &graph){
    string nodesfile = "../resources/nodes_x_y.txt";
    ifstream nodes;
    string line;
    int numNodes;

    nodes.open(nodesfile);

    getline(nodes, line);
    numNodes = stoi(line);

    for (int i = 0; i < numNodes; i++) {
        getline(nodes, line);
        int id;
        double x, y;
        size_t pos = line.find(',');
        id = stoi(line.substr(1, pos));
        line.erase(0, pos + 2);
        pos = line.find(',');
        x = stof(line.substr(0, pos));
        line.erase(0, pos + 2);
        pos = line.find(')');
        y = stof(line.substr(0, pos));
        graph.addVertex(id, x, y);
    }
    nodes.close();

}

void readEdgesFile(Graph &graph, bool bidir){

    string edgesfile = "../resources/edges.txt";
    ifstream edges;
    string line;

    edges.open(edgesfile);

    getline(edges, line);
    int numEdges = stoi(line);
    for (int i = 0; i < numEdges; i++) {
        getline(edges, line);
        int n1, n2;
        size_t pos = line.find(',');
        n1 = stoi(line.substr(1, pos));
        line.erase(0, pos + 2);
        pos = line.find(')');
        n2 = stoi(line.substr(0, pos));

        Vertex* v1 = graph.findVertex(n1);
        Vertex* v2 = graph.findVertex(n2);
        double weight = v1->distanceLatLon(v2);
        if(bidir)
            graph.addBiDirEdge(n1, n2, weight);
        else
            graph.addEdge(n1, n2, weight);
    }
    edges.close();
}

void readLatLonFile(Graph &graph){
    string latlonfile = "../resources/nodes_lat_lon.txt";
    ifstream latlon;
    string line;
    int numNodes;

    latlon.open(latlonfile);

    getline(latlon, line);
    numNodes = stoi(line);

    for (int i = 0; i < numNodes; i++) {
        getline(latlon, line);
        int id;
        double lat, lon;
        size_t pos = line.find(',');
        id = stoi(line.substr(1, pos));
        line.erase(0, pos + 2);
        pos = line.find(',');
        lat = stof(line.substr(0, pos));
        line.erase(0, pos + 2);
        pos = line.find(')');
        lon = stof(line.substr(0, pos));
        Vertex* v = graph.findVertex(id);
        v->setLat(lat);
        v->setLon(lon);
        graph.checkLatLon(lat, lon);
    }
    latlon.close();
}

vector<int> readTags(Graph &g) {
    srand(time(NULL));

    string tagfile = "../resources/tags.txt";

    vector<int> res;
    ifstream file;
    string line;
    int numTypes;

    file.open(tagfile);

    getline(file, line);
    numTypes = stoi(line);
    for (int i = 0; i < numTypes; i++) {
        string type;
        getline(file, type);
        type.erase(0, 8);
        int numNodes;
        getline(file, line);
        numNodes = stoi(line);
        for(int j = 0; j < numNodes; j++) {
            getline(file, line);
            Vertex* v = g.findVertex(stoi(line));
            v->setType(type);
            int dur = generateRandomTime(type);
            v->setDuration(dur);
            res.push_back(stoi(line));
        }
    }
    return res;
}

void readMetroFile(Graph &g) {
    ifstream file;
    string line;
    int numStations;

    file.open("../resources/metro_routes.txt");
    
    getline(file, line);
    numStations = stoi(line);

    for(int i = 0; i < numStations; i++){
        auto metroStation = new MetroStation();

        getline(file, line);
        size_t pos = line.find(',');

        Vertex* v = g.findVertex(stoi(line.substr(1, pos-1)));
        if(v == nullptr)
            continue;

        line.erase(0, pos + 2);

        pos = line.find(',');
        metroStation->setStationName(line.substr(1, pos-2));
        line.erase(0, pos + 2);

        pos = line.find('[');
        line.erase(0, pos+1);

        while(line.empty()){
            pos = line.find(',');
            if(pos == string::npos){
                pos = line.find(']');
            }
            metroStation->addLine(line.substr(1, pos-2));
            line.erase(0, pos+2);
        }
       
        v->setMetroStation(metroStation);
    }

}


void readBusFile(Graph &g) {
    ifstream file;
    file.open("../resources/stcp_routes.txt");

    string line;
    getline(file, line);
    int n = stoi(line);
    for (int i = 0; i < n; i++) {
        auto busStop = new BusStop();
        
        getline(file, line);
        size_t pos = line.find(',');
        Vertex* v = g.findVertex(stoi(line.substr(1, pos)));
        if(v == nullptr)
            continue;
        line.erase(0, pos + 2);
        
        pos = line.find(',');
        busStop->setCodStop(line.substr(1, pos-1));
        line.erase(0, pos + 2);

        pos = line.find(',');
        busStop->setCodLine(line.substr(1, pos-1));
        line.erase(0, pos + 2);

        pos = line.find(',');
        busStop->setCodZone(line.substr(1, pos-1));
        line.erase(0, pos + 2);
        
        pos = line.find(',');
        busStop->setCounty(line.substr(1, pos-1));
        line.erase(0, pos + 2);

        pos = line.find(',');
        busStop->setParish(line.substr(1, pos-1));
        line.erase(0, pos + 2);

        pos = line.find(',');
        busStop->setAddress(line.substr(1, pos-1));
        line.erase(0, pos + 2);

        pos = line.find(',');
        busStop->setType(line.substr(1, pos-1));
        line.erase(0, pos + 2);
        
        v->setBusStop(busStop);
    }

}