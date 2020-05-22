#include "Graph.h"

using namespace std;

Graph::Graph() {
    maxX = INT_MIN;
    minX = INT_MAX;
    maxY = INT_MIN;
    minY = INT_MAX;

    maxLat = INT_MIN;
    minLat = INT_MAX;
    maxLon = INT_MIN;
    minLon = INT_MAX;

    biDir = false;
}

Graph::~Graph() {
    deleteMatrix(W, vertexSet.size());
    deleteMatrix(P, vertexSet.size());
}

void Graph::initializeGraph() {
    for(auto v: vertexSet) {
        v->dist = INT_MAX;
        v->path = nullptr;
        v->distFromDest = 0;
        v->distSourcToDest = 0;
    }
}

void Graph::initializeForSearch() {
    for(Vertex* v: vertexSet)
        v->visited = false;
}

void Graph::initializeForAStar(const int &orig, const int &dest) {
    Vertex* o = findVertex(orig);
    Vertex* d = findVertex(dest);
    double pathDist = o->distanceLatLon(d);
    for(auto v: vertexSet) {
        v->dist = INT_MAX;
        v->path = nullptr;
        v->distFromDest = v->distanceLatLon(d);
        v->distSourcToDest = pathDist;
    }
}

void Graph::initializeForFindPOI() {
    for(auto v: vertexSet) {
        v->setUsedInPath(false);
    }
}

void Graph::initializeForBirDir() {
    for(Vertex* v: vertexSet){
        v->invertedVisited = false;
    }
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}
void Graph::setVertexSet(vector<Vertex*> vertexSet){
    this->vertexSet = vertexSet;
}


vector<Vertex*> Graph::getVertexSet() const {
    return vertexSet;
}



/*
 * Auxiliary function to find a vertex with a given content.
 */

Vertex * Graph::findVertex(const int &id) const {
    auto it = vertexMap.find(id); 
    if(it == vertexMap.end())
        return nullptr;
    return vertexSet.at(it->second);
}

int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < currentPoints.size(); i++)
        if (currentPoints.at(i) == id)
            return i;
    return -1;
}

int Graph::findStationID(const int &numStop) const {
    auto it = stationsMap.find(numStop);
    return it->second;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */

bool Graph::addVertex(const int &id, const double &x, const double &y) {
    if ( findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id, x, y, " "));
    if(x > maxX) maxX = x;
    if(x < minX) minX = x;
    if(y > maxY) maxY = y;
    if(y < minY) minY = y;

    vertexMap.insert(make_pair(id, vertexSet.size() - 1));

    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    for(Edge e: v1->getAdj()){
        if(e.getDest() == dest)
            return false;
    }
    v1->addEdge(dest,w);
    return true;
}

bool Graph::addBiDirEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;

    bool found = false;
    for(Edge e: v1->getAdj()){
        if(e.getDest() == dest) {
            found = true;
            break;
        }
    }
    if(!found)
        v1->addEdge(dest,w);

    for(Edge e: v2->getAdj()){
        if(e.getDest() == sourc)
            return true;
    }
    v2->addEdge(sourc, w);
    return true;
}

void Graph::clearEdges() {
    for(Vertex* vertex: vertexSet)
        vertex->clearEdges();
}


double Graph::getMaxX() const{
    return maxX;
}

double Graph::getMinX() const{
    return minX;
}
double Graph::getMaxY() const{
    return maxY;
}
double Graph::getMinY() const{
    return minY;
}

bool Graph::getBiDir() const{
    return biDir;
}

void Graph::checkLatLon(double lat, double lon) {
    if(lat > maxLat) maxLat = lat;
    if(lat < minLat) minLat = lat;
    if(lon > maxLon) maxLon = lon;
    if(lon < minLon) minLon = lon;
}

double Graph::getMaxLat() const{
    return maxLat;
}

double Graph::getMinLat() const{
    return minLat;
}
double Graph::getMaxLon() const{
    return maxLon;
}
double Graph::getMinLon() const{
    return minLon;
}

void Graph::addMetroStation(MetroStation station) {
    stations.push_back(station);
    stationsMap.insert(make_pair(station.getStopNum(), station.getID()));
}

vector<MetroStation> Graph::getMetroStations() const{
    return stations;
}

void Graph::setBiDir(bool biDir){
    this->biDir = biDir;
}


int Graph::getMetroTime(int stopOrig, int stopEnd) {
    cout << stopOrig << " " << stopEnd << endl;
    int total = 0;
    int min, max;
    if(stopOrig < stopEnd) {
        min = stopOrig;
        max = stopEnd;
    }
    else {
        min = stopEnd;
        max = stopOrig;
    }
    for(int i = min; i < max; i++) {
        Vertex* v1 = findVertex(stationsMap.find(i)->second);
        Vertex* v2 = findVertex(stationsMap.find(i+1)->second);

        double distance = v1->distanceLatLon(v2);
        cout << "Distance : " << distance << endl;
        total += minutesFromDistance(distance, 'p');
        cout << total << endl;
    }
    return total;
}

