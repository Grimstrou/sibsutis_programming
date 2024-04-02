#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <limits> 
#include <vector>
#include <algorithm> 

    // Функция для обнуления элементов между двумя минимальными
void one(std::vector<int>& arr) {
    if (arr.size() < 3) return; 

    int min1Index = 0;
    int min2Index = 1;

    // Инициализируем индексы для двух минимальных элементов
    if (arr[min2Index] < arr[min1Index]) {
        std::swap(min1Index, min2Index);
    }

    // Ищем минимальные элементы в массиве
    for (int i = 2; i < arr.size(); ++i) {
        if (arr[i] < arr[min1Index]) {
            min2Index = min1Index;
            min1Index = i;
        } else if (arr[i] < arr[min2Index] && i != min1Index) {
            min2Index = i;
        }
    }

    // Обнуляем элементы между двумя минимальными, если они не соседние
    if (abs(min1Index - min2Index) > 1) {
        for (int i = std::min(min1Index, min2Index) + 1; i < std::max(min1Index, min2Index); ++i) {
            arr[i] = 0;
        }
    }
}


// Функция для заполнения и вывода двумерного массива и суммы элементов каждой строки
void two(int rows) {
    srand(static_cast<unsigned>(time(nullptr)));
    std::vector<std::vector<int>> arr(rows);

    for (int i = 0; i < rows; ++i) {
        int length = rand() % 9 + 2;
        arr[i].resize(length);
        arr[i][0] = length;
        int sum = 0;
        for (int j = 1; j < length; ++j) {
            arr[i][j] = rand() % 10;
            sum += arr[i][j];
        }
        std::cout << "Ряд " << i << " (Длина " << length-1 << ", Cумма " << sum << "): ";
        for (int j = 1; j < length; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Функция сортировки в порядке убывания
void sortDescending(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), std::greater<int>());
}

// Линейный поиск
int linearSearch(const std::vector<int>& arr, int value) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == value) return i; // Возвращает индекс найденного элемента
    }
    return -1; // Элемент не найден
}

// Бинарный поиск
int binarySearch(const std::vector<int>& arr, int value) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) return mid; // Элемент найден
        else if (arr[mid] < value) high = mid - 1;
        else low = mid + 1;
    }
    return -1; // Элемент не найден
}

int main() {
    // Задача 1
    std::vector<int> oneDArray = {5, 3, 8, 2, 9, 2, 6, 7};
    std::cout << "Начальный массив: ";
    for (int num : oneDArray) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    one(oneDArray);

    std::cout << "Сортнутый: ";
    for (int num : oneDArray) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Задача 2
    std::cout << "Обработка 2D-массива:" << std::endl;
    two(5); 

    // Задача 3
    std::vector<int> arrayForSorting100(100);
    std::vector<int> arrayForSorting1000(1000);
    srand(static_cast<unsigned>(time(nullptr)));
    for (auto& num : arrayForSorting100) {
        num = rand() % 100;
    }
    for (auto& num : arrayForSorting1000) {
        num = rand() % 1000;
    }

    sortDescending(arrayForSorting100);
    sortDescending(arrayForSorting1000);

    // Поиск элемента
    int searchValue100 = arrayForSorting100[50]; // Примерное значение для поиска в первом массиве
    int searchValue1000 = arrayForSorting1000[500]; // Примерное значение для поиска во втором массиве

    int index = linearSearch(arrayForSorting100, searchValue100);
    std::cout << "Линейный поиск в массиве 100: значение " << searchValue100 << " найдено по индексу " << index << std::endl;

    index = binarySearch(arrayForSorting100, searchValue100);
    std::cout << "Двоичный поиск в массиве 100: значение " << searchValue100 << " найдено по индексу " << index << std::endl;

    index = linearSearch(arrayForSorting1000, searchValue1000);
    std::cout << "Линейный поиск в массиве 1000: значение " << searchValue1000 << " найдено по индексу " << index << std::endl;

    index = binarySearch(arrayForSorting1000, searchValue1000);
    std::cout << "Двоичный поиск в массиве 1000: значение " << searchValue1000 << " найдено по индексу " << index << std::endl;

    return 0;
}