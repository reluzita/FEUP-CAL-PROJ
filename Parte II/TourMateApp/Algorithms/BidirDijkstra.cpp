#include "BidirDijkstra.h"


int biDirRegularSearch(Graph g, const int &s, const int &t){
    queue<Vertex*> s_queue, t_queue;

    int intersectNode = -1;

    g.initializeForBiDir();

    Vertex* orig = g.findVertex(s);
    Vertex* dest = g.findVertex(t);

    s_queue.push(orig);
    orig->setVisited(true);

    t_queue.push(dest);
    dest->setInvertedVisited(true);

    while (!s_queue.empty() && !t_queue.empty())
    {
        BFS(&s_queue,orig-> , s_parent);
        BFS(&t_queue, t_visited, t_parent);

        intersectNode = isIntersecting(s_visited, t_visited);

        // If intersecting vertex is found
        // that means there exist a path
        if(intersectNode != -1)
        {
            cout << "Path exist between " << s << " and "
                 << t << "\n";
            cout << "Intersection at: " << intersectNode << "\n";

            // print the path and exit the program
            printPath(s_parent, t_parent, s, t, intersectNode);
            exit(0);
        }
    }
}
int

void bfsAux(Graph g, queue<Vertex> *queue, bool inverted)
{
    Vertex* v = queue.front();
    queue.pop();
    for (Edge edge: v->getAdj()) {
        Vertex * adj = g.findVertex(edge.getDest());
        if (!inverted)
        {
            if(!adj.)
            // set current as parent of this vertex
            parent[*i] = current;

            // Mark this vertex visited
            visited[*i] = true;

            // Push to the end of queue
            queue->push_back(*i);
        }
    }
}

// check for intersecting vertex
int isIntersecting(Graph g, bool *s_visited, bool *t_visited)
{
    int intersectNode = -1;
    for(int i=0;i<g.getVertexSet();i++)
    {
        // if a vertex is visited by both front
        // and back BFS search return that node
        // else return -1
        
        if(s_visited[i] && t_visited[i])
            return i;
    }
    return -1;
}