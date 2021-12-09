#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#include <vector>
#include <stdexcept>
#include "HashNode.h"
#include <list>
#include <string>

template<class K, class T>
class HashTable {
  private:

    std::list<HashNode<K,T>>*table;
    std::vector<HashNode<K,T>> tableQ;
    int size;
    int maxSize; // preferible un numero primo
    int method;
    int representacion;
    std::vector<int> status;

  public:

    HashTable(int selectedMaxSize, int _representacion);
    int getHashIndex(K keyVal);
    int getSize();
    void print();
    void add(K keyVal, T value);


};

template<class K, class T>
HashTable<K, T>::HashTable(int selectedMaxSize, int _representacion) {

  representacion = _representacion;

  maxSize = selectedMaxSize;
  size = 0;

  if (representacion == 1 /*Quadratic*/) {

    maxSize = selectedMaxSize;
    size = 0;
    tableQ = std::vector<HashNode<K,T>>(maxSize);

  } else { // Chain
    
    table = new std::list<HashNode<K,T>>[maxSize];

  }

  
}

template<class K, class T>
int HashTable<K, T>::getHashIndex(K keyVal) {
  return keyVal % maxSize;
}

template<class K, class T>
int HashTable<K, T>::getSize() {
  return size;
}

template<class K, class T>
void HashTable<K,T>::print() {

  std::cout << "Content of the hash table: " << std::endl;
  
  if (representacion == 1) { //quadratic

    for (int i = 0; i < maxSize; i++) {

      std::cout << "Cell: " << i << " Key: " << tableQ[i].getKey() << ", Value: " << tableQ[i].getData() << ", Overflow.size: " << tableQ[i].getOverflowSize() << std::endl;

    }

  } else {

    for (int i = 0; i < maxSize; i++) {

      std::cout << "Casilla " << i << ": ";
      for (auto x:table[i]) {
        std::cout << " > " << x.getKey() << " - " << x.getData();
      }
      std::cout << std::endl;
    }

  }

}

template<class K, class T>
void HashTable<K,T>::add(K keyVal, T value) {

  if (representacion == 1) {

    if (size == maxSize) {
      throw std::out_of_range("Hash tableQ is full");
    }
    // Compute the index of the tableQ using a key and a hash function
    int hashVal = getHashIndex(keyVal); 
    HashNode<K, T> node = tableQ.at(hashVal);
    // The cell in the tableQ is not taken
    if (node.getStatus() != 1) {
      node.setKey(keyVal);
      node.setData(value);
      tableQ.at(hashVal) = node;
    }
    else { // The cell in the tableQ is already taken
      // Find next free space using quadratic probing
      int i = 1;
      int currentHashVal = getHashIndex(hashVal + i * i);
      HashNode<K, T> currentNode = tableQ.at(currentHashVal);
      while (currentNode.getStatus() == 1) {
        i++;
        currentHashVal = getHashIndex(hashVal + i * i);
        currentNode = tableQ.at(currentHashVal);
      }
      currentNode.setKey(keyVal);
      currentNode.setData(value);
      node.addToOverflow(currentHashVal);
      tableQ.at(currentHashVal) = currentNode;
      tableQ.at(hashVal) = node;
    }
    size++;

    // Quadratic O(N)

  } else {
    
    int index = getHashIndex(keyVal);
    HashNode<K,T> node;
    node.setKey(keyVal);
    node.setData(value);

    table[index].push_back(node);

    // Chain O(N)
  }

}

#endif // __HASH_TABLE_H_

