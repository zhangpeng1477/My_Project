#include <iostream>
using namespace std;

#include <string.h>

#include "fileio.h"

int main()
{
	FileIO *p = new FileIO("1.txt");
	
	char buf[] = "hello world";
	p->write(buf, sizeof(buf)-1);

	delete p;

	FileIO a("1.txt");

#define MAX 1024
	char rbuf[MAX+4];
	memset(rbuf, 0, MAX+4);
	a.read(rbuf, MAX);
	cout << "main: " << rbuf << endl;

}


