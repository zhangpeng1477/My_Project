#include <iostream>
using namespace std;

#include "array.h"


Array::Array(const int len):
	addr(new T[len]),
	size(len)
{
	for(int i = 0; i < size; i++){
		addr[i] = 0;		
	}
}

Array::Array(const Array &obj):
	addr(new T[obj.size]),
	size(obj.size)
{
	for(int i = 0; i < size; i++){
		addr[i] = obj.addr[i];		
	}
}

Array::~Array()
{
	if(addr){
		delete addr;
	}
}

T& Array::at(const int id) const
{
	return addr[id];
}

bool Array::compare(const Array &a, const Array &b)
{
	if(a.size != b.size)
		return false;

	for(int i = 0; i < a.size; i++){
		if(a.addr[i] != b.addr[i])
			return false;
	}

	return true;
}

Array append(const Array &a, const Array &b)
{
	Array tmp(a.size + b.size);

	int i;
	for(i = 0; i < a.size; i++){
		//tmp.at(i) = a.at(i);
		tmp.addr[i] = a.addr[i];
	}
	for(int j = 0; j < b.size; j++){
		tmp.addr[i+j] = b.addr[j];
	}

	return tmp;
}
