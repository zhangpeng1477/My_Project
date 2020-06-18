#include <iostream>
using namespace std;

class Inter{
public:
	Inter(const int val); //普通构造
	Inter(const Inter &);	//拷贝构造

public:
	int getval() const;	//const成员函数
	void setval(const int val);//普通成员函数

	//友元运算符+重载函数
	friend Inter operator +(const Inter &a, const Inter &b);


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

//因为友元不是类的成员，+是双目操作，故此需要设计两个参数
//+的操作，操作数在运算过程中不会发生改变，那么参数加const限制
//参数没有必要实参拷贝构造形参，故此设计为引用
//+的结果不会改变数据类型，那么返回值还是Inter类型
Inter operator +(const Inter &a, const Inter &b)
{
	cout << "operator +====================\n";
#if 1
	Inter tmp(a.ival+b.ival); //普通构造
	cout << "tmp: " << &tmp << endl;
	return tmp; //返回值被临时对象保存
#else
	return Inter(a.ival+b.ival); //没有对象名的临时对象，效果等同上面的代码
#endif
}

int main()
{
	Inter a(1);//普通构造
	Inter b = 2;//构造临时对象Inter(2)，拷贝构造出b
	
	Inter c(a+b);//运行a+b，其返回值拷贝构造c
	//Inter c=a+b; //等同Inter c(a+b)

	c = a+b;	//运行a+b，其他返回值赋值给c，与Inter c(a+b)有语法上的区别

	cout << "a: " << &a << "; b: " << &b << "; c: " << &c << endl; 

	cout << c.getval() << endl;
}

