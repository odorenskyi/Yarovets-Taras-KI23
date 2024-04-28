#ifndef YAROVETS_H_H_INCLUDED
#define YAROVETS_H_H_INCLUDED

#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

#include "struct_type_project_2.h"

void saveDataBase(vector<Employee> &database, string filename);
void PrintTitle(string title);
void InputString(string title, string &str);
void InputNumber(string title, int &number);
void InputThreeNumber(short &numOne, short &numTwo, short &numThree, char sign, string title, string errorText);
void InputDate(string title, date &creationDate);
void InputGenderOrTypeWork(string title, char &input, char checkMark, char defaultMark);
void InputEducation(Employee &personalcard);
void InputWorkExp(Employee &personalcard);
bool YouWorked();
Employee InputPersonalCard();
void addToDataBase(vector<Employee> &database);


#endif // YAROVETS_H_H_INCLUDED
