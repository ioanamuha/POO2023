#include "Number.h"
#include<iostream>
#include<string>

using namespace std;

Number::Number()
{

}

Number::Number(const char *numar, int b)
{
	int i,l;
	v=new char[20];
	l=strlen(numar);
	for (i=0;i<l;i++)
    {
        v[i] = numar[i];
    }

	v[i]= '\0';
  baza=b;


}

void Number::SwitchBase(int nb) {


	// convertim numarul in baza 10
	int p = 1;
	int nr = 0;
	int l;
	int cifra;
	int i,j;
	l=strlen(v);
	for (i=l-1; i>=0; i--)
    {
		cifra=0;
		if(v[i]>='0' && v[i]<='9')
			cifra=v[i]-'0'; // convertim un caracter in cifra
		else
			if(v[i]>='A' && v[i]<='F')
				cifra = v[i]-'A'+10;
		nr=nr+cifra*p;
		p=p*baza;
	}
	// schimbam baza
	v=new char[100];
	i=0;

	while (nr > 0)
	{
		cifra= nr % nb;
		if (cifra>= 0 && cifra<= 9)
			v[i++] =cifra+'0';
		else
			v[i++] =cifra+'A'-10;
		nr=nr/nb;

	}
	v[i]='\0';
	char copie;
	for (j = 0; j < i / 2; j++)
	{
		copie=v[j];
		v[j]=v[i-j-1];
		v[i-j-1]=copie;
	}
	this->baza=nb;
}

void Number::Print()
{
    cout<<"Numarul:"<<" ";
	cout<<this->v<<" ";
	cout<<"Baza:"<<" ";
	cout<<this->baza<<" ";
	cout<<endl;
}

int Number::GetDigitsCount()
{

	int cont=0,i,l;
	l=strlen(v);
	for(i=0;i<l;i++)
    {
        cont++;
    }
	return cont;
}

int Number::GetBase() const
{
	return this->baza;
}

Number operator+(const Number& n1,const Number& n2)
{

	int baza1 = n1.GetBase();
	int baza2 = n2.GetBase();
	int base;
	char *nr =new char[100];
	if(baza1>baza2)
        base=baza1;
	else
		base=baza2;
	int nr1 = 0, nr2 = 0, s = 0;
    int p=1,cifra,i,j,l;
    char copie;
    l=strlen(n1.v);
		for (i=l-1; i>=0; i--)
        {
			cifra=0;
			if (n1.v[i] >= '0' && n1.v[i] <= '9')
				cifra=n1.v[i]-'0'; // convertim un caracter in cifra
			else
				if (n1.v[i]>='A' && n1.v[i]<='F')
					cifra=n1.v[i]-'A'+10;
			nr1=nr1+cifra*p;
			p=p*n1.baza;
		}
		 p=1;
		l=strlen(n2.v);
		for (i=l-1; i>=0; i--)
        {
			cifra=0;
			if (n2.v[i] >= '0' && n2.v[i] <= '9')
				cifra=n2.v[i]-'0'; // convertim un caracter in cifra
			else
				if (n2.v[i]>='A' && n2.v[i]<='F')
					cifra=n2.v[i]-'A'+10;
			nr2=nr2+cifra*p;
			p=p*n2.baza;
		}

		s=nr1+nr2;
		Number suma;
		suma.v=new char[100];
		i=0;
		while(s>0)
        {
			cifra=s%base;
			if (cifra>=0 && cifra<= 9)
				suma.v[i++]=cifra+'0';
			else
				suma.v[i++]=cifra+'A'-10;
			s=s/base;

		}
		suma.v[i]='\0';
		for (j = 0; j < i / 2; j++)
		{
			copie = suma.v[j];
			suma.v[j] = suma.v[i-j-1];
			suma.v[i-j-1]=copie;
		}
		suma.baza=base;
		return suma;
}

