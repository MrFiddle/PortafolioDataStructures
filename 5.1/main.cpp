// Juan Pablo Pérez Durán
// Jonathan Joaquin Quirino Carrasco

#include <iostream>
#include "HashTable.h"


int main() {
  std::cout << "Hash Table Example!\n";

  // 1 -> Quadratic / 2 -> Chain

  HashTable<int, std::string> myHashTable(7, 1);
  std::cout << "Table current size: " << myHashTable.getSize() << std::endl;
  std::cout << "Add (50, Hello)" << std::endl;
  myHashTable.add(50, "Hello");
  std::cout << "Add (700, World)" << std::endl;
  myHashTable.add(700, "World");
  std::cout << "Add (85, Collision element 1)" << std::endl;
  myHashTable.add(85, "Collision element 1");
  std::cout << "Add (86, Collision element 2)" << std::endl;
  myHashTable.add(86, "Collision element 2");
  std::cout << "Table current size: " << myHashTable.getSize() << std::endl;
  myHashTable.print();
  int index;
  
} 