#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0);

	void setval(const int val);
	int getval()const;

private:
	int ival;
};

Demo::Demo(int val)
{
	ival = val;
}

void Demo::setval(const int val)
{
//	ival = val;
}

int Demo::getval()const
{
	//ival = 0;
	return ival;
}

int main()
{
	const Demo a; //a是只读对象，那么a所有的成员（除const成员外）都不能用
	a.getval();	//const成员,ok
	a.setval(123);	//error,非const成员
}

