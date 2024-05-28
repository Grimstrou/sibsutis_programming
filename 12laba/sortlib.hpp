#pragma once
#include <algorithm>

// Функция сортировки пузырьком
template<typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Быстрая сортировка
template<typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        T pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

// Обертка для быстрой сортировки
template<typename T>
void quickSortWrapper(T arr[], int n) {
    quickSort(arr, 0, n - 1);
}

// Сортировка вставками
template<typename T>
void insertionSort(T arr[], int n) {
    T key;
    int j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
