#include <iostream>
#include "workers.hpp"
#include "Menu.hpp"
#include "nameclass.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    // Запись информации о работниках
    Workers workers;
    workers.Start();

    // Запуск меню
    Menu menu;
    menu.Menu_Start();

    return 0;
}