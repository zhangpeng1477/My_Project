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

#define T Array
//设计一个类，通过运算符重载类模拟指针
class Pointer{
public:
	Pointer(Array *p){
		ptr = p;
	}

public:
	T* getaddr() const {
		return ptr;
	}
	T* operator->() const {
		return ptr;
	}

	T& getobj(){
		return *ptr;
	}
	T& operator*(){
		return *ptr;
	}

private:
	T *ptr;
};

#define MAX 3
int main()
{
	Array a(MAX);
	Array* p = &a;

	Pointer ptr(&a);

	for(int i = 0; i < MAX; i++){
		//p->at(i) = i;
		ptr.getaddr()->at(i) = i;
		ptr->at(i) = i;
	}

	for(int i = 0; i < MAX; i++){
		//cout << "a[" << i << "]=" << (*p).at(i) << endl;
		cout << "a[" << i << "]=" << ptr.getobj().at(i) << endl;
		cout << "a[" << i << "]=" << (*ptr).at(i) << endl;
	}
}

