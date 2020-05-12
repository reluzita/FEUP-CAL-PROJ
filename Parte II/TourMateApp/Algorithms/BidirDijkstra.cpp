#include "BidirDijkstra.h"

/*
Linguagem regular:
- inicializar dois grafos, o normal e o revertido para a bidirdijkstra--> visited a false;
- por cada ponto no grafo, aplicar uma iteraçao do dijsktra em cada
- verificar se os dois vertices apos a iteraçao ja foram visitados.
*/
void initializeVertexForBiDir(vector<Vertex*> vertexSet){
    for(Vertex* v: vertexSet){
        v->setVisited(false);
    }
}

/*void addReverseEdges(Graph *reverse, Graph g){
    for (Vertex * v: g.getVertexSet()){
        for(Edge e: v->getAdj()){
            reverse->addEdge(e.getDest(),*v,e.getWeight());
        }
    }

}
*/
/*queue<Vertex*> biDirRegularSearch(Graph g, const int &s, const int &t){
    Graph reverse;

    reverse.setVertexSet(g.getVertexSet());
    addReverseEdges(&reverse, g);


    queue<Vertex*> res; 
    vector<int> normal, reverse;

    int intersectNode = -1;

    
    Vertex* orig = g.findVertex(s);
    Vertex* dest = g.findVertex(t);

    orig->setDist(0);
    dest->setDist(0);
    MutablePriorityQueue<Vertex> qn, qi;
    qn.insert(orig);
    orig->setVisited(true);
    qi.insert(dest);
    dest->setVisited(true);


    while (!qn.empty() && !qi.empty()){
        Vertex* temp1 = qn.extractMin();

        for(Edge edge: temp1->getAdj()) {
            Vertex * v = g.findVertex(edge.getDest());
            bool notFound = (v->getDist() == INT_MAX);
            if(v->getDist() > temp1->getDist() + edge.getWeight()) {
                v->setDist(temp1->getDist() + edge.getWeight());
                v->setPath( temp1);
                if(notFound)
                    qn.insert(v);
                else
                    qn.decreaseKey(v);
            }
        }





        Vertex* temp2 = qi.empty();





        normal = bfs(g,orig, dest);
        reverse= bfs(reverse, dest, orig);
        


        intersectNode = isIntersecting(normal, reverse);

        // If intersecting vertex is found that means there exist a path
        if(intersectNode != -1)
        {
            return res; 
        }
    }
    for(int i: normal){
        res.push(i);
    }
    return res;
}
queue<Vertex*> dijkstraShortestPath(Graph g, const int &origin, const int &dest) {
    //g.initializeGraph();
    //Vertex * vertex = g.findVertex(origin);
    //vertex->setDist(0);
    //MutablePriorityQueue<Vertex> q;
    //q.insert(vertex);
    while(!q.empty()) {
        Vertex* temp = q.extractMin();
        for(Edge edge: temp->getAdj()) {
            Vertex * v = g.findVertex(edge.getDest());
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

    Vertex* final = g.findVertex(dest);
    queue<Vertex*> path;
    path.push(final);
    Vertex* previous = final->getPath();
    path.push(previous);
    while(previous != vertex) {
        previous = previous->getPath();
        path.push(previous);
    }

    return path;
}
// check for intersecting vertex
int isIntersecting(Graph g, Graph rev, vector<int> normal, vector<int> reverse)
{
    int intersectNode = -1;
    for(int i=0; i<g.getVertexSet();i++){
        Vertex* v = g.findVertex(normal.at(i));
        Vertex* i = rev.findVertex(reverse.at(i));
        if(v->isVisited() && i->isVisited())
            return i;
    }

    return -1;
}*/