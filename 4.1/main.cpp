#include <iostream>
#include "Graph.h"

int main() {
  
  std::cout << "Ejemplo de representacion de grafos!\n";
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf(); 
  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  Graph g1(1, inputInfo);
  g1.printGraph();
  g1.DFS(7);
  g1.BFS(7);

  std::cout << std::endl;
  std::cout << "--" << std::endl;

  Graph g2;
  g1.copyGraph(1, g2);

  g2.printGraph();
  g2.DFS(7);
  g2.BFS(7);
  

} 