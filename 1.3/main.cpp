// Juan Pablo Pérez Durán | A01639947

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include "ataque.h"

struct ITEM{
    Ataque ataque;
    std::string wholeDate;
    std::string ip;
} items;

void exchange(ITEM* x, ITEM* y) {
    ITEM temp = *x;
    *x = *y;
    *y = temp;
}

int partition (std::vector<ITEM> &vec, int lower, int upper) {
    Ataque head = vec[upper].ataque;
    int i = (lower - 1);

    for (int j = lower; j <= upper - 1; j++) {

        Ataque index = vec[j].ataque;
        if (index <= head) {
            i++;
            exchange(&vec[i], &vec[j]);
        }
    }
    exchange(&vec[i + 1], &vec[upper]);
    return (i + 1);
}

template <class T>
void quickSort(std::vector<T> &vec, int lower, int upper) {   
    if (lower < upper) {
        int x = partition(vec, lower, upper);
        quickSort(vec, lower, x - 1);
        quickSort(vec, x + 1, upper);
    }
}

int busquedaBinaria(std::vector<ITEM> vec, int size, Ataque key) {
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (key == vec[mid].ataque) {
            return mid;
        } else if (key < vec[mid].ataque) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

Ataque extractDate(std::string date) {
    std::string month = date.substr(0,3);
    int day = stoi(date.substr(4,6));
    int hour = stoi(date.substr(7,9));
    int min = stoi(date.substr(10,12));
    int sec = stoi(date.substr(13,15));

    Ataque orgDate(month, day, hour, min, sec);
    return orgDate;
}

void readTxt(std::vector<ITEM> &vecItems, int &x) {

    x = 0;
    std::string month = "";
    std::string day = "";
    std::string time = "";

    std::ifstream txt;

    txt.open("bitacora.txt");
    std::string line;

    while (getline(txt, line)) {
        Ataque ataque = extractDate(line);
        std::string wholeDate = line.substr(0,15);
        std::string ip = line.substr(16, line.size());

        ITEM newItems;
        newItems.ataque = ataque;
        newItems.wholeDate = wholeDate;
        newItems.ip = ip;

        vecItems.push_back(newItems);

        x++;
    }    
}

void writeTxt(std::vector<ITEM> vec, int size) {

    std::ofstream out("ordenado.txt");
    for (int i = 0; i < size; i++){
        std::string line;
        if (i == size - 1) {
            line = vec[i].wholeDate + " " + vec[i].ip;
            out << line;
        } else {
            line = vec[i].wholeDate + " " + vec[i].ip + "\n";
            out << line;
        }
    }
    out.close();
}

void range(std::vector<ITEM> vec, int size, int x, int y) {
    for (int i = x; i < y; i++){
        std::cout << vec[i].wholeDate << " ";
        std::cout << vec[i].ip << std::endl;
    }
}

int main() {
    
    std::vector<ITEM> vec;
    int n = 0;

    // ORDENAMIENTO DE BITACORA

    readTxt(vec, n);
    quickSort(vec, 0, n - 1);

    writeTxt(vec, n);
    std::string d1;
    std::string d2;

    std::cout << "REGISTROS A BUSCAR" << std::endl; 
    std::cout << "EJEMPLO: 'Jan 13 08:21:20' - 'Jan 29 17:21:02'" << std::endl << std::endl;

    std::cout << "PRIMERA FECHA: " << std::endl;
    std::getline(std::cin, d1);
    std::cout << std::endl;

    std::cout << "SEGUNDA FECHA: " << std::endl;
    std::getline(std::cin, d2);
    std::cout << std::endl;

    int out1, out2;

    Ataque date1 = extractDate(d1);
    out1 = busquedaBinaria(vec, n, date1);
    
    Ataque date2 = extractDate(d2);
    out2 = busquedaBinaria(vec, n, date2);

    if (out1 == -1 || out2 == -1){
        std::cout << "Fecha no encontrada" << std::endl;
    } else {
        range(vec, n, out1, out2);
    }
}