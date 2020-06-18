#include <iostream>
using namespace std;

#include "DemoA.h"
#include "DemoB.h"

int main()
{
	DemoA a(1);
	DemoB b;

	cout << "ival = " << b.getval(a) << endl;
}

