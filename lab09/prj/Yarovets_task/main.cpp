#include <iostream>
#include "ModulesYarovets.h"

using namespace std;

int main()
{
    system("chcp 65001 > nul");
    cout << "������ ������ �� ���� ������� �������:" << endl;
    char entering;
    cin >> entering;
    switch (entering) {
        case 'u':
            int y;
            int z;
            cout << "������ �������� y:";
            cin >> y;
            cout << "������ �������� z:";
            cin >> z;
            s_calculation(y, z);
            break;
        case 'o':
            int bal;
            cout << "������ ��� ����� �� ��������:" << endl;
            cin >> bal;
            bofort(bal);
            break;
        case 'p':
            int sizeUA;
            cout << "������ ����� ��������� �� ���������� ��������:" << endl;
            cin >> sizeUA;
            socks(sizeUA);
            break;
        case 'a':
            int N;
            cout << "������ N:" << endl;
            cin >> N;
            bit(N);
            break;
        case 's':
            exit(1);
            break;
        case 'S':
            exit(1);
            break;
        default:
            cout << "\a\a" << endl;
    }
    main();
}
