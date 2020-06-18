#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

#include "demo.h"

// test.cc
Demo a;

void gfunc()
{
	Demo b;
	static Demo c;

	a.setval(123);
	cout << "a: ival = " << a.getval() << endl;

	b.setval(456);
	cout << "b: ival = " << b.getval() << endl;
	
	c.setval(789);
	cout << "c: ival = " << c.getval() << endl;
}

void ptrfunc()
{
	Demo *p = new Demo;

	p->setval(111);
	cout << "heap: ival = " << p->getval() << endl;
}

void arrfunc()
{
#define MAX 12
	Demo arr[12];
	for(int i= 0; i < MAX; i++){
		arr[i].setval(i);
		cout << "arr["<< i << "].ival = " << arr[i].getval() << endl;
	}
}

int main()
{
	//gfunc();
	//ptrfunc();
	arrfunc();
}


