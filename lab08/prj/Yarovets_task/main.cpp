#include <iostream>
#include "ModulesYarovets.h"

void eightone();
void eighttwo(int a, int b);

using namespace std;

int main()
{
    int y, z, a, b;
    system("chcp 65001 & cls");
    cout << "Введіть значення y:";
    cin >> y;
    cout << "Введіть значення z:";
    cin >> z;
    cout << "Введіть значення a:";
    cin >> a;
    cout << "Введіть значення b:";
    cin >> b;
    cout << endl;
    eightone();
    eighttwo(a,b);
    s_calculation(y, z);
    cout << "y у десятковій формі: " << y << endl;
    cout << "z у десятковій формі: " << z << endl;
    cout << "y у шістнадцятковій формі: " << hex << y << endl;
    cout << "z у шістнадцятковій формі: " << hex << z << endl;
    return 0;
}
void eightone(){
    cout << "Яровець Тарас ©" << endl;
}

void eighttwo(int a, int b){
    bool result;
    result = a + 1 < b;
    cout << result << endl;
}
