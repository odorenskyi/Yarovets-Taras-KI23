#include <iostream>
#include "ModulesYarovets.h"

using namespace std;

int main()
{
    system("chcp 65001 > nul");
    cout << "Введіть символ за який відповідає функція:" << endl;
    char entering;
    cin >> entering;
    switch (entering) {
        case 'u':
            int y;
            int z;
            cout << "Введіть значення y:";
            cin >> y;
            cout << "Введіть значення z:";
            cin >> z;
            s_calculation(y, z);
            break;
        case 'o':
            int bal;
            cout << "Введіть бал хвиль за Бофортом:" << endl;
            cin >> bal;
            bofort(bal);
            break;
        case 'p':
            int sizeUA;
            cout << "Введіть розмір шкарпеток за українською системою:" << endl;
            cin >> sizeUA;
            socks(sizeUA);
            break;
        case 'a':
            int N;
            cout << "Введіть N:" << endl;
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
