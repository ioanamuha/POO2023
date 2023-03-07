#include <iostream>
#include "Functions.h"

using namespace std;
int main() {
	Student a, b, c;
	a.setName("Bob");
	a.setEnglishGrade(4);
	a.setHistoryGrade(5);
	a.setMathGrade(1);
	b.setName("Ana");
	b.setEnglishGrade(9);
	b.setHistoryGrade(2);
	b.setMathGrade(7);
	std::cout << compareByName(a, b) << '\n'; 
	std::cout << compareByEnglishGrade(a, b) << '\n';
	std::cout << compareByHistoryGrade(a, b) << '\n';
	std::cout << compareByMathGrade(a, b) << '\n';
	std::cout << compareByAverageGrade(a, b) << '\n';
}