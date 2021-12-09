#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

  #include<vector>
  #include<iostream>

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

    public:
    
      MaxHeap(int capacity);
      ~MaxHeap();
      bool isEmpty();
      int getSize();
      int getCapacity();
      void printMaxHeap();
      void push(T key);
      void pop();
      void moveDown(int i);
      void moveUp(int i);
      T top();
      void deleteElement(int i);

  };

  template <class T> 
  MaxHeap<T>::MaxHeap(int capacity) {
      std::cout << "--->Creando un MaxHeap: " <<  this << std::endl;
      size = 0;
      maxSize = capacity;
      data.resize(maxSize);
  }

  template <class T> 
  MaxHeap<T>::~MaxHeap() {
      std::cout << "--->Liberando memoria del MaxHeap: " <<  this << std::endl;
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
  void MaxHeap<T>::printMaxHeap() {
    for (int i=0; i < size; i++)
      std::cout << data[i] << " ";
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
        std::cout << "Overflow | no se puede insertar la llave: " << key << std::endl;
        return;
    }
    // Insertamos la nueva llave al final del vector
    int i = size;
    data[i] = key;
    size++;
    // Reparar las propiedades del max heap si son violadas
    moveUp(i);

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
    T result = -1;
    if (isEmpty()) {
        std::cout << "El MaxHeap está vacio" << std::endl;
        return result;
    }
    return data[0];
  }

#endif // __MAXHEAP_H_