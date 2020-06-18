#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0);

	int getval()const;

private:
	const int ival; //const成员数据，非静态，即，有对象才存在，那么只能通过构造初始化
	int x;
};

#if 0
int i = 0; //声明定义初始化
int main()
{
	i = 0;//赋值操作
}
#endif

Demo::Demo(int val):
	ival(val),x(1)	//const成员数据只能通过初始化列表来初始化
{
	//ival = val;//这个是赋值操作，错误，因为ival是const只读，
	x = 1;
}

int Demo::getval()const
{
	return ival;
}

int main()
{
	Demo a(123);
	cout << "ival = " << a.getval() << endl;
}

