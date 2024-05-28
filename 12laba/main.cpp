#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>   
#include "sortlib.hpp"

// Функция таймера
template<typename T, typename Function>
double timer(Function sortFunction, T arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(arr, n);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = stop - start;
    return duration.count();
}

int main() {
    const int size = 10000; // Большой размер массива для оценки времени сортировки
    int intArray[size];
    double doubleArray[size];

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Заполнение массивов случайными значениями
    for (int i = 0; i < size; ++i) {
        intArray[i] = rand() % size;
        doubleArray[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    // Использование функции таймера с различными функциями сортировки
    double intSortTimeBubble = timer(bubbleSort<int>, intArray, size);
    double doubleSortTimeBubble = timer(bubbleSort<double>, doubleArray, size);
    double intSortTimeQuick = timer(quickSortWrapper<int>, intArray, size);
    double doubleSortTimeQuick = timer(quickSortWrapper<double>, doubleArray, size);

    std::cout << "Time for integer array bubble sort: " << intSortTimeBubble << " ms\n";
    std::cout << "Time for double array bubble sort: " << doubleSortTimeBubble << " ms\n";
    std::cout << "Time for integer array quick sort: " << intSortTimeQuick << " ms\n";
    std::cout << "Time for double array quick sort: " << doubleSortTimeQuick << " ms\n";

    return 0;
}
