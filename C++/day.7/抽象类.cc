#include <iostream>
using namespace std;

class Base{ //�д��麯��������ǳ�����
protected:
	Base(){
	}
public:
	virtual void prnmsg() = 0; //���麯��
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


