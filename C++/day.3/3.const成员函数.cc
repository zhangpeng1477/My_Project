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
	ival = val;
}

int Demo::getval()const
{
	//ival = 0; //��Ϊgetval��const��Ա��������ô����﷨�Ͳ��У�Ҫ�޸Ķ���
	return ival;
}

int main()
{
}

