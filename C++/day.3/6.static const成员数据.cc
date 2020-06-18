#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0);

	int getval();

private:
	static const int ival;//静态const数据成员（必须初始化）
};

//因为是静态必须单独定义（唯一的一个，跟对象无关）
const int Demo::ival = 0; //定义并初始化

Demo::Demo(int val):
	ival(val)//初始化列表：对象创建时候，构造自动调用，初始化列表赋值给数据成员赋初值，相当于
	//声明定义初始化。只要是静态的成员就不能初始化列表
{
	//ival = val;
}

int Demo::getval()
{
	return ival;
}

int main()
{
	Demo a(123);
	cout << "ival = " << a.getval() << endl;
}

