#include <iostream>
#include "ModulesYarovets.h"
#include <fstream>

using namespace std;

int main()
{
    system("chcp 65001 & cls");
    cout << "TASK 10.1 TEST:" << endl;
    ofstream test1 ("name.txt");
    test1 << "�������������������� ������������ �������� ���������� - ����� ���������� ������, ���� ���� �������� �� ���������������, �� �������� ��� ������� �������� �����.";
    test1.close();
    task10_1("name.txt");
    ofstream test2 ("sun.txt");
    test2 << "��� �� ����������� ������� ���� ����� �������.";
    test2.close();
    task10_1("sun.txt");
    ofstream test3 ("cat.txt");
    test3 << "ʳ� �'��� �������.";
    test3.close();
    task10_1("cat.txt");

    task10_1("information.txt");

    ofstream test5 ("bird.txt");
    test5 << "������ ������ ������.";
    test5.close();
    task10_1("bird.txt");
    cout << "END OF TEST 10.1" << endl;

    cout << "TASK 10.2 TEST:" << endl;
    ofstream test6 ("ball.txt");
    test6 << "ĳ�� �������� �'����.";
    test6.close();
    task10_2("ball.txt");
    ofstream test7 ("water.txt");
    test7 << "���� ������� � �����.";
    test7.close();
    task10_2("water.txt");
    ofstream test8 ("autumn.txt");
    test8 << "����� ����� ������.";
    test8.close();
    task10_2("autumn.txt");
    ofstream test9 ("book.txt");
    test9 << "���� ���� �����.";
    test9.close();
    task10_2("book.txt");

    task10_2("all.txt");

    cout << "END OF TEST 10.2" << endl;


    cout << "TASK 10.3 TEST:" << endl;
    ofstream test11 ("dog.txt");
    test11 << "������ ��� ������.";
    test11.close();
    task10_3(7, 8, 3, "dog.txt");
    ofstream test12 ("wind.txt");
    test12 << "³��� ��� ������.";
    test12.close();
    task10_3(6, 15, 113, "wind.txt");
    ofstream test13 ("flowers.txt");
    test13 << "���� ������� ������.";
    test13.close();
    task10_3(2, 4, 87, "flowers.txt");
    ofstream test14 ("radical.txt");
    test14.close();
    task10_3(5, 5, 0, "radical.txt");

    task10_3(0, 0, 43, "see.txt");

    cout << "END OF TEST 10.3" << endl;

    system("pause");
    return 0;
}
