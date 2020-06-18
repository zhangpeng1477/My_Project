#include <iostream>
using namespace std;

#include "MyFile.h"
#include "Array.h"

#define TRACE()\
	cout << this << " : " << __FILE__ << " : " << __func__ << " : " << __LINE__ << endl;

class Demo{
public:
	Demo(const int a = 0, const int b = 0):
		arr{a,b}
	{
	}

private:
	const int arr[2];
};

int main()
{
	Demo obj(1,2);
}
