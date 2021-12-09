// Jonathan Joaquín Quirino Carrasco | A01640100
// Juan Pablo Pérez Durán | A01639947

#include <iostream>
#include <vector>
#include <string>

template <class T>
void ordenaIntercambioTemplate(std::vector<T>&x, T size) { // COMPLEJIDAD O(n^2)
    int swaps = 0;
    int comparaciones = 0;
    for (int i = 0; i < x.size() - 1; i++){
        for (int j = i + 1; j < x.size(); j++){
            comparaciones++;
            if (x[i] > x[j]) {
                T temp = x[i];
                x[i] = x[j];
                x[j] = temp;
                swaps++;
            }
        }
    }
    std::cout << "num de swaps: " << swaps << std::endl;
    std::cout << "num de comparaciones: " << comparaciones << std::endl;
}

template <class T>
void ordenaBurbujaTemplate(std::vector<T>&vec, T size) { // COMPLEJIDAD O(n^2)
    int swaps = 0;
    int comparaciones = 0;
    for (int i = 0; i < vec.size() - 1; i++){
        for (int j = 0; j < vec.size() - i - 1; j++){
            comparaciones++;
            if (vec[j] > vec[j + 1]) {
                T temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                swaps++;
            }
        }
    }
    std::cout << "num de swaps: " << swaps << std::endl;
    std::cout << "num de comparaciones: " << comparaciones << std::endl;
}

template <class T>
void merge(std::vector<T>&vec, int const left, int const mid, int const right) { // O(n log n)
	int swaps = 0;
    int comparaciones = 0;
    
    auto const n1 = mid - left + 1;
	auto const n2 = right - mid;

	auto *leftvec = new int[n1], *rightvec = new int[n2];

	for (auto i = 0; i < n1; i++)
		leftvec[i] = vec[left + i];
        comparaciones++;
	for (auto j = 0; j < n2; j++)
		rightvec[j] = vec[mid + 1 + j];
        comparaciones++;

	int i = 0;
    int j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (leftvec[i] <= rightvec[j]) {
			vec[k] = leftvec[i];
			i++;
		} else {
			vec[k] = rightvec[j];
			j++;
		}
		k++;
        swaps++;
	}

    std::cout << "num de swaps: " << swaps << std::endl;
    std::cout << "num de comparaciones: " << comparaciones << std::endl;

	while (i < n1) {
		vec[k] = leftvec[i];
		i++;
		k++;
	}

	while (j < n2) {
		vec[k] = rightvec[j];
		j++;
		k++;
	}
}

template <class T>
void mergeSort(std::vector<T>&vec, int const begin, int const end)
{
	if (begin >= end)
		return;

    int tamanio = vec.size();

	auto mid = begin + (end - begin) / 2;
	mergeSort(vec, begin, mid);
	mergeSort(vec, mid + 1, end);
	merge(vec, begin, mid, end);
}

template <class T>
int busquedaSecuencialOrdTemplate(std::vector<T>&vec, T key, T size){ // COMPLEJIDAD o(n)

    int comparaciones = 0;

    int n = vec.size();
    for (int i = 0; i < n; i++) {
        comparaciones++;
        if (key <= vec[i]) {
            if (key == vec[i]) {
                std::cout << "numero de comparaciones: " << comparaciones << std::endl;
                return i;
            } else {
                std::cout << "numero de comparaciones: " << comparaciones << std::endl;                
                return -1;
            }
        }
    }
}

template <class T>
T busquedaBinaria(std::vector<T>&vec, T key, T size) { // COMPLEJIDAD o(log(n))

    int comparaciones = 0;

    int n = vec.size();
    T l = 0;
    T r = n - 1;

    while (l <= r) {
        comparaciones++;
        int mid = l + ((r - l)/2);
        if (key == vec[mid]) {
            return mid;
        } else if (key < vec[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    std::cout << "num de comparaciones: " << comparaciones << std::endl;
    std::cout << "si" << std::endl;
    return -1;
}

template <class T>
void printVector(std::vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }
}


int main(){

    int n, ord, bus, key;

    std::cin >> n;
    std::cin >> ord;
    std::cin >> bus;
    std::cin >> key;

    std::vector<int> vec;

    // Leyendo los elementos del vector del TXT
    for (int i = 0; i < n; i++) {
        int element;
        std::cin >> element;
        vec.push_back(element);
    }

    // Print arreglo original
    std::cout << "--- ARREGLO ORIGINAL ---" << std::endl;
    printVector(vec);

    // Elección de ordenamiento y su respectivo print
    std::string tipoOrdenamiento;
    if (ord == 1) {
        tipoOrdenamiento = ".:Ordenamiento por intercambio:.";
        std::cout << "--- ARREGLO ORDENADO | " << tipoOrdenamiento <<  " ---" << std::endl;
        ordenaIntercambioTemplate(vec, n);
    } else if (ord == 2) {
        tipoOrdenamiento = ".:Ordenamiento por burbuja:.";
        std::cout << "--- ARREGLO ORDENADO | " << tipoOrdenamiento <<  " ---" << std::endl;
        ordenaBurbujaTemplate(vec, n);
    } else if (ord == 3) {
        tipoOrdenamiento = ".:Ordenamiento por merge:.";
        std::cout << "--- ARREGLO ORDENADO | " << tipoOrdenamiento <<  " ---" << std::endl;
        mergeSort(vec, 0, n - 1);
    }

    printVector(vec);
    
    // Elección de algoritmo de búsqueda y su respectivo print
    std::string tipoBusqueda;
    int resBusqueda;
    if (bus == 1) {
        tipoBusqueda = ".:Busqueda secuencial:.";
        std::cout << "--- INDICE DEL VALOR (" << key << ")" << " | " << tipoBusqueda << " ---" << std::endl;
        resBusqueda = busquedaSecuencialOrdTemplate(vec, key, n);
    } else if (bus == 2) {
        tipoBusqueda = ".:Busqueda binaria:.";
        std::cout << "--- INDICE DEL VALOR (" << key << ")" << " | " << tipoBusqueda << " ---" << std::endl;
        resBusqueda = busquedaSecuencialOrdTemplate(vec, key, n);
    }
    std::cout << "indice: " << resBusqueda << std::endl;

}