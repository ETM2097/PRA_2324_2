#ifndef DIVIDE_H
#define DIVIDE_H

#include <vector>
#include <utility>
#include <random>
#include <ctime>

template <typename T>

T b_binaria(T valor, std::vector<T>& array, int ini, int fin){
	if (ini > fin){
		return NULL;
	}
	int mid = array.size()/2;
	if (array[mid] == valor){
		return array[mid];
	}
	else{
		if (array[mid] > valor){
			return b_binaria(valor, array, ini, mid - 1);
		}
		else return b_binaria(valor, array, mid + 1, fin);
	}
}

template <typename T>
int Particion (std::vector<T>& array, int ini, int fin, int tipo){
    switch (tipo) {
		case 1: // Último elemento
			break;
		case 2: // Primer elemento
			std::swap(array[ini], array[fin]);
			break;
		case 3: // Pivote aleatorio
			{
				int randIndex = ini + std::rand() % (fin - ini + 1);
				std::swap(array[randIndex], array[fin]);
			}
			break;
		default:
			// Último elemento por defecto
			break;
	}    
	T x = array[fin];
        int i = ini;
        for(int j = ini; j < fin - 1; j++){
                if (array[j] <= x){
                        std::swap(array[i], array[j]);
                        i++;
                }
        }
        std::swap(array[i], array[fin]);
        return i;
}


template <typename T>
void Quicksort_last(std::vector<T>& array, int ini, int fin){
	if (ini < fin){
		int pivot = Particion(array, ini, fin, 1);
		Quicksort_last(array, ini, pivot - 1);
		Quicksort_last(array, pivot + 1, fin);
	}
}

template <typename T>
void Quicksort_first(std::vector<T>& array, int ini, int fin){
	if (ini < fin){
		int pivot = Particion(array, ini, fin, 2);
		Quicksort_first(array, ini, pivot - 1);
		Quicksort_first(array, pivot + 1, fin);
	}
}

template <typename T>
void Quicksort_random(std::vector<T>& array, int ini, int fin){
	if (ini < fin){
		int pivot = Particion(array, ini, fin, 3);
		Quicksort_random(array, ini, pivot - 1);
		Quicksort_random(array, pivot + 1, fin);
	}
}

#endif

	
	

		
