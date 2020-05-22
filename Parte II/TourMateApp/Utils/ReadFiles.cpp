#include "ReadFiles.h"

using namespace std;

Graph readMap(bool bidir)
{
    Graph graph;

    readNodesFile(graph);
    readLatLonFile(graph);
    readEdgesFile(graph, bidir);
    vector<int> tags = readTags(graph);
    readMetroFile(graph);

    graph.setBiDir(bidir);
    return graph;
}

void readNodesFile(Graph &graph){   
    string nodesfile = "../resources/porto_strong_nodes_xy.txt";
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
        line.erase(0, pos + 1);
        pos = line.find(',');
        x = stof(line.substr(0, pos));
        line.erase(0, pos + 1);
        pos = line.find(')');
        y = stof(line.substr(0, pos));
        graph.addVertex(id, x, y);
    }
    nodes.close();
}

void readEdgesFile(Graph &graph, bool bidir){

    string edgesfile = "../resources/porto_strong_edges.txt";
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
        line.erase(0, pos + 1);
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
    string latlonfile = "../resources/porto_strong_nodes_latlng.txt";
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
        lon = stof(line.substr(0, pos));
        line.erase(0, pos + 2);
        pos = line.find(')');
        lat = stof(line.substr(0, pos));
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
        getline(file, line);
        size_t pos = line.find(',');

        int ID = stoi(line.substr(1, pos));

        line.erase(0, pos + 2);

        pos = line.find(',');
        string stationName = line.substr(0, pos);
        line.erase(0, pos + 2);

        int numStop = stoi(line.substr(0, pos));
       
        MetroStation ms(ID, stationName, numStop);
        g.addMetroStation(ms);
    }
}

Graph readDistanceFile(Graph &graph, string filename){
    ifstream file;
    string line;
    int numNodes;

    Graph res;
    for(Vertex* vertex: graph.getVertexSet()) {
        res.addVertex(vertex->getID(), 0, 0);
    }

    file.open(filename);

    getline(file, line);
    numNodes = stoi(line);

    for (int i = 0; i < numNodes; i++) {
        getline(file, line);
        int id1, id2;
        double dist;
        size_t pos = line.find(',');
        id1 = stoi(line.substr(1, pos));
        line.erase(0, pos + 1);
        pos = line.find(',');
        id2 = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        pos = line.find(')');
        dist = stof(line.substr(0, pos));
        res.addEdge(id1, id2, dist);
    }
    file.close();
    return res;
}