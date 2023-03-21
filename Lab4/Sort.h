#include <cstring>
#include <iostream>

using namespace std;


class Sort
{
private:
	int* a;
	int nr,minn,maxx;

public:
	Sort(int nr, int minn, int maxx);
	Sort(int nr, int x[]);
	Sort(int nr, ...);
	Sort(char *s, int nr);
	Sort();
	//Sort(const Sort &s);
	//Sort(Sort&& s);
	void InsertSort(bool ascendance = false);
	void BubbleSort(bool ascendance = false);
	void QuickSort(bool ascendance = false);
	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);


	~Sort();

private:
	bool areDisplaced(int a, int b, bool ascendance);
	void quickSort(int p, int q, bool ascendance);
	void partitioneaza(int p, int q, int& k, bool ascendance);
};
