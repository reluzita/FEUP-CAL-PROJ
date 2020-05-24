#include "AlgorithmAnalysis.h"

using namespace std::chrono;
void compareAllSmallPath(Graph<coord> &g){
    system("cls");
    int idStrt = 30413, idEnd = 36869;
    cout << "Execution of the algorithms in a small path"<<endl;
    milliseconds t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    queue<Vertex<coord>*> path = g.dijkstraShortestPath(30413, 36869);
    milliseconds t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    queue<Vertex<coord>*> path2 = g.aStarShortestPath(30413, 36869);
    milliseconds t2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    milliseconds t3 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());  


    cout << "Dijkstra execution time: "<< t1.count()- t0.count()<< " milliseconds"<<endl;
    cout << "AStar execution time: "<< t2.count()- t1.count()<< " milliseconds"<<endl;
    cout << "Floyd-Warshall execution time: "<< t3.count()- t2.count()<< " milliseconds"<<endl;

    GraphViewer* gv = createMapViewer(g);
    showTestPath(gv, path);

    cout << endl << "Insert any key to return to the menu..."<<endl;
    int input;
    cin >> input;
}


void compareAllBigPath(Graph<coord> &g){
    system("cls");
    int idStart, idEnd; 
    cout << "Execution of the algorithms in a big path"<<endl;
    milliseconds t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    //chamar dijkstra
    milliseconds t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    //chamar astar
    milliseconds t2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());  
    //chamar floydWarshall 
    milliseconds t3 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());  


    cout << "Dijkstra execution time: "<< t1.count()- t0.count()<< " milliseconds"<<endl;
    cout << "AStar execution time: "<< t2.count()- t1.count()<< " milliseconds"<<endl;
    cout << "Floy-Warshall execution time: "<< t3.count()- t2.count()<< " milliseconds"<<endl;
    
    cout << endl << "Insert any key to return to the menu..."<<endl;
    getchar();
}

void compareBidirectional(Graph<coord> &g){
    system("cls");
    int idStart, idEnd; 
    cout << "Execution of the bidirectional algorithms"<<endl;
    milliseconds t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    //chamar bidirdijkstra
    milliseconds t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    //chamar bidirastar
    milliseconds t2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());  

    cout << "Bidirectional Dijkstra execution time: "<< t1.count()- t0.count()<< " milliseconds"<<endl;
    cout << "Bidirectional AStar execution time: "<< t2.count()- t1.count()<< " milliseconds"<<endl;
 
    cout << endl << "Insert any key to return to the menu..."<<endl;
    getchar();

}


void compareDFSBFS(Graph<coord> &g){
    system("cls");
    int idStrt, idEnd; 
    cout << "Execution of the depth first and breath first search algorithms"<<endl;
    milliseconds t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    //chamar BFS
    milliseconds t1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    //chamar DFS
    milliseconds t2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());  


    cout << "BFS execution time: "<< t1.count()- t0.count()<< " milliseconds"<<endl;
    cout << "DFS execution time: "<< t2.count()- t1.count()<< " milliseconds"<<endl;
    
    cout << endl << "Insert any key to return to the menu..."<<endl;
    getchar();
}

void compareAllGrid() {
    system("cls");

    Graph<coord> graph;
    readNodesFile(graph, "../Resources/GridGraphs/16x16/nodes.txt");
    readEdgesFile(graph, false, "../Resources/GridGraphs/16x16/edges.txt");
    graph.floydWarshallShortestPath();

    int idStrt = 0, idEnd = 288;
    cout << "Execution of the algorithms in a small path"<<endl;
    auto t0 = std::chrono::high_resolution_clock::now();
    queue<Vertex<coord>*> path = graph.dijkstraShortestPath(idStrt, idEnd);
    auto t1 = std::chrono::high_resolution_clock::now();
    queue<Vertex<coord>*> path2 = graph.aStarShortestPath(idStrt, idEnd);
    auto t2 = std::chrono::high_resolution_clock::now();
    vector<coord> path3 = graph.getfloydWarshallPath(idStrt, idEnd);
    auto t3 = std::chrono::high_resolution_clock::now();


    cout << "Dijkstra execution time: "<< duration_cast<std::chrono::microseconds>(t1 - t0).count() << " microseconds"<<endl;
    cout << "AStar execution time: "<< duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds"<<endl;
    cout << "Floyd-Warshall execution time: "<< duration_cast<std::chrono::microseconds>(t3 - t2).count() << " microseconds"<<endl;

    GraphViewer* gv = createMapViewer(graph);
    showTestPath(gv, path);

    cout << endl << "Insert any key to return to the menu..."<<endl;
    int input;
    cin >> input;

}