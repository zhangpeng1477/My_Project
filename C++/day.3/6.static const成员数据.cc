#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0);

	int getval();

private:
	static const int ival;//��̬const���ݳ�Ա�������ʼ����
};

//��Ϊ�Ǿ�̬���뵥�����壨Ψһ��һ�����������޹أ�
const int Demo::ival = 0; //���岢��ʼ��

Demo::Demo(int val):
	ival(val)//��ʼ���б����󴴽�ʱ�򣬹����Զ����ã���ʼ���б�ֵ�����ݳ�Ա����ֵ���൱��
	//���������ʼ����ֻҪ�Ǿ�̬�ĳ�Ա�Ͳ��ܳ�ʼ���б�
{
	//ival = val;
}

int Demo::getval()
{
	return ival;
}

int main()
{
	Demo a(123);
	cout << "ival = " << a.getval() << endl;
}

