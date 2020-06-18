#include <iostream>
#include <stdexcept>
using namespace std;

#include <unistd.h>
#include <stdio.h>
#include "thread.h"

class Demo{
public:
	Demo(const size_t len=1024)
		throw(bad_alloc)
		//�������캯��֧�ֵ��쳣�࣬����bad_alloc��newʧ��ʱ���׳����쳣
		//������Ҫ�����׳��쳣
	{
		p = new int[len];
		size = len;
	}

	~Demo(){
		delete [] p;
		cout << "----------~Demo----------" << endl;
	}

	int& operator[] (const int id)
		throw(overflow_error, underflow_error)
	{
		//�Լ��Ĵ������Ƿ�������Լ��׳��쳣
		if(id < 0){
			throw underflow_error("id is too small.");
		}else if(id >= size){
			throw overflow_error("id is too big.");
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
	}catch(const overflow_error &err){
		cout << "1: " << err.what() << endl;
	}catch(const underflow_error &err){
		cout << "2: " << err.what() << endl;
	}catch(const bad_alloc &err){
		cout << "3: " << err.what() << endl;
	}

	cout << "----------------------------" << endl;

	return 0;
}


