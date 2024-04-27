#include "../struct_type_project_2.h"

using namespace std;

void PrintTitle(string title) {
    cout << title << endl;
    cout << "$ ";
}

void InputString(string title, string &str) {
    PrintTitle(title);
    getline(cin, str);
}

void InputNumber(string title, int &number) {
    bool iscorrect = true;
    string rawNumber = "";

    do{
        iscorrect = true;

        InputString(
            title,
            rawNumber
        );

        for(int i = 0; i < rawNumber.size(); i++){
            if(rawNumber[i] < '0' || rawNumber[i] > '9'){
                cout << "Введено не вірний формат, повторіть спробу ще раз" << endl;
                iscorrect = false;
                break;
            }
        }

        if(!iscorrect){
            continue;
        }

        number = stoi(rawNumber);
        iscorrect = true;
    }while(!iscorrect);
}

void InputThreeNumber(short &numOne, short &numTwo, short &numThree, char sign, string title, string errorText) {
    bool iscorrect = true;
    string rawDate = "";
    string num = "";
    int date[3];

    do{
        iscorrect = true;

        InputString(
            title,
            rawDate
        );

        for(int i = 0, dotCount = 0; i < rawDate.size(); i++) {
            if(rawDate[i] == sign) {
                dotCount++;
            }
            else if(rawDate[i] < '0' || rawDate[i] > '9') {
                cout << errorText << endl;
                iscorrect = false;
                break;
            }
            if(dotCount != 2 && i + 1 == rawDate.size()) {
                cout << errorText << endl;
                iscorrect = false;
                break;
            }
        }

        if(!iscorrect){
            continue;
        }

        for(int i = 0, j = 0; i < rawDate.size(); i++) {
            if(rawDate[i] != sign){
                num += rawDate[i];
            }
            else{
                date[j] = stoi(num);
                num = "";
                j++;
            }
            if(i+1 == rawDate.size()) {
                date[j] = stoi(num);
            }
        }

        numOne = date[0];
        numTwo = date[1];
        numThree = date[2];

        iscorrect = true;
    } while(!iscorrect);
}

void InputDate(string title, date &creationDate){
    bool iscorrect = true;

    do{
        InputThreeNumber(creationDate.day, creationDate.month, creationDate.year, '.' , title + "{день.місяць.рік}", "Дата заповнена неправильно");

        if((creationDate.day > 31 || creationDate.day <= 0) ||
           (creationDate.month > 12 || creationDate.month <= 0) ||
            (creationDate.year > 2072 || creationDate.year <= 0)) {
            cout << "Дата заповнена неправильно" << endl;
            iscorrect = false;
            continue;
        }

        iscorrect = true;
    } while(!iscorrect);
}

void InputGenderOrTypeWork(string title, char &input, char checkMark, char defaultMark){
    string str = "";

    InputString(title, str);

    if(str[0] == checkMark - 32){
        input = str[0] + 32;
    }
    else{
        input = str[0];
    }

    if(input != checkMark){
        input = defaultMark;
    }
}

void InputEducation(Employee &personalcard){
    int numberOfEducation = 0;
    int choiseAction = 0;

    do{
        InputNumber("Введіть кількість освіт(максимальна кількість освіт для введення 4)", numberOfEducation);

        if(numberOfEducation > 4){
            cout << "Введіть будь ласка коректне число" << endl;
        }
    }while(numberOfEducation > 4);

    string title = R"(Освіта:
 1 - базова середня
 2 - повна середня,
 3 - професійна,
 4 - неповна вища,
 5 - базова вища,
 6 - вища): )";
    for(int i = 0; i < numberOfEducation; i++){

        InputNumber(title, choiseAction);

        switch(choiseAction){
            case 1: personalcard.education[i] = Employee::basicSecondary; break;
            case 2: personalcard.education[i] = Employee::basicHigher; break;
            case 3: personalcard.education[i] = Employee::vocational; break;
            case 4: personalcard.education[i] = Employee::incompHigher; break;
            case 5: personalcard.education[i] = Employee::basicHigher; break;
            case 6: personalcard.education[i] = Employee::higher; break;
            default: cout << "Немає такого варіанту відповіді" << endl; i--; continue;
        }

        InputString("В якому закладі здобували освіту?", personalcard.placeOfEducation[i]);
    }
}

void InputWorkExp(Employee &personalcard){
    bool iscorrect = false;

    do{
        InputThreeNumber(
            personalcard.workExp.days,
            personalcard.workExp.months,
            personalcard.workExp.years,
            ',',
            "Введіть ваш досвід роботи в форматі{день,місяць,рік}",
            "Досвід роботи заповнений неправильно"
        );

        if(personalcard.workExp.days < 0 ||
            personalcard.workExp.months < 0 ||
            personalcard.workExp.years < 0){
            cout << "Введіть ваш досвід роботи в форматі{день місяць рік}" << endl;
            continue;
        }

        iscorrect = true;

    }while(!iscorrect);
}

bool YouWorked(){
    string action = "";

    do{
        InputString("Ви працювали?(Y - так N - ні)", action);

        if(action[0] == 'Y' || action[0] == 'y') {
            return true;
        }
        else if(action[0] == 'N' || action[0] == 'n') {
            return false;
        }
    } while(true);
}

Employee InputPersonalCard() {
    Employee personalcard;
    cin.ignore();
    InputDate("Дата заповнення: ", personalcard.creationDate);


    InputNumber("Табельний номер:", personalcard.regNum);

    InputNumber("Індифікаційний номер:", personalcard.ID);

    InputGenderOrTypeWork("Стать(m - чоловік, w - жінка):", personalcard.gender, 'm', 'w');

    InputGenderOrTypeWork("Вид роботи(f - основна, p - за сумісництвом):", personalcard.typeOfWork, 'f', 'p');

    InputString("ПІБ працівника:", personalcard.fullName);

    InputDate("День народження: ", personalcard.birthday);

    InputString("Громадянство:", personalcard.citizenship);

    InputEducation(personalcard);

    bool isjob = YouWorked();

    if(isjob){
        InputString("Останнє місце роботи:", personalcard.lastJobPlace);

        InputString("Посада:", personalcard.lastJob);

        InputWorkExp(personalcard);
    }

    InputString("Місце проживання:", personalcard.placeOfLiving);

    InputString("Паспортні дані:", personalcard.passportInfo);

    InputString("Додаткова інформація:", personalcard.additionalInfo);

    if(isjob){
        InputDate("Дата звільнення: ", personalcard.dateOfDissial);

        InputString("Причина звільнення:", personalcard.reasonForDissial);
    }


    cout << setw(20) << "" << "+++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << setw(20) << "" << "+         Дані успішно занесено         +" << endl;
    cout << setw(20) << "" << "+++++++++++++++++++++++++++++++++++++++++" << endl << endl;

    return personalcard;
}
