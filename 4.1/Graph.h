#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>

class Graph {
  private:
    int numNodes;
    int numEdges;
    int representation; // 1 Adjacency list; 2 Adjacency matrix
    // Matriz de adyacencia
    int **adjMatrix;
    // Lista de adyacencia (vector de vectores)
    std::vector<std::vector<int>> adjList;

    void loadGraphList(std::istream& input);
    void loadGraphMatrix(std::istream& input);
    void split(std::string line, std::vector<int> & res);
    void printAdjList();
    void printAdjMatrix();
    std::vector<bool> status;
    
  
  public:
    Graph();
    Graph(int representacion, std::istream& input);
    ~Graph();
    void printGraph();
    void copyGraph(int representElegida, Graph &other);

    void printadjListVector();
    void explore(int index);
    void DFS(int index);
    void BFS(int index);

    void printNumNode();
    void printNumEdges();
    void printMatrix();


};



#endif // __GRAPH_H_