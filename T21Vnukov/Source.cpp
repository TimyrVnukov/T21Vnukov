#include <iostream>
#include "string"
#include <map>
#include <vector>
#include "list"
using namespace std;
int main() {
    setlocale(0, "UKR");
    list<string> l;
    map<string, list<string>> myMap;
    string number;
    string offenses;
    bool isEnable;
    int menu;
    do
    {
        cout << "1: ������� ��i ��������������" << endl;
        cout << "2: ������� �������������� �� �������� ������" << endl;
        cout << "3: ������ ��������������" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            for (auto& item : myMap)
            {
                cout << item.first << " ";
                for (auto iter = item.second.begin(); iter != item.second.end(); iter++)
                {
                    cout << *iter << " ";
                }
                cout << endl;
            }
            break;
        case 2:
            cout << "������ �������� ����: ";
            getline(cin, number);
            cin.ignore();
            for (auto& item : myMap)
            {
                if (number == item.first) {
                    for (auto iter = item.second.begin(); iter != item.second.end(); iter++)
                    {
                        cout << *iter << " ";
                    }
                }
            }
            break;
        case 3:
            isEnable = false;
            cout << "������ �������� ����: ";
            cin.ignore();
            getline(cin, number);
            cout << "������ ��������������: ";
            getline(cin, offenses);
            for (auto& item : myMap)
            {
                if (number == item.first) {
                    l.push_back(offenses);
                    isEnable = true;
                }
            }
            if (!isEnable) {
                l.push_back(offenses);
                myMap.insert(make_pair(number, l));
            }
            break;
        default:
            break;
        }
    } while (menu);
	return 0;
}