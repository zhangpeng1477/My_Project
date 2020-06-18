#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0);

	//friend int getval();

//private:	
public:
	static int ival;
};

int Demo::ival = 0;

Demo::Demo(int val)
{
	ival = val;
}

//如果访问类的成员是public的，则是不是友元函数都可以
//友员函数和普通函数的区别：能不能访问非public的类成员
int getval()
{
	return Demo::ival;
}

int main()
{
	cout << "ival = " << getval() << endl;

	Demo a(123);
	cout << "ival = " << getval() << endl;
}

