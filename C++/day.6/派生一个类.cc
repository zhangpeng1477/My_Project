#include <iostream>
using namespace std;

class Base{ //声明一个类
public:
	Base(const int val=0);//构造函数：负责自己的成员数据
	~Base();		//析构函数：负责回收构造函数分配的资源

public:
	void setival(const int val);
	int getival()const;

private:
	int ival;
};

Base::Base(const int val){
	ival = val;
	cout << "Base: normal------------\n";
}

Base::~Base(){
	cout << "Base: ~  ------------\n";
}

void Base::setival(const int val)
{
	ival = val;
}

int Base::getival()const
{
	return ival;
}

/////////////////////////////////////////////////////////////

//公有继承
class subcls : public Base{ //在Base的基础上派生一个类，Base:基类/父类、subcls：派生类/子类
public:
	subcls(const int val, const char ch);//派生类的构造函数：在Base构造函数运行后再运行
					//因为派生类可以使用基类的非private成员，显然Base先构造好
	~subcls(); //先析构派生的，再析构基类：因为派生类可以使用非private成员，那么只能是派生先析构才不会出现逻辑问题

	void setcval(const char val);
	char getcval()const;

private:
	char ch;
};

subcls::subcls(const int val, const char ch):
	Base(val)
{
	this->ch = ch;
	cout << "subcls: normal------------\n";
}

subcls::~subcls()
{
	cout << "subcls: ~   ------------\n";
}

void subcls::setcval(const char val)
{
	ch = val;
}

char subcls::getcval()const
{
	return ch;
}

int main()
{
	subcls a(123, 'a');

	cout << "ival = " << a.getival() << endl;
	cout << "ch = " << a.getcval() << endl;
}


