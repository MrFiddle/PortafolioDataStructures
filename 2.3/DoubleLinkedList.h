#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <iostream>
#include <fstream>
#include "Node.h"
#include "Stack.h"
#include "Log.h"

template <class T>
class DoubleLinkedList {
    
    private:

        Node<T>* head;
        Node<T>* tail;
        int numElements;

    public:
    
        DoubleLinkedList();
        ~DoubleLinkedList();
        int getNumElements();
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);
        void updateAt(T value, T nuevo);
        void loadLogs(std::string);
        void write(std::string);
        void swap(Node<T>* a, Node<T>* b);
        Node<T>* partition(Node<T> *l, Node<T> *h);
        void quickSort();
        int binarySearch(dateTime target);
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    std::cout << "--->Creando una lista vacia " << this << std::endl;
    head = NULL;
    tail = NULL;
    numElements = 0;
}
  
template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    std::cout << "--->Liberando memoria de la lista " << this << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
}

template<class T>
void DoubleLinkedList<T>::swap(Node<T>* a, Node<T>* b) {

    // Time complexity o(1)
    T temp = a->data;
    a->data = b->data;
    b->data = temp;

}

template<class T>
Node<T>* DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h) {

    T x = h->data;
    Node<T> *i = l->prev;

    // Time complexity o(n)
    for (Node<T> *j = l; j != h; j = j->next) {
      if (j->data.getDate() <= x.getDate()) {
        i = (i == NULL)? l : i->next;
        swap(i, j);
      }
    }
    i = (i == NULL)? l : i->next;
    swap(i,h);
    return i;

}


template<class T>
void DoubleLinkedList<T>::quickSort(){

  Stack<Node<T>*> stack;

  Node<T>* l = head;
  Node<T>* h = tail;

  stack.push(l);
  stack.push(h);

  // Time complexity o(n)
  while (stack.getNumElements() > 0) {
    h = stack.pop();
    l = stack.pop();

    Node<T>* p = partition(l, h);

    if (p->data.getDate() > l->data.getDate()) {
      stack.push(l);
      stack.push(p->prev);
    }
    
    if (p->data.getDate() < h->data.getDate()) {
      stack.push(p->next);
      stack.push(h);
    }
  }
}

template<class T>
void DoubleLinkedList<T>::updateAt(T value, T nuevo) {
    Node<T> *p;
    p = head;

    // Time complexity o(1)
    if (p != NULL && p->data == value) {
      p->data = nuevo;
    } else{
      while (p != NULL && p->data != value) {
        p = p->next;
      }

      if (p == NULL){
        std::cout << "Index out of range" << std::endl;
      } else {
        p->data = nuevo;
      }
    }
}


template<class T>
int DoubleLinkedList<T>::getNumElements() {
    return numElements;
  }

  template<class T>
  void DoubleLinkedList<T>::addFirst(T value) {
    Node<T> *newNode = new Node<T>(value);

    // O(1)
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    }
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    numElements++;
  }
  
  template<class T>
  void DoubleLinkedList<T>::addLast(T value) {

    if (head == NULL) {
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      numElements++;
    }    
}
  
template<class T>
bool DoubleLinkedList<T>::deleteData(T value) {
    Node<T> *p, *q;
    p = head;
    q = NULL;

    // o(n)

    if (p == NULL) {
      return false;
    }
    else {

      while (p != NULL && p->data != value) {
        q = p;
        p = p->next;
      }

      if (p == NULL)
        return false;

      if (p->prev == NULL) {
        head = p->next;
        if (head != NULL)
          head->prev = NULL;
      }
      else if (p->next == NULL) { 

        q->next = NULL;
        tail = q;
      }
      else {

        q->next = p->next;
        p->next->prev = q;

      }
      delete p;
      numElements--;
      return true;
    }
}

template<class T>
bool DoubleLinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return false;
    }
    else if (position == 0) {
      Node<T> *p = head;

      if (head != NULL && head->next == NULL) {
        head = NULL;
        tail = NULL;  
      }
      else {
        head = p->next;
        head->prev = NULL;
      }
      delete p;
      numElements--;
      return true; 
    }
    else { 
      Node<T> *p = head, *q = NULL;
      int index = 0;
      while (index != position) {
        q = p;
        p = p->next;
        index++;
      }

      if (p->next == NULL) {
        q->next = NULL;
        tail = q;
      }
      else {
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
}
  
template<class T>
T DoubleLinkedList<T>::getData(int position) {

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

      return p->data;

}
  
template<class T>
void DoubleLinkedList<T>::loadLogs(std::string txtName){
    
    std::string month, day, hour, min, sec, ip, desc;
    std::ifstream in(txtName);
    // Time complexity o(n)
    while(std::getline(in, month, ' ')){
        std::getline(in, day, ' ');
        std::getline(in,hour,':');
        std::getline(in,min,':');
        std::getline(in,sec,' ');
        std::getline(in,ip,' ');
        std::getline(in,desc);

        dateTime dt(month, stoi(day), stoi(hour), stoi(min), stoi(sec));
        Log tmpLog(month, day, hour, min, sec, ip, desc, dt);
        addLast(tmpLog);
        std::cout << tmpLog.getAll() << std::endl;

    }
}

template<class T>
void DoubleLinkedList<T>::write(std::string txtName){
      
      std::ofstream out(txtName);

      // Time complexity o(n)
      for (int i = 0; i < this->getNumElements(); i++){
          std::string line;

          if (i == this->getNumElements() - 1){
              line = this->getData(i).getAll();
              out << line;
          }else {
              line = this->getData(i).getAll() + "\n";
              out << line;
          }
          
      }

      out.close();
}

template<class T>
int DoubleLinkedList<T>::binarySearch(dateTime target) {

  int l = 0;
  int r = numElements - 1;

  // Time complexity o(n)
  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (target == this->getData(mid).getDate()) {
      return mid;
    } else if (target < this->getData(mid).getDate()) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

#endif // _DOUBLELINKEDLIST_H_