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
	//通过构造传参给定指向“堆”对象：当智能指针（实质是对象，重载了指针运算符，且是模板）销毁时
	//其析构函数会自动回收指向的堆对象
	unique_ptr<Demo> p(new Demo);
	//unique_ptr<Demo> pp(p);//error，不能是拷贝构造，这样就不能共享，是独占

	p->prnmsg();
	//pp->prnmsg();

	(*p).prnmsg();
	//(*pp).prnmsg();
	

	return 0;
}


