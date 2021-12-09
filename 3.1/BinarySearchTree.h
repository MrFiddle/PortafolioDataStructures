#ifndef _BinarySearchTree_H_
#define _BinarySearchTree_H_

  #include<iostream>
  #include "NodeTree.h"

  template <class T>
  class BinarySearchTree { 
  private:
    
     NodeTree<T>* insertRecursive(NodeTree<T> *p, T value);
     NodeTree<T>* getSuccessor(NodeTree<T> *p);
     NodeTree<T>* deleteRecursive(NodeTree<T> *p, T value);
     void inorder(NodeTree<T> *p);
     void postorder(NodeTree<T> *p);
     void preorder(NodeTree<T> *p);

  public: 

      BinarySearchTree();
      void levelOrder();
      ~BinarySearchTree();
      NodeTree<T> *root;
      void clearMemory(NodeTree<T> *p);
      void insert(T value);
      bool search(T value);
      void deleteNode(T value);
      void callInorder();
      void callPostorder();
      void callPreorder();
      void callLevelByLevel();
      void printNode(NodeTree<T>* root, int level);
      int height(NodeTree<T>* root);
      int whatLevelAmI(T);
      void visit(int opc);
      bool ancestors(NodeTree<T>* root, T target);
      
      
  }; 

  template<class T>
  BinarySearchTree<T>::BinarySearchTree() {
    std::cout << "--->Creando un BinarySearchTree vacio: " <<  this << std::endl;
    root = NULL;
  }
  
  template<class T>
  BinarySearchTree<T>::~BinarySearchTree() {
    std::cout << "--->Liberando memoria del BinarySearchTree: " << this << std::endl;
    clearMemory(root);
  }

  template<class T>
  void BinarySearchTree<T>::clearMemory(NodeTree<T> *p) {
    if (p != NULL) {
      clearMemory(p->left);
      clearMemory(p->right);
      delete p;
      p = NULL;
    }
  }
  template<class T>
  NodeTree<T>* BinarySearchTree<T>::insertRecursive(NodeTree<T> *p, T value) {
    if (p == NULL) // Arbol esta vacio
      p = new NodeTree<T>(value);
    else if (value < p->data)
      p->left = insertRecursive(p->left, value);
    else if (value > p->data)
      p->right = insertRecursive(p->right, value);
    else
      std::cout << "El elemento " << value << " ya existe en el BST" << std::endl;
    return p;
  }
  template<class T>
  void BinarySearchTree<T>::insert(T value) {
    root = insertRecursive(root, value);
  }

  template<class T>
  bool BinarySearchTree<T>::search(T value) {
    NodeTree<T> *p = root;
    while (p != NULL) {
      if (p->data == value) {
        return true;
      }
      else {
        p = (value < p->data ? p->left : p->right);
      }
    }
    return false;
  }

  template<class T>
  NodeTree<T> * BinarySearchTree<T>::getSuccessor(NodeTree<T> *p) {
    NodeTree<T> *current = p;
    while (current && current->left != NULL) {
      current = current->left;
    }
    return current;
  }

  template<class T>
  void BinarySearchTree<T>::deleteNode(T value) {
    root = deleteRecursive(root, value);
  }

  template<class T> 
  NodeTree<T>* BinarySearchTree<T>::deleteRecursive(NodeTree<T> *p, T value) {
    NodeTree<T> *current = p;
    // caso base 
    if (p == NULL)
      return p;
    if (value < p->data)
      p->left = deleteRecursive(p->left, value);
    else if (value > p->data)
      p->right = deleteRecursive(p->right, value);
    else { // Hemos localizado el nodo a borrar
      // El nodo a borrar no tiene ningun hijo
      if (p->left == NULL && p->right == NULL) {
        delete p;
        p = NULL;
        return p;
      }
      else if (p->left == NULL) { // El nodo a borrar solo tiene hijo derecho
        current = p->right;
        delete p;
        p = NULL;
        return current;
      } 
      else if (p->right == NULL) { // El nodo a borrar solo tiene hijo izquierdo
        current = p->left;
        delete p;
        p = NULL;
        return current;
      }
      // El nodo a borrar tiene dos hijos
      current = getSuccessor(p->right);
      p->data = current->data;
      p->right = deleteRecursive(p->right, current->data);
    }
    return p;
  }

  template<class T>
  void BinarySearchTree<T>::inorder(NodeTree<T> *p) {
    if (p != NULL) {
      inorder(p->left);
      std::cout << p->data << " ";
      inorder(p->right);
    }
  }

  template<class T>
  void BinarySearchTree<T>::callInorder() {
    std::cout << "--Recorrido inorder--" << std::endl;
    inorder(root);
    std::cout << std::endl;
  }

  template<class T>
  void BinarySearchTree<T>::postorder(NodeTree<T> *p) {
    if (p != NULL) {
      postorder(p->left);
      postorder(p->right);
      std::cout << p->data << " ";
    }
  }

  template<class T>
  void BinarySearchTree<T>::callPostorder() {
    std::cout << "--Recorrido postorder--" << std::endl;
    postorder(root);
    std::cout << std::endl;
  }

  template<class T>
  void BinarySearchTree<T>::preorder(NodeTree<T> *p) {
    if (p != NULL) {
      std::cout << p->data << " ";
      preorder(p->left);
      preorder(p->right);
    }
  }

  template<class T>
  void BinarySearchTree<T>::callPreorder() {
    std::cout << "--Recorrido preorder--" << std::endl;
    preorder(root);
    std::cout << std::endl;
  }

  template<class T>
  void BinarySearchTree<T>::callLevelByLevel() {

    int h = height(root);
    for (int i = 1; i <= h; i++) {
      std::cout << "Nivel " << i - 1 << ": ";
      printNode(root, i);
      std::cout << "\n";
    }

  }

  template<class T>
  void BinarySearchTree<T>::printNode(NodeTree<T>* root, int level) {

    if (root == NULL) {
      return;
    }

    if (level == 1) {
      std::cout << root->data << " ";
    } else if (level > 1) {
      printNode(root->left, level - 1);
      printNode(root->right, level - 1);
    }

  }

  //O(n) siendo n el numero de nodos que se van a recorrer
  template<class T>
  int BinarySearchTree<T>::height(NodeTree<T>* root){

    if (root == NULL){
      return 0;
    }

    int lHeight = height(root->left);
    int RHeight = height(root->right);

    if (lHeight > RHeight){
      return  lHeight + 1;
    } else {
      return RHeight + 1;
    }
  }

  /* Mejor caso O(1)
  Peor caso O(n) */
  template<class T>
  int BinarySearchTree<T>::whatLevelAmI(T value){
    int level = 0;

    NodeTree<T> *p = root;

    while(p != NULL){
      if (value < p->data){
        p = p->left;
        level++;
      } else if (value > p->data){
        p = p->right;
        level++;
      } else{
        return level;
      }
    }

    return -1;
  }

  template<class T>
  void BinarySearchTree<T>::visit(int opc) {

    if (opc == 1) {
      std::cout << "-- Recorrido Preorder --" << std::endl;
      callPreorder();
    } else if (opc == 2) {
      std::cout << "-- Recorrido Inorder --" << std::endl;
      callInorder();
    } else if (opc == 3) {
      std::cout << "-- Recorrido Postorder --" << std::endl;
      callPostorder();
    } else if (opc == 4) {
      std::cout << "-- Recorrido Level by level --" << std::endl;
      callLevelByLevel();
    }

  }

  template<class T>
  bool BinarySearchTree<T>::ancestors(NodeTree<T>* root, T target) {

    if (root == nullptr) {
      return false;
    } else if (root->data == target) {
      return true;
    }

    bool left = ancestors(root->left, target);
    bool right = false;
    
    if (left == false) {
      right = ancestors(root->right, target);
    }

    if (left || right) {
      std::cout << root->data << std::endl;
    }

    return left || right; 
    
  }


  #endif // _BinarySearchTree_H_