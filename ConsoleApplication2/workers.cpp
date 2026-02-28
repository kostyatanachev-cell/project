#include "workers.hpp"

void Workers::Start()
{
    ckeckData();

    ofstream outFile("dataWorkers.txt");

    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    outFile << "=== ИНФОРМАЦИЯ О РАБОТНИКАХ ПАРИКМАХЕРСКОЙ ===\n\n";

    for (size_t i = 0; i < employees.size(); i++) {
        outFile << "Работник #" << i + 1 << endl;
        outFile << "ФИО: " << employees[i].fullName << endl;
        outFile << "Пол: " << employees[i].gender << endl;
        outFile << "Стаж работы: " << employees[i].experience << " лет" << endl;
        outFile << "Телефон: " << employees[i].phone << endl;
        outFile << "Email: " << employees[i].email << endl;
        outFile << "Зал: " << employees[i].hall << endl;

        outFile << "Услуги:" << endl;
        for (const string& service : employees[i].services) {
            outFile << "  - " << service << endl;
        }

        outFile << "------------------------\n" << endl;
    }

    outFile.close();
    cout << "Информация успешно записана в файл: dataWorkers.txt" << endl;
}

void Workers::createData()
{
    ofstream data("dataWorkers.txt");
    data.close();
}

void Workers::ckeckData()
{
    ifstream data("dataWorkers.txt");
    if (!data.is_open())
    {
        createData();
    }
    else
    {
        data.close();
    }
}