Number operator-(const Number& n1,const Number& n2)
{
	int baza1 = n1.GetBase();
	int baza2 = n2.GetBase();
	int base;
	char *nr =new char[100];
	if(baza1>baza2)
        base=baza1;
	else
		base=baza2;
	// convertim numerele in baza 10
	int nr1 = 0, nr2 = 0, d = 0;
    int p=1,cifra,i,j,l;
    char copie;
    l=strlen(n1.v);
		for (i=l-1; i>=0; i--)
        {
			cifra=0;
			if (n1.v[i] >= '0' && n1.v[i] <= '9')
				cifra=n1.v[i]-'0'; // convertim un caracter in cifra
			else
				if (n1.v[i]>='A' && n1.v[i]<='F')
					cifra=n1.v[i]-'A'+10;
			nr1=nr1+cifra*p;
			p=p*n1.baza;
		}
		 p=1;
		l=strlen(n2.v);
		for (i=l-1; i>=0; i--)
        {
			cifra=0;
			if (n2.v[i] >= '0' && n2.v[i] <= '9')
				cifra=n2.v[i]-'0';
			else
				if (n2.v[i]>='A' && n2.v[i]<='F')
					cifra=n2.v[i]-'A'+10;
			nr2=nr2+cifra*p;
			p=p*n2.baza;
		}

		d=nr1-nr2;
		Number diferenta;
		diferenta.v=new char[100];
		i=0;
		while (d>0)
        {
			cifra=d%base;
			if (cifra>=0 && cifra<= 9)
				diferenta.v[i++]=cifra+'0';
			else
				diferenta.v[i++]=cifra+'A'-10;
			d=d/base;

		}
		diferenta.v[i]='\0';
		for (j=0;j<i/2;j++)
		{
			copie = diferenta.v[j];
			diferenta.v[j] = diferenta.v[i-j-1];
			diferenta.v[i-j-1]=copie;
		}
		diferenta.baza=base;
		return diferenta;
}


Number& Number::operator+=(const Number& n)
{

	int baza1 = baza;
	int baza2 = n.baza;
	int base;
	char *nr =new char[100];
	if(baza1>baza2)
        base=baza1;
	else
		base=baza2;
	// convertim numerele in baza 10
	int nr1 = 0, nr2 = 0, s = 0;
    int p=1,cifra,i,j,l;
    char copie;
    l=strlen(v);
		for (i=l-1; i>=0; i--)
        {
			cifra=0;
			if (v[i] >= '0' && v[i] <= '9')
				cifra=v[i]-'0'; // convertim un caracter in cifra
			else
				if (v[i]>='A' && v[i]<='F')
					cifra=v[i]-'A'+10;
			nr1=nr1+cifra*p;
			p=p*baza;
		}
		 p=1;
		l=strlen(n.v);
		for (i=l-1; i>=0; i--)
        {
			cifra=0;
			if (n.v[i] >= '0' && n.v[i] <= '9')
				cifra=n.v[i]-'0'; // convertim un caracter in cifra
			else
				if (n.v[i]>='A' && n.v[i]<='F')
					cifra=n.v[i]-'A'+10;
			nr2=nr2+cifra*p;
			p=p*n.baza;
		}

		s=nr1+nr2;
		delete []v;
		this->v=new char[100];
		i=0;
		while(s>0)
        {
			cifra=s%base;
			if (cifra>=0 && cifra<= 9)
				this->v[i++]=cifra+'0';
			else
				this->v[i++]=cifra+'A'-10;
			s=s/base;

		}
		this->v[i]='\0';
		for (j = 0; j < i / 2; j++)
		{
			copie = this->v[j];
			this->v[j] = this->v[i-j-1];
			this->v[i-j-1]=copie;
		}
		this->baza=base;
		return (*this);
}

Number& Number::operator-=(const Number& n)
{

	int baza1 = baza;
	int baza2 = n.baza;
	int base;
	char *nr =new char[100];
	if(baza1>baza2)
        base=baza1;
	else
		base=baza2;
	// convertim numerele in baza 10
	int nr1 = 0, nr2 = 0, d = 0;
    int p=1,cifra,i,j,l;
    char copie;
    l=strlen(v);
		for (i=l-1; i>=0; i--)
        {
			cifra=0;
			if (v[i] >= '0' && v[i] <= '9')
				cifra=v[i]-'0'; // convertim un caracter in cifra
			else
				if (v[i]>='A' && v[i]<='F')
					cifra=v[i]-'A'+10;
			nr1=nr1+cifra*p;
			p=p*baza;
		}
		 p=1;
		l=strlen(n.v);
		for (i=l-1; i>=0; i--)
        {
			cifra=0;
			if (n.v[i] >= '0' && n.v[i] <= '9')
				cifra=n.v[i]-'0'; // convertim un caracter in cifra
			else
				if (n.v[i]>='A' && n.v[i]<='F')
					cifra=n.v[i]-'A'+10;
			nr2=nr2+cifra*p;
			p=p*n.baza;
		}

		d=nr1-nr2;
		delete []v;
		this->v=new char[100];
		i=0;
		while(d>0)
        {
			cifra=d%base;
			if (cifra>=0 && cifra<= 9)
				this->v[i++]=cifra+'0';
			else
				this->v[i++]=cifra+'A'-10;
			d=d/base;

		}
		this->v[i]='\0';
		for (j = 0; j < i / 2; j++)
		{
			copie = this->v[j];
			this->v[j] = this->v[i-j-1];
			this->v[i-j-1]=copie;
		}
		this->baza=base;
		return (*this);
}
/*Number& Number::operator=(Number&& n) { //move assigment


	if (this != &n) {
		int length = strlen(n.value);
		delete[] value;
		this->value = new char[length + 1];
		this->value[length] = '\0';
		for (int i = 0; i < length; i++) {
			this->value[i] = n.value[i];
		}
		this->base = n.base;

	}
	return *this;

}*/

