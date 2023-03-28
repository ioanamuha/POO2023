#include "Number.h"
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    /*
	/Number n1("1011", 2);

	Number n2("734", 8);

	Number n3("FF", 16);

	n3.SwitchBase(10);
	n3.Print();
	n1.Print();*/
	/*Number n1("10110010", 2);

	Number n2("734", 8);

	Number n3("FF", 16);


	printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());

	for (int tr = 0; tr < n1.GetDigitsCount(); tr++)

	{

		printf("n1[%d]=%c\n", tr, n1[tr]);

	}

	n1.Print();

	n2.Print();

	//n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16

	n1.SwitchBase(10);

	n1.Print();


	if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");

	Number n4("211", 3);
	Number n5("20", 10);
	Number n7("25", 10);

	Number n6;

	n6 = n7-n5;
	n6.Print();

    cout<<endl;

    Number n8;
    n8=12345;
    n8.Print();

    //Number n10;
    //n10="1357884";
    //n10.Print();

    n7-=n5;
    n7.Print();
    //--n8;
    n8--;
    n8.Print();

    //Number n12;
    //n12 = (n4+n5)+n7;
    //n12.Print();
  // Number n4; // n4 will be in base 10
//
	//n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
//
//	n4 += n1;
//
///	n4.Print();
//
////
//	n4 = "13579"; // n4 mentains its base (10) and will be 13579
////
//	n4.Print();
//
////	--n4; // the first digit from n4 will be remove ==> n4 becomes 3579
////
//	n4.Print();
////
////	n4--; // the last digit from n4 will be remove ==> n4 becomes 357
////
////	n4.Print();
//
//

    if(n1<n2) cout<<1;
    else cout<<0;

    if(n1>n2) cout<<1;
    else cout<<0;

    if(n1<=n2) cout<<1;
    else cout<<0;

    if(n1>=n2) cout<<1;
    else cout<<0;

    if(n1==n2) cout<<1;
    else cout<<0;

    if(n1!=n2) cout<<1;
    else cout<<0;
	return 0;*/

	Number n1("20",8);
	n1.Print();
	n1.SwitchBase(2);
	n1.Print();
	cout<<n1.GetDigitsCount();
	cout<<endl;
	cout<<n1.GetBase();
	cout<<endl;
	int i=0;
	for(i=0;i<=n1.GetDigitsCount();i++)
    {
        cout<<n1[i]<<" ";
    }

    cout<<endl;

    Number n2("21",7);
    Number n3("20",10);
    Number n4;
    n4=n2+n3;
    n4.Print();

    n4=n3-n2;
    n4.Print();

    Number n5("40",5);
    n5+=n3;
    n5.Print();
    Number n6("40",5);
    n6-=n2;
    n6.Print();

    Number n7;
    n7=1238;
    n7.Print();

    /*Number n8;
    n8="12578";
    n8.Print();*/

    Number n9("5724",8);
    --n9;
    n9.Print();

    Number n10("5724",8);
    n10--;
    n10.Print();

    --n10;
    n10.Print();
    Number n11=n7;
    n11.Print();

    Number n12("50",8);
    Number n13("52",7);

    if(n12>n13) cout<<1;
    else cout<<0;
    cout<<endl;

    if(n12<n13) cout<<1;
    else cout<<0;
    cout<<endl;

    if(n12>=n13) cout<<1;
    else cout<<0;
    cout<<endl;

    if(n12<=n13) cout<<1;
    else cout<<0;
    cout<<endl;

    if(n12==n13) cout<<1;
    else cout<<0;
    cout<<endl;

    if(n12!=n13) cout<<1;
    else cout<<0;
    cout<<endl;

    Number n14("43",8);
    Number n15("50",10);
    Number n16("52",7);
    Number n17;
    n17=(n14+n15)+n16;
    n17.Print();

    Number n18("678",16);
    Number n19("123",10);
    Number n20;
    n20=n18-n19;
    n20.Print();
    --n20--;
    n20.Print();
}
