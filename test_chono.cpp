#include "divide.h"
#include <chrono>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
        std::srand(std::time(nullptr));

        std::vector<char> vec_char(20);
        for (auto& c : vec_char) c = static_cast<char>('A' + std::rand() % 26);

        std::vector<int> vec_int(20);
        for (auto& i : vec_int) i = 1 + std::rand() % 100;

        std::vector<double> vec_double(20);
        for (auto& d : vec_double) d = (std::rand() / (double)RAND_MAX) * 100.0;
        std::cout << "Elige modo:\n 1. Char\n 2. Int\n 3. Double\n";
        int modo;
        std::cin >> modo;
        std::cout << "Elige un pivote:\n 1. Último elemento\n 2. Primer elemento\n 3. Pivote aleatorio\n";
        int pivote;
        std::cin >> pivote;
        auto start = std::chrono::system_clock::now();
        if(pivote == 1){
            switch (modo) {
                case 1:
                    Quicksort_last(vec_char, 0, vec_char.size() - 1);
                    break;
                case 2:
                    Quicksort_last(vec_int, 0, vec_int.size() - 1);
                    break;
                case 3:
                    Quicksort_last(vec_double, 0, vec_double.size() - 1);
                    break;
                default:
                    std::cout << "Modo no válido\n";
                    return 1;
            }
        }
        else if(pivote == 2){
            switch (modo) {
                case 1:
                    Quicksort_first(vec_char, 0, vec_char.size() - 1);
                    break;
                case 2:
                    Quicksort_first(vec_int, 0, vec_int.size() - 1);
                    break;
                case 3:
                    Quicksort_first(vec_double, 0, vec_double.size() - 1);
                    break;
                default:
                    std::cout << "Modo no válido\n";
                    return 1;
            }
        }
        else if(pivote == 3){
            switch (modo) {
                case 1:
                    Quicksort_random(vec_char, 0, vec_char.size() - 1);
                    break;
                case 2:
                    Quicksort_random(vec_int, 0, vec_int.size() - 1);
                    break;
                case 3:
                    Quicksort_random(vec_double, 0, vec_double.size() - 1);
                    break;
                default:
                    std::cout << "Modo no válido\n";
                    return 1;
            }
        }
        else{
            std::cout << "Pivote no válido\n";
            return 1;
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> duration = end - start;
        std::cout << "Time: " << duration.count() << "s" << std::endl;
	return 0;
}
