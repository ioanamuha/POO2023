#include "NumberList.h"
#include <iostream>
using namespace std;
int main()
{
	NumberList numberlist;
	numberlist.Init();
	int x;
	for (int i = 0;i < 10;i++)
	{
		cin >> x;
		numberlist.Add(x);
	}
	numberlist.Sort();
	numberlist.Print();
	return 0;
}
