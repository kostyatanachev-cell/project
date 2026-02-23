#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "Menu.hpp"

using namespace std;

void start::Menu()
{
    setlocale(LC_ALL, "RU");
    getCurrentTime();
    while (true)
    {
        string vhod;
        cout << "Парикмахерская" << endl;
        cout << "Хотите войти?" << endl;
        cout << "1 -- да" << endl;
        cout << "2 -- нет" << endl;
        getline(cin, vhod);
        cout << endl;

        if (vhod == "1" || vhod == "да" || vhod == "Да")
        {
            string KakoiKlient;
            cout << "Постоянный клиент?" << endl;
            cout << "1 -- да" << endl;
            cout << "2 -- нет" << endl;
            getline(cin, KakoiKlient);
            cout << endl;

            if (KakoiKlient == "1" || KakoiKlient == "Да" || KakoiKlient == "да")
            {
                loginKlient();

            }
            else if (KakoiKlient == "2" || KakoiKlient == "Нет" || KakoiKlient == "нет")
            {
                string klient;
                cout << "Хотите зарегистрироваться?" << endl;
                cout << "1 -- да" << endl;
                cout << "2 -- нет" << endl;
                getline(cin, klient);

                if (klient == "1" || klient == "Да" || klient == "да")
                {
                    registr();
                    //дальше код димы и сергея
                }
                else
                {
                    cout << "Ваш пол ?  М/Ж \n";
                    cin >> Pol;
                    if (Pol == "М" || Pol == "м")
                    {
                        //дальше код димы и сергея. Спросить какую стрижку нужно и тд по тз.

                    }
                    else if (Pol == "Ж" || Pol == "ж")
                    {
                        //дальше код димы и сергея. Спросить какую стрижку нужно и тд по тз.

                    }
                    else { cout << "Некорректный ввод пола" << endl; }
                }
            }
        }
        else if (vhod == "2" || vhod == "Нет" || vhod == "нет")
        {
            cout << "До свидания! :)" << endl;
            break;
        }
        else
        {
            cout << "Некорректный ввод. Пожалуйста, введите 1 или 2." << endl;
        }
    }
}
void start::findKlient(string number)
{
    string line;
    ifstream fileData("Data.txt");
    bool found = false;

    if (fileData.is_open())
    {
        while (getline(fileData, line))
        {
            if (line.find("Телефон: " + number) != string::npos)
            {
                found = true;
                cout << "Клиент найден!" << endl;
                cout << line << endl;
                break; 
            }
        }
        fileData.close();

        if (!found)
        {
            string que;
            cout << "Клиент с номером " << number << " не найден." << endl;
            cout << "Хотите зарегистрироваться? \n 1) Да \n 2) Нет" << endl;
            cin >> que;
            if (que == "1" || que == "да" || que == "Да")
            {
                registr();
                //дальше код димы и сергея. Спросить какую стрижку нужно и тд по тз.
            }
            else if (que == "2" || que == "Нет" || que == "нет")
            {
                //дальше код димы и сергея. Спросить какую стрижку нужно и тд по тз.
            }
        }
    }
    else
    {
        cout << "Ошибка открытия файла Data.txt" << endl;
    }
}

void start::loginKlient()
{
    cout << "Ваше ФИО: ";
    getline(cin, name);
    cout << "Введите номер телефона: ";
    getline(cin, phone);
    findKlient(phone);
}

void start::registr()
{
    cout << "Приступим к регистрации" << endl;
    cout << "Введите ФИО: ";
    getline(cin, name);
    cout << "Введите номер телефона: ";
    getline(cin, phone);
    cout << "Введите пол (М/Ж): ";
    getline(cin, Pol);
    discount = rand() % (end - start + 1) + start;
    Discount = to_string(discount);
    Time = getCurrentTime();
    allDanKlient = "Имя: " + name + "Телефон: " + phone + "Пол: " + Pol + "Скидка: " + Discount + "Последнее время приема: " + Time + ", ";
    checkData();
    addInfo(allDanKlient);
    cout << "Ваша скидка: " << Discount << "%" << endl;
}

void start::addInfo(string klient)
{
    ofstream fileData("Data.txt", ios::app);

    if (fileData.is_open())
    {
        fileData << klient << endl;
        fileData.close();
        cout << "Регистрация прошла успешно!" << endl;
    }
    else
    {
        cout << "Извините, произошла ошибка. Файл Data.txt не найден!" << endl;
    }
}

void start::creataData()
{
    ifstream txt;
    txt.open("Data.txt");
    txt.close();
}

void start::checkData()
{
    ifstream file("Data.txt");
    if (file.is_open())
    {
        file.close();
    }
    else
    {
        creataData();
    }
}

string getCurrentTime() {
    time_t now = time(0);  // получаем текущее время
    char* dt = ctime(&now);  // преобразуем в строку
    string timeStr(dt);
    timeStr.pop_back();  // убираем символ переноса строки в конце
    return timeStr;
}