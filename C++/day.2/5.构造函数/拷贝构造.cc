#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Demo{
public:
	Demo(const int val);
	Demo(const Demo&); //������������

	void setval(const int val=0){
		ival = val;
	}

	int getval(void){
		return ival;
	}

private:
	int ival;
};

Demo::Demo(const int val)
{
	ival = val;
	cout << "--------1--------" << endl;
}

Demo::Demo(const Demo &obj)
{
	ival = obj.ival;
	cout << "--------2--------" << endl;
}

Demo a(1);

//�����ʵ�ֿ������죬����Ĭ�ϵ�
Demo b = a; //Demo b(a); ����һ������b��ʹ�õĲ����Ƕ���a��������a�����b,��������

int main()
{
	cout << "a : ival = " << a.getval() << endl;
	cout << "b : ival = " << b.getval() << endl;
}


