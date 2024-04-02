#include <iostream>
#include <cstdlib> 
#include <ctime> 

/*
new — оператор языка программирования C++, обеспечивающий выделение динамической памяти в куче.
malloc() - выделяет память длиной для определенного количества байт и возвращает 
указатель на начало выделенной памяти.
*/

int main() {
    int m, n = 5;
    std::cout << "Введите m: ";
    std::cin >> m;

    srand(time(0));

    






    
    int** B = new int*[m]; 
    for (int i = 0; i < m; ++i) {
        B[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            B[i][j] = rand() % 100; // Случайное число от 0 до 99
            std::cout << B[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Поиск максимального элемента и его позиции
    int z = B[0][0], x = 0, c = 0; //z - макс элимент, x - макс строк, c - макс столб.
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (B[i][j] > z) {
                z = B[i][j];
                x = i;
                c = j;
            }
        }
    }


    // Создание и заполнение новой матрицы C
    int** C = (int**)malloc((m-1) * sizeof(int*)); //выделяем память для m-1
    for (int i = 0, k = 0; i < m; ++i) {
        if (i == x) continue; // Пропускаем строку с макс эл
        C[k] = (int*)malloc((n-1) * sizeof(int));
        for (int j = 0, l = 0; j < n; ++j) {
            if (j == c) continue; // Пропускаем столбец с макс эл
            C[k][l++] = B[i][j];
        }
        ++k;
    }

    // Вывод новой матрицы C
    std::cout << "\nНовая матрица C[m-1][n-1]:\n";
    for (int i = 0; i < m-1; ++i) {
        for (int j = 0; j < n-1; ++j) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    for(int i = 0; i < m; ++i) {
        delete[] B[i];
    }
    delete[] B;

    for(int i = 0; i < m-1; ++i) {
        free(C[i]);
    }
    free(C);


    std::cout << "Введите m и n для массива A: ";
    std::cin >> m >> n;

    // Создание и заполнение массива A
    int** A = new int*[m]; //Выделение памяти в m
    for (int i = 0; i < m; i++) {
        A[i] = new int[n]; //выделяем память для n
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100; // Случайное число от 0 до 99
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Создание массива D
    int** D = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        D[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    // Заполнение массива D и вычисление сумм
    int totalSum = 0;
    for (int i = 0; i < m; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            D[i][j] = A[i][j]; // Копирование элементов из A в D
            x += A[i][j]; //эл + сум строк
        }
        D[i][n] = x; // Сумма строки
        totalSum += x;
    }

    for (int j = 0; j < n; j++) {
        int c = 0;
        for (int i = 0; i < m; i++) {
            c += A[i][j]; //эл + сум столб
        }
        D[m][j] = c; // Сумма столбца
    }
    D[m][n] = totalSum; // Общая сумма всех элементов

    // Вывод массива D
    std::cout << "\nМассив D:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            std::cout << D[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти, выделенной для массива A
    for (int i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;

    // Освобождение памяти, выделенной для массива D
    for (int i = 0; i <= m; i++) {
        free(D[i]);
    }
    free(D);

    return 0;
}