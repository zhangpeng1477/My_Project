#include <iostream>
using namespace std;
#include <assert.h>
#include <string.h>

#include "String.h"

String::String(const char* str)
{
	if(NULL != str){
		size = ::strlen(str)+1;
		addr = new char[size];
	
		assert(NULL != addr);

		::strncpy(addr, str, size);
	}else{
		addr = NULL;
		size = 0;
	}
}

String::String(const char &ch):
	size(2),
	addr(new char[2])
{
	assert(NULL != addr);
	addr[0] = ch;
	addr[1] = '\0';
}

String::String(const String &obj)
{
	if(NULL != obj.addr){
		size = obj.size;
		addr = new char[obj.size];

		assert(NULL != addr);
		::strncpy(addr, obj.addr, size);
	}else{
		addr = NULL;
		size = 0;
	}
}

String::~String()
{
	if(NULL != addr){
		delete [] addr;
		addr = NULL;
		size = 0;
	}
}

char& String::at(const int id)const
{
	assert((0 <= id) && (id < (size-1)));
	return addr[id];
}

char& String::operator[](const int id)const
{
	assert((0 <= id) && (id < (size-1)));
	return addr[id];
}

String& String::operator=(const String &a)
{
	if(addr){
		delete [] addr;
		addr = NULL;
		size = 0;
	}

	size = a.length()+1;
	addr = new char[size];

	assert(NULL != addr);
	::strncpy(addr, a.data(), size);
}

String& String::operator=(const char *str)
{
	if(addr){
		delete [] addr;
		addr = NULL;
		size = 0;
	}

	size = strlen(str)+1;
	addr = new char[size];

	assert(NULL != addr);
	::strncpy(addr, str, size);
}

char* String::data()const
{
	return addr;
}

size_t String::length()const
{
	return size-1;
}