vector<pair<double,double>> Graph::getCityCoords(){
    vector<pair<double,double>> cityCoords;
    for(auto v: vertexSet){
        pair<double,double> p(v->getLat(),v->getLon());
        cityCoords.push_back(p);
    }
    return cityCoords;
}
vector<pair<double,double>> Graph::idToCoords(const vector<int>& v){
    vector<pair<double,double>> coords;
    
    for(auto id: v){
        Vertex * vertex = findVertex(id);
        pair<double,double> c (vertex->getLat(),vertex->getLon());
        coords.push_back(c);
    }
    return coords;
}

vector<Vertex*> Graph::bfs(const int &source, const int &dest) {
    vector<Vertex*> res;
    if(source == dest)
        return res;
    queue<Vertex*> q;
    initializeForSearch();

    Vertex* s = findVertex(source);
    q.push(s);
    s->setVisited(true);

    while (!q.empty()) {
        Vertex* temp = q.front();
        q.pop();
        res.push_back(temp);

        for(Edge edge: temp->getAdj()) {
            Vertex *d = findVertex(edge.getDest());
            if(d == findVertex(dest)) {
                res.push_back(d);
                return res;
            }
            if (!d->isVisited()) {
                q.push(d);
                d->setVisited(true);
            }
        }
    }
    res.clear();
    return res;
}

queue<Vertex*> Graph::dijkstraShortestPath(const int &origin, const int &dest) {
    queue<Vertex*> path;
    if(origin == dest)
        return path;
    initializeGraph();
    Vertex * vertex = findVertex(origin);
    vertex->setDist(0);
    MutablePriorityQueue<Vertex> q;
    q.insert(vertex);
    while(!q.empty()) {
        Vertex* temp = q.extractMin();
        for(Edge edge: temp->getAdj()) {
            Vertex * v = findVertex(edge.getDest());
            bool notFound = (v->getDist() == INT_MAX);
            if(v->getDist() > temp->getDist() + edge.getWeight()) {
                v->setDist(temp->getDist() + edge.getWeight());
                v->setPath( temp);
                if(notFound)
                    q.insert(v);
                else
                    q.decreaseKey(v);
            }
        }
    }

    Vertex* final = findVertex(dest);

    path.push(final);
    Vertex* previous = final->getPath();
    path.push(previous);
    while(previous != vertex) {
        previous = previous->getPath();
        path.push(previous);
    }

    return path;
}

void Graph::floydWarshallShortestPath(vector<int> points) {
    cout << "shit" << endl;
    currentPoints = points;
    unsigned n = points.size();
    deleteMatrix(W, n);
    deleteMatrix(P, n);

    cout << "shit" << endl;

    W = new double *[n];
    P = new queue<Vertex*> *[n];
    queue<Vertex*> empty;

    cout << "shit" << endl;

    for (unsigned i = 0; i < n; i++) {
        W[i] = new double[n];
        P[i] = new queue<Vertex*>[n];
        for (unsigned j = 0; j < n; j++) {
            W[i][j] = i == j? 0 : INT_MAX;
            P[i][j] = empty;
        }   

        for (unsigned j = 0; j < n; j++) {
            if( j != i){
                if(!bfs(points.at(i), points.at(j)).empty()) {
                    queue<Vertex*> path = dijkstraShortestPath(points.at(i), points.at(j));
                    W[i][j] = distancePath(path);
                    P[i][j] = path;
                }
            }

        }
    }
/*
    for(unsigned k = 0; k < n; k++)
        for(unsigned i = 0; i < n; i++)
            for(unsigned j = 0; j < n; j++) {
                if(W[i][k] == INT_MAX || W[k][j] == INT_MAX)
                    continue; // avoid overflow
                int val = W[i][k] + W[k][j];
                if (val < W[i][j]) {
                    W[i][j] = val;
                    P[i][j] = P[k][j];
                }
            }*/
}

double Graph::getDistance(const int &orig, const int &dest) const {
    int i = findVertexIdx(orig);
    int j = findVertexIdx(dest);
    return W[i][j];

}
queue<Vertex*> Graph::getPath(const int &orig, const int &dest) const{
    int i = findVertexIdx(orig);
    int j = findVertexIdx(dest);
    return P[i][j];
}

template <class T>
void deleteMatrix(T **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}


void Graph::extractDistances(string filename, vector<int> points) {
    ofstream file;
    file.open(filename);

    for(int p1: points) {
        for(int p2: points) {
            if(!bfs(p1, p2).empty()) {
                queue<Vertex*> path = dijkstraShortestPath(p1, p2);
                double distance = distancePath(path);
                file << "(" << p1 << "," << p2 << "," << distance << ")" << endl;
            }
        }
    }

    file.close();
}

