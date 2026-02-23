#include <iostream>

using namespace std;

class start {
public:
	void Menu();
	void addInfo(string klient);
	void creataData();
	void checkData();
	void registr();
	void loginKlient();
	void findKlient(string number);
private:
	string name, phone, Pol, Time, Discount, allDanKlient;
	int start = 0, end = 70, discount;

};
