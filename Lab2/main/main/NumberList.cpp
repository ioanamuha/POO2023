#include "NumberList.h"
#include <iostream>
void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	if (this->count > 9)
		return false;
	else
	{
		this->numbers[this->count] = x;
		this->count++;
		return true;
	}
}
void NumberList::Sort()
{
	int i, j;
	for (i = 0;i < this->count - 1;i++)
		for (j = i + 1;j < this->count;j++)
			if (this->numbers[i] > this->numbers[j])
				std::swap(this->numbers[i], this->numbers[j]);
}
void NumberList::Print()
{
	int i;
	for (i = 0;i < this->count;i++)
		std::cout << this->numbers[i] << " ";
}
