#include <iostream>
#include <stdexcept>
using namespace std;

#include "String.h"

int main()
{
	try{
		String a('a');
		String b;
		String c("hello world");
		String d(b);
		String e(c);

		cout << "a: " << a.data() << endl;
		cout << "c: " << c.data() << endl;
		cout << "e: " << e.data() << endl;

		b = 'c';
		d = "12345678";
		cout << "b: " << b.data() << endl;
		cout << "d: " << d.data() << endl;

		b += d;
		cout << "b: " << b.data() << endl;
	}catch(const underflow_error &err){
		cout << err.what() << endl;
	}catch(const overflow_error &err){
		cout << err.what() << endl;
	}catch(const bad_alloc &err){
		cout << err.what() << endl;
	}

	cout << "-------------------------------------" << endl;
	return 0;
}


