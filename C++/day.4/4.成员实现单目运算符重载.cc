#include <iostream>
using namespace std;

class Array{
public:
	Array(const int len=12);
	Array(const Array &);

	~Array();

public:
	int& at(const int id) const;
	int& operator[](const int id)const;

private:
	int *const addr;
	const size_t size;
};

Array::Array(const int len):
	addr(new int[len]),
	size(len)
{
	cout << this << "----normal-----\n";
}

Array::Array(const Array &obj):
	addr(new int[obj.size]),
	size(obj.size)
{
	cout << this << "----copy-----\n";
	for(int i=0; i < size; i++){
		addr[i] = obj.addr[i];
	}
}

Array::~Array()
{
	if(addr)
		delete [] addr;
}

int& Array::at(const int id) const
{
	return addr[id];
}

int& Array::operator[](const int id) const
{
	return addr[id];
}

#define MAX 3
int main()
{
	Array a(MAX);
	Array arr[MAX];

	for(int i = 0; i < MAX; i++){
		//a.at(i) = i;
		a[i] = i; //调用重载的运算符[]
		for(int j = 0; j < MAX; j++){
			//arr[i].at(j) = i*j;//[]取出对象数组一个对象，.调用成员
			arr[i][j] = i*j; //第一[]取出对象数组一个对象，第二个[]调用成员函数
		}
	}

	for(int i = 0; i < MAX; i++){
		//cout << "a[" << i << "] = " << a.at(i) << endl; 
		cout << "a[" << i << "] = " << a[i] << endl; 
		for(int j = 0; j < MAX; j++){
			//cout << "arr[" << i << "]["<< j <<"]= " << arr[i].at(j) << endl; 
			cout << "arr[" << i << "]["<< j <<"]= " << arr[i][j] << endl; 
		}
	}

}

