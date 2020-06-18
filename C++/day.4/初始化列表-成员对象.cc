#include <iostream>
using namespace std;

#include "MyFile.h"
#include "Array.h"

#define TRACE()\
	cout << this << " : " << __FILE__ << " : " << __func__ << " : " << __LINE__ << endl;

class DemoA{
public:
	DemoA(const int val = 0){
		ival = val; 
	}

public:
	int getval()const{
		return ival;
	}

	void setval(const int val){
		ival = val;
	}

private:
	int ival;
};

class DemoB{
public:
	DemoB(const int val):obj(val){
	}

public:
	int getval()const{
		return obj.getval();
	}

	void setval(const int val){
		obj.setval(val);
	}
	
private:
	DemoA obj;
};

int main()
{
	DemoB obj(123);
	cout << obj.getval() << endl;
}
