#include <iostream>
using namespace std;

#include <assert.h>

#define T char

class Array{
public:
	Array(const int len=1024);
	Array(const Array &);

	~Array();

public:
	T& at(const int id)const;
	T& operator[](const int id)const;

	class Pointer{
	public:
		Pointer(T *p, const int len);
	
		T* operator++();
		T* operator++(int);

		T *operator->() const;
		T& operator*() const;

	private:
		T *ptr;
		int pos;
		size_t size;
	};

	Pointer begin();
	
private:
	T *const addr;
	const size_t size;
};

Array::Pointer Array::begin()
{
	Array::Pointer tmp(addr, size);
	return tmp;
}	

Array::Pointer::Pointer(T *p, const int len):
	size(len)
{
	ptr = p;
	pos = 0;
}

T* Array::Pointer::operator++()
{
	if(pos < (size-1)){
		++ptr;
		++pos;
		return ptr;
	}

	return NULL;
}

T* Array::Pointer::operator++(int)
{
	T *p = ptr;

	if(pos < size){
		ptr++;
		pos++;
		return ptr;
	}

	return NULL;
}

T* Array::Pointer::operator->() const
{
	return ptr;
}

T& Array::Pointer::operator*() const
{
	return *ptr;
}

Array::Array(const int len):
	addr(new T[len]),
	size(len)
{
	assert(NULL != addr);
	cout << "-------normal---------\n";
}

Array::Array(const Array &obj):
	addr(new T[obj.size]),
	size(obj.size)
{
	assert(NULL != addr);
	for(int i = 0; i < size; i++){
		addr[i] = obj.addr[i];
	}
	cout << "-------copy---------\n";
}

Array::~Array()
{
	delete [] addr;
}

T& Array::at(const int id)const
{
	assert((0<=id) && (id < size));
	return addr[id];
}

T& Array::operator[](const int id)const
{
	assert((0<=id) && (id < size));
	return addr[id];
}


int main()
{
#define MAX 6
	Array arr(MAX);

	Array::Pointer p = arr.begin();

	int i;
	for(i = 0; i < 2*MAX; i++){
		*p = 'a';
		if(NULL == ++p)
			break;
	}

	cout << "i = " << i << endl;

	p = arr.begin();
	for(i = 0; i < 2*MAX; i++){
		cout <<"a[" << i << "]=" << *p << endl;

		if(NULL == ++p)
			break;
	}
}


