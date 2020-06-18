#include <iostream>
using namespace std;

class DemoA{
public:
	DemoA(const int x = 0);
	
private:
	//������DemoB����DemoA����Ԫ
	//DemoB�����г�Ա��������DemoA�����г�Ա
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
	//��ΪDemoB��DemoA����Ԫ���ʴ˿��Է���DemoA˽������
	obj.x = y;
}

int DemoB::getval(const DemoA &obj)
{
	//��ΪDemoB��DemoA����Ԫ���ʴ˿��Է���DemoA˽������
	return obj.x;
}

int main()
{
	DemoA a(1);
	DemoB b(a, 2);

	cout << "ival = " << b.getval(a) << endl;
}

