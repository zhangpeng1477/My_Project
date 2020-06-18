#include <iostream>
using namespace std;

class Base{
public:
	//虚函数
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
	//根据对象而非类型来判断调用是哪个版本的prnmsg()
	p->prnmsg(); 
}

int main()
{
	Inherit obj;
	func(&obj);
}


