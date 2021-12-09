// Juan Pablo Pérez Durán | A01639947

#include <iostream>
#include <fstream>
#include "Log.h"
#include "MaxHeap.h"

int main() {

    MaxHeap<Log> nonSortedLog(16807);

    std::string month, day, hour, min, sec, ip, desc;
    std::ifstream in("bitacoraHeap.txt");

    while(std::getline(in, month, ' ')) {
        std::getline(in, day, ' ');
        std::getline(in,hour,':');
        std::getline(in,min,':');
        std::getline(in,sec,' ');
        std::getline(in,ip,' ');
        std::getline(in,desc);

        dateTime dt(month, stoi(day), stoi(hour), stoi(min), stoi(sec));
        Log tmpLog(month, day, hour, min, sec, ip, desc, dt);
        nonSortedLog.push(tmpLog);

    }

    nonSortedLog.heapSort();

    std::ofstream MyFile("bitacora_ordenada.txt");
    //
    MyFile.close();
    //
    nonSortedLog.write("bitacora_ordenada.txt");
    std::ofstream MyFile2("duplicates.txt");
    //
    MyFile2.close();
    
}