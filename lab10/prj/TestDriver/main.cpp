#include <iostream>
#include "ModulesYarovets.h"
#include <fstream>

using namespace std;

int main()
{
    system("chcp 65001 & cls");
    cout << "TASK 10.1 TEST:" << endl;
    ofstream test1 ("name.txt");
    test1 << "Центральноукраїнський національний технічний університет - вищий навчальний заклад, який готує студентів за спеціальностями, які актуальні для галузей економіки країни.";
    test1.close();
    task10_1("name.txt");
    ofstream test2 ("sun.txt");
    test2 << "Йде до університету студент який гарно вчиться.";
    test2.close();
    task10_1("sun.txt");
    ofstream test3 ("cat.txt");
    test3 << "Кіт м'яко муркоче.";
    test3.close();
    task10_1("cat.txt");

    task10_1("information.txt");

    ofstream test5 ("bird.txt");
    test5 << "Пташка летить високо.";
    test5.close();
    task10_1("bird.txt");
    cout << "END OF TEST 10.1" << endl;

    cout << "TASK 10.2 TEST:" << endl;
    ofstream test6 ("ball.txt");
    test6 << "Діти граються м'ячем.";
    test6.close();
    task10_2("ball.txt");
    ofstream test7 ("water.txt");
    test7 << "Вода прозора і чиста.";
    test7.close();
    task10_2("water.txt");
    ofstream test8 ("autumn.txt");
    test8 << "Листя опадає восени.";
    test8.close();
    task10_2("autumn.txt");
    ofstream test9 ("book.txt");
    test9 << "Мама читає книгу.";
    test9.close();
    task10_2("book.txt");

    task10_2("all.txt");

    cout << "END OF TEST 10.2" << endl;


    cout << "TASK 10.3 TEST:" << endl;
    ofstream test11 ("dog.txt");
    test11 << "Собака бігає швидко.";
    test11.close();
    task10_3(7, 8, 3, "dog.txt");
    ofstream test12 ("wind.txt");
    test12 << "Вітер дме сильно.";
    test12.close();
    task10_3(6, 15, 113, "wind.txt");
    ofstream test13 ("flowers.txt");
    test13 << "Квіти пахнуть приємно.";
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
