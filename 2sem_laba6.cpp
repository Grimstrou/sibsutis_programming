#include <iostream>
#include <cstdlib>
#include <cmath>

// bool PravTr(int a, int b, int c) {
//     return (a + b > c) && (a + c > b) && (b + c > a);
// }

// void CalcTriangle(int a, int b, int c, int* perimeter, double* area, bool* result) {
//     if (PravTr(a, b, c)) {
//         *perimeter = a + b + c; // Вычисляем и возвращаем периметр через указатель
//         double p = (*perimeter) / 2.0; // Вычисление полупериметра
//         *area = sqrt(p * (p - a) * (p - b) * (p - c)); // Вычисляем и возвращаем площадь через указатель
//         *result = true; // Указываем, что треугольник возможен
//     } else {
//         *result = false; // Указываем, что треугольник невозможен
//     }
// }

// int main(){
//     std::cout << "Введите значения для a, b, c" << std::endl;
//     int a, b, c;
//     std::cin >> a >> b >> c;
    
//     int P;
//     double S;
//     bool result;
//     CalcTriangle(a, b, c, &P, &S, &result);
    
//     if (result) {
//         std::cout << "Треугольник возможен." << std::endl;
//         std::cout << "Периметр: " << P << std::endl;
//         std::cout << "Площадь: " << S << std::endl;
//     } else {
//         std::cout << "Треугольник невозможен." << std::endl;
//     }
    
//     return 0; 
// }

// Функция для вычисления факториала
long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long long comb(int n, int m) {
    return factorial(n) / (factorial(m) * factorial(n - m));
}

// Функция для вычисления вероятностей
void calculateProbabilities(int n, int m, double& pd, double& pm) {
    double p = 0.45; // Вероятность рождения девочки
    double q = 1 - p; // Вероятность рождения мальчика
    
    if (n < 0 || m < 0 || n < m) {
        std::cout << "Некорректные входные данные." << std::endl;
        pd = pm = 0;
        return;
    }

    long long cnm = comb(n, m);
    pd = cnm * pow(p, m) * pow(q, n - m); // Вероятность рождения m девочек
    pm = cnm * pow(q, m) * pow(p, n - m); // Вероятность рождения m мальчиков
}

int main() {
    int n, m;
    std::cout << "Введите общее количество детей (n) и количество девочек/мальчиков (m): ";
    std::cin >> n >> m;
    
    double pd, pm; // Вероятности для девочек и мальчиков соответственно
    calculateProbabilities(n, m, pd, pm);
    
    std::cout << "Вероятность того, что среди " << n << " детей будет " << m << " девочек: " << pd << std::endl;
    std::cout << "Вероятность того, что среди " << n << " детей будет " << m << " мальчиков: " << pm << std::endl;
    
    return 0;
}