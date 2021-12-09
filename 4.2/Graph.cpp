#include "Graph.h"
#include <stdint.h>
#include <queue>
#include <list>
#include <algorithm>
#define INF 0x3f3f3f3f

Graph::Graph(){
    numEdges = 0;
    numNodes = 0;
}

Graph::Graph(int representa, std::istream& input) {
    loadDirectedGraph(input);
    visited.resize(numNodes+1);
}

Graph::~Graph() {
  adjList.clear();
  visited.clear();
}

void Graph::loadDirectedGraph(std::istream& input) {
    std::string line;
    int i = 0;
    while (std::getline(input, line)) {
      if (i == 0) {
        i++;
        continue;
      }
      if (i == 1) {
        std::vector<int> res;
        split(line, res);
        numNodes = res[0];
        numEdges = res[2];
        // Reservar memoria para la lista de adyacencia
        adjList.resize(numNodes+1);
        i++;
        continue; 
      }
      std::vector<int> res;
      split(line, res);
      int u = res[0];
      int v = res[1];
      int w = res[2];
      // Grafos dirigidos
      std::pair<int, int> p (v, w);
      adjList[u].push_back(p);
      i++;
    }
}


void Graph::split(std::string line, std::vector<int> & res) {
    size_t strPos = line.find(" ");
    size_t lastPos = 0;
    while (strPos != std::string::npos) {
      res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
      lastPos = strPos + 1;
      strPos = line.find(" ", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::printAdjList(){
	  std::cout << "Adjacency List" << std::endl;
		for (int i = 1; i <= numNodes; i++){
	        std::cout << "vertex " << i << ": ";
	        for (int j = 0; j < (int)adjList[i].size(); j ++){
							 std::cout << " (" << adjList[i][j].first << ", " << adjList[i][j].second << ") ";
					}
	        std::cout << std::endl;
    }
}


void Graph::printGraph() {
  printAdjList();
}

void Graph::explore(int v) {
  visited[v] = true;
  std::cout << v << " ";
  // Recorrer nodos adyacente a v
  for (int j = 0; j < (int)adjList[v].size(); j++) {
    int u = adjList[v][j].first;
    if (!visited[u])
      explore(u);
  }
}

void Graph::DFS(int v) {
  int i;
  for (i = 0; i < numNodes+1; i++)
    visited[i] = false;
  std::cout << "Recorrido DFS " << std::endl;
  for (i = 1; i < numNodes+1; i++) {
    if (!visited[i])
      explore(i);
  }
  std::cout << std::endl;
}

void Graph::exploreTopologicalSort(int v) {
  visited[v] = true;
  // Recorrer nodos adyacente a v
  for (int j = 0; j < (int)adjList[v].size(); j++) {
    int u = adjList[v][j].first;
    if (!visited[u])
      exploreTopologicalSort(u);
  }
  // Almacena el vertice v después de 
  // explorar todos sus nodos adyacentes
  tmpStack.push(v);
}

void Graph::topologicalSort(int v) {
  int i;
  for (i = 0; i < numNodes+1; i++)
    visited[i] = false;
  // Inicializa el stack vacio
  tmpStack = std::stack<int>();
  std::cout << "Topological sort " << std::endl;
  for (i = 1; i < numNodes+1; i++) {
    if (!visited[i])
      exploreTopologicalSort(i);
  }
  // Se imprime el ordenamiento a partir del stack
  while(!tmpStack.empty()) {
    std::cout << tmpStack.top() << " ";
    tmpStack.pop();
  }
  std::cout << std::endl;
}

int Graph::getNumNodes() {

  return numNodes;

}

int Graph::minDistance(std::vector<int> distance, std::vector<bool> check) {

  int min = INT8_MAX;
  int min_index;

  for (int i = 0; i < numNodes; i++) {

    if (check[i] == false && distance[i] <= min) {

      min = distance[i];
      min_index = i;

    }

  }

  return min_index;

}

bool Graph::BFS(int source, int destination, std::vector<int> pred, std::vector<int> distance) {

  std::list<int> queue;
  std::vector<bool> visited;

  for (int i = 0; i < numNodes; i++) {

    visited.push_back(false);
    distance.push_back(INT8_MAX);
    pred.push_back(-1);

  }

  visited[source] = true;
  distance[source] = 0;
  queue.push_back(source);

  while (!queue.empty()) {

    int u = queue.front();
    queue.pop_front();
    for (int i = 0; i < numNodes; i++) {
      if (visited[adjList[u][i].first] == false) {

        visited[adjList[u][i].first] = true;
        distance[visited[adjList[u][i].first]] = distance[u] + 1;
        pred[visited[adjList[u][i].first]] = u;
        queue.push_back(adjList[u][i].first);

        if (adjList[u][i].first == destination) {
          return true;
        }

      }

    }

  }
  return false;
}

void Graph::shortestPath(int source, int destination) {

  std::vector<int> pred;
  std::vector<int> distance;

  if (!BFS(source, destination, pred, distance)) {

    std::cout << "ERROR: Nodos no conectados" << std::endl;

  } else {

    std::vector<int> path;
    int x = destination;

    path.push_back(x);

    while (pred[x] != -1) {

      path.push_back(pred[x]);
      x = pred[x];

    }

    std::cout << source << ": " << distance[destination] << std::endl;
    std::reverse(path.begin(), path.end());

    for (int i; i < path.size(); i++) {

      if (i != path.size() - 1) {

        std::cout << path[i] << " ";

      } else {

        std::cout << path[i] << std::endl;

      }

    }

  }

  // TIME COMPLEXITY O(N^2)

}

bool Graph::isBipartite(int v){
  std::vector<int> color(numNodes + 1);
  visited[1] = true;
  color[1] = 0;

  for (int j = 0; j < (int)adjList[v].size(); j++){
    if (visited[j] == false){
      visited[j] = true;
      color[j] = !color[v];

      if (!isBipartite(v)){
        return false;
      }
    } else if (color[j] == color[v]){
      return false;
    }
  }
  return true;
}

void Graph::bipartiteGraph(){
  if (isBipartite(1)){
    std::cout << "El grafo es bipartita\n\n";
    printAdjList();
  } else {
    std::cout << "El grafo no es bipartita\n\n";
  }
}


int Graph::findShortestPath(int source) {


  std::queue<std::pair<int, int>> queue;
  std::vector<int> dist(numNodes, INT8_MAX);

  queue.push(std::make_pair(0, source));
  dist[source] = 0;

  while (!queue.empty()) {

    int u = queue.front().second;
    queue.pop();

    std::cout << u << std::endl;
    std::vector<std::pair<int, int>>::iterator i;

    for (i = adjList[u].begin(); i != adjList[u].end(); ++i) {
      
      int v = (*i).first;
      int weight = (*i).second;

      if (dist[v] > dist[u] + weight) {

        dist[v] = dist[u] + weight;
        queue.push(std::make_pair(dist[v], v));

      }

    }

  }

  std::cout << "Distancia desde el nodo " << source << std::endl;
  for (int i = 0; i < numNodes; ++i) {

    std::cout << "Nodo " << i << ": " << dist[i] << std::endl;

  }

}


