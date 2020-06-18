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

	//1.查表：有的运算符友元和成员都可以去实现，但是只能一种
	//成员是自己加别的对象，故此双目的+仅需要传递一个参数
	//运算后，自己和加数对象都不会改变，故此返回值只有被临时对象暂存，返回值不能引用
	Inter operator +(const Inter &a);

	//友元不是类的成员，双目操作+要传递两个参数
	friend Inter operator +(const Inter &a, const Inter &b);

	//友元函数的作用范围是全局的
	//成员函数的作用域是类域

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

Inter Inter::operator +(const Inter &a)
{
	Inter tmp(this->ival+a.ival);
	cout << "-----------member-------------" << endl;
	return tmp;
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

int main()
{
	Inter a(1);
	Inter b(2);

	//a.+(b) 
	//+(a,b)
	//因为类域更小，故此先调用成员，那么这里友元永远不会被调用，实际就不能两种形式都实现
	Inter c = a+b;

	cout << "c: " << c.getval() << endl; 
}

