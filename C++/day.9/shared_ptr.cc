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
	//当智能指针对象销毁时，指向的堆自动被回收，这样避免了堆泄漏的问题
#if 0
	Demo *ptr = new Demo; //这样使用存在风险：无语法问题，但是杜绝使用
	shared_ptr<Demo> p(ptr);
	--------------------------------
	Demo obj;	//这样使用是错误的：无语法问题，逻辑上智能指针是要自动回收堆
	shared_ptr<Demo> p(&obj);
#else
	shared_ptr<Demo> p(new Demo); //只能这么使用智能指针
#endif
	shared_ptr<Demo> pp(p);

	p->prnmsg();
	pp->prnmsg();

	(*p).prnmsg();
	(*pp).prnmsg();
	

	return 0;
}


