#include <iostream>
#include <memory>
using namespace std;

class Demo{
public:
	Demo(){
		cout << this << "----------normal-------------\n";
	}

	Demo(const Demo &obj){
		cout << this << "----------copy-------------\n";
	}

	~Demo(){
		cout << this << "---------- ~ -------------\n";
	}

	void prnmsg()const {
		cout << "---------- prnmsg -------------\n";
	}
};

template<typename T>
class Pointer{
public:
	Pointer(const T *p):
		ptr(const_cast<T*>(p))
	{
		counter++;
	}

	Pointer(const T &){
		cout << "----------------------" << endl;
	}

	~Pointer(){
		--counter;
		if(0 == counter)
			delete ptr;
	}

	T* operator -> ()const{
		return ptr;
	}

	T& operator * () const{
		return *ptr;
	}

private:
	T* const ptr;
	static int counter;
};

template<typename T>
int Pointer<T>::counter = 0;

int main()
{
	Pointer<Demo> p(new Demo);
	//Pointer<Demo> pp=p;
	Pointer<Demo> pp(p);

	p->prnmsg();
	pp->prnmsg();

	(*p).prnmsg();
	(*pp).prnmsg();
	

	return 0;
}


