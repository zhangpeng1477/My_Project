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

//������ָ�븳ֵ�İ�ȫ�汾����֤һ����ֵ���ǶѶ��󣬼�����ָ��ֻ��ָ���
template<typename T>
shared_ptr<T> my_make_shared(const T &obj)
{
	shared_ptr<T> p(new T(obj));
	return p;
}
int main()
{
	//��׼���ģ�庯��
	//shared_ptr<Demo> p = make_shared<Demo>(Demo());
	//ģ��ʵ��make_shared����ʾ
	shared_ptr<Demo> p = my_make_shared<Demo>(Demo());
	shared_ptr<Demo> pp(p);

	p->prnmsg();
	pp->prnmsg();

	(*p).prnmsg();
	(*pp).prnmsg();

	return 0;
}


