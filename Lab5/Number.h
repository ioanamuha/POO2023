#pragma once
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
class Number
{
public:
	char *v;
	int baza;

	// add data members
public:
	Number(); //default constructor
	Number(const char *numar, int b);
	Number(Number& ceva);
	//Number(Number&& other);// move constructor
	~Number();

	friend Number operator+(const Number& n1,const Number& n2);
	friend Number operator-(const Number& n1,const Number& n2);

	bool operator<(const Number& nr);
	bool operator>(const Number& nr);
	bool operator<=(const Number& nr);
	bool operator>=(const Number& nr);
	bool operator==(const Number& nr);
	bool operator!=(const Number& nr);
	Number& operator=(const Number& n);
	Number& operator=(int numar);
    Number& operator=(const char* numar);
    Number& operator+=(const Number& n);
    Number& operator-=(const Number& n);
	char operator[](int index);
	Number& operator--();
	Number& operator--(int numar);

	void SwitchBase(int nb);
	void Print();
	int GetDigitsCount(); // returns the number of digits for the current number
	int GetBase() const; // returns the current base

};
