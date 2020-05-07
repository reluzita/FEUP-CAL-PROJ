//
// Created by ineso on 5/4/2020.
//

#include "ReadFiles.h"

using namespace std;

Graph readMap(const string &cityName)
{
    Graph graph;
    string lowercase = cityName;
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    string nodesfile = "../resources/PortugalMaps/PortugalMaps/" + cityName + "/nodes_x_y_" + lowercase + ".txt";
    string latlonfile = "../resources/PortugalMaps/PortugalMaps/" + cityName + "/nodes_lat_lon_" + lowercase + ".txt";
    string edgesfile = "../resources/PortugalMaps/PortugalMaps/" + cityName + "/edges_"+ lowercase + ".txt";

    //cout << nodesfile << endl;
    //cout << edgesfile << endl;

    ifstream nodes, latlon, edges;
    nodes.open(nodesfile);
    latlon.open(latlonfile);
    edges.open(edgesfile);

    string line;
    getline(nodes, line);
    int numNodes = stoi(line);
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
        //cout << id << endl;
    }
    nodes.close();

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
    }
    latlon.close();

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
        graph.addEdge(n1, n2, weight);
    }
    edges.close();
    return graph;
}

vector<int> readTags(Graph &g , const string &cityName) {
    string lowercase = cityName;
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    string tagfile = "../resources/TagExamples/" + cityName + "/t03_tags_" + lowercase + ".txt";

    vector<int> res;
    ifstream file;
    file.open(tagfile);

    string line;
    getline(file, line);
    int numTypes = stoi(line);
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
            res.push_back(stoi(line));
        }
    }
    return res;
}