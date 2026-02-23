using namespace std;

void menu() {
    while (true) {
        setlocale(LC_ALL, "RU");
        int vhod;
        cout << "Парехмахерская" << endl;
        cout << "Хотите войти ?" << endl;
        cout << "1 -- да" << endl;
        cout << "2 -- нет" << endl;
        cin >> vhod;
        cout << endl;

        if (vhod == 1) {
            int KakoiKlient;
            cout << "Постоянный клиент ?" << endl;
            cout << "1 -- да" << endl;
            cout << "2 -- нет" << endl;
            cin >> KakoiKlient;
            cout << endl;

            if (KakoiKlient == 1) {
                cout << "красава" << endl;

            }
            if (KakoiKlient == 2) {
                int klient;
                cout << "Хотие зарегестрироватся?" << endl;
                cout << "1 -- да" << endl;
                cout << "2 -- нет" << endl;
                cin >> klient;

                if (klient == 1)
                {
                    string name, phone, Pol;
                    cout << "Приступим к ргистрации" << endl;
                    cout << "Введите ФИО" << endl;
                    cin >> name;
                    cout << "Введите номер телефона" << endl;
                    cin >> phone;
                    cout << "введите пол ( М/Ж )" << endl;
                    cin >> Pol;
                }

                if (klient == 2) {
                    cout << "Досвидания  :)" << endl;
                    cout << "Извените за беспокойство" << endl;
                    cout << "=^ᴥ^=" << endl;
                    break;
                }
            }


        }

        if (vhod == 2) {
            cout << "Досвидания  :)" << endl;
            break;
        }
        else {
            cout << "Запустите програму заного и выберите 1 или 2" << endl;
            break;
        }

    }
}
