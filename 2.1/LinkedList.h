#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

  #include <climits>
  #include "Node.h"

  template <class T>
  class LinkedList {
      private:
        Node<T>* head;
        int numElements;

      public:
        LinkedList();
        ~LinkedList();
        int getNumElements();
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T findData(int position);
        T operator[](int index);
        void operator=(LinkedList<T> &arr);
        T getData(int);
        void updateData(T, T);
        void updateAt(int, T);
        void printList();
      
  };

  template<class T>
  LinkedList<T>::LinkedList() {
      std::cout << "--->Creando una lista vacia" << std::endl;
      head = NULL;
      numElements = 0;
  }
  
  template<class T>
  LinkedList<T>::~LinkedList() {
    std::cout << "--->Liberando memoria de la lista" << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    numElements = 0;
  }
 
  template<class T>
  int LinkedList<T>::getNumElements() {
    return numElements;
  }
  template<class T>
  void LinkedList<T>::printList() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  /* Este metodo tendra una complejidad temporal de O(1) en el caso que el indice esté fuera de rango y 
  de O(n) en el peor caso. Asi como O(log n) en el mejor.*/
  template<class T>
  T LinkedList<T>::operator[](int index){
    
    Node<T> *ptr = head;
    if (index >= getNumElements()) {
      std::cout << "Index fuera de rango" << " (";
      T value = -1;
      return value;
    } else {

      for (int i = 0; i < index; i++){
        ptr = ptr->next;
      }

      
      return ptr->data;
    }
  }

  /* O(n) en el peor caso. Asi como O(log n) en el mejor. */
  template<class T>
  void LinkedList<T>::operator=(LinkedList<T> &arr) {

    std::cout << "-- Remplazando valores de lista original e imprimiendolos --" << std::endl;

      if (arr.getNumElements() == numElements) {
        
          for (int j = 0; j < arr.getNumElements(); j++) {
            addLast(arr[j]);
          }
          
        int i = 0;
        
          while (i < numElements) {
            deleteAt(0);
            i++;
          }

      } else {
        std::cout << "La LinkedList no es del mismo tamaño" << std::endl;
      }
  }
  
  template<class T>
  void LinkedList<T>::addFirst(T value) {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    numElements++;
  }
  
  template<class T>
  void LinkedList<T>::addLast(T value) {
    if (head == NULL) {
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      Node<T> *p;
      p = head;
      while (p->next != NULL) {
        p = p->next;
      }
      newNode->next = NULL;
      p->next = newNode;
      numElements++;
    }    
  }
  template<class T>
  bool LinkedList<T>::deleteData(T value) {
    Node<T> *p, *prev;
    p = head;
    prev = NULL;
    // head existe y contiene el valor a borrar
    if (p != NULL && p->data == value) {
      head = p->next;
      delete p;
      numElements--;
      return true;
    }
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value) {
        prev = p;
        p = p->next;
      }
      // Si no existe value
      if (p == NULL)
        return false;
      // Si existe value
      prev->next = p->next;
      delete p;
      numElements--;
      return true;
    }
  }
  
  template<class T>
  bool LinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return false;
    }
    else {
      Node<T> *p = head, *prev;
      // Si se debe borrar head
      if (position == 0) {
        head = p->next;
        delete p;
        numElements--;
        return true;
      }
      // Si se debe borrar algun otro nodo
      // Encontrar el nodo previo
      p = head;
      prev = NULL;
      int index = 0;
      // buscar value en la lista
      while (index != position) {
        prev = p;
        p = p->next;
        index++;
      }
      prev->next = p->next;
      delete p;
      numElements--;
      return true;    
    }     
  }
  
  /* O(1) en caso de que el indice este fuera de rango o busquemos la posicion 0,
  O(n) en el caso de que busquemos el ultimo elemento y O(log n) en los mejores casos */
  template<class T>
  T LinkedList<T>::findData(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return -1;
    }
    else {
      if (position == 0)
        return head->data;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }
      return -1;
    }
  }

  //Mejor caso O(1)
  //Peor caso O(n)
  template<class T>
  T LinkedList<T>::getData(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return -1;
    }
    else {
      if (position == 0)
        return head->data;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }
      return -1;
    }
  }


  //Mejor caso O(1)
  //Peor caso O(n)
  template<class T>
  void LinkedList<T>::updateData(T value, T nuevo){
    Node<T> *p;
    p = head;
    // Head existe y contiene el valor a actualizar
    if (p != NULL && p->data == value) {
      p->data = nuevo;
    }
    else {
      // Buscar value en la lista
      while (p != NULL && p->data != value) {
        p = p->next;
      }
      // Determinar si existe o no
      if (p == NULL){
        std::cout << "Indice fuera de rango" << std::endl;
      }else{
        p->data = nuevo;
      }
    }
  }

  //Mejor caso O(1)
  //Peor caso O(n)
  template<class T>
  void LinkedList<T>::updateAt(int position, T value) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
    }
    else {
      Node<T> *p = head;
      // Si la posicion es 0
      if (position == 0) {
        p->data = value;
      }
      p = head;
      int index = 0;
      // buscar posicion en la lista
      while (index != position) {
        p = p->next;
        index++;
      }
      p->data = value;   
    }     
  }
#endif // _LINKEDLIST_H_