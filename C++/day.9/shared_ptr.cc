#include <iostream>
#include <memory>
using namespace std;

class Demo{
public:
	Demo(){
		cout << "----------normal-------------\n";
	}

	Demo(const Demo &obj){
		cout << "----------copy-------------\n";
	}

	~Demo(){
		cout << "---------- ~ -------------\n";
	}

	void prnmsg()const {
		cout << "---------- prnmsg -------------\n";
	}
};

int main()
{
	//������ָ���������ʱ��ָ��Ķ��Զ������գ����������˶�й©������
#if 0
	Demo *ptr = new Demo; //����ʹ�ô��ڷ��գ����﷨���⣬���Ƕž�ʹ��
	shared_ptr<Demo> p(ptr);
	--------------------------------
	Demo obj;	//����ʹ���Ǵ���ģ����﷨���⣬�߼�������ָ����Ҫ�Զ����ն�
	shared_ptr<Demo> p(&obj);
#else
	shared_ptr<Demo> p(new Demo); //ֻ����ôʹ������ָ��
#endif
	shared_ptr<Demo> pp(p);

	p->prnmsg();
	pp->prnmsg();

	(*p).prnmsg();
	(*pp).prnmsg();
	

	return 0;
}


