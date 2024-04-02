#include <iostream>
#include <vector>
#include <string>
// int main() {
//     int m, k;
//     std::cout << "Введите количество элементов m: ";
//     std::cin >> m;

//     std::cout << "Введите k (k < m): ";
//     std::cin >> k;

//     std::vector<int> A(m);
//     for(int i = 0; i < m; ++i) {
//         A[i] = i + 1;
//     }

//     // if (m % k != 0) {
//     //     std::cout << "m должно быть кратно k для создания матрицы." << std::endl;
//     //     return 1; 
//     // }

//      int rows = (m + k - 1) / k;


//     std::vector<std::vector<int>> B;

//      for (int i = 0; i < rows; ++i) {
//         std::vector<int> row(k, 0); 
//         B.push_back(row); 
//     }

//     for (int i = 0; i < m; ++i) {
//         B[i / k][i % k] = A[i]; 
//     }


//     std::cout << "Матрица B:" << std::endl;
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < k; ++j) {
//             std::cout << B[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }

int main() {
    int nrow = 9; 
    for (int i = 1; i <= nrow; i++) {
        std::vector<int> z;
        
        for (int i1 = 1; i1 <= i; i1++) {
            z.push_back(i * i1); 
        }

        for (int num : z) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}