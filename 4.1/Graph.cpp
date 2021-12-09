#include "Graph.h"

Graph::Graph(){
  numNodes = 0;
  numEdges = 0;
  representation = 1;
}

Graph::Graph(int representa, std::istream& input) {

    if (representa == 1) {
      loadGraphList(input);
      representation = 1;
    }
    else {
      loadGraphMatrix(input);
      representation = 2;
    }

    status.resize(numNodes + 1);
    /* userInput = input; */

}

Graph::~Graph() {
  if (representation == 1) {
    adjList.clear();
  }
  else {
    for (int i = 0; i < numNodes+1; i++) 
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
}

void Graph::loadGraphList(std::istream& input) {
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
      // Grafos no dirigidos
      adjList[u].push_back(v);
      adjList[v].push_back(u);
      i++;
    }
}

void Graph::loadGraphMatrix(std::istream& input) {
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
        // Reserva memoria para los renglones de la matriz de adyacencia
        adjMatrix = new int*[numNodes+1];
        // Para cada renglon reserva memoria para las columnas de la matriz de adyacencia
        for (int j=0; j < numNodes+1; j++) {
          adjMatrix[j] = new int[numNodes+1];
	        for (int k = 0; k < numNodes+1; k++)
            adjMatrix[j][k] = 0;
        }
        i++;
        continue; 
      }
      std::vector<int> res;
      split(line, res);
      int u = res[0];
      int v = res[1];
      // Grafos no dirigidos
      adjMatrix[u][v] = 1;
      adjMatrix[v][u] = 1;
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
	        std::cout << "V " << i << ": ";
	        for (int j = 0; j < (int)adjList[i].size(); j ++){
							 std::cout << " " << adjList[i][j];
					}
	        std::cout << std::endl;
    }
}

void Graph::printAdjMatrix(){
    std::cout << "Adjacency Matrix" << std::endl;
		for (int i = 1; i < numNodes+1; i++){
	    for (int j = 1; j < numNodes+1; j++) {
        std::cout << adjMatrix[i][j] << " ";
			}
	    std::cout << std::endl;
    }
}

void Graph::printGraph() {
  if (representation == 1)
    printAdjList();
  else
    printAdjMatrix();
}


/* O(n) siendo n el tamaño de nuestra lista de adyacencia */
void Graph::explore(int index) {

  status[index] = true;
  std::cout << index << " ";
  if (representation == 1) {

    for (int i = 0; i < (int)adjList[index].size(); i++) {

      int j = adjList[index][i];

      if (!status[j]) {
        
        explore(j);

      } 

    }

  } else {

    for (int i = 1; i < numNodes + 1; i++) {

      int x = adjMatrix[index][i];

      if (x != 0) {

        if (!status[i]) {

          explore(i);

        }

      }

    }

  }

}


/* O(n ^ 2)*/
void Graph::copyGraph(int represent, Graph &other){

  other.numNodes = numNodes;
  other.numEdges = numEdges;
  other.representation = represent;
  
  if (represent == 1 && representation == 1){
    
    other.adjList.resize(numNodes + 1);

    for (int i = 0; i <= numNodes; i++){
      for (int j = 0; j < (int)adjList[i].size(); j++){
        other.adjList[i].push_back(adjList[i][j]);
      }
    }
  }

  if (represent == 2 && representation == 2){
    other.adjMatrix = new int*[numNodes + 1];

    for (int i = 0; i < numNodes + 1; i++){
      other.adjMatrix[i] = new int[numNodes + 1];
      for (int j = 0; j < numNodes + 1; j++){
        other.adjMatrix[i][j] = 0;
      }
    }

    for (int i = 0; i < numNodes + 1; i++){
      for (int j = 0; j < numNodes + 1; j++){
        if (adjMatrix[i][j] != 0){
          other.adjMatrix[i][j] = adjMatrix[i][j];
        }
      }
    }

  }

  if (represent == 1 && representation == 2){
    other.adjList.resize(numNodes + 1);

    for (int i = 0; i < numNodes + 1; i++){
      for (int j = 0; j < numNodes + 1; j++){
        if (adjMatrix[i][j] != 0){
          other.adjList[i].push_back(j);
        }
      }
    }
  }

  if (represent == 2 && representation == 1){
    other.adjMatrix = new int*[numNodes + 1];

    for (int i = 0; i < numNodes + 1; i++){
      other.adjMatrix[i] = new int[numNodes + 1];
      for (int j = 0; j < numNodes + 1; j++){
        other.adjMatrix[i][j] = 0;
      }
    }

    for (int i = 0; i <= numNodes; i++){
      for (int j = 0; j < (int)adjList[i].size(); j++){
        int v = adjList[i][j];
        other.adjMatrix[i][v] = 1;
      }
    }
  }

  other.status.resize(numNodes + 1);

  
}

/* O(V + E) Donde V es numero de vertices en el grafo y E el numero de aristas. */
void Graph::DFS(int index) {

  for (int i = 0; i < numNodes + 1; i++) {

    status[i] = false;

  }

  std::cout << "- D F S | Nodo " << index << " -" << std::endl;

  status[index] = true;
  explore(index);


  for (int i = 1; i < numNodes + 1; i++) {

    if (!status[i]) {

      explore(i);

    }

  }

  std::cout << std::endl;

}

/* O(V + E) Donde V es numero de vertices en el grafo y E el numero de aristas. */
void Graph::BFS(int index) {

  for (int i = 0; i < numNodes + 1; i++) {

    status[i] = false;

  }

  std::cout << "- B F S | Nodo " << index << " -" << std::endl;

  std::list<int> nodesQueue;

  status[index] = true;
  //explore(index);

  std::vector<int>::iterator i;

  nodesQueue.push_back(index);

  while(!nodesQueue.empty()) {

    index = nodesQueue.front();
    std::cout << index << " ";
    nodesQueue.pop_front();

    if (representation == 1) {

      for (i = adjList[index].begin(); i < adjList[index].end(); i++) {


        if (!status[*i]) {

          status[*i] = true;
          nodesQueue.push_back(*i);

        }

      }

    } else {

      for (int j = 0; j < numNodes + 1; j++) {

        if (!status[j]) {

          status[j] = true;
          nodesQueue.push_back(j);

        }

      }

    }


  }

}

void Graph::printNumNode() {

  std::cout << numNodes << std::endl;

}

void Graph::printNumEdges() {

  std::cout << numEdges << std::endl;

}

void Graph::printadjListVector() {

		for (int i = 1; i <= numNodes; i++){
	        std::cout << "V " << i << ": ";
	        for (int j = 0; j < (int)adjList[i].size(); j ++){
							 std::cout << " " << adjList[i][j];
					}
	        std::cout << std::endl;
    }

}
