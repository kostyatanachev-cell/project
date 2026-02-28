#ifndef WORKERS_HPP
#define WORKERS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Workers {  // Переименовал с start на Workers
public:
    void Start();
    void createData();
    void ckeckData();
private:
    struct Employee {
        string fullName;
        string gender;
        vector<string> services;
        int experience;
        string phone;
        string email;
        string hall;
    };

    vector<Employee> employees = {
        {"Иванов Иван Иванович", "М", {"Мужская стрижка", "Бритье", "Моделирование бороды"}, 5, "+7 (123) 456-78-90", "ivanov@mail.com", "мужской"},
        {"Петров Петр Петрович", "М", {"Мужская стрижка", "Стрижка машинкой"}, 2, "+7 (123) 456-78-91", "petrov@mail.com", "мужской"},
        {"Сидоров Сидор Сидорович", "М", {"Мужская стрижка", "Бритье опасной бритвой", "Камуфляж бороды"}, 10, "+7 (123) 456-78-92", "sidorov@mail.com", "мужской"},
        {"Иванова Мария Ивановна", "Ж", {"Женская стрижка", "Окрашивание", "Мелирование", "Укладка"}, 7, "+7 (987) 654-32-10", "ivanova@mail.com", "женский"},
        {"Петрова Анна Сергеевна", "Ж", {"Женская стрижка", "Стрижка горячими ножницами", "Ламинирование"}, 4, "+7 (987) 654-32-11", "petrova@mail.com", "женский"},
        {"Соколова Елена Дмитриевна", "Ж", {"Свадебные прически", "Вечерние укладки", "Плетение кос"}, 8, "+7 (987) 654-32-12", "sokolova@mail.com", "женский"},
        {"Козлова Ольга Александровна", "Ж", {"Стрижка", "Окрашивание", "Ботокс для волос", "Кератиновое выпрямление"}, 6, "+7 (987) 654-32-13", "kozlova@mail.com", "женский"}
    };
};

#endif