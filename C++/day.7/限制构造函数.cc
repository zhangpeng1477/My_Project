#include <iostream>
using namespace std;

class Base{
private://���ƹ���
	Base(){
		//���캯����˽�У�����������������������ƶ�����������
		cout << "-----------Base: normal------------" << endl;
	}

	virtual ~Base(){
		cout << "-----------Base: ~ ------------" << endl;
	}

public:
	void prnmsg(){
		cout << "-----------prnmsg------------" << endl;
	}

	//����һ���Ѷ���
	static Base* GetObj(){
		//��̬��Ա����û�ж��󶼴���
		return new Base;
	}

	//�ͷŶѶ���
	static void FreeObj(Base* p){
		delete p;
	}
};

int main()
{
	//Base a;//����һ�����󣬴�����Ϊ���캯�������Ƶ�

	Base*p = Base::GetObj();
	p->prnmsg();
	Base::FreeObj(p);	
}


