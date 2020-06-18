#include <iostream>
#include <memory>
using namespace std;

class Demo{
public:
	Demo(){
		cout << this << "----------normal-------------\n";
	}

	Demo(const Demo &obj){
		cout << this << "----------copy-------------\n";
	}

	~Demo(){
		cout << this << "---------- ~ -------------\n";
	}

	void prnmsg()const {
		cout << "---------- prnmsg -------------\n";
	}
};


int main()
{
	//ͨ�����촫�θ���ָ�򡰶ѡ����󣺵�����ָ�루ʵ���Ƕ���������ָ�������������ģ�壩����ʱ
	//�������������Զ�����ָ��ĶѶ���
	unique_ptr<Demo> p(new Demo);
	//unique_ptr<Demo> pp(p);//error�������ǿ������죬�����Ͳ��ܹ����Ƕ�ռ

	p->prnmsg();
	//pp->prnmsg();

	(*p).prnmsg();
	//(*pp).prnmsg();
	

	return 0;
}


