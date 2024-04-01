#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>

using namespace std;

void s_calculation(int y, int z){
    float S;
    system("chcp 65001 > nul");
    if (z >= 0){
        S = pow((z + y + z),2)- 6.28*sqrt(0.33*z);
        cout << "S: " << setprecision(1) << fixed << S << endl;
    }
    else{
        cout << "Неможливо визначити, тому що корінь не може бути від'ємним!" << endl;
    }
}
void bofort(int bal){
    system("chcp 65001 > nul");
    switch (bal) {
        case 0:
            cout << "Швидкість відру: < 0.3 - Штиль" << endl;
            break;
        case 1:
            cout << "Швидкість відру: 0.3 – 1.5 - Тихий" << endl;
            break;
        case 2:
            cout << "Швидкість відру: 1.6 – 9.4 - Легкий" << endl;
            break;
        case 3:
            cout << "Швидкість відру: 9.4 – 5.4 - Слабкий" << endl;
            break;
        case 4:
            cout << "Швидкість відру: 5.5 – 7.9 - Помірний" << endl;
            break;
        case 5:
            cout << "Швидкість відру: 8.0 – 10.7 - Свіжий" << endl;
            break;
        case 6:
            cout << "Швидкість відру: 10.8 – 13.8 - Сильний" << endl;
            break;
        case 7:
            cout << "Швидкість відру: 13.9 – 17.1 - Міцний" << endl;
            break;
        case 8:
            cout << "Швидкість відру: 17.2 – 20.7 - Дуже міцний" << endl;
            break;
        case 9:
            cout << "Швидкість відру: 20.8 - 24.4 - Шторм" << endl;
            break;
        case 10:
            cout << "Швидкість відру: 24.5 – 28.4 - Сильний шторм" << endl;
            break;
        case 11:
            cout << "Швидкість відру: 28.5 – 32.6 - Шквальний шторм" << endl;
            break;
        case 12:
            cout << "Швидкість відру: >= 32.7 - Ураган(буревій)" << endl;
            break;
        default:
            cout << "Такого балу за шкалою Бофорта немає." << endl;
            break;
	}
}

void socks (int sizeUA){
    system("chcp 65001 > nul");
    switch (sizeUA) {
        case 23:
            cout << "За українською системою: 23, за європейською 37/38, за системою Великобританія, США 8" << endl;
            break;
        case 25:
            cout << "За українською системою: 25, за європейською 39/40, за системою Великобританія, США 9" << endl;
            break;
        case 27:
            cout << "За українською системою: 27, за європейською 41/42, за системою Великобританія, США 10" << endl;
            break;
        case 29:
            cout << "За українською системою: 29, за європейською 43/44, за системою Великобританія, США 11" << endl;
            break;
        case 31:
            cout << "За українською системою: 31, за європейською 45/46, за системою Великобританія, США 12" << endl;
            break;
        default:
            cout << "Такого розміру не існує." << endl;
            break;
    }
}

void bit (int N){
    system("chcp 65001 > nul");
    if (N < 0 || N > 7483650) {
        cout << "Число вийшло за заданий діапазон (0 - 7483650)" << endl;
        return 1;
    }
    int bin = 0, k = 1;
    while (N)
    {
        bin += (N%2) * k;
        k *= 10;
        N/=2;

    }
    string str = to_string(bin);
    int equalone = count(str.begin(), str.end(), '1');
    int equalzero = count(str.begin(), str.end(), '0');
    reverse(str.begin(), str.end());
    if (str.length() < 8) {
        cout << "Недостатньо бітів" << endl;
        return 1;
    }
    switch (str[7]) {
        case '1':
            cout << "Кількість двійкових нулів: " << equalzero << endl;
            break;
        case '0':
            cout << "Сума двійкових одиниць: " << equalone << endl;
            break;
    }
    return 0;
}
