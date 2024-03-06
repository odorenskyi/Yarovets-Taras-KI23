#include <iostream>
#include <cmath>
#include <iomanip>

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
