#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0);

	//��������getval����Demo����Ԫ
	friend int getval(const Demo &obj);

private:
	int ival;
};

Demo::Demo(int val) : 
	ival(val)
{
	ival = val;
}

//��Ϊ��Ա���ʵ����˽�����ݲ��Ǿ�̬�ģ���ô�ͱ���Ҫ������󣬲��ж���ĳ�Ա����
//�ʴˣ�Ҫ���һ�����ݶ���Ĳ���������ʹ�õ�����
int getval(const Demo &obj)
{
	return obj.ival;
}

int main()
{
	Demo a(123);
	cout << "ival = " << getval(a) << endl;
}

