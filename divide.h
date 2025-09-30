#ifndef DIVIDE_H
#define DIVIDE_H

#include <vector>
#include <utility>

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
int Particion (std::vector<T>& array, int ini, int fin){
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
void Quicksort(std::vector<T>& array, int ini, int fin){
	if (ini < fin){
		int pivot = Particion(array, ini, fin);
		Quicksort(array, ini, pivot - 1);
		Quicksort(array, pivot + 1, fin);
	}
}

#endif

	
	

		
