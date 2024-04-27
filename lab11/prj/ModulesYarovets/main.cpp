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
                cout << "������� �� ����� ������, �������� ������ �� ���" << endl;
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
        InputThreeNumber(creationDate.day, creationDate.month, creationDate.year, '.' , title + "{����.�����.��}", "���� ��������� �����������");

        if((creationDate.day > 31 || creationDate.day <= 0) ||
           (creationDate.month > 12 || creationDate.month <= 0) ||
            (creationDate.year > 2072 || creationDate.year <= 0)) {
            cout << "���� ��������� �����������" << endl;
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
        InputNumber("������ ������� ����(����������� ������� ���� ��� �������� 4)", numberOfEducation);

        if(numberOfEducation > 4){
            cout << "������ ���� ����� �������� �����" << endl;
        }
    }while(numberOfEducation > 4);

    string title = R"(�����:
 1 - ������ �������
 2 - ����� �������,
 3 - ���������,
 4 - ������� ����,
 5 - ������ ����,
 6 - ����): )";
    for(int i = 0; i < numberOfEducation; i++){

        InputNumber(title, choiseAction);

        switch(choiseAction){
            case 1: personalcard.education[i] = Employee::basicSecondary; break;
            case 2: personalcard.education[i] = Employee::basicHigher; break;
            case 3: personalcard.education[i] = Employee::vocational; break;
            case 4: personalcard.education[i] = Employee::incompHigher; break;
            case 5: personalcard.education[i] = Employee::basicHigher; break;
            case 6: personalcard.education[i] = Employee::higher; break;
            default: cout << "���� ������ ������� ������" << endl; i--; continue;
        }

        InputString("� ����� ������ ��������� �����?", personalcard.placeOfEducation[i]);
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
            "������ ��� ����� ������ � ������{����,�����,��}",
            "����� ������ ���������� �����������"
        );

        if(personalcard.workExp.days < 0 ||
            personalcard.workExp.months < 0 ||
            personalcard.workExp.years < 0){
            cout << "������ ��� ����� ������ � ������{���� ����� ��}" << endl;
            continue;
        }

        iscorrect = true;

    }while(!iscorrect);
}

bool YouWorked(){
    string action = "";

    do{
        InputString("�� ���������?(Y - ��� N - �)", action);

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
    InputDate("���� ����������: ", personalcard.creationDate);


    InputNumber("��������� �����:", personalcard.regNum);

    InputNumber("�������������� �����:", personalcard.ID);

    InputGenderOrTypeWork("�����(m - ������, w - ����):", personalcard.gender, 'm', 'w');

    InputGenderOrTypeWork("��� ������(f - �������, p - �� �����������):", personalcard.typeOfWork, 'f', 'p');

    InputString("ϲ� ����������:", personalcard.fullName);

    InputDate("���� ����������: ", personalcard.birthday);

    InputString("������������:", personalcard.citizenship);

    InputEducation(personalcard);

    bool isjob = YouWorked();

    if(isjob){
        InputString("������ ���� ������:", personalcard.lastJobPlace);

        InputString("������:", personalcard.lastJob);

        InputWorkExp(personalcard);
    }

    InputString("̳��� ����������:", personalcard.placeOfLiving);

    InputString("�������� ���:", personalcard.passportInfo);

    InputString("��������� ����������:", personalcard.additionalInfo);

    if(isjob){
        InputDate("���� ���������: ", personalcard.dateOfDissial);

        InputString("������� ���������:", personalcard.reasonForDissial);
    }


    cout << setw(20) << "" << "+++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << setw(20) << "" << "+         ��� ������ ��������         +" << endl;
    cout << setw(20) << "" << "+++++++++++++++++++++++++++++++++++++++++" << endl << endl;

    return personalcard;
}
