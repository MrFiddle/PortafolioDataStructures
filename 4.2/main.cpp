#include <iostream>
#include "Graph.cpp"
#include <stdint.h>


//g++ main.cpp
//./a.out < test01.txt
//./a.exe < test01.txt

int main() {

  std::cout << "Ejemplo de Ordenamiento Topologico en grafos!\n";
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf(); 
  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  Graph g1(1, inputInfo);
  g1.DFS(1);
  //g1.printGraph();
  g1.topologicalSort(1);
  g1.bipartiteGraph();
  g1.shortestPath(0, 6);

} 