Number& Number::operator=(const Number& n)
{
    int i;
    int l=strlen(n.v);
    delete[] v;
    this->v=new char[l+1];
    this->v[l]='\0';
    for(i=0;i<l;i++)
    {
        this->v[i]=n.v[i];
    }
    this->baza=n.baza;

    return (*this);
}

Number& Number::operator=(int numar)
{
    int i=0,cifra;
    char copie;
    delete[] v;
    this->v=new char[100];
    this->baza=10;
   while (numar>0)
    {
        cifra=numar%baza;
        if (cifra>=0 && cifra<=9)
            v[i++]=cifra+'0';
        else
            v[i++]=cifra+'A'-10;
        numar=numar/baza;
    }
    v[i]='\0';
    int j;
    for(j=0;j<i/2;j++)
    {
        copie=v[j];
        v[j]=v[i-j-1];
        v[i-j-1]=copie;
    }

    return (*this);
}

Number& Number::operator=(const char* numar)
{
    int i=0;
    delete[] v;
    this->v=new char[100];
    int l=strlen(numar);
    for(i=0;i<l;i++)
    {
        v[i]=numar[i];
    }
    this->v[i]='\0';
    char maxx;
    maxx=0;
    for(i=0;i<l;i++)
    {
        if(numar[i]>maxx) maxx=numar[i];
    }
    if(maxx=='1') this->baza=2;
    if(maxx=='2') this->baza=3;
    if(maxx=='3') this->baza=4;
    if(maxx=='4') this->baza=5;
    if(maxx=='5') this->baza=6;
    if(maxx=='6') this->baza=7;
    if(maxx=='7') this->baza=8;
    if(maxx=='8') this->baza=9;
    if(maxx=='9') this->baza=10;
    if(maxx=='A') this->baza=11;
    if(maxx=='B') this->baza=12;
    if(maxx=='C') this->baza=13;
    if(maxx=='D') this->baza=14;
    if(maxx=='E') this->baza=15;
    if(maxx=='F') this->baza=16;

    return(*this);
}
bool Number::operator<(const Number& nr)
{
    int nr1=0,nr2=0,l1,l2,p=1,i,cifra;
    l1=strlen(v);
    l2=strlen(nr.v);

	for(i=l1-1;i>=0;i--)
    {
		cifra=0;
		if (v[i]>='0' && v[i]<='9')
			cifra=v[i]-'0';
		else
			if (v[i]>='A' && v[i]<='F')
				cifra=v[i]-'A'+10;
		nr1 =nr1+cifra*p;
		p=p*baza;
	}
	p=1;
	for (i=l2 - 1; i>=0; i--)
	{
		cifra=0;
		if (nr.v[i]>='0' && nr.v[i]<='9')
			cifra=nr.v[i] - '0'; // convertim un caracter in cifra
		else
			if (nr.v[i] >= 'A' && nr.v[i] <= 'F')
				cifra=nr.v[i] - 'A' + 10;
		nr2= nr2+cifra*p;
		p=p*nr.baza;
	}
	if (nr1<nr2) return true;
	  return false;

}
bool Number::operator>(const Number& nr)
{

	int nr1=0,nr2=0,l1,l2,p=1,i,cifra;
    l1=strlen(v);
    l2=strlen(nr.v);

	for(i=l1-1;i>=0;i--)
    {
		cifra=0;
		if (v[i]>='0' && v[i]<='9')
			cifra=v[i]-'0'; // convertim un caracter in cifra
		else
			if (v[i]>='A' && v[i]<='F')
				cifra=v[i]-'A'+10;
		nr1 =nr1+cifra*p;
		p=p*baza;
	}
	p=1;
	for (i=l2 - 1; i>=0; i--)
	{
		cifra=0;
		if (nr.v[i]>='0' && nr.v[i]<='9')
			cifra=nr.v[i] - '0'; // convertim un caracter in cifra
		else
			if (nr.v[i] >= 'A' && nr.v[i] <= 'F')
				cifra=nr.v[i] - 'A' + 10;
		nr2= nr2+cifra*p;
		p=p*nr.baza;
	}
	if (nr1>nr2) return true;
	  return false;

}

