#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include <stdio.h>

int main()
{
	char ch = 'a';
	
	char *p = &ch;

	int *p1 = reinterpret_cast<int*>(p);

	if(NULL != p1){
		*p1 = 0x12345678;
		printf("%p, %x; %p, %x\n", p1, *p1, &ch, ch);
	}else{ 
		cout << "----------------------------" << endl;
	}
	return 0;
}


