#include "nameclass.hpp"

void startUslugi() {
    Uslugi uu;
    bool temp = true;
    string res;
    string userPol;

    cout << "Выбор услуг по полу" << endl;
    cout << "Введите ваш пол (муж/жен): ";
    cin >> userPol;
    uu.setPol(userPol);

    while (temp) {
        cout << "Просмотреть услуги (да/нет):" << endl;
        cin >> res;
        if (res == "да") {
            uu.sort_pol();
        }
        else if (res == "нет") {
            temp = false;
        }
        else {
            cout << "Некорректный ввод!" << endl;
        }
    }
    cout << "До свидания!" << endl;
}

bool Uslugi::sort_pol() {
    if (pol == "men" || pol == "муж" || pol == "women" || pol == "жен") {
        menu();
        return true;
    }
    else {
        cout << "У вас не указан пол. Введите ваш пол для просмотра услуг:" << endl;
        cin >> pol;
        if (pol == "men" || pol == "муж" || pol == "women" || pol == "жен") {
            menu();
            return true;
        }
        else {
            cout << "Такого пола нет!" << endl;
            return false;
        }
    }
}

void Uslugi::menu() {
    cout << "Введите услугу которая вас интересует (для просмотра всех доступных услуг введите - 0):" << endl;
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
        cout << x.first << " - Имя: " << x.second.name << ", Услуга: " << x.second.usluga << ", Стаж: " << x.second.data << ", Цена: " << x.second.price << endl;
    }

    while (res) {
        cout << "Для выбора мастера введите его ID (для перехода к оплате введите - 0):" << endl;
        int temp;
        cin >> temp;
        if (temp == 0) {
            res = false;
        }
        else if (masters.find(temp) != masters.end()) {
            sum += masters[temp].price;
            string nn = masters[temp].usluga + "\t" + to_string(masters[temp].price) + " руб.";
            uslug.push_back(nn);
        }
        else {
            cout << "Мастер с ID " << temp << " не найден!" << endl;
        }
    }

    cout << "\n\t\t\tЧЕК" << endl;
    cout << "=================================" << endl;
    cout << "ООО 'Парикмахерская'" << endl;
    cout << "---------------------------------" << endl;
    for (auto x : uslug) {
        cout << x << endl;
    }
    cout << "---------------------------------" << endl;
    cout << "К оплате: " << sum << " руб." << endl;

    if (isPermanent) {
        cout << "К оплате (с учетом скидки 10%): " << sum * 0.9 << " руб." << endl;
    }
    cout << "=================================" << endl;
}

void Uslugi::print(string pol, string sort) {
    map<int, master> masters;

    ifstream in("services.txt");
    if (!in.is_open()) {
        ofstream out("services.txt");
        out << "Иванов Стрижка муж 5 500\n";
        out << "Петров Бритье муж 3 300\n";
        out << "Сидорова Стрижка жен 7 800\n";
        out << "Козлова Окрашивание жен 4 1500\n";
        out.close();
        in.open("services.txt");
    }

    if (in.is_open()) {
        string name, usl, polusl, staj;
        double pr;
        int id = 0;

        while (in >> name >> usl >> polusl >> staj >> pr) {
            if (polusl == "муж" && (pol == "муж" || pol == "men") ||
                polusl == "жен" && (pol == "жен" || pol == "women")) {
                if (sort == "all" || usl == sort) {
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

        if (!masters.empty()) {
            oplata(masters);
        }
        else {
            cout << "Нет доступных мастеров" << endl;
        }
    }
}