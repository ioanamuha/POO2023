#include "Functions.h"
#include <cstring>

int compareByName(Student& a, Student& b) {
	int nameSizeOfFirst = strlen(a.getName());
	int nameSizeOfSecond = strlen(b.getName());
	if (nameSizeOfFirst > nameSizeOfSecond) {
		return 1;
	}
	if (nameSizeOfFirst < nameSizeOfSecond) {
		return -1;
	}
	return strcmp(a.getName(), b.getName());
}

int compareByMathGrade(Student& a, Student& b) {
	if (a.getMathGrade() > b.getMathGrade()) {
		return 1;
	}
	if (a.getMathGrade() < b.getMathGrade()) {
		return -1;
	}
	return 0;
}

int compareByEnglishGrade(Student& a, Student& b) {
	if (a.getEnglishGrade() > b.getEnglishGrade()) {
		return 1;
	}
	if (a.getEnglishGrade() < b.getEnglishGrade()) {
		return -1;
	}
	return 0;
}

int compareByHistoryGrade(Student& a, Student& b) {
	if (a.getHistoryGrade() > b.getHistoryGrade()) {
		return 1;
	}
	if (a.getHistoryGrade() < b.getHistoryGrade()) {
		return -1;
	}
	return 0;
}

int compareByAverageGrade(Student& a, Student& b) {
	if (a.getAverageGrade() > b.getAverageGrade()) {
		return 1;
	}
	if (a.getAverageGrade() < b.getAverageGrade()) {
		return -1;
	}
	return 0;
}
