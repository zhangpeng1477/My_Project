#include <iostream>
using namespace std;

#include <stdio.h>

class Inter{
public:
	Inter(const int val);
	Inter(const Inter &);

public:
	int getval() const;
	void setval(const int val);

	//1.����е��������Ԫ�ͳ�Ա������ȥʵ�֣�����ֻ��һ��
	//��Ա���Լ��ӱ�Ķ��󣬹ʴ�˫Ŀ��+����Ҫ����һ������
	//������Լ��ͼ������󶼲���ı䣬�ʴ˷���ֵֻ�б���ʱ�����ݴ棬����ֵ��������
	Inter operator +(const Inter &a);

	//��Ԫ������ĳ�Ա��˫Ŀ����+Ҫ������������
	friend Inter operator +(const Inter &a, const Inter &b);

	//��Ԫ���������÷�Χ��ȫ�ֵ�
	//��Ա������������������

private:
	int ival;
};

Inter::Inter(const int val):
	ival(val)
{
	cout << this << "----normal-----\n";
}

Inter::Inter(const Inter&obj)
{
	ival = obj.ival;
	cout << this << "----copy-----\n";
}

int Inter::getval() const
{
	return ival;
}

void Inter::setval(const int val)
{
	ival = val;
}

Inter Inter::operator +(const Inter &a)
{
	Inter tmp(this->ival+a.ival);
	cout << "-----------member-------------" << endl;
	return tmp;
}

Inter operator +(const Inter &a, const Inter &b)
{
	cout << "operator +====================\n";
#if 1
	Inter tmp(a.ival+b.ival);
	cout << "tmp: " << &tmp << endl;
	//Inter tmp;
	//tmp.setval(a.ival+b.ival);
	return tmp;
#else
	return Inter(a.ival+b.ival);
#endif
}

int main()
{
	Inter a(1);
	Inter b(2);

	//a.+(b) 
	//+(a,b)
	//��Ϊ�����С���ʴ��ȵ��ó�Ա����ô������Ԫ��Զ���ᱻ���ã�ʵ�ʾͲ���������ʽ��ʵ��
	Inter c = a+b;

	cout << "c: " << c.getval() << endl; 
}

