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
	const Demo a; //a��ֻ��������ôa���еĳ�Ա����const��Ա�⣩��������
	a.getval();	//const��Ա,ok
	a.setval(123);	//error,��const��Ա
}

