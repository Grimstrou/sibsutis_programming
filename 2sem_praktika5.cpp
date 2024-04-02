#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
//vector - динамический массив, 
//обеспечивающий быстрое добавление новых элементов в конец и меняющий свой размер при необходимости.
//getline - извлечение одной строки и записывание ее в переменную
//stringstream — это такой же stream, как и, например, cin, только его содержимое берётся не из входного потока программы, а из данной ему строки.
//push_back() - добавить элемент в конец массива

bool mashini(){
    std::string model;
    std::cout << "Введите модель машины которую собираетесь внести в базу данных: ";
    std::cin >> model;
    
    std::ofstream f("spisoc_car.txt", std::ios::app);
    if(!f.is_open()) {
        std::cout << "Нет исходника";
        return false;
    }
    f << model << " "<< "\n  ";
    f.close();
    std::cout << "машина успешно добавлена";
    std::cout << std::endl;
    return true;
}

bool view_car(){
    std::string model;
    std::ifstream f("spisoc_car.txt");
    if(!f.is_open()) {
        std::cout << "Нет исходника";
        return false;
    }
    std::cout << "Список доступных машин:\n";
   while (getline(f, model)) {
        std::cout << model << std::endl;
    }
    f.close();\
    return true;
}

bool reserve_car() {
    std::string model;
    std::cout << "Введите модель машины, которую хотите забронировать: ";
    std::cin >> model;

    std::ifstream f("spisoc_car.txt");
    std::vector<std::string> cars; // Создаем вектор для хранения всех строк из файла
    bool found = false; //флаг, найдена/нет
    std::string line;
    while (getline(f, line)) {
        std::stringstream ss(line);
        std::string currentModel, status; // Объявляем переменные для хранения модели машины и статуса брони
        ss >> currentModel >> status; //классная тема, мы извлекаем 2 показателя из строки
        //именно тут это модель и статус, спасибо хабр
        if (currentModel == model && status != "*") {
            cars.push_back(currentModel + " *"); // Добавляем звездочку
            found = true;
        } else {
            cars.push_back(line);
        }
    }
    f.close();

    if (found) {
        std::ofstream f_out("spisoc_car.txt", std::ios::trunc); //открытие + отчистка
        for (const auto& car_line : cars) { // Проходимся по всем строкам вектора
            f_out << car_line << "\n"; // Записываем обновленные данные в файл
        }
        f_out.close();
        std::cout << "Машина успешно забронирована.\n";
    } else {
        std::cout << "Машина не найдена в базе данных или уже забронирована.\n";
    }
    return true;
}


bool snat() {
    std::string model;
    std::cout << "Введите модель машины, бронь на которую хотите снять: ";
    std::cin >> model;

    std::ifstream f("spisoc_car.txt");
    std::vector<std::string> cars;
    bool found = false;
    std::string line;
    while (getline(f, line)) {
        std::stringstream ss(line);
        std::string currentModel, status;
        ss >> currentModel >> status;
        if (currentModel == model && status == "*") {
            cars.push_back(currentModel + " 0"); // Удаляем звездочку, обозначая отсутствие брони
            found = true;
        } else {
            cars.push_back(line);
        }
    }
    f.close();

    if (found) {
        std::ofstream f_out("spisoc_car.txt", std::ios::trunc);
        for (const auto& car_line : cars) {
            f_out << car_line << "\n";
        }
        f_out.close();
        std::cout << "Бронь успешно снята.\n";
    } else {
        std::cout << "Машина не найдена в базе данных или на нее не было брони.\n";
    }
    return true;
}


int main(){
    while(1){
        std::cout << "чтобы внести маншину в базу данных нажмите 0" << "\n" << "чтобы забронировать машину на сутки нажмите 1" << "\n" << "чтобы просмотреть список машин нажмите 2" << "\n" << "чтобы снять бронь нажмите 3" << std::endl;
        int num;
        std::cin >> num;
        switch(num)
        {
        case 0:
            mashini();
            break;
        case 1: 
            reserve_car();
            break;
        case 2:
            view_car();
            break;
        case 3:
            snat();
            break;
        }

    }   
    return 0;
}

