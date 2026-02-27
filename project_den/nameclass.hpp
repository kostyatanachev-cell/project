#include <iostream>
#include <map>
using namespace std;

struct master {
	string name; // имя мастера 
	string usluga; // услуга(и) которую выполняет мастер
	string pol_uslugi; // пол с которым работает мастер
	string data;  // стаж мастера
	double price; // стоимость услуги
};

void start();

class Uslugi {
private:
	string pol; // по дефолту он будет браться из txt 
	string oplata = "ООО 'название компании',\n фио ИП, "; // основа, при выводе просто добавить остальное
public:
	bool sort_pol(); // проверка пола
	void menu(); // поиск по услуге
	void print(string pol, string sort); // слртировка и вывод по запросу
	void static oplata(map<int, master> masters); // финал, выбор услуг и вывод оплаты
};