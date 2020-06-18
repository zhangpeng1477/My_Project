#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Demo{
public:
	Demo(const int val);

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
	cout << "----------------" << endl;
}

void test()
{
	Demo *p = new Demo(123); //构造函数传递参数
}

int main()
{
	test();
}


