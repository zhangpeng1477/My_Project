#include <iostream>
using namespace std;

class DemoA{
public:
	DemoA(const int x = 0);
	
private:
	//声明类DemoB是类DemoA的友元
	//DemoB的所有成员函数访问DemoA的所有成员
	friend class DemoB;
	int x;
};

DemoA::DemoA(const int x)
{
	this->x = x;
}

class DemoB{
public:
	DemoB(DemoA &, const int y = 0);

	int getval(const DemoA &);
};

DemoB::DemoB(DemoA &obj, const int y)
{
	//因为DemoB是DemoA的友元，故此可以访问DemoA私有数据
	obj.x = y;
}

int DemoB::getval(const DemoA &obj)
{
	//因为DemoB是DemoA的友元，故此可以访问DemoA私有数据
	return obj.x;
}

int main()
{
	DemoA a(1);
	DemoB b(a, 2);

	cout << "ival = " << b.getval(a) << endl;
}

