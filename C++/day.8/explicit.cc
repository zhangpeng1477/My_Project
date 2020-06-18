#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Demo{
public:
	//explicit关键字：阻止在构造对象时候发生隐式转换（仅仅针对一个参数的版本）
	explicit Demo(const int &a):
		x(a), y(a)
	{
		cout << this << ": -------normal-----------" << endl;
	}

	Demo(const Demo &obj):
		x(obj.x), y(obj.y)
	{
		cout << this << ": -------copy  -----------" << endl;
	}

	~Demo(){
		cout << this << ": -------~     -----------" << endl;
	}

	operator int() const{
		cout << "-----------------" << endl;
		return x+y;
	}

private:
	int x;
	int y;
};

int main()
{
	Demo a(1);
	Demo b = 1; //error，实际过程：int i转换成临时对象Demo(1)，再拷贝构造b
		//这里相当于有个隐式转换，且构造函数参数是一个，
		//在explicit关键字存在的情况下就不被允许这样的转换发生
	Demo b = Demo(1);//ok，临时对象Demo(1)拷贝构造b

	cout << "a: " << &a << endl;
	cout << "b: " << &b << endl;
	
	return 0;
}


