//Programa que incluye 3 funciones que calculan una sumatoria de 1 a n de forma recursiva, iterativa y directa.
//También encontramos dos funciones que calculan el n-ésimo número de la serie de Fibonacci de forma recursiva e iterativa.
//Código por Jonathan Joaquín Quirino Carrasco A01640100 & Juan Pablo Pérez Durán A01639947
//Fecha de Creación: agosto 13, 2021  |  Última Fecha de Modificación: agosto XX, 2021

#include <iostream>
#include <vector>


// GRADO DE COMPLEJIDAD | O(n)
int sumaIterativa(int n){
    int retValue = 0;

    if (n >= 0){
        while (n >= 0){
        retValue = retValue + n;
        n--;
        }
    }
    return retValue;
}

// GRADO DE COMPLEJIDAD | O(n)
int sumaRecursiva(int n){
    if (n <= 0){
        return 0;
    } else{
        return n + sumaRecursiva(n - 1);
    }
}

// GRADO DE COMPLEJIDAD | O(n^3)
int sumaDirecta(int n) {

    int resultado = (n*(n + 1)) / 2;
    return resultado;
}

//GRADO DE COMPLEJIDAD | O(n)
int fibonacciIterativo(int n){

    int resultado;
    int buffer = 1;
    int buffer_ = 1;

    if (n < 3) {

        resultado = 1;

    } else {

        for (int i = 1; i < n + 1; i++) {

            if (i == 1 || i == 2) {

                std::cout << "F(" << i << ") = " << 1 << " ";       

            } else {

                resultado = buffer + buffer_;
                std::cout << "F(" << i << ") = " << resultado << " "; 
                buffer_ = buffer;
                buffer = resultado; 

            }
        }
    }

    return resultado;

}

//GRADO DE COMPLEJIDAD | O(2^n)
int fibonacciRecursivo(int n){

    int resultado;

    if (n <= 1){
        return n;
    } else {
        resultado = fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
        return resultado;
    }
}

int main(){

    std::cout << "| TEST CASE n = 20 |" << std::endl;
    std::cout << "Suma por Iteracion: " << sumaIterativa(20) << std::endl;
    std::cout << "Suma por Recursion: " << sumaRecursiva(20) << std::endl;
    std::cout << "Suma directa: " << sumaDirecta(20) << std::endl;

    std::cout << "\n";

    std::cout << "| TEST CASE n = 50 |" << std::endl;
    std::cout << "Suma por Iteracion: " << sumaIterativa(50) << std::endl;
    std::cout << "Suma por Recursion: " << sumaRecursiva(50) << std::endl;
    std::cout << "Suma directa: " << sumaDirecta(50) << std::endl;

    std::cout << "\n";

    std::cout << "| TEST CASE n = 100 |" << std::endl;
    std::cout << "Suma por Iteracion: " << sumaIterativa(100) << std::endl;
    std::cout << "Suma por Recursion: " << sumaRecursiva(100) << std::endl;
    std::cout << "Suma directa: " << sumaDirecta(100) << std::endl;

    std::cout << "\n";

    std::cout << "| TEST CASE n = 1000 |" << std::endl;
    std::cout << "Suma por Iteracion: " << sumaIterativa(1000) << std::endl;
    std::cout << "Suma por Recursion: " << sumaRecursiva(1000) << std::endl;
    std::cout << "Suma directa: " << sumaDirecta(1000) << std::endl;    

    std::cout << "\n";


    std::cout << "Fibonacci por Iteración: " << std::endl;

    std::cout << "| TEST CASE n = 5 | ";
    fibonacciIterativo(5);

    std::cout << "\n";

    std::cout << "| TEST CASE n = 10 | ";
    fibonacciIterativo(10);

    std::cout << "\n";

    std::cout << "| TEST CASE n = 15 | ";
    fibonacciIterativo(15);

    std::cout << "\n";

    std::cout << "| TEST CASE n = 30 | ";
    fibonacciIterativo(30);

    std::cout << "\n";
    std::cout << "\n";

    std::cout << "Fibonacci por Recursion: " << std::endl;

    std::cout << "| TEST CASE n = 5 | ";
    for (int i = 1; i < (5) + 1; i++) {
        std::cout << "F(" << i << ") = " << fibonacciRecursivo(i) << " ";
    }
    std::cout << "\n";

    std::cout << "| TEST CASE n = 10 | ";
    for (int i = 1; i < (10) + 1; i++) {
        std::cout << "F(" << i << ") = " << fibonacciRecursivo(i) << " ";
    }
    std::cout << "\n";

    std::cout << "| TEST CASE n = 15 | ";
    for (int i = 1; i < (15) + 1; i++) {
        std::cout << "F(" << i << ") = " << fibonacciRecursivo(i) << " ";
    }
    std::cout << "\n";

    std::cout << "| TEST CASE n = 30 | ";
    for (int i = 1; i < (30) + 1; i++) {
        std::cout << "F(" << i << ") = " << fibonacciRecursivo(i) << " ";
    }
    std::cout << "\n";

    return 0;

}