// Juan Pablo Pérez Durán | A01639947

#include "Log.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <fstream>
#include "vector"

int main(){

    DoubleLinkedList<Log> logDoubleLinkedList;

    // Cargamos logs de nuestro archivo bitacora.txt
    logDoubleLinkedList.loadLogs("bitacora.txt");

    // Creamos el archivo de bitacora_ordenada.txt
    std::ofstream MyFile("bitacora_ordenada.txt");
    MyFile.close();

    // Creamos el archivo de resultado_busqueda.txt
    std::ofstream MyFile2("resultado_busqueda.txt");
    
    // Ordenamos nuestra double linked list y la guardamos en nuestro archivo
    logDoubleLinkedList.quickSort();
    logDoubleLinkedList.write("bitacora_ordenada.txt");


    // Declaracion de intervalos para búsqueda binaria
    std::string mes1;
    int dia1, hora1, min1, seg1;

    std::string mes2;
    int dia2, hora2, min2, seg2;

    // Input de intervalos de ambas fechas
    std::cout << "1ra fecha | Mes: " << std::endl;
    std::cin >> mes1;

    std::cout << "1ra fecha | Dia: " << std::endl;
    std::cin >> dia1;

    std::cout << "1ra fecha | Hora: " << std::endl;
    std::cin >> hora1;

    std::cout << "1ra fecha | Minuto: " << std::endl;
    std::cin >> min1;

    std::cout << "1ra fecha | Segundo: " << std::endl;
    std::cin >> seg1;

    // -- //

    std::cout << "2da fecha | Mes: " << std::endl;
    std::cin >> mes2;

    std::cout << "2da fecha | Dia: " << std::endl;
    std::cin >> dia2;

    std::cout << "2da fecha | Hora: " << std::endl;
    std::cin >> hora2;

    std::cout << "2da fecha | Minuto: " << std::endl;
    std::cin >> min2;

    std::cout << "2da fecha | Segundo: " << std::endl;
    std::cin >> seg2;


    dateTime date1(mes1, dia1, hora1, min1, seg1);
    dateTime date2(mes2, dia2, hora2, min2, seg2);

    
    int l = logDoubleLinkedList.binarySearch(date1);
    int r = logDoubleLinkedList.binarySearch(date2);

    // Write de la búsqueda por intervalos en nuestro archivo
    for (int i = l; i < r; i++) {
        
        std::string line;
        if (i == logDoubleLinkedList.getNumElements()) {
            line = logDoubleLinkedList.getData(i).getAll();
            MyFile2 << line;
        } else {
            line = logDoubleLinkedList.getData(i).getAll() + "\n";
            MyFile2 << line;
        }

    }

    MyFile2.close();

    return 0;
}