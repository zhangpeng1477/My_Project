#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Demo{
public:
//���캯������ͬ����û�з���ֵ����ϵͳ�Զ����õ����⺯����
//���캯���������ʼ������
	Demo(const int val=0); //��Ϊ�Ǻ������п�����Ĭ�ϲ���

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
	cout << "----------------" << endl;
}

//����һ������ϵͳ���Զ����ù��캯��
//Demo a(123); //��ʽָ�����캯���Ĳ���
Demo a; //ʹ�ù��캯����Ĭ�ϲ���

int main()
{
	cout << "----------main---------------" << endl;
	cout << "ival = " << a.getval() << endl;
}