bool Number::operator<=(const Number& nr)
{

	int nr1=0,nr2=0,l1,l2,p=1,i,cifra;
    l1=strlen(v);
    l2=strlen(nr.v);

	for(i=l1-1;i>=0;i--)
    {
		cifra=0;
		if (v[i]>='0' && v[i]<='9')
			cifra=v[i]-'0'; // convertim un caracter in cifra
		else
			if (v[i]>='A' && v[i]<='F')
				cifra=v[i]-'A'+10;
		nr1 =nr1+cifra*p;
		p=p*baza;
	}
	p=1;
	for (i=l2 - 1; i>=0; i--)
	{
		cifra=0;
		if (nr.v[i]>='0' && nr.v[i]<='9')
			cifra=nr.v[i] - '0'; // convertim un caracter in cifra
		else
			if (nr.v[i] >= 'A' && nr.v[i] <= 'F')
				cifra=nr.v[i] - 'A' + 10;
		nr2= nr2+cifra*p;
		p=p*nr.baza;
	}
	if (nr1<=nr2) return true;
	  return false;

}
bool Number::operator>=(const Number& nr)
{

	int nr1=0,nr2=0,l1,l2,p=1,i,cifra;
    l1=strlen(v);
    l2=strlen(nr.v);

	for(i=l1-1;i>=0;i--)
    {
		cifra=0;
		if (v[i]>='0' && v[i]<='9')
			cifra=v[i]-'0'; // convertim un caracter in cifra
		else
			if (v[i]>='A' && v[i]<='F')
				cifra=v[i]-'A'+10;
		nr1 =nr1+cifra*p;
		p=p*baza;
	}
	p=1;
	for (i=l2 - 1; i>=0; i--)
	{
		cifra=0;
		if (nr.v[i]>='0' && nr.v[i]<='9')
			cifra=nr.v[i] - '0'; // convertim un caracter in cifra
		else
			if (nr.v[i] >= 'A' && nr.v[i] <= 'F')
				cifra=nr.v[i] - 'A' + 10;
		nr2= nr2+cifra*p;
		p=p*nr.baza;
	}
	if (nr1>=nr2) return true;
	  return false;

}
bool Number::operator==(const Number& nr)
{

	int nr1=0,nr2=0,l1,l2,p=1,i,cifra;
    l1=strlen(v);
    l2=strlen(nr.v);

	for(i=l1-1;i>=0;i--)
    {
		cifra=0;
		if (v[i]>='0' && v[i]<='9')
			cifra=v[i]-'0'; // convertim un caracter in cifra
		else
			if (v[i]>='A' && v[i]<='F')
				cifra=v[i]-'A'+10;
		nr1 =nr1+cifra*p;
		p=p*baza;
	}
	p=1;
	for (i=l2 - 1; i>=0; i--)
	{
		cifra=0;
		if (nr.v[i]>='0' && nr.v[i]<='9')
			cifra=nr.v[i] - '0'; // convertim un caracter in cifra
		else
			if (nr.v[i] >= 'A' && nr.v[i] <= 'F')
				cifra=nr.v[i] - 'A' + 10;
		nr2= nr2+cifra*p;
		p=p*nr.baza;
	}
	if (nr1==nr2) return true;
	  return false;

}
bool Number::operator!=(const Number& nr)
{

	int nr1=0,nr2=0,l1,l2,p=1,i,cifra;
    l1=strlen(v);
    l2=strlen(nr.v);

	for(i=l1-1;i>=0;i--)
    {
		cifra=0;
		if (v[i]>='0' && v[i]<='9')
			cifra=v[i]-'0'; // convertim un caracter in cifra
		else
			if (v[i]>='A' && v[i]<='F')
				cifra=v[i]-'A'+10;
		nr1 =nr1+cifra*p;
		p=p*baza;
	}
	p=1;
	for (i=l2 - 1; i>=0; i--)
	{
		cifra=0;
		if (nr.v[i]>='0' && nr.v[i]<='9')
			cifra=nr.v[i] - '0'; // convertim un caracter in cifra
		else
			if (nr.v[i] >= 'A' && nr.v[i] <= 'F')
				cifra=nr.v[i] - 'A' + 10;
		nr2= nr2+cifra*p;
		p=p*nr.baza;
	}
	if (nr1!=nr2) return true;
	  return false;
}

char Number::operator[](int index)
{
    int l=strlen(this->v);
	if(index>=0 && index<=l)
		return v[index];
}

Number& Number::operator--()
{
	int k = 0,i;
	int l=strlen(v);
	for(i = 1; i<=l-1; i++)
		v[k++]=v[i];
    v[l-1]='\0';
    return (*this);

}
Number& Number::operator--(int nr)
{
    int l=strlen(v);
	v[l-1]='\0';
	return (*this);
}

// copy consturcor
Number::Number(Number& ceva)
{

	v = ceva.v;
	baza = ceva.baza;
}

//move consturctor
/*Number::Number(Number&& ceva)
{
	v=ceva.v;
	baza=ceva.baza;
	ceva.v=nullptr;
	ceva.baza = 0;
}*/

Number::~Number()
{
	delete[] v;

}
