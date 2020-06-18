#include <iostream>
using namespace std;

class Base{ //有纯虚函数的类就是抽象类
protected:
	Base(){
	}
public:
	virtual void prnmsg() = 0; //纯虚函数
};

class Inherit : public Base{
public:
	Inherit(){}
	void prnmsg(){
		cout << "-----------aaaaaaaaaaa------------" << endl;
	}
};

int main()
{
	//Base a;
	Inherit a;
	a.prnmsg();
}


