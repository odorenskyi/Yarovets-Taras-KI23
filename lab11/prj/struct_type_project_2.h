#ifndef STRUCT_TYPE_PROJECT_2_H_INCLUDED
#define STRUCT_TYPE_PROJECT_2_H_INCLUDED

#include <iostream>

using namespace std;

struct date{
    short day;
    short month;
    short year;
};

struct Employee {
    date creationDate;
    int regNum;
    int ID;
    char gender;
    char typeOfWork;
    string fullName;
    date birthday;
    string citizenship;
    enum {basicSecondary, compSecondary, vocational,
          incompHigher, basicHigher, higher} education[4];
    string placeOfEducation[4];
    string lastJobPlace;
    string lastJob;
    struct {
        short days;
        short months;
        short years;
    } workExp;
    string placeOfLiving;
    string passportInfo;
    string additionalInfo;
    date dateOfDissial;
    string reasonForDissial;
};

#endif // STRUCT_TYPE_PROJECT_2_H_INCLUDED
