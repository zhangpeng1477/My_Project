#include <iostream>
using namespace std;

#include <assert.h>

#include "array.h"

Array::Array(const int len) :
	addr(new T[len]),
	size(len)
{
	assert(NULL == addr);
}

Array::Array(const Array &obj) :
	addr(new T[obj.size]),
	size(obj.size)
{
	assert(NULL != addr);
	
	for(int i = 0; i < size; i++){
		addr[i] = obj.addr[i];
	}
}

Array::~Array()
{
	delete [] addr;
}

T& Array::at(const int id)
{
	assert((0<=id) && (id < size));

	return addr[id];
}

Array append(const Array &a, const Array &b)
{
	Array tmp(a.size+b.size);

	int i, j;
	for(i = 0; i < a.size; i++){
		tmp.addr[i] = a.addr[i];
	}

	for(j = 0; j < b.size; j++){
		tmp.addr[i+j] = b.addr[j];
	}

	return tmp;
}
	
