#include <iostream>
#include "Node.h"
#include "LinkedList.h"

int main(){
    LinkedList<int> myLinkedList;
    LinkedList<int> secondLinkedList;

    for (int i = 0; i < 5; i++){
        myLinkedList.addFirst(i);
    }

    for (int i = 5; i < 10; i++){
        secondLinkedList.addFirst(i);
    }

    std::cout << "-- Lista original --" << std::endl;
    myLinkedList.printList();

    int value = myLinkedList.findData(2);

    if (value != -1){
        std::cout << "Valor encontrado en la posicion 2: " << value << std::endl;
    }

    std::cout << "--Probando getData(): " << myLinkedList.getData(3) << std::endl;
    std::cout << "--Probando updateData(): ";
    myLinkedList.updateData(3, 2);
    myLinkedList.printList();

    std::cout << "--Probando updateAt(): ";
    myLinkedList.updateAt(4, 10);
    myLinkedList.printList();


    value = myLinkedList.findData(6);

    //A continuacion probamos nuestra sobrecarga con diferentes casos de prueba
    std::cout << "-- Prueba de sobrecarga operador [] --\n";
    std::cout << "El elemento en la posicion 0 de la lista ligada: " << myLinkedList[0] << std::endl;
    std::cout << "El elemento en la posicion 2 de la lista ligada: " << myLinkedList[2] << std::endl;
    std::cout << "El elemento en la posicion 6 de la lista ligada: " << myLinkedList[6] << std::endl;
    

    std::cout << "-- Segunda lista --" << std::endl;
    secondLinkedList.printList();


    myLinkedList = secondLinkedList;
    myLinkedList.printList();
     
    return 0;
}