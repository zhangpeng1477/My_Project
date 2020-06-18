#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Demo{
public:
	Demo(const int val);
	Demo(const Demo&); //参数必须引用

	void setval(const int val=0){
		ival = val;
	}

	int getval(void){
		return ival;
	}

private:
	int ival;
};

Demo::Demo(const int val)
{
	ival = val;
	cout << "--------1--------" << endl;
}

Demo::Demo(const Demo &obj)
{
	ival = obj.ival;
	cout << "--------2--------" << endl;
}

Demo a(1);

//如果不实现拷贝构造，则有默认的
Demo b = a; //Demo b(a); 构造一个对象b，使用的参数是对象a，就是用a构造出b,拷贝构造

int main()
{
	cout << "a : ival = " << a.getval() << endl;
	cout << "b : ival = " << b.getval() << endl;
}


