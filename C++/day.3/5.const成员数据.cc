#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0);

	int getval()const;

private:
	const int ival; //const��Ա���ݣ��Ǿ�̬�������ж���Ŵ��ڣ���ôֻ��ͨ�������ʼ��
	int x;
};

#if 0
int i = 0; //���������ʼ��
int main()
{
	i = 0;//��ֵ����
}
#endif

Demo::Demo(int val):
	ival(val),x(1)	//const��Ա����ֻ��ͨ����ʼ���б�����ʼ��
{
	//ival = val;//����Ǹ�ֵ������������Ϊival��constֻ����
	x = 1;
}

int Demo::getval()const
{
	return ival;
}

int main()
{
	Demo a(123);
	cout << "ival = " << a.getval() << endl;
}

