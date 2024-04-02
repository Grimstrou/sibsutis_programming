#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

struct SchoolInfo {
    int schoolNumber;
    int graduates;
    int universityAdmissions;
    double getAdmissionRate() const {
        if (graduates == 0) return 0.0;
        return static_cast<double>(universityAdmissions) / graduates * 100;
    }
};

struct DormRoom {
    int roomNumber;
    double area;
    std::string faculty;
    int residents;
};

int main() {
    // Заполнение данных о школах
    std::vector<SchoolInfo> schools = {
        {1, 200, 150},
        {2, 180, 100},
        {3, 220, 180},
    };

    // Создание и заполнение индексного массива
    std::vector<int> indices(schools.size());
    for (size_t i = 0; i < indices.size(); ++i) {
        indices[i] = i;
    }

    // Сортировка индексного массива на основе процента поступивших в ВУЗ
    std::sort(indices.begin(), indices.end(), [&schools](int a, int b) {
        return schools[a].getAdmissionRate() > schools[b].getAdmissionRate();
    });

    // Вывод информации о школах после сортировки
    std::cout << "Номер школы   | Выпускники | Скорость приема (%)" << std::endl;
    for (int index : indices) {
        const auto& school = schools[index];
        std::cout << school.schoolNumber << "             | "
                  << school.graduates << "        | "
                  << school.getAdmissionRate() << std::endl;
    }



    // Заполнение данных о комнатах
    std::vector<DormRoom> rooms = {
        {101, 20.5, "Инженерное дело", 2},
        {102, 18.0, "Искусство -----", 1},
        {103, 25.0, "Инженерное дело", 3},
    };

    // Определение различных факультетов
    std::set<std::string> facultySet;
    for (const auto& room : rooms) {
        facultySet.insert(room.faculty);
    }
    std::vector<std::string> faculties(facultySet.begin(), facultySet.end());

    // Сбор информации по факультетам
    std::map<std::string, std::tuple<int, int, double>> facultyInfo; // <Факультет, (Количество комнат, Общее количество студентов, Общая площадь)>
    for (const auto& room : rooms) {
        auto& info = facultyInfo[room.faculty];
        std::get<0>(info)++; // Количество комнат
        std::get<1>(info) += room.residents; // Общее количество студентов
        std::get<2>(info) += room.area; // Общая площадь
    }

    // Вывод информации
    std::cout << "Факультет           | Комнаты | Студенты | Среднее Площадь на одного студента" << std::endl;
    for (const auto& faculty : faculties) {
        auto& info = facultyInfo[faculty];
        int rooms = std::get<0>(info);
        int students = std::get<1>(info);
        double totalArea = std::get<2>(info);
        double avgAreaPerStudent = students == 0 ? 0 : totalArea / students;
        std::cout << faculty << "     | " << rooms << "       | " << students << "        | " << avgAreaPerStudent << std::endl;
    }



    return 0;
}
