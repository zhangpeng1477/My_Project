#include <iostream>
using namespace std;

class Base{
public:
	Base(const int val=0);
	~Base();

public:
	void setival(const int val);

protected:
	int getival()const; //保护成员：派生类可以，外部不能用

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

class subcls : public Base{
public:
	subcls(const int val, const char ch);
	~subcls();

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
	cout << "ival = " <<  getival() << endl;

	return ch;
}

int main()
{
	subcls a(123, 'a');

	//cout << "ival = " << a.getival() << endl;//因为getival是保护成员，不能用
	cout << "ch = " << a.getcval() << endl;
	

}


