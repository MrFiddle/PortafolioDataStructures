#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

  #include<vector>
  #include <fstream>
  #include<iostream>
  #include"Log.h"

  template<class T>
  class MaxHeap {

    private:
      // contiene los elementos del heap
      std::vector<T> data; 
      // capacidad maxima del heap
      int maxSize;
      // tamaño actual del heap   
      int size;   

      int parent(int i);
      int left(int i);
      int right(int i);
      std::vector<T> duplicates;

    public:
    
      MaxHeap(int capacity);
      ~MaxHeap();
      bool isEmpty();
      int getSize();
      int getCapacity();
      T getData(int index);
      void printMaxHeap();
      void push(T key);
      void pop();
      void moveDown(int i);
      void moveUp(int i);
      T top();
      void deleteElement(int i);
      void heapify(int n, int i);
      void heapSort();
      void bubbleSort();
      void write(std::string txtName);
      void writeIpOnly(std::string txtName);
      void writeDuplicates(std::string txtName);
      void writeTopFive(MaxHeap<T> topFive);
      void printVector();

  };

  template <class T> 
  MaxHeap<T>::MaxHeap(int capacity) {
      std::cout << "--->Creando un MaxHeap: " << std::endl;
      size = 0;
      maxSize = capacity;
      data.resize(maxSize);
  }

  template <class T> 
  MaxHeap<T>::~MaxHeap() {
      std::cout << "--->Liberando memoria del MaxHeap: " << std::endl;
      data.clear();
  }
  
  template <class T> 
  bool MaxHeap<T>::isEmpty() {
    return (size <= 0);
  }

  template <class T> 
  int MaxHeap<T>::getSize() {
    return size;
  }

  template <class T> 
  int MaxHeap<T>::getCapacity() {
    return maxSize;
  }

  template <class T>
  T MaxHeap<T>::getData(int index){

    return data[index];

  }

  template <class T> 
  void MaxHeap<T>::printMaxHeap() {
    for (int i=0; i < size; i++)
      std::cout << data[i] << std::endl;
      std::cout << std::endl;
  }

  template <class T> 
  int MaxHeap<T>::parent(int i) {
    return (i-1)/2; 
  }
  
  template <class T> 
  int MaxHeap<T>::left(int i) {
    return (2*i + 1); 
  }

  template <class T> 
  int MaxHeap<T>::right(int i) {
    return (2*i + 2);
  }

  template <class T>
  void MaxHeap<T>::deleteElement(int i) {

    T swapElement = i;

    if (left(i) <= size && data[i] > data[left(i)]) {

      swapElement = left(i);

    } 

    if (right(i) <= size && data[swapElement] > data[right(i)]) {

      i = right(i);

    }

    if (swapElement != i) {

      std::swap(data[i], data[swapElement]);
      deleteElement(swapElement);

    }
    return;

  }

  template <class T>
  void MaxHeap<T>::moveDown(int i) {

    int maxIndex = i;

    if (left(i) <= size && data[left(i)] > data[maxIndex]) {
      maxIndex = left(i);
    }

    if (right(i) <= size && data[right(i)] > data[maxIndex]) {
      maxIndex = right(i);
    }

    if (i != maxIndex) {

      std::swap(data[i], data[maxIndex]);
      moveDown(maxIndex);

    }


  }

  template <class T>
  void MaxHeap<T>::moveUp(int i) {

    while (i != 0 && data[parent(i)] < data[i]) {
      std::swap(data[i], data[parent(i)]);
      i = parent(i);
    }

  }

  template <class T> 
  void MaxHeap<T>::push(T key) {

    if (size == maxSize) {
        std::cout << "Overflow | no se puede insertar la llave: " << std::endl;
        return;
    }
    // Insertamos la nueva llave al final del vector
    int i = size;

    data[i] = key;
    size++;

    // if (data[i] == key) {

    //   duplicates.push_back(key);

    // }


    // Reparar las propiedades del max heap si son violadas
    while (i != 0 && data[parent(i)] < data[i]) {
       std::swap(data[i], data[parent(i)]);
       i = parent(i);
    }

  }

  template <class T>
  void MaxHeap<T>::pop() {

    if (size < 1) {

      std::cout << "No hay ningún dato en el heap" << std::endl;
      return;

    }
    data[0] = data[size];
    size = size - 1;

    moveDown(0);
    return;

  }

  template <class T> 
  T MaxHeap<T>::top() {
    T result;
    if (isEmpty()) {
        std::cout << "El MaxHeap está vacio" << std::endl;
        return result;
    }
    return data[0];
  }

  template <class T>
  void MaxHeap<T>::bubbleSort() {

    int n = (sizeof(data) / sizeof(data[0]));

    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        std::swap(data[j], data[j + 1]);
      }

    }

  }

  template <class T>
  void MaxHeap<T>::heapify(int n, int i) {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && data[l] > data[largest]) {

        largest = l;

    }
 

    if (r < n && data[r] > data[largest]) {

        largest = r;

    }


    if (largest != i) {

        std::swap(data[i], data[largest]);
        heapify(n, largest);

    }



  }

  template <class T>
  void MaxHeap<T>::heapSort() {
    
      int n = size;

      for (int i = n / 2 - 1; i >= 0; i--) {
       
        heapify(n, i);
       
      }
 
      for (int i = n - 1; i > 0; i--) {

        std::swap(data[0], data[i]);
        heapify(i, 0);

    }

  }

  template <class T>
  void MaxHeap<T>::write(std::string txtName) {

    std::ofstream out(txtName);

      // Time complexity o(n)
    for (int i = 0; i < this->getSize(); i++){
        std::string line;

        if (i == this->getSize() - 1){
            line = this->getData(i).getAll();
            out << line;
        }else {
            line = this->getData(i).getAll() + "\n";
            out << line;
          }
          
      }

      out.close();

  }

  template <class T>
  void MaxHeap<T>::writeIpOnly(std::string txtName) {

    std::ofstream out(txtName);

      // Time complexity o(n)
    for (int i = 0; i < this->getSize(); i++){
        std::string line;

        if (i == this->getSize() - 1){
            line = this->getData(i).getIp().getIpNoPort();
            out << line;
        }else {
            line = this->getData(i).getIp().getIpNoPort() + "\n";
            out << line;
          }
          
      }

      out.close();

  }

  template <class T>
  void MaxHeap<T>::writeDuplicates(std::string txtName) {

    std::ofstream out(txtName);

      // Time complexity o(n)
    for (int i = 0; i < duplicates.size(); i++) {

        std::string line;

        if (i == duplicates.size() - 1){
            line = duplicates[i].getIp().getIpNoPort();
            out << line;
        }else {
            line = duplicates[i].getIp().getIpNoPort() + "\n";
            out << line;
          }
          
      }

      out.close();

  }

  template <class T>
  void MaxHeap<T>::writeTopFive(MaxHeap<T> topFive) {
    

    int i = size;
    int index = 0;
    std::vector<Log> five;
    five.push_back(data[data.size()]);
    five[0].getIp().sumarCantidad();

    std::cout << data.size() << std::endl;

    while (i > -1) {
      if (data[data.size()] == data[data.size() - 1]) {

        five[index].getIp().sumarCantidad();
        data.pop_back();
        i--;

      } else {

        five.push_back(data[data.size()]);
        five[0].getIp().sumarCantidad();
        index++;
        i--;

      }

    }

  }

  template <class T>
  void MaxHeap<T>::printVector() {

    for (int i = 0; i < data.size(); i++) {

      std::cout << data[i].getIp().getIpYCantidad() << std::endl;

    }

  }

  

#endif // __MAXHEAP_H_