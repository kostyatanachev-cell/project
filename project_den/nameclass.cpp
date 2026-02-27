#include <iostream> 
#include "nameclass.hpp"
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

void start() {
	Uslugi uu;
	bool temp = true;
	string res;
	cout << "Выбор услуг по полу" << endl;
	while (temp) {
		cout << "Просмотреть услуги(да/нет):" << endl;
		cin >> res;
		if (res == "да") {
			uu.menu();
		}
		if (res == "нет") {
			temp = false;
		}
		else {
			cout << "Некоректный ввод!" << endl;
		}
	}
	cout << "Досвидания!" << endl;
}

bool Uslugi::sort_pol() {
	if (pol == "men" || pol == "муж" || pol == "women" || pol == "жен") {
		menu();
	}
	else {
		cout << "У вас не указан пол. Введите ваш пол для просмотра услуг:" << endl;
		cin >> pol;
		if (pol == "men" || pol == "муж" || pol == "women" || pol == "жен") {
			menu();
		}
		else {
			cout << "Такого пола нет!" << endl;
		}
	}
}

void Uslugi::menu() {
	cout << "Введите услугу которая вас интересует(для просмотра всех доступных услуг введите - 0):" << endl;
	string temp;
	cin >> temp;
	if (temp == "0") {
		print(pol, "all");
	}
	else {
		print(pol, temp);
	}
}

void Uslugi::oplata(map<int, master> masters) {
	bool res = true;
	double sum = 0;
	vector<string> uslug;
	for (auto x : masters) {
		cout << x.first << " - Имя: " << x.second.name << ", Название услуги: " << x.second.usluga << ", Стаж работы: " << x.second.data << ", Цена: " << x.second.price << endl;
	}

	while (res) {
		cout << "Для выбора мастера введите его ID(для перехода к оплате введите - 0):" << endl;
		int temp;
		try {
			cin >> temp;
			if (temp == 0) {
				res = false;
			}
			else {
				sum += masters[temp].price;
				string nn = masters[temp].usluga + "\t" + to_string(masters[temp].price);
				uslug.push_back(nn);
			}
		}
		catch (exception x) {
			cout << "Некоректный ввод!" << endl;
		}
	}
	cout << "\t\t\tЧек:" << endl;
	cout << oplata << endl;
	for (auto x : uslug) {
		cout << x << endl;
	}
	bool post_klient = true;
	cout << "К оплате - " << to_string(sum) << endl;
	if (post_klient == true) {
		cout << "К оплате (с учетом скидки) - " << sum * 0.10 << endl;
	}
}

void print(string pol, string sort) {
	map<int, master> masters;
	string line, chast_line;
	ifstream in("name.txt"); //просто чтобы не было ошибок, а то глаза режет красное подчеркивание
	if (in.is_open()) {
		string name, usl, polusl, staj;
		double pr;
		int id = 0;
		while (in >> name >> usl >> polusl >> staj >> pr) {
			if (polusl == pol) {
				id++;
				master mm;
				mm.name = name;
				mm.usluga = usl;
				mm.pol_uslugi = polusl;
				mm.data = staj;
				mm.price = pr;
				masters[id] = mm;
			}
		}
	}
	in.close();
	Uslugi::oplata(masters);
}

