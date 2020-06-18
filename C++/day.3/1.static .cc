#include <iostream>
using namespace std;

#if 0
静态成员:成员数据和成员函数
1、作用范围是类的范围
2、不属于任何类对象，有没有对象都有，是唯一的一份
#endif
class Demo{
public:
	Demo(int val = 0){
		ival = val;
	}

	void setval(int val);
	static int getval(); //声明静态成员函数

private:
	static int ival;	//声明静态成员数据
};

int Demo::ival;		//定义静态成员数据
//int Demo::ival = 0;	//定义静态成员数据，并初始化

void Demo::setval(int val)
{
	ival = val;//因为静态成员数据是类域，所以构造函数可以访问

	//类名::静态成员
	Demo::ival = val;//明确静态成员数据ival的作用范围也可以
}

int Demo::getval()
{
	return ival;
}

int main()
{

}


