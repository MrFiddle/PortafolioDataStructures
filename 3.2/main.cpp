/* Jonathan Joaquin Quirino Carrasco | A01640100
Juan Pablo Perez Duran | A01639947

Fecha de creacion: Octubre 18, 2021
Fechade modificacion: Octubre XX, 2021 */

#include <iostream>
#include "MaxHeap.h"

int main() {
  std::cout << "Prueba de un MaxHeap!\n";
  MaxHeap<int> myMaxHeap(100);
  std::cout << "isEmpty() " << myMaxHeap.isEmpty() << std::endl;
  std::cout << "getSize() " << myMaxHeap.getSize() << std::endl;
  std::cout << "getCapacity() " << myMaxHeap.getCapacity() << std::endl;
  std::cout << "push() de 7 valores" << std::endl;
  myMaxHeap.push(3);  
  myMaxHeap.push(2);
  myMaxHeap.push(1);
  myMaxHeap.push(15);
  myMaxHeap.push(5);
  myMaxHeap.push(4);
  myMaxHeap.push(45);
  /* Max Heap creado 
             45
            /  \
           5    15
          / \   / \
         2   3 1   4
  */
  std::cout << "getSize() " << myMaxHeap.getSize() << std::endl;
  myMaxHeap.printMaxHeap();
  std::cout << "top() " << myMaxHeap.top() << std::endl;
  std::cout << "getSize() " << myMaxHeap.getSize() << std::endl;
  myMaxHeap.pop();
  myMaxHeap.printMaxHeap();

}