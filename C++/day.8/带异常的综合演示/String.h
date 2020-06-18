#ifndef STRING_H
#define STRING_H

#include <stdexcept>
using namespace std;

#include <string.h>

class String{
public:
	String(const char *str = NULL) throw(bad_alloc)
	{
		if(NULL != str){
			size = ::strlen(str)+1;
			addr = new char[size];
			::strncpy(addr, str, size);
		}else{
			addr =  NULL;
			size = 0;
		}
		cout << "----------normal: char*-----------" << endl;
	}

	String(const char ch) throw(bad_alloc)
	{
		size = 2;
		addr = new char[size];
		addr[0] = ch;
		addr[1] = 0;
		cout << "----------normal: char-----------" << endl;
	}

	String(const String &obj) throw(bad_alloc)
	{
		size = obj.size;
		if(size){
			addr = new char[size];
			::strncpy(addr, obj.addr, size);
		}else{
			addr = NULL;
		}
		cout << "----------copy-----------" << endl;
	}

	~String(){
		if(NULL != addr){
			delete [] addr;
			addr = NULL;
			size = 0;
		}
		cout << "----------  ~  -----------" << endl;
	}

public:
	char& at(const int id) const throw(overflow_error, underflow_error){
		if(id < 0){
			throw underflow_error("id is too small");
		}else if(id >= size){
			throw overflow_error("id is too big");
		}

		return addr[id];
	}

	char& operator[](const int id) const
	throw(overflow_error, underflow_error)
	{
		if(id < 0){
			throw underflow_error("id is too small");
		}else if(id >= size){
			throw overflow_error("id is too big");
		}

		return addr[id];
	}

	String& operator=(const char &ch)throw(bad_alloc)
	{
		if(NULL != addr){
			delete [] addr;
		}

		size = 2;
		addr = new char[2];
		addr[0] = ch;
		addr[1] = 0;
	}

	String& operator=(const char* str)throw(bad_alloc)
	{
		if(NULL != addr){
			delete [] addr;
		}

		size = ::strlen(str)+1;
		addr = new char[size];
		::strncpy(addr, str, size);
	}

	String& operator=(const String &obj)throw(bad_alloc)
	{
		if(NULL != addr){
			delete [] addr;
		}

		size = obj.size;
		if(size){
			addr = new char[size];
			::strncpy(addr, obj.addr, size);
		}else{
			addr = NULL;
		}
	}

	String& operator+=(const String &obj)throw(bad_alloc){
		if(NULL == addr){
			if(NULL != obj.addr){
				size = obj.size;
				addr = new char[size];
				::strncpy(addr, obj.addr, size);
			}
		}else{
			if(NULL != obj.addr){
				String tmp(*this);
				delete [] addr;
				size += obj.size;
				size--;
				addr = new char[size];
				::strncpy(addr, tmp.addr, tmp.size);
				::strncat(addr, obj.addr, obj.size);
			}
		}

		return *this;
	}

	const char *data() const{
		return addr;
	}

	int length() const{
		return size-1;
	}

	bool empty()const{
		return (0 == size) ? true : false; 
	}

private:
	char* addr;
	size_t size;
};

#endif
