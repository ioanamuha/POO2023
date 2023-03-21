#include "Sort.h"

#include <cstdlib>
#include <ctime>
#include <stdarg.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

Sort::Sort(int nr,int minn,int maxx)
{
    srand(time(0));
    int i;
	a=new int[nr];
    this->nr=nr;
	for(i=0;i<nr;i++)
	{
		a[i] = minn + rand() % (maxx-minn);
	}
}

Sort::Sort(int nr, int a[])
{
    int i;
    this->nr=nr;
    this->a=new int[nr];
	for(i=0;i<nr;i++)
	{
		this->a[i]=a[i];
	}
}

Sort::Sort(int nr, ...)
{
    int i;
	va_list liste;
	this->nr = nr;
	a=new int[nr];
	va_start(liste, nr);

	for(i=0;i<nr;i++)
	{
		a[i] = va_arg(liste, int);
	}
	va_end(liste);
}

Sort::Sort(char* s, int nr)
{
	a= new int[nr];
	this->nr = nr;
	char* p;
	int value, i = 0;
	p = strtok(s, ",");
	while (p)
	{
		value = atoi(p);
		a[i++] = value;
		p = strtok(NULL, ",");
	}
}

Sort::Sort() : a(new int[8]{5,2,1,10,8,20,17,4})
{
	nr=8;
}

void Sort::InsertSort(bool ascendance)
{
	int i,j,temp;

	if(ascendance==true)
    {
        for(i=1;i<nr;i++)
        {
            j=i-1;
            temp=a[i];
            while(j>=0 && a[j]>temp)
            {
                a[j+1]=a[j];
                j=j-1;
            }
            if(a[j+1]!=temp)
            {
                a[j+1]=temp;
            }
        }
    }

	else if(ascendance==false)
    {
        for(i=1;i<nr;i++)
        {
            j=i-1;
            temp=a[i];
            while(j>=0 && a[j]<temp)
            {
                a[j+1]=a[j];
                j=j-1;
            }
            if(a[j+1]!=temp)
            {
                a[j+1]=temp;
            }
        }
    }
}



void Sort::QuickSort(bool ascendance)
{
	quickSort(0,nr-1,ascendance);
}

void Sort::quickSort(int p, int q, bool ascendance)
{
	int k;
	if(p<q)
	{
		partitioneaza(p,q,k,ascendance);
		quickSort(p,k-1,ascendance);
		quickSort(k+1,q,ascendance);
	}
}

void Sort::partitioneaza(int p, int q, int &k, bool ascendance)
{
    int x,i,j;
	x=a[p];
	i=p+1;
	j=q;
	if(ascendance==true)
    {
        while(i<=j)
        {
            if(a[i]<=x)
                i=i+1;
            if(a[j]>=x)
                j--;
            if (i<j && a[i]>x && x>a[j])
            {
                swap(a[i],a[j]);
                i=i+1;
                j=j-1;
            }
        }
    }
    else if(ascendance==false)
    {
        while(i<=j)
        {
            if(a[i]>=x)
                i=i+1;
            if(a[j]<=x)
                j--;
            if (i<j && a[i]<x && x<a[j])
            {
                swap(a[i],a[j]);
                i=i+1;
                j=j-1;
            }
        }
    }
	k=i-1;
	a[p]=a[k];
	a[k]=x;
}

void Sort::BubbleSort(bool ascendance)
{
	int i,n1,ultim;
	ultim=nr-1;
	while(ultim > 0)
	{
		n1=ultim - 1;
		ultim=0;
		for(i=0;i<=n1;i++)
        {
            if(ascendance==true)
            {
                if(a[i]>a[i+1])
                {
                    swap(a[i],a[i+1]);
                    ultim=i;
                }

            }
            else if(ascendance==false)
            {
                if(a[i]<a[i+1])
                {
                    swap(a[i],a[i+1]);
                    ultim=i;
                }
            }
        }
	}
}

/*Sort::Sort(const Sort & s)
{
    int i;
    this->nr=s.nr;
    this->a=new int[s.nr];
    for(i=0;i<s.nr;i++)
    {
        a[i]=s.a[i];
    }

}*/

/*Sort::Sort(Sort&& s)
{
    this->nr=s.nr;
    this->a=s.a;
    s.a=nullptr;
    s.nr=0;
}*/
void Sort::Print()
{
    int i;
	for (i=0;i<nr;i++)
	{
		cout <<a[i]<<' ';
	}
}

int Sort::GetElementsCount()
{
	return nr;
}

int Sort::GetElementFromIndex(int index)
{
	return a[index];
}

Sort::~Sort()
{
	delete[](a);
}
