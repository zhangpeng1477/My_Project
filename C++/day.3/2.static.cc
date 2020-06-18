#include <iostream>
using namespace std;

class Demo{
public:
	Demo(int val = 0){
		ival = val;
	}

	void setval(int val);
	static int getval();

private:
	static int ival;
};
//int Demo::ival;
int Demo::ival = 0;
void Demo::setval(int val){
	ival = val;
}

int Demo::getval(){
	return ival;
}
int main(){
	Demo a(1);
	Demo b(456);
	a.setval(789);
	cout << "ival = " << b.getval() << endl;
	cout << "ival = " << Demo::getval() << endl;

	getval();
}

