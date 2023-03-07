#pragma once
class Student
{
	char name[50];
	double englishGrade;
	double historyGrade;
	double mathGrade;

public:
	bool setName(const char* name);
	char* getName();
	bool setMathGrade(double grade);
	double getMathGrade();
	bool setEnglishGrade(double grade);
	double getEnglishGrade();
	bool setHistoryGrade(double grade);
	double getHistoryGrade();
	double getAverageGrade();
};

