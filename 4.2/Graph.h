#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <limits>
#include <stdint.h>


class Graph {
  private:
    int numEdges;
    int numNodes;
  
    // Lista de adyacencia (vector de vectores)
    std::vector<std::vector<std::pair<int,int>>> adjList;
    std::vector<bool> visited;
    std::stack<int> tmpStack;

    void loadDirectedGraph(std::istream& input);
    void split(std::string line, std::vector<int> & res);
    void printAdjList();
    void explore(int v);
    void exploreTopologicalSort(int v);
    bool isBipartite(int v);
    

  
  public:
    Graph();
    Graph(int representacion, std::istream& input);
    ~Graph();
    void printGraph();
    void DFS(int v);
    void topologicalSort(int v);
    int minDistance(std::vector<int> distance, std::vector<bool> check);
    void shortestPath(int source, int destination);
    int getNumNodes();
    void bipartiteGraph();
    int printShortestPath(std::vector<int> parent, int s, int d);
    int findShortestPath(int source);
    bool BFS(int source, int destination, std::vector<int> pred, std::vector<int> distance);

    #define V numNodes;

};



#endif // __GRAPH_H_