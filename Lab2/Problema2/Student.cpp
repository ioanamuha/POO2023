#include "Student.h"
#include <cstring>
#pragma warning(disable : 4996)

bool Student::setName(const char* name) {
	strcpy(this->name, name);
	return true;
}
double Student::getMathGrade() {
	return mathGrade;
}
double Student::getEnglishGrade() {
	return englishGrade;
}
bool Student::setMathGrade(double grade) {
	this->mathGrade = grade;
	return true;
}
bool Student::setHistoryGrade(double grade) {
	this->historyGrade = grade;
	return true;
}
bool Student::setEnglishGrade(double grade) {
	this->englishGrade = grade;
	return true;
}
double Student::getHistoryGrade() {
	return historyGrade;
}
double Student::getAverageGrade() {
	return (mathGrade + englishGrade + historyGrade) / 3;
}
char* Student::getName() {
	return name;
}