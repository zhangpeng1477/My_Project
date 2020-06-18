#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Demo{
public:
//构造函数：类同名，没有返回值，被系统自动调用的特殊函数。
//构造函数：负责初始化对象
	Demo(const int val=0); //因为是函数所有可以有默认参数

	void setval(const int val=0){
		ival = val;
	}

	int getval(void){
		return ival;
	}

private:
	int ival;
};

Demo::Demo(const int val)
{
	ival = val;
	cout << "----------------" << endl;
}

//定义一个对象，系统会自动调用构造函数
//Demo a(123); //显式指定构造函数的参数
Demo a; //使用构造函数的默认参数

int main()
{
	cout << "----------main---------------" << endl;
	cout << "ival = " << a.getval() << endl;
}


