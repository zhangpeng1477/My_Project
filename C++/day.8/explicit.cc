#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Demo{
public:
	//explicit�ؼ��֣���ֹ�ڹ������ʱ������ʽת�����������һ�������İ汾��
	explicit Demo(const int &a):
		x(a), y(a)
	{
		cout << this << ": -------normal-----------" << endl;
	}

	Demo(const Demo &obj):
		x(obj.x), y(obj.y)
	{
		cout << this << ": -------copy  -----------" << endl;
	}

	~Demo(){
		cout << this << ": -------~     -----------" << endl;
	}

	operator int() const{
		cout << "-----------------" << endl;
		return x+y;
	}

private:
	int x;
	int y;
};

int main()
{
	Demo a(1);
	Demo b = 1; //error��ʵ�ʹ��̣�int iת������ʱ����Demo(1)���ٿ�������b
		//�����൱���и���ʽת�����ҹ��캯��������һ����
		//��explicit�ؼ��ִ��ڵ�����¾Ͳ�������������ת������
	Demo b = Demo(1);//ok����ʱ����Demo(1)��������b

	cout << "a: " << &a << endl;
	cout << "b: " << &b << endl;
	
	return 0;
}


