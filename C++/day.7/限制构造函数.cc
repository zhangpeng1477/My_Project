#include <iostream>
using namespace std;

class Base{
private://限制构造
	Base(){
		//构造函数是私有，则不能用来定义对象，则起到限制定义对象的作用
		cout << "-----------Base: normal------------" << endl;
	}

	virtual ~Base(){
		cout << "-----------Base: ~ ------------" << endl;
	}

public:
	void prnmsg(){
		cout << "-----------prnmsg------------" << endl;
	}

	//分配一个堆对象
	static Base* GetObj(){
		//静态成员，有没有对象都存在
		return new Base;
	}

	//释放堆对象
	static void FreeObj(Base* p){
		delete p;
	}
};

int main()
{
	//Base a;//定义一个对象，错误：因为构造函数是限制的

	Base*p = Base::GetObj();
	p->prnmsg();
	Base::FreeObj(p);	
}


