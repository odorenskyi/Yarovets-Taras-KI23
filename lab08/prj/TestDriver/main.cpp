#include <iostream>
#include "ModulesYarovets.h"
using namespace std;

int main()
{
    system("chcp 65001 & cls");
    cout << "TC_01: ";
    s_calculation(7, 8);
    cout << "TC_02: ";
    s_calculation(6, 15);
    cout << "TC_03: ";
    s_calculation(2, 4);
    cout << "TC_04: ";
    s_calculation(5, 5);
    cout << "TC_05: ";
    s_calculation(0, 0);
    cout << "TC_06: ";
    s_calculation(-12, 6);
    cout << "TC_07: ";
    s_calculation(0, 12);
    cout << "TC_08: ";
    s_calculation(-5, 54);
    cout << "TC_09: ";
    s_calculation(1, 18);
    cout << "TC_10: ";
    s_calculation(7, 11);
    return 0;
}
