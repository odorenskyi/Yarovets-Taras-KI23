#include "ModulesYarovets.h"
#include "ModulesKarpets.h"
#include "ModulesChepil.h"

int main()
{
    system("chcp 1251 && cls");
    vector<Employee> database;
    loadDataBase(database, "database.dat");
    do {
        int option = 0;
        cout << setfill('+') << setw(48) << "|| ²�Ĳ� ���в� ||" << setw(32) << "" << endl;
        cout << setfill(' ') << "+ " << setw(77) << left << " �� ��������� ������������ "
                "�������� ��� ������ � ��������� ��������" << "+" << endl;
        cout << "+ " << setw(77) << left << "���������� �. �-2. ����� �������� ������ "
                "�����, ��������� �����������." << "+" << endl;
        cout << "+ " << setw(77) << "" << "+" << endl;
        cout << "+ " << setw(77) << "1. ������� ��� ���� ����� �� ����� ��� � ��������� ����." << "+" << endl;
        cout << "+ " << setw(77) << "2. ������ ����� ����� �� ���� �����." << "+" << endl;
        cout << "+ " << setw(77) << "3. ����� ������ �� ��������." << "+" << endl;
        cout << "+ " << setw(77) << "4. �������� ����� � ���� �����." << "+" << endl;
        cout << "+ " << setw(77) << "5. ��������� ������ ��������." << "+" << endl;
        cout << setfill('+') << setw(80) << "" << endl << setfill(' ');
        cout << "������ ����� ��������, ��� �� ������ ��������: " << endl << "$ ";

        if (!(cin >> option)) {
            cin.clear();
            cin.ignore();
        }

        cout << resetiosflags(ios::left);
        string surname = "";
        int id = 0;
        if (option == 1) {
            getDataBase(database);
        } else if (option == 2) {
            addToDataBase(database);
        } else if (option == 3) {
            cout << "������ ������� ����������, ��� ������ �� ������: " << endl << "$ ";
            cin >> surname;
            searchAccount(database, surname);
        } else if (option == 4) {
            cout << "������ ���������������� ����� ������, ��� �� ������ ��������: " << endl << "$ ";
            cin >> id;
            deleteFromDataBase(database, id);
        } else if (option == 5) {
            saveDataBase(database, "database.dat");
            return 0;
        } else {
            continue;
        }
    } while(true);
}

