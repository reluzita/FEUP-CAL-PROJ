/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include "MutablePriorityQueue.h"
#include "../Utils/Stop.h"
#include <cmath>

using namespace std;

template <class T> class Edge;
template <class T> class Graph;

typedef pair<double, double> coord;

/************************************** Vertex  ***************************************/

template <class T>
class Vertex {
	T info; //coordinates 
	int id;      
	string type = " "; //if " ", not point of interest

	//Auxiliar Field
	bool visited;   
	
	double dist = 0;
	int duration = 0; // if 0, not point of interest
	Vertex<T> *path = nullptr;  
	
	int queueIndex = 0; 		// required by MutablePriorityQueue

	//Bidirectional
	vector<Edge<T> *> outgoing;
    vector<Edge<T> *> incoming;

	void addEdge(Vertex<T> *dest, double w);

public:
	Vertex(T in, int id);
	
	vector<Edge<T> *> getAdj() const;
	vector<Edge<T> *> getIncoming() const;
	int getId() const;
	T getInfo() const;
	double getDist() const;
	Vertex *getPath() const;
	string getType() const;
	int getDuration() const;

	void setDuration(int dur);
	void setType(string type);

	bool operator<(Vertex<T> & vertex) const; // required by MutablePriorityQueue

	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;
};


/************************************** Edge  **************************************/

template <class T>
class Edge {
	Vertex<T> *orig; 	
	Vertex<T> *dest;      // destination vertex
	double weight;         // edge weight

public:
	Edge(Vertex<T> *o, Vertex<T> *d, double w);

	double getWeight() const;
	Vertex<T> *getDest() const;

	friend class Graph<T>;
	friend class Vertex<T>;
};


/************************************** Graph  **************************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set
	unordered_map<int, int> vertexMap; // <id, index>

	unordered_map<int, int> stationsMap; //<stopNum, vertexID>
    vector<MetroStation> stations;

	unordered_map<int, string> realPOIs; // <id, name>

	double maxX = INT_MIN;
    double minX = INT_MAX;
    double maxY = INT_MIN;
    double minY = INT_MAX;

	double ** W = nullptr; // dist
    int **P = nullptr; // path
    vector<int> currentPoints;

	bool relax(Vertex<T> *v, Vertex<T> *w, double weight);


public:
	void initializeRealPOIs();

	double getMaxX() const;
    double getMinX() const;
    double getMaxY() const;
    double getMinY() const;
	vector<Vertex<T> *> getVertexSet() const;
	vector<MetroStation> getMetroStations() const;
    int getMetroTime(MetroStation stopOrig, MetroStation stopEnd) const;
	int getPath(const int &orig, const int &dest) const;
    double getDistance(const int &orig, const int &dest) const;

	Vertex<T> *findVertex(const int &id) const;
	int findVertexIdx(const int &id) const;
	int findStationID(const int &numStop) const;

	bool addVertex(const int &id, const T &info);
	bool addEdge(const int &sourc, const int &dest, double w);
	bool addBiDirEdge(const int &sourc, const int &dest, double w);
	void addMetroStation(MetroStation station);

	double euclideanDistance(Vertex<T> * v1, Vertex<T> * v2) const ;
	
	string realPOIName(const int &id);

	double distancePath(queue<Vertex<T>*> path); 
	int minutesFromDistance(double distance, const char& transportation) const;

	//Initialize Graph For Algorithms
	void initializeForSearch();
	void initializeForShortestPath();
    void initializeForBiDir();

	//Algorithms
	vector<Vertex<T>*> bfs(const int &source, const int &dest);
	vector<Vertex<T>*> bfsAll( const int & source);
	vector<Vertex<T>*> bfsAllPOI(const int & source, vector<string> types, int dur);
	queue<Vertex<T>*> dijkstraShortestPath(const int &origin, const int &dest);
	queue<Vertex<T>*> aStarShortestPath(const int &origin, const int &dest);
	queue<Vertex<T>*> biDirDijkstraShortestPath(const int &origin, const int &dest);
	queue<Vertex<T>*> biDirAStarShortestPath(const int &origin, const int &dest);
	void floydWarshallShortestPath(vector<int> points);

};

template<class T>
void deleteMatrix(T **m, int n);


#endif /* GRAPH_H_ */
