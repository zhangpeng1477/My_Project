#include <iostream>
using namespace std;

class Base{
public:
	Base(){
		cout << "-----------Base: normal------------" << endl;
	}

	virtual ~Base(){ //����������virtualҲ���麯��
		cout << "-----------Base: ~ ------------" << endl;
	}
};

class Inherit : public Base{
public:
	Inherit(){
		cout << "-----------Inherit: normal------------" << endl;
	}

	~Inherit(){//������Ӳ��ӹؼ���virtual�����麯������Ϊ������������麯��
		cout << "-----------Inherit: ~    ------------" << endl;
	}
};

void func()
{
	Base *p = new Inherit;
	delete p;
	//������ͻ���������������
	//delete�����ٶ��󣬶������پͻ��Զ�������������
	//��Ϊ�����������麯�������Բ��Ǹ������Ͷ��Ǹ��ݶ�������������������Ļ��ǻ������������
	//���������������������Ի�����������������������ȻҲ����û��������������
}

int main()
{
	func();
}


