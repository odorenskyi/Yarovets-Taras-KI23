#include "Yarovets_h.h"

using namespace std;

void saveDataBase(vector<Employee> &database, string filename) {
    ofstream bout (filename, ios::out | ios::binary);
    if (bout.is_open()) {
        for (int i = 0, lenOfType; i < database.size(); i++) {
            bout.write((char*)&database[i], sizeof(date));

            bout.write((char*)&database[i].regNum, sizeof(int));
            bout.write((char*)&database[i].ID, sizeof(int));

            bout.write(&database[i].gender, sizeof(char));
            bout.write(&database[i].typeOfWork, sizeof(char));

            lenOfType = int(database[i].fullName.size());
            bout.write((char*)&lenOfType, sizeof(int));
            bout.write(&database[i].fullName[0], lenOfType);

            bout.write((char*)&database[i].birthday, sizeof(date));

            lenOfType = int(database[i].citizenship.size());
            bout.write((char*)&lenOfType, sizeof(int));
            bout.write(&database[i].citizenship[0], lenOfType);

            char numOfEd = 0;
            for (; numOfEd < 4 && database[i].placeOfEducation[numOfEd] != ""; numOfEd++);
            bout.write((char*)&numOfEd, sizeof(char));

            for (int j = 0; j < numOfEd; j++) {
                bout.write((char*)&database[i].education[j], sizeof(int));

                lenOfType = int(database[i].placeOfEducation[j].size());
                bout.write((char*)&lenOfType, sizeof(int));
                bout.write(&database[i].placeOfEducation[j][0], lenOfType);
            }

            lenOfType = int(database[i].lastJobPlace.size());
            bout.write((char*)&lenOfType, sizeof(int));
            bout.write(&database[i].lastJobPlace[0], lenOfType);
            lenOfType = int(database[i].lastJob.size());
            bout.write((char*)&lenOfType, sizeof(int));
            bout.write(&database[i].lastJob[0], lenOfType);

            bout.write((char*)&database[i].workExp, sizeof(short)*3);

            lenOfType = int(database[i].placeOfLiving.size());
            bout.write((char*)&lenOfType, sizeof(int));
            bout.write(&database[i].placeOfLiving[0], lenOfType);
            lenOfType = int(database[i].passportInfo.size());
            bout.write((char*)&lenOfType, sizeof(int));
            bout.write(&database[i].passportInfo[0], lenOfType);
            lenOfType = int(database[i].additionalInfo.size());
            bout.write((char*)&lenOfType, sizeof(int));
            bout.write(&database[i].additionalInfo[0], lenOfType);

            bout.write((char*)&database[i].dateOfDissial.day, sizeof(date));

            lenOfType = int(database[i].reasonForDissial.size());
            bout.write((char*)&lenOfType, sizeof(int));
            bout.write(&database[i].reasonForDissial[0], lenOfType);
        }
        bout.close();
    }
    else {
        cerr << "\n��������� ����������� ���� '" << filename << "'.";
        exit(1);
    }
}

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

void addToDataBase(vector<Employee> &database){
    database.push_back(InputPersonalCard());
}
