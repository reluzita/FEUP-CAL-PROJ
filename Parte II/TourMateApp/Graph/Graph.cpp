//
// Created by ineso on 5/4/2020.
//

#include "Graph.h"

using namespace std;

Graph::Graph() = default;

int Graph::getNumVertex() const {
    return vertexSet.size();
}


vector<Vertex*> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */

Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->id == id)
            return v;
    return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */

bool Graph::addVertex(const int &id, const int &x, const int &y) {
    if ( findVertex(id) != NULL)
        return false;
    vertexSet.push_back(new Vertex(id, x, y, " "));
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
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(dest,w);
    return true;
}


/*


template<class T>
void Graph<T>::unweightedShortestPath(const int &orig) {
    for(auto v: vertexSet) {
        v->dist = INT_MAX;
        v->path = NULL;
    }
    Vertex<T> * vertex = findVertex(orig);
    vertex->dist = 0;
    queue<Vertex<T>*> q;
    q.push(vertex);
    while(!q.empty()) {
        Vertex<T> * temp = q.front();
        q.pop();
        for(Edge<T> edge: temp->adj) {
            if((edge.dest)->getDist() == INT_MAX) {
                q.push(edge.dest);
                (edge.dest)->dist = temp->dist + 1;
                (edge.dest)->path = temp;
            }
        }
    }
}


template<class T>
void Graph<T>::dijkstraShortestPath(const int &origin) {
    for(auto v: vertexSet) {
        v->dist = INT_MAX;
        v->path = NULL;
    }
    Vertex<T> * vertex = findVertex(origin);
    vertex->dist = 0;
    MutablePriorityQueue<Vertex<T>> q;
    q.insert(vertex);
    while(!q.empty()) {
        Vertex<T>* temp = q.extractMin();
        for(Edge<T> edge: temp->adj) {
            bool notFound = ((edge.dest)->dist == INT_MAX);
            if((edge.dest)->dist > temp->dist + edge.weight) {
                (edge.dest)->dist = temp->dist + edge.weight;
                (edge.dest)->path = temp;
                if(notFound)
                    q.insert(edge.dest);
                else
                    q.decreaseKey(edge.dest);
            }
        }
    }
}


template<class T>
void Graph<T>::bellmanFordShortestPath(const int &orig) {
    for(auto v: vertexSet) {
        v->dist = INT_MAX;
        v->path = NULL;
    }
    Vertex<T> * vertex = findVertex(orig);
    vertex->dist = 0;

    for (int i = 1; i < vertexSet.size() - 1; i++) {
        for (auto v : vertexSet) {
            for(Edge<T> edge: v->adj) {
                if(edge.dest->dist > v->dist + edge.weight) {
                    edge.dest->dist = v->dist + edge.weight;
                    edge.dest->path = v;
                }
            }
        }
    }
    for (auto v : vertexSet) {
        for(Edge<T> edge: v->adj) {
            if(edge.dest->dist > v->dist + edge.weight) {
                edge.dest->dist = v->dist + edge.weight;
                edge.dest->path = v;
                cout << "Negative cycle!" << endl;
            }
        }
    }
}


template<class T>
vector<T> Graph<T>::getPathTo(const int &dest) const{
    vector<T> res;
    stack<T> temp;
    Vertex<T> * vertex = findVertex(dest);
    temp.push(vertex->getInfo());
    while(vertex->getDist()!=0) {
        vertex = vertex->getPath();
        temp.push(vertex->getInfo());
    }
    while(!temp.empty()) {
        res.push_back(temp.top());
        temp.pop();
    }
    return res;
}


template<class T>
void Graph<T>::floydWarshallShortestPath() {
    for(int i = 0; i < vertexSet.size(); i++) {
        for (int j = 0; j < vertexSet.size(); j++)
            D[i][j] = INT_MAX;
    }
    for(int i = 0; i < vertexSet.size(); i++) {
        for(Edge<T> edge: vertexSet[i]->adj) {
            auto it = find(vertexSet.begin(), vertexSet.end(), edge.dest);
            int j = distance(vertexSet.begin(), it);
            D[i][j] = edge.weight;
        }
    }

    for(int k = 0; k < vertexSet.size(); k++) {
        for(int i = 0; i < vertexSet.size(); i++) {
            for (int j = 0; j < vertexSet.size(); j++) {
                if(D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }
}

template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const int &orig, const int &dest) const{
    vector<T> res;

    return res;
}
*/