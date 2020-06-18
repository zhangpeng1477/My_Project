#include <iostream>
using namespace std;

//模板函数最好声明定义在头文件
template <typename T> 
T add(const T &a, const T &b)
{
	return a+b;
}

#if 0
add(1,2)
--->
int add(const int &a, const int &b)
{
	retrun a+b;
}

#endif

int main()
{
	cout << "val = " << add(1,2) << endl; // int add (int, int)
	cout << "val = " << add<double>(1,2) << endl; //double add (double, double)
}


