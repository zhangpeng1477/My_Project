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

//给智能指针赋值的安全版本：保证一定赋值的是堆对象，即智能指针只能指向堆
template<typename T>
shared_ptr<T> my_make_shared(const T &obj)
{
	shared_ptr<T> p(new T(obj));
	return p;
}
int main()
{
	//标准库的模板函数
	//shared_ptr<Demo> p = make_shared<Demo>(Demo());
	//模拟实现make_shared的演示
	shared_ptr<Demo> p = my_make_shared<Demo>(Demo());
	shared_ptr<Demo> pp(p);

	p->prnmsg();
	pp->prnmsg();

	(*p).prnmsg();
	(*pp).prnmsg();

	return 0;
}


