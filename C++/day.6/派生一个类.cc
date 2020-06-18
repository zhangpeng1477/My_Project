#include <iostream>
using namespace std;

class Base{ //����һ����
public:
	Base(const int val=0);//���캯���������Լ��ĳ�Ա����
	~Base();		//����������������չ��캯���������Դ

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

//���м̳�
class subcls : public Base{ //��Base�Ļ���������һ���࣬Base:����/���ࡢsubcls��������/����
public:
	subcls(const int val, const char ch);//������Ĺ��캯������Base���캯�����к�������
					//��Ϊ���������ʹ�û���ķ�private��Ա����ȻBase�ȹ����
	~subcls(); //�����������ģ����������ࣺ��Ϊ���������ʹ�÷�private��Ա����ôֻ���������������Ų�������߼�����

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


