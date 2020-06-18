#include <iostream>
using namespace std;

////////////////声明一个自定义类型：类/////////////////////
//声明类
class Demo{
public:
	void setval(int val); //公共的成员函数，提供给使用者用的
	int getval(void); //公共的成员函数，提供给使用者用的

private:
	//（工程上，数据一般应该是私有的，通过公共接口操作数据）
	int ival;	//私有数据，只能类内部用
};

//定义类（声明时没有把类的成员函数的函数体进行描述，可以在外面单独描述）
//这里概念上：这里没有任何实体产生，只有定义对象后才有会函数和数据出现
void Demo::setval(int val)
{
	ival = val;
}

int Demo::getval(void)
{
	return ival;
}
////////////////声明一个自定义类型：类；结束/////////////////////

Demo a; //全局变量：数据来全局数据区

void test()
{
	Demo b;		//局部变量：栈区
	static Demo c;	//静态局部变量;全局数据区
	Demo* p = new Demo; //堆区
	
	Demo arr[12];	//对象数组，一个数组，每个成员都是对象

	struct data{
		Demo obj;	//结构体的对象成员
		int i;
	};
}

int main()
{
}


