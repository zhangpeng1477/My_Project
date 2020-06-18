#include <iostream>
using namespace std;

#include "array.h"

int main()
{
	Array a(5);
	Array b(6);

	for(int i = 0; i < 5; i++){
		a.at(i) = 1.23+i;
		//a[i] = 1.23+i;
	}
	for(int i = 0; i < 6; i++){
		b.at(i) = 4.56+i;
	}

	Array c = append(a,b);
	//Array c = a+b;


	for(int i = 0; i < 11; i++){
		cout << "c[" << i << "] = " << c.at(i) << endl;
	}
}

