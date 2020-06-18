#include <iostream>
using namespace std;

class DemoA;

class DemoB{
public:
	DemoB();
	int getval(const DemoA &);
};

DemoB::DemoB()
{
}

class DemoA{
public:
	DemoA(const int val=0);

private:
	friend int DemoB::getval(const DemoA &);
	int ival;
};

DemoA::DemoA(const int val):
	ival(val)
{
	ival = val;
}

int DemoB::getval(const DemoA &obj)
{
	return obj.ival;
}


int main()
{
	DemoA a(1);
	DemoB b;

	cout << "ival = " << b.getval(a) << endl;
}

