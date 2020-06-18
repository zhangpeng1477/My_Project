#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Demo{
public:
	explicit Demo(const int &a):
		x(a), y(a)
	{}

	operator int() const{ //无参数无返回值，尽量不要修改类对象
				//函数名就是要把类转成的类型
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

	i = a; //隐式转换operator int()
	//i = int(a);//显示转换operator int()
	
	return 0;
}


