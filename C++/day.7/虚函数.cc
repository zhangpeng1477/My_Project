#include <iostream>
using namespace std;

class Base{
public:
	//�麯��
	virtual void prnmsg()const{
		cout << "-------base: prnmsg------------" << endl;
	}
};

class Inherit : public Base{
public:
	void prnmsg()const{
		cout << "-------Inherit: prnmsg------------" << endl;
	}
};

void func(Base *p)
{
	//���ݶ�������������жϵ������ĸ��汾��prnmsg()
	p->prnmsg(); 
}

int main()
{
	Inherit obj;
	func(&obj);
}


