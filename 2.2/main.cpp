/*
Juan Pablo Pérez Durán | A01639947
Jonathan Joaquín Quirino Carrasco | A01640100
*/


#include <iostream>
#include "DoubleLinkedList.h"

int suma(int x, int y) {
    int res = x + y;
    return res;
}

int main() {

    DoubleLinkedList<int> link;

    link.addLast(3);
    link.addLast(9);
    link.addLast(21);
    link.addLast(32);
    link.addLast(1);
    link.addLast(12);
    link.addLast(43);

    std::cout << "-- Lista original --" << std::endl;
    link.printList();
    std::cout << "-- Lista al reves (1,3) --" << std::endl;
    DoubleLinkedList<int> reversed = link.getReversedSubList(1, 3);
    reversed.printList();
    std::cout << "-- Lista con valores duplicados --" << std::endl;
    link.duplicate();
    link.printList();
    std::cout << "-- Sort de la lista duplicada --" << std::endl;
    link.sort();
    link.printList();
    std::cout << "-- Eliminación de los duplicados --" << std::endl;
    link.removeDuplicates();
    link.printList();
    std::cout << "-- Clear de la lista --" << std::endl;
    link.clear();
    std::cout << "Num de elementos de la lista: " << link.getNumElements() << std::endl;
    link.printList();

}