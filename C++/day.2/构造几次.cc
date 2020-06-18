#include <iostream>
using namespace std;

# g++ xxx.cc -fno-elide-constructors

#include <iostream>
using namespace std;

class Demo{
public:
	Demo(){
		cout << this << "-------start----------" << endl;
	}
	Demo(const Demo &){
		cout << this << "-------Copy----------" << endl;
	}
	~Demo(){
		cout << this << "-------end----------" << endl;
	}
};

Demo func()
{
	Demo a;
	cout << "func: " << &a << endl;
	return a;
}


int main()
{
	Demo b(func());
	cout << "main: " << &b << endl;

}


