#ifndef NAMECLASS_HPP
#define NAMECLASS_HPP

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct master {
    string name;
    string usluga;
    string pol_uslugi;
    string data;
    double price;
};

void startUslugi();  // Переименовано

class Uslugi {
private:
    string pol;
    bool isPermanent = false;
public:
    void setPol(string p) { pol = p; }
    void setPermanent(bool perm) { isPermanent = perm; }
    bool sort_pol();
    void menu();
    void print(string pol, string sort);
    void oplata(map<int, master> masters);
};

#endif