#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include "Sort.h"
using namespace std;

int main()
{
    int numar;
    cin>>numar;
    if(numar==1)
    {
        Sort s(10,1,20);
        s.Print();
        cout<<endl;
        s.InsertSort(true);
        s.Print();
        cout<<endl;
        s.InsertSort(false);
        s.Print();
        cout<<endl;
        cout<<endl;
    }
    /*else if(numar==2)
    {
        int x[10]={7,1,2,8,9,4,6,3,10,5};
        Sort s(10,x);
        Sort s2=s;
        s2.Print();
        cout<<endl;
        s2.BubbleSort(true);
        s2.Print();
        cout<<endl;
        s2.BubbleSort(false);
        s2.Print();
        cout<<endl;
        cout<<endl;
    }*/
    else if(numar==2)
    {
        int x[10]={7,1,2,8,9,4,6,3,10,5};
        Sort s(10,x);
        s.Print();
        cout<<endl;
        s.BubbleSort(true);
        s.Print();
        cout<<endl;
        s.BubbleSort(false);
        s.Print();
        cout<<endl;
        cout<<endl;
    }
    else if(numar==3)
    {
        Sort s(8,2,1,8,6,5,4,3,7);
        s.Print();
        cout<<endl;
        s.QuickSort(true);
        s.Print();
        cout<<endl;
        s.QuickSort(false);
        s.Print();
        cout<<endl;
        cout<<endl;
    }
    else if(numar==4)
    {
        char x[]="10, 40, 100, 5, 70";
        Sort s(x,5);
        s.Print();
        cout<<endl;
        s.BubbleSort(true);
        s.Print();
        cout<<endl;
        s.BubbleSort(false);
        s.Print();
        cout<<endl;
        cout<<endl;
    }
    else if(numar==5)
    {
        Sort s;
        s.Print();
        cout<<endl;
        s.QuickSort(true);
        s.Print();
        cout<<endl;
        s.QuickSort(false);
        s.Print();
        cout<<endl;
        cout<<s.GetElementsCount();
        cout<<endl;
        cout<<s.GetElementFromIndex(4);

    }

    return 0;
}
