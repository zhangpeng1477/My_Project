#include <iostream>
using namespace std;

#include <stdio.h>

class Inter{
public:
	Inter(const int val);
	Inter(const Inter &);

public:
	int getval() const;
	void setval(const int val);

	friend Inter operator +(const Inter &a, const Inter &b);

	//友元实现运算符~重载
	friend Inter operator ~(const Inter &);


private:
	int ival;
};

Inter::Inter(const int val):
	ival(val)
{
	cout << this << "----normal-----\n";
}

Inter::Inter(const Inter&obj)
{
	ival = obj.ival;
	cout << this << "----copy-----\n";
}

int Inter::getval() const
{
	return ival;
}

void Inter::setval(const int val)
{
	ival = val;
}

Inter operator +(const Inter &a, const Inter &b)
{
	cout << "operator +====================\n";
#if 1
	Inter tmp(a.ival+b.ival);
	cout << "tmp: " << &tmp << endl;
	//Inter tmp;
	//tmp.setval(a.ival+b.ival);
	return tmp;
#else
	return Inter(a.ival+b.ival);
#endif
}

//
Inter operator ~(const Inter &a)
{
	return Inter(~a.ival);
}

int main()
{
	Inter a(0);
	Inter b = ~a; //调用运算符友元函数Inter operator ~(const Inter &a)

	cout << "a: " << a.getval() << "; b: " << b.getval() << endl; 

	printf("%x : %x\n", a.getval(), b.getval());
}

