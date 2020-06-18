#include <iostream>
using namespace std;

#include "array.h"

#if 0
Array<int, MAX>--->
class Array1{
public:
	Array(const int val);
	Array(const Array &);
	~Array();

public:
	int& at(const int id)const{
		return arr[id];
	}

	int& operator[](const int id)const{
		return arr[id];
	}

private:
	int arr[6];
};

Array<int, 2*MAX>--->
class Array2{
public:
	Array(const int val);
	Array(const Array &);
	~Array();

public:
	int& at(const int id)const{
		return arr[id];
	}

	int& operator[](const int id)const{
		return arr[id];
	}

private:
	int arr[12];
};

Array2 a = 1;
#endif

int main()
{
#if 0
#define MAX 3
	Array<int, MAX> a(0); //定义一个对象，管理整数数组int arr[MAX]

	for(int i= 0; i < MAX; i++){
		cout << "a[" << i << "] = " << a[i] << endl;
	}

	//定义一个对象管理对象数组Array<int, MAX> arr[2*MAX];
	//Array<int, MAX>对象调用的构造函数是没有参数构造函数
	Array<Array<int, MAX>, 2*MAX> b(a);

	for(int i= 0; i < 2*MAX; i++){
		for(int j = 0; j < MAX; j++){
			//b[i].at(j) = 1+i+j; 
			//第一个[]取出一个对象
			//第二个[]运行对象运算符[]得到对象管理的整型数组的一个成员
			b[i][j] = 1+i+j;
		}
	}

	for(int i= 0; i < 2*MAX; i++){
		for(int j = 0; j < MAX; j++){
			cout << "a[" << i << "] = " << b[i][j] << endl;
		}
	}
#else
	//定义一个对象数组，每个对象管理整型数组int arr[MAX];

！！！	//每个对象的构造函数调用一个参数的版本	Array(int val)
	Array<int, MAX> a[MAX](0); //定义一个对象，管理整数数组int arr[MAX]
！！！	//每个对象的构造函数调用没有参数的版本	Array()
	Array<int, MAX> a[MAX]; //定义一个对象，管理整数数组int arr[MAX]
#endif
}


