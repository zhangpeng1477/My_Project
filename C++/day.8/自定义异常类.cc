#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include <unistd.h>
#include <stdio.h>
#include "thread.h"

//设计一个异常类：模拟标准异常类
class Myexcept{
public:
	Myexcept(const char *err):
		msg(err)
	{
	}

	const char *what() noexcept
	{
		string tmp(msg+string(": overflow error"));
		msg = tmp;
		return msg.data();	
	}

private:
	string msg;
};

class Demo{
public:
	Demo(const size_t len=1024)
		throw(bad_alloc)
	{
		p = new int[len];
		size = len;
	}

	~Demo(){
		delete [] p;
		cout << "----------~Demo----------" << endl;
	}

	int& operator[] (const int id)
		throw(Myexcept, underflow_error)
	{
		if(id < 0){
			throw underflow_error("id is too small.");
		}else if(id >= size){
			throw Myexcept("id is too big.");
		}
			
		return p[id];
	}

private:
	int *p;
	size_t size;
};

int main()
{
	try{
		Demo a(1024);
		a[1024] = 0;
	}catch(Myexcept &err){
		cout << "1: " << err.what() << endl;
	}catch(const underflow_error &err){
		cout << "2: " << err.what() << endl;
	}catch(const bad_alloc &err){
		cout << "3: " << err.what() << endl;
	}

	cout << "----------------------------" << endl;

	return 0;
}


