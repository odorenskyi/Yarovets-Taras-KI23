#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

float s_calculation(int y, int z){
    float S;
    system("chcp 65001 > nul");
    if (z >= 0){
        S = pow((z + y + z),2)- 6.28*sqrt(0.33*z);
        setprecision(1);
        fixed;
        return S;
    }
    else{
        return -1;
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

void socks(int sizeUA){
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

int bit(int N){
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

void task10_1(const char* file_name)
{
    fstream fileread (file_name);
    string buffer;
    string information = "У вхідному файлі було знайдено такі слова:";
    string allInfo;
    int countChar;
    if(!fileread.is_open())
    {
        ofstream file(file_name);
        file.close();
        fstream fileread(file_name);
    }


    if (fileread.is_open())
    {
        while(getline(fileread, buffer))
        {
                        allInfo += buffer;
        }
        countChar = allInfo.length();
        for(int i = 0; i < countChar; i++)
        {
            if(isascii(buffer[i]))
                {
                    buffer[i] = '/';
                }
        }
        int countStudent = buffer.find("/студент/");
        int countModule = buffer.find("/модуль/");
        int countDev = buffer.find("/програміст/");
        int countApp = buffer.find("/програма/");
        if (countStudent != -1) information += " студент";
        if (countModule != -1)
        {
            if (information.length() > 43)
            {
                information += ",";
            }
            information += " модуль";
        }
        if (countDev != -1)
        {
            if (information.length() > 43)
            {
                information += ",";
            }
            information += " програміст";
        }
        if (countApp != -1)
        {
            if (information.length() > 43)
            {
                information += ",";
            }
            information += " програма";
        }
        if (countStudent == -1 && countModule == -1 && countDev == -1 && countApp == -1)
        {
            information = "У файлі не було знайдено слів: студент, модуль, програміст, програма";
        }
        information += ".";

        fileread.close();

        ofstream filewrite(file_name);

        filewrite << "Кількість символів у даному тексті: " << countChar << "\n";
        filewrite << information << "\n";
        filewrite << "Модуль було розроблено студентом Центральноукраїнського національного технічого університету - Яровцем Тарасом; м. Кропивницький; Україна; 2024 рік.";
        filewrite.close();
    }
}

void task10_2(const char* file_name)
{
    system("chcp 65001 > nul");
    fstream filewrite(file_name, ios_base::app);
    filewrite << "\n" << "Згідно зі ст. 20 Конституції України державними символами є: Державний Прапор України, Державний Герб України і Державний Гімн України." <<"\n";
    time_t now = time(NULL);
    tm *localeTime = localtime(&now);
    filewrite << 1900 + localeTime->tm_year;
    filewrite.close();
}

void task10_3(int y, int z, int b, const char* file_name)
{
    float res_calc = s_calculation(y, z);
    int bin = 0, k = 1;
    while (b)
    {
        bin += (b%2) * k;
        k *= 10;
        b/=2;

    }
    string b_in_bin = to_string(bin);

    fstream filewrite(file_name, ios_base::app);
    if (res_calc == -1)
    {
        filewrite << "\n" << "Неможливо визначити, тому що корінь не може бути від'ємним!" << "\n";
    }
    else
    {
        filewrite << "\n" << "S: " << setprecision(1) << fixed << res_calc <<"\n";
    }
    filewrite << "b у двійковій: " << b_in_bin <<"\n";
    filewrite.close();
}
