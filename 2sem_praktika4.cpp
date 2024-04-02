#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

bool write(){
    std::string nazvanie;
    std::string god;
    std::cout << "Введите название книги: ";
    std::cin >> nazvanie;
    std::cout << "Введите год издания книги";
    std::cin >> god;
    
    std::ofstream f("book_library.txt", std::ios::app);
    if(!f.is_open()) {
        std::cout << "Нет исходника";
        return false;
    }
    f << nazvanie << " "<< god << "\n  ";
    f.close();
    return true;
}

bool output(){
    std::string strocka;
    std::ifstream f("book_library.txt");
    if(!f.is_open()) {
        std::cout << "Нет исходника";
        return false;
    }
    while(!f.eof()) {
        getline(f, strocka);
        std::cout << strocka << std::endl;
    }
    f.close();
}
bool search() {
    std::string book;
    std::cout << "Введите какую книгу вы хотите найти: ";
    std::cin >> book;
    std::ifstream f("book_library.txt");
    if (!f.is_open()) {
        std::cout << "Нет доступа к файлу";
        return false;
    }

    std::string b;
    bool found = false;
    while (getline(f, b)) {
        if (b.find(book) != std::string::npos) {
            std::cout << "Найдена книга: " << b << std::endl;
            found = true;
        }
    }

    f.close();
    if (!found) {
        std::cout << "Книга не найдена" << std::endl;
        return false;
    }

    return true;
}



int main (){
    while(1){
    std::cout << "Для того чтобы ввести название книги нажмите 1" << "\n" << "Для того чтобы вывести список книг введите 2" << "\n" << "для того чтобы выбрать поиск книг, нажмите 3" << std::endl;
    int num;
    std::cin>> num;
    switch (num)
    {
    case 1:
        write();
        break;
    
    case 2:
        output();
        break;
    case 3:
        search();
        break;
    }
    }
}
