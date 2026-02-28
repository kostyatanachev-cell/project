#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class Menu {
public:
    void Menu_Start();
    void addInfo(string klient);
    void createDataFile();
    void checkData();
    void registr();
    void loginKlient();
    void findKlient(string number);
    string getCurrentTime();
private:
    string name, phone, Pol, Time, Discount, allDanKlient;
    int start = 0, end = 70, discount;
};

#endif