#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Demo{
public:
	explicit Demo(const int &a):
		x(a), y(a)
	{}

	operator int() const{ //�޲����޷���ֵ��������Ҫ�޸������
				//����������Ҫ����ת�ɵ�����
		cout << "-----------------" << endl;
		return x+y;
	}

private:
	int x;
	int y;
};

int main()
{
	Demo a(1, 2);
	int i = 0;

	i = a; //��ʽת��operator int()
	//i = int(a);//��ʾת��operator int()
	
	return 0;
}


