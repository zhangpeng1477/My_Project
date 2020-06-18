#include <iostream>
using namespace std;

class Inter{
public:
	Inter(const int val); //��ͨ����
	Inter(const Inter &);	//��������

public:
	int getval() const;	//const��Ա����
	void setval(const int val);//��ͨ��Ա����

	//��Ԫ�����+���غ���
	friend Inter operator +(const Inter &a, const Inter &b);


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

//��Ϊ��Ԫ������ĳ�Ա��+��˫Ŀ�������ʴ���Ҫ�����������
//+�Ĳ���������������������в��ᷢ���ı䣬��ô������const����
//����û�б�Ҫʵ�ο��������βΣ��ʴ����Ϊ����
//+�Ľ������ı��������ͣ���ô����ֵ����Inter����
Inter operator +(const Inter &a, const Inter &b)
{
	cout << "operator +====================\n";
#if 1
	Inter tmp(a.ival+b.ival); //��ͨ����
	cout << "tmp: " << &tmp << endl;
	return tmp; //����ֵ����ʱ���󱣴�
#else
	return Inter(a.ival+b.ival); //û�ж���������ʱ����Ч����ͬ����Ĵ���
#endif
}

int main()
{
	Inter a(1);//��ͨ����
	Inter b = 2;//������ʱ����Inter(2)�����������b
	
	Inter c(a+b);//����a+b���䷵��ֵ��������c
	//Inter c=a+b; //��ͬInter c(a+b)

	c = a+b;	//����a+b����������ֵ��ֵ��c����Inter c(a+b)���﷨�ϵ�����

	cout << "a: " << &a << "; b: " << &b << "; c: " << &c << endl; 

	cout << c.getval() << endl;
}

