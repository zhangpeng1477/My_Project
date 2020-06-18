#include <iostream>
using namespace std;

template <typename T1, typename T2> 
void prndata(const T1 &a, const T2 &b)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main()
{
#if 0
	int i = 123;
	char ch = 'a';

	prndata(i, ch);
#else
	int i = 123;
	int j = 456;
	prndata<int, int>(i, j);
#endif
}


