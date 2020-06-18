#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0);

	//声明函数getval是类Demo的友元
	friend int getval(const Demo &obj);

private:
	int ival;
};

Demo::Demo(int val) : 
	ival(val)
{
	ival = val;
}

//因为友员访问的类的私有数据不是静态的，那么就必须要有类对象，才有对象的成员数据
//故此，要设计一个传递对象的参数，这里使用的引用
int getval(const Demo &obj)
{
	return obj.ival;
}

int main()
{
	Demo a(123);
	cout << "ival = " << getval(a) << endl;
}

