#include <iostream>
#include <stdexcept>
using namespace std;

#include <unistd.h>
#include <stdio.h>
#include "thread.h"

int mydiv(const int x, const int y)
throw(invalid_argument, overflow_error)
{
	if(0 != y){
		if(0 < y){
			return x/y;
		}else{
			throw overflow_error("ERROR!!! y is overflow.");
		}
	}else{
	#if 0
		invalid_argument tmp("ERROR!!! y is zero.");
		throw tmp;
	#else
		throw invalid_argument("ERROR!!! y is zero.");;
	#endif
	}
}

int main()
{
	try{
		cout << "1/2 = " << mydiv(1, -2) << endl;
		cout << "1/0 = " << mydiv(1, 0) << endl;
	}catch(const invalid_argument &err){
		cout << "1: " << err.what() << endl;
	}catch(const overflow_error &err){
		cout << "2: " << err.what() << endl;
	}

	cout << "----------------------------" << endl;

	return 0;
}


