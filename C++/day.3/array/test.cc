#include <iostream>
using namespace std;

#include "array.h"

int main()
{
	Array a(5);
	Array b(6);

	for(int i = 0; i < 5; i++){
		a.at(i) = i;
	}
	for(int i = 0; i < 6; i++){
		b.at(i) = i;
	}

	Array c = append(a,b);

	for(int i = 0; i < 11; i++){
		cout << "c[" << i << "] = " << c.at(i) << endl;
	}
}

