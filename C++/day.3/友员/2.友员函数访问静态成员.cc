#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0);

	//friend int getval();

//private:	
public:
	static int ival;
};

int Demo::ival = 0;

Demo::Demo(int val)
{
	ival = val;
}

//���������ĳ�Ա��public�ģ����ǲ�����Ԫ����������
//��Ա��������ͨ�����������ܲ��ܷ��ʷ�public�����Ա
int getval()
{
	return Demo::ival;
}

int main()
{
	cout << "ival = " << getval() << endl;

	Demo a(123);
	cout << "ival = " << getval() << endl;
}

