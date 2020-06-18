#include <iostream>
using namespace std;

class Base{
public:
	Base(){
		cout << "-----------Base: normal------------" << endl;
	}

	virtual ~Base(){ //析构函数加virtual也是虚函数
		cout << "-----------Base: ~ ------------" << endl;
	}
};

class Inherit : public Base{
public:
	Inherit(){
		cout << "-----------Inherit: normal------------" << endl;
	}

	~Inherit(){//派生类加不加关键字virtual都是虚函数，因为基类的析构是虚函数
		cout << "-----------Inherit: ~    ------------" << endl;
	}
};

void func()
{
	Base *p = new Inherit;
	delete p;
	//派生类和基类的析构都会调用
	//delete会销毁对象，对象销毁就会自动调用析构函数
	//因为析构函数是虚函数，所以不是根据类型而是根据对象来决定调用派生类的还是基类的析构函数
	//这里对象是派生类对象，所以会调用派生类的析构函数（自然也会调用基类的析构函数）
}

int main()
{
	func();
}


