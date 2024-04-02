#include <iostream>
#include <cstdlib>
#include <ctime>

void nomerodin(int* b, int n) {
    srand(time(NULL));

    int m = 0; // положительные
    int k = 0; // отрицательные

    // считаем положительные и отрицательные
    for(int i = 0; i < n; i++){
        if (b[i] > 0){
            m++;
        }
        else if (b[i] < 0){
            k++;
        }
    }

    // Выделение памяти под массивы c и d
    int* c = (int*)malloc(m * sizeof(int));
    int* d = (int*)malloc(k * sizeof(int));

    if (c == NULL || d == NULL){
        std::cout << "ERROR!" << std::endl;
        if (c != NULL) free(c);
        if (d != NULL) free(d);
        return;
    }

    int poloj = 0;
    int otrec = 0;
    // Заполнение массивов c и d
    for(int i = 0; i < n; i++){
        if (b[i] > 0){
            c[poloj++] = b[i];
        }
        else if (b[i] < 0){
            d[otrec++] = b[i];
        }
    }

    // Вывод массива b
    std::cout << "Начальный массив b: ";
    for(int i = 0; i < n; i++){
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    // Вывод массива c
    std::cout << "Массив c: ";
    for(int i = 0; i < m; i++){
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    // Вывод массива d
    std::cout << "Массив d: ";
    for(int i = 0; i < k; i++){
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;

    // фришим
    free(c);
    free(d);
}

    double random(double min, double max) {
        return min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (max - min)));
    } 

    void nomertwo(double* a1, int n1) {
        srand(time(NULL)); 
        for (int i = 0; i < n1; ++i) {
            a1[i] = random(0.0, 100.0);
        }
    }
    void nomertwo2(double**& b1, double* a1, int n1) {
        for (int i = 0; i < n1; ++i) {
            b1[i] = &a1[i]; 
        }
    }
    // сортируем массив b пузырями
    void bubbleSort(double** b1, int n1) {
        for (int i = 0; i < n1 - 1; ++i) {
            for (int j = 0; j < n1 - i - 1; ++j) {
                if (*b1[j] > *b1[j + 1]) { 
                    std::swap(b1[j], b1[j + 1]); 
                }
            }
        }
    }
    // Функция для вывода массива a
    void massiv_a(const double* a1, int n1, const std::string& message) {
        std::cout << message;
        for (int i = 0; i < n1; ++i) {
            std::cout << a1[i] << " ";
        }
        std::cout << std::endl;
    }
    // Функция для вывода массива b
    void massiv_b(double** b1, int n1, const std::string& message) {
        std::cout << message;
        for (int i = 0; i < n1; ++i) {
            std::cout << *b1[i] << " ";
        }
        std::cout << std::endl;
    }
    void freea(double* a1, double** b1) {
        free(a1);
        free(b1);
    }

    void resheto(int n2) {
    if (n2 < 2) {
        std::cout << "Простое число не может быть отрицательным или меньше двух.\n";
        return;
    }

    bool* prime = new bool[n2 + 1];
    for (int i = 0; i <= n2; ++i)
        prime[i] = true;

    for (int p = 2; p * p <= n2; ++p) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n2; i += p)
                prime[i] = false;
        }
    }

    // Вывод прост.ч
    std::cout << "Простые числа в диапазоне от 2 до " << n2 << ":\n";
        for (int p = 2; p <= n2; ++p) {
        if (prime[p])
            std::cout << p << " ";
        }
        std::cout << std::endl;
        free(prime);
    }

int main(){
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    // Выделение памяти под массив b
    int* b = (int*)malloc(n * sizeof(int));
    if (b == NULL){
        std::cout << "ERROR!" << std::endl;
        return -1;
    }

    srand(time(NULL));
    for(int i = 0; i < n; i++){
        b[i] = rand() % 101 - 50;
    }

    nomerodin(b, n);
    free(b);

    int n1;
    std::cout << "Введите размер массива: ";
    std::cin >> n1;

    double* a1 = new double[n1]; 
    double** b1 = new double*[n1]; 

    nomertwo(a1, n1);
    nomertwo2(b1, a1, n1);
    bubbleSort(b1, n1);
    massiv_a(a1, n1, "Исходный массив a: ");
    massiv_b(b1, n1, "Массив b: ");
    freea(a1, b1);

    int n2;
    std::cout << "Введите число для решето Эратосфена: ";
    std::cin >> n2;
    resheto(n2);
    return 0;
}
