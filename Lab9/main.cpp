#include<iostream>
#include"Map.h"
using namespace std;


int main() {
	Map<int, const char*> m, x;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";

	for (auto [key, value, index] : m) {

		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	
	for (auto [key, value, index] : m) {

		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	m.Set(10, "Schimbare");
	printf("Am schimbat valoarea de la cheia %d\n",10);

	for (auto [key, value, index] : m) {

		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m.Clear();

	const char* value="ceva";
	if (m.Get(30, value))
		printf("Cheia exista in map\n");
	else
		printf("Cheia nu exista in map\n");

	printf("Nmarul de elemente din map: %d\n", m.Count());

	if (m.Delete(20)) {
		printf("Am sters cheia cu numarul %d\n",20);
		for (auto [key, value, index] : m) {

			printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
		}
	}
	else
		printf("Nu putem sterge cheia, deoarece aceasta nu exista\n");

	x[10] = "Lucram";
	x[20] = "Power";
	x[30] = "Aici";
	x[40] = "Interesant";
	x[50] = "Yeap";



	if (m.Includes(x))
		printf("Mapul m este inclus in mapul x\n");
	else
		printf("Mapul m nu inclus in mapul x\n");

	m.Clear();

	return 0;